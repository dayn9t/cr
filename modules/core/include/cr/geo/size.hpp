#pragma once

#include "point.hpp"

namespace cr {

    /// 2D尺寸
    template<typename T>
    struct Size2D {
        T width = 0;
        T height = 0;
    public:
        /// 构造对象
        Size2D() {}

        /// 用不同精度点构造
        template<typename T1>
        explicit Size2D(Size2D<T1> size)
                : width(T(size.width)), height(T(size.height)) {}

        /// 根据宽高构造
        Size2D(T width, T height)
                : width(width), height(height) {}

        /// 根据点构造
        explicit Size2D(const Point2D<T> &point)
                : width(point.x), height(point.y) {}

    public:
        /// 判断是否为正
        bool positive() const { return width > 0 && height > 0; }

        /// 判断是否为负
        bool negative() const { return width < 0 || height < 0; }

        /// 判断是否为非负
        bool nonnegative() const { return width >= 0 && height >= 0; }

        /// 判断是否为空
        bool empty() const { return width == 0 && height == 0; }

        /// 判断是否存在非零成员
        explicit operator bool() const {
            return width || height;
        }

        /// 面积
        T area() const { return width * height; }

    public:

        /// 判断是否包含目标
        bool contains(const Size2D &r) const {
            return width >= r.width && height >= r.height;
        }

        /// 判断是否包含点(人性化接口)
        bool contains(Point2D<T> p) const {
            return p.x >= 0 && p.x < width && p.y >= 0 && p.y < height;
        }

        /// Size的并集
        Size2D &operator|=(const Size2D &size) {
            width = std::max(width, size.width);
            height = std::max(height, size.height);
            return *this;
        }

        /// Size的并集
        Size2D operator|(const Size2D &size) const {
            Size2D s = *this;
            s |= size;
            return s;
        }

        /// Size的交集
        Size2D &operator&=(const Size2D &size) {
            width = std::min(width, size.width);
            height = std::min(height, size.height);
            return *this;
        }

        /// Size的交集
        Size2D operator&(const Size2D &size) const {
            Size2D s = *this;
            s &= size;
            return s;
        }

        /// 将一个 Size 结构的宽度和高度与另一个 Size 结构的宽度和高度相加。
        Size2D &operator+=(const Size2D &size) {
            this->width += size.width;
            this->height += size.height;
            return *this;
        }

        /// 将一个 Size 结构的宽度和高度从另一个 Size 结构的宽度和高度中减去。
        Size2D &operator-=(const Size2D &size) {
            this->width -= size.width;
            this->height -= size.height;
            return *this;
        }

        /// 按比例扩大
        template<typename T1>
        Size2D scale(T1 n) const {
            return Size2D(T(width * n), T(height * n));
        }

        /// 按比例缩放
        Size2D &operator*=(double n) {
            width = T(width * n);
            height = T(height * n);
            return *this;
        }

        /// 按比例缩放
        Size2D operator*(double n) const {
            Size2D s = *this;
            s *= n;
            return s;
        }

        /// 按比例缩放
        Size2D &operator/=(double n) {
            width = T(width / n);
            height = T(height / n);
            return *this;
        }

        /// 按比例缩放
        Size2D operator/(double n) const {
            Size2D s = *this;
            s /= n;
            return s;
        }

        /// XY轴分别放大
        Size2D &operator*=(Size2D size) {
            width = T(width * size.width);
            height = T(height * size.height);
            return *this;
        }

        /// XY轴分别放大
        Size2D operator*(Size2D size) const {
            Size2D s = *this;
            s *= size;
            return s;
        }

        /// XY轴分别缩小
        Size2D &operator/=(Size2D size) {
            width = T(width / size.width);
            height = T(height / size.height);
            return *this;
        }

        /// XY轴分别缩小
        Size2D operator/(Size2D size) const {
            Size2D s = *this;
            s /= size;
            return s;
        }

    public:
        /// 交换
        void swap(Size2D &size) noexcept {
            Size2D t = size;
            size = *this;
            *this = t;
        }
    };

    cr_template_struct_2f(Size2D, width, height);

    /// 从类型中获取2D尺寸, 相关类型皆可重载 get_size 函数
    template<typename T>
    Size2D<T> get_size(Size2D<T> s) { return s; }

    /// 整数2D尺寸
    using Size = Size2D<int>;
    /// 浮点2D尺寸
    using SizeF = Size2D<float>;
    /// 浮点2D尺寸
    using SizeD = Size2D<double>;


    /// 判定2D尺寸相等
    template<typename S1, typename S2>
    bool same_size(const S1 &s1, const S2 &s2) { return get_size(s1) == get_size(s2); }

    /// 判定2D尺寸相等 - 多个参数
    template<typename S1, typename S2, typename ... Args>
    bool same_size(const S1 &a, const S2 &b, const Args &... rest) { return same_size(a, b) && same_size(a, rest...); }

    /// 判定纵横比相等
    template<typename T1, typename T2>
    bool aspect_ratio_equal(Size2D<T1> s1, Size2D<T2> s2) {
        return s1.height * s2.width == s2.height * s1.width;
    }

    /// 获取纵横比为指定值的最小外包Size
    template<typename T>
    Size2D<T> bounding_size(Size2D<T> src, Size2D<T> aspect) {
        auto dst = src;
        if (src.height * aspect.width > aspect.height * src.width) {
            dst.width = dst.height * aspect.width / aspect.height;   // 偏高则增加宽度
        } else {
            dst.height = dst.width * aspect.height / aspect.width;  // 偏宽则增加高度
        }
        return dst;
    }

    /// 标量除法，对应宽高相除结果相等则返回该结果，否则抛出异常
    template<typename T1, typename T2>
    double scalar_div(Size2D<T1> s1, Size2D<T2> s2) {
        ensure(aspect_ratio_equal(s1, s2));
        return 1.0 * s1.height / s2.height;
    }

    /// 尺寸向上对齐
    template<typename T>
    Size2D<T> align_up(Size2D<T> size, T n) {
        return Size2D<T>{
                align_up(size.width, n),
                align_up(size.height, n)
        };
    }

    /// 尺寸向下对齐
    template<typename T>
    Size2D<T> align_down(Size2D<T> size, T n) {
        return Size2D<T>{
                align_down(size.width, n),
                align_down(size.height, n)
        };
    }

    /// 遍历每个元素
    template<typename T, typename F>
    void for_xy(Size2D<T> size, F fun) {
        for (int y = 0; y < size.height; ++y) {
            for (int x = 0; x < size.width; ++x) {
                fun(x, y);
            }
        }
    }

    /// 遍历每个元素
    template<typename T, typename F>
    void for_point(Size2D<T> size, F fun) {
        for (int y = 0; y < size.height(); ++y) {
            for (int x = 0; x < size.width(); ++x) {
                fun(Point(x, y));
            }
        }
    }
}

