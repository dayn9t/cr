#include <cr/media/img_io.hpp>
#include <cr/test.hpp>

TEST(Image, io) {
    U8 data[1 << 20] = {};
    Size size(640, 360);
    {
        Image img1(CR_CF_BGR_P, size, data);

        auto channels = img1.channels();
        channels[2].set_to(255);
        for (auto c: channels) {
                    EQ(c.size(), size);
        }
        save(img1, "/home/jiang/1/a.jpg");
    }
    {
        Image img1(CR_CF_NV12, size, data);
        img1.clear();

        auto channels = img1.channels();
        channels[0].set_to(200);
        channels[1].set_to(200);

        save(img1, "/home/jiang/1/b.jpg");
    }
}

