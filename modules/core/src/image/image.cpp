#include "cr/image/image.hpp"
#include <memory.h>
#include <map>
#include "cr/dbc.hpp"
#include "cr/geo.hpp"

namespace cr {

    ImageLayout::ImageLayout(CrColorFormat format, Size size, size_t pitch)
            : pitch_(pitch) {
        pitch = pitch > 0 ? pitch : size.width;
        const size_t max_channel_len = pitch * size.height;

        auto &meta = format_meta(format);

        size_t offset = 0;
        for (size_t i = 0; i < meta.channel_num; ++i) {
            sizes_.push_back(meta.channel_size(i, size));
            offsets_.push_back(offset);
            colors_.push_back(meta.default_colors[i]);
            offset += meta.channel_len(i, max_channel_len);
        }
        total_len_ = offset;
    }

    ImageChannels ImageLayout::lay_channels(UByte *data) const {
        int col_step = 1;
        ImageChannels cs;
        for (size_t i = 0; i < sizes_.size(); ++i) {
            ImageChannel c(sizes_[i], data + offsets_[i], pitch_, colors_[i], col_step);
            cs.push_back(c);
        }
        return cs;
    }


    size_t ImageMeta::channel_len(size_t i, size_t max_channel_len) const {
        return size_t(double(max_channel_len) * size_factors[i].area());
    }

    Size ImageMeta::channel_size(size_t i, Size size) const {
        auto s = size_factors[i];
        return {int(size.width * s.width), int(size.height * s.height)};
    }

    const static ImageMeta I420 = {2, {{1, 1}, {1, 0.5}}, {0, 128}};
    const static ImageMeta P3 = {3, {{1, 1}, {1, 1}, {1, 1}}};
    const static ImageMeta P1 = {1, {{1, 1}}};

    const ImageMeta &format_meta(CrColorFormat format) {
        const static std::map<CrColorFormat, const ImageMeta &> map = {
                {CR_CF_NV12,  I420},
                {CR_CF_NV21,  I420},
                {CR_CF_RGB_P, P3},
                {CR_CF_BGR_P, P3},
                {CR_CF_GRAY,  P1},
        };
        auto p = map.find(format);
        cr_ensure(p != map.end());
        return p->second;
    }


    Image::Image(CrColorFormat format, Size size, UByte *data, size_t pitch)
            : format_(format), size_(size) {
        auto layout = ImageLayout(format, size, pitch);
        channels_ = layout.lay_channels(data);
    }

    void Image::clear() {
        for (auto &c: channels_) {
            c.clear();
        }
    }

    string Image::brief() const {
        std::string plans;
        for (auto &c: channels()) {
            plans += c.brief() + ",";
        }

        char buf[512] = {};
        auto s = size();
        sprintf(buf, "Frame(%d %dx%d,%p,[%s])", format_, s.width, s.height, data(), plans.c_str());
        return buf;
    }
}
