#pragma once

#include <cr/basic.hpp>
#include <cr/reflect/struct.hpp>

namespace cr {

    /// 预定义颜色
    enum ColorDef : int {
        RED, ORANGE, YELLOW, GREEN, CYAN, BLUE, PURPLE,
        BLACK, WHITE, GRAY
    };

    /// 颜色
    struct Color {
    public:
        U8 b = 0;
        U8 g = 0;
        U8 r = 0;
        U8 a = 0;
    public:
        /// 默认构建黑色
        Color() {}

        /// 根据整数创建颜色
        explicit Color(uint32_t argb) { reset(argb); }

        /// 根据分量创建颜色
        explicit Color(U8 b, U8 g, U8 r, U8 a = 0)
                : b(b), g(g), r(r), a(a) {}

        /// 根据预定义索引创建颜色
        explicit Color(ColorDef def)
                : Color(colors[int(def)]) {}

        explicit Color(InString argb);

    public:
        /// 转化为整数
        uint32_t as_int() const { return *(uint32_t *) this; }

        void reset(uint32_t argb = 0) { *(uint32_t *) this = argb; }

        /// 转化成字符串
        string to_string() const;

    public:
        static const Color red;
        static const Color orange;
        static const Color yellow;
        static const Color green;
        static const Color cyan;
        static const Color blue;
        static const Color purple;
        static const Color black;
        static const Color white;
        static const Color gray;

        static const Color colors[10];
    };

    static_assert(sizeof(Color) == sizeof(uint32_t), "");
    //cx_equals_4f(Color, r, g, b, a);


    /// 保存颜色
    template<typename T, typename A>
    inline void save(const Color &v, A &o) {
        o.set(v.to_string());
    }


    /// 加载颜色
    template<typename T, typename A>
    inline bool load(Color &v, const A &o) {
        string s;
        if (!load(s, o)) return false;
        v = Color(s);
        return true;
    }


    extern const unsigned char color_tab[16][3];

    /// RGB颜色模板
    template<typename T>
    struct RgbT {
        using byte = unsigned char;
    public:
        T b;
        T g;
        T r;

    public:
        RgbT() {}

        RgbT(T r, T g, T b)
                : r(r), g(g), b(b) {}

        RgbT(int rgb) {
            byte *p = (byte *) (&rgb);
            r = *(p + 2);
            g = *(p + 1);
            b = *(p + 0);
        }

        //创建预定义颜色
        RgbT(ColorDef color) {
            this->r = color_tab[color][0];
            this->g = color_tab[color][1];
            this->b = color_tab[color][2];
        }

    public:
        int toArgb() {
            int i = 0;
            i |= (int) r << 16;
            i |= (int) g << 8;
            i |= (int) b;
            return i;
        }

        int toAbgr() {
            int i = 0;
            i |= (int) b << 16;
            i |= (int) g << 8;
            i |= (int) r;
            return i;
        }

    public:
        /// 颜色的混合
        RgbT &operator+=(const RgbT &rgb) {
            r = (r + rgb.r) / 2;
            g = (g + rgb.g) / 2;
            b = (b + rgb.b) / 2;
            return *this;
        }
    };

    //类型定义
    using Rgb = RgbT<unsigned char>;    /// 元素为Byte的RgbT
    using RgbI = RgbT<int>;                /// 元素为int的RgbT

    /// rgb获取颜色名
    ColorDef rgb_color(Rgb rgb);

    /// rgb->hsv
    void rgb2hsv(float r, float g, float b, float &h, float &s, float &v);

    /// 实际上是YCrCb->RGB
    void yuv2rgb(U8 y, U8 u, U8 v, U8 &r, U8 &g, U8 &b);

    void yuv2rgb(float y, float u, float v, float &r, float &g, float &b);

    void rgb2yuv(float r, float g, float b, float &y, float &u, float &v);


    /// 颜色
    struct Yuv {
    public:
        U8 y = 0;
        U8 u = 128;
        U8 v = 128;
    public:
        /// RGB颜色转YUV
        Yuv(Color color);
    };
}
