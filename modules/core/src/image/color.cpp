
#include <cr/image/color.hpp>
#include <cr/image/pixel.hpp>
#include <algorithm>

namespace cr {

    Color::Color(InString argb) {
        uint32_t bgra = 0;
        cr_ensure(sscanf(argb.c_str(), "#%x", &bgra) == 1);
        *this = Color(bgra);
    }


    string Color::to_string() const {
        char str[32];
        auto fmt = a ? "#%08x" : "#%06x";
        sprintf(str, fmt, as_int());
        return str;
    }


    const Color Color::red{0x00, 0x00, 0xff, 0xff};
    const Color Color::orange{0x00, 0x80, 0xff, 0xff};
    const Color Color::yellow{0x00, 0xff, 0xff, 0xff};
    const Color Color::green{0x00, 0xff, 0x00, 0xff};
    const Color Color::cyan{0xff, 0xff, 0x00, 0xff};
    const Color Color::blue{0xff, 0x00, 0x00, 0xff};
    const Color Color::purple{0xff, 0x00, 0xff, 0xff};
    const Color Color::black{0x00, 0x00, 0x00, 0xff};
    const Color Color::white{0xff, 0xff, 0xff, 0xff};
    const Color Color::gray{0x80, 0x80, 0x80, 0xff};

    const Color Color::colors[] = {red, orange, yellow, green, cyan, blue, purple, black, white, gray};


    const UByte color_tab[16][3] = {
            {0xff, 0x00, 0x00},    // RED
            {0xff, 0x80, 0x00},    // ORANGE
            {0xff, 0xff, 0x00},    // YELLOW
            {0x00, 0xff, 0x00},    // GREEN
            {0x00, 0xff, 0xff},    // CYAN
            {0x00, 0x00, 0xff},    // BLUE
            {0xff, 0x00, 0xff},    // PURPLE
            {0x00, 0x00, 0x00},    // BLACK
            {0xff, 0xff, 0xff},    // WHITE
            {0x80, 0x80, 0x80},    // GRAY
    };


    ///rgb获取颜色名
    ColorDef rgb_color(Rgb rgb) {
        int n = 0;
        int m = 255 * 255 * 3 + 1;
        for (int i = 0; i < 9; ++i) {        // 不考虑灰色
            int r = color_tab[i][0] - rgb.r;
            int g = color_tab[i][1] - rgb.g;
            int b = color_tab[i][2] - rgb.b;
            int d = r * r + g * g + b * b;
            if (d < m) {
                n = i;
                m = d;
            }
        }
        return ColorDef(n);
    }


    void rgb2hsv(float r, float g, float b, float &h, float &s, float &v) {
        // r,g,b values are from 0 to 1
        // h = [0,360], s = [0,1], v = [0,1]
        // if s == 0, then h = -1 (undefined)

        float mi, ma, delta, tmp;

        tmp = std::min(r, g);
        mi = std::min(tmp, b);
        tmp = std::max(r, g);
        ma = std::max(tmp, b);
        v = ma; // v

        delta = ma - mi;

        if (ma != 0)
            s = delta / ma; // s
        else {        // r = g = b = 0 // s = 0, v is undefined
            s = 0;
            h = 0;
            return;
        }
        if (r == ma)
            h = (g - b) / delta; // between yellow & magenta
        else if (g == ma)
            h = 2 + (b - r) / delta; // between cyan & yellow
        else
            h = 4 + (r - g) / delta; // between magenta & cyan

        h *= 60; // degrees
        if (h < 0)
            h += 360;
    }


    // 实际上是YCrCb->RGB
    void yuv2rgb(UByte y, UByte u, UByte v, UByte &r, UByte &g, UByte &b) {
        int u1 = u - 128;
        int v1 = v - 128;

        int rd = v1 + ((v1 * 103) >> 8);
        int gd = ((u1 * 88) >> 8) + ((v1 * 183) >> 8);
        int bd = u1 + ((u1 * 198) >> 8);

        r = to_ubyte(y + rd);
        g = to_ubyte(y - gd);
        b = to_ubyte(y + bd);
    }


    void yuv2rgb(float y, float u, float v, float &r, float &g, float &b) {
        r = y + 1.14f * v;
        g = y - 0.39f * u - 0.58f * v;
        b = y + 2.03f * u;
    }


    void rgb2yuv(float r, float g, float b, float &y, float &u, float &v) {
        y = 0.299f * r + 0.587f * g + 0.114f * b;
        u = -0.147f * r - 0.289f * g + 0.436f * b;
        v = 0.615f * r - 0.515f * g - 0.100f * b;
    }

    Yuv::Yuv(Color color) {
        float y, u, v;
        rgb2yuv(color.r, color.g, color.b, y, u, v);
        y = to_ubyte(y);
        u = to_ubyte(u + 128);
        v = to_ubyte(v + 128);
    }
}
