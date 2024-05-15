
#include "cr/image/image.hpp"
#include "cr/test.hpp"

TEST(image_layout, all) {

    Size size{9, 10};
    int pitch = 10;
    UByte buffer[1024] = {};
    auto p = buffer;

    {
        auto l = ImageLayout(CR_CF_GRAY, size, pitch);
                EQ(l.total_len(), 100);
        auto cs = l.lay_channels(buffer);
                EQ(cs.size(), 1);
                EQ(cs[0].size(), size);
                EQ(cs[0].data(), buffer);

    }
    {
        auto l = ImageLayout(CR_CF_BGR_P, size, pitch);
                EQ(l.total_len(), 300);
        auto cs = l.lay_channels(buffer);
                EQ(cs.size(), 3);
        size_t offsets[] = {0, 100, 200};
        for (size_t i = 0; i < cs.size(); ++i) {
                    EQ(cs[i].size(), size);
                    EQ(cs[i].data(), buffer + offsets[i]);
        }
    }
    {
        auto l = ImageLayout(CR_CF_NV12, size, pitch);
                EQ(l.total_len(), 150);
        auto cs = l.lay_channels(buffer);
                EQ(cs.size(), 2);
        size_t offsets[] = {0, 100};
        Size sizes[] = {size, Size(9, 5)};
        for (size_t i = 0; i < cs.size(); ++i) {
                    EQ(cs[i].size(), sizes[i]);
                    EQ(cs[i].data(), buffer + offsets[i]);
        }
    }
}
