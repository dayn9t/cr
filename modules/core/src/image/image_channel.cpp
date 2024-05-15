
#include "cr/image/image_channel.hpp"
#include <memory.h>

namespace cr {

    void ImageChannel::set_to(UByte value) {
        cr_ensure(width() == pitch())   // FIXME: 非连续图像有待支持
        auto a = pitch_area();
        memset(data_, value, pitch_area());
    }

    std::string ImageChannel::brief() const {
        char buf[1024];
        if (size_.width == pitch_)
            sprintf(buf, "ImageChannel(%dx%d,%p)", size_.width, size_.height, data_);
        else
            sprintf(buf, "ImageChannel(%dx%d[%d],%p)", size_.width, size_.height, pitch_, data_);
        return buf;
    }
}