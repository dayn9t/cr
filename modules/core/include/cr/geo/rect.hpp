#pragma once

#include <algorithm>
#include "size.hpp"

namespace cr {
    /**
        矩形类.

        矩形区域，常用来表示范围。
    */
    template<typename T>
    struct Rectangle {
    public:
        T x = 0;
        T y = 0;
        T width = 0;
        T height = 0;
    public:
        /// 顶点
        using Vertex = Point2D<T>;

        /// 顶点集合
        using Vertexes = vector<Vertex>;
    public:
        /** @name 对象的构造与销毁.
            @{
            */

        /// 建立空的Rectangle
        Rectangle() = default;

        /// 根据宽高创建原点在左上的Rectangle
        Rectangle(T width, T height)
                : width(width), height(height) {}

        /// 用不同精度点构造
        template<typename T1>
        explicit Rectangle(Rectangle<T1> r)
                : x(T(r.x)), y(T(r.y)), width(T(r.width)), height(T(r.height)) {}

        /// 根据宽高创建原点在左上的Rectangle
        template<typename T1>
        explicit Rectangle(const Size2D<T1> &size)
                : width(T(size.width)), height(T(size.height)) {}

        /// 根据坐标高，宽创建Rectangle
        Rectangle(T x, T y, T width, T height)
                : x(x), y(y), width(width), height(height) {}

        /// 根据原点和尺寸创建Rectangle
        Rectangle(const Point2D<T> &origin, const Size2D<T> &size)
                : x(origin.x), y(origin.y), width(size.width), height(size.height) {}

        /// 根据原点和右下点创建Rectangle
        Rectangle(const Point2D<T> &left_top, const Point2D<T> &right_bottom)
                : x(left_top.x), y(left_top.y), width(right_bottom.x - left_top.x),
                  height(right_bottom.y - left_top.y) {}

        /// 根据尺寸和中心创建Rectangle
        Rectangle(const Size2D<T> &size, const Point2D<T> &center)
                : x(center.x - size.width / 2), y(center.y - size.height / 2), width(size.width), height(size.height) {}
        //@}

    public:
        /** @name 获取状态.
            @{
            */

        /// 获取原点
        Vertex location() const { return Vertex(x, y); }

        /// 获取左上点坐标
        Vertex left_top() const { return Vertex(x, y); }

        /// 获取右上点坐标
        Vertex right_top() const { return Vertex(right(), y); }

        /// 获取右下点坐标
        Vertex right_bottom() const { return Vertex(right(), bottom()); }

        /// 获取右下点坐标
        Vertex left_bottom() const { return Vertex(x, bottom()); }

        /// 获取x + width
        T right() const { return x + width; }

        /// 获取y + height
        T bottom() const { return y + height; }

        /// 获取顶点集合
        Vertexes vertexes() const {
            return Vertexes{
                    left_top(),
                    right_top(),
                    right_bottom(),
                    left_bottom(),
            };
        }

        /// 获取尺寸
        Size2D<T> size() const { return Size2D<T>(width, height); }

        /// 判断Rectangle是否是负数
        //bool negative() const { return width < 0 || height < 0; }

        /// 判断是否为正
        bool positive() const { return width > 0 && height > 0; }

        /// 判断是否存在非零成员
        explicit operator bool() const {
            return x || y || width || height;
        }
        //@}

    public:
        /** @name 平移.
        @{
        */

        /// 平移
        Rectangle &operator+=(const Point2D<T> &offset) {
            x += offset.x;
            y += offset.y;
            return *this;
        }

        /// 反方向平移
        Rectangle &operator-=(const Point2D<T> &offset) {
            return *this += -offset;
        }

        /// 平移
        Rectangle operator+(const Point2D<T> &offset) const {
            Rectangle r(*this);
            return r += offset;
        }

        /// 反方向平移
        Rectangle operator-(const Point2D<T> &offset) const {
            Rectangle r(*this);
            return r -= offset;
        }

        //@}

    public:
        /** @name 对象间空间集合运算.
            @{
            */

        /// 计算交集，结果为空的时候，产生的Rectangle为负
        Rectangle &operator&=(const Rectangle &rect) {
            T r = std::min(right(), rect.right());
            T b = std::min(bottom(), rect.bottom());

            x = std::max(x, rect.x);    //改变x,y会改变right(), bottom(),所以置于上两句后面,fixed by ccc
            y = std::max(y, rect.y);

            set_point2(r, b);
            return *this;
        }

        /// 计算交集，结果为空的时候，产生的Rectangle为负
        Rectangle operator&(const Rectangle &rect) const {
            Rectangle r = *this;
            r &= rect;
            return r;
        }

        /// 计算并集，两个矩形的外接矩形
        Rectangle &operator|=(const Rectangle &rect) {
            T r = std::max(right(), rect.right());
            T b = std::max(bottom(), rect.bottom());
            x = std::min(x, rect.x);
            y = std::min(y, rect.y);

            set_point2(r, b);
            return *this;
        }

        /// 计算并集，两个矩形的外接矩形
        Rectangle operator|(const Rectangle &rect) const {
            Rectangle r = *this;
            r |= rect;
            return r;
        }

        /// 按比例缩放
        template<typename N>
        Rectangle scale(N n) const {
            return Rectangle(T(x * n), T(y * n), T(width * n), T(height * n));
        }

        /// 按比例缩放
        template<typename N>
        void scale_me(N n) {
            x = T(x * n);
            y = T(y * n);
            width = T(width * n);
            height = T(height * n);
        }

        /// 按比例放大
        Rectangle &operator*=(double n) {
            x = T(x * n);
            y = T(y * n);
            width = T(width * n);
            height = T(height * n);
            return *this;
        }

        /// 按比例放大
        Rectangle operator*(double n) const {
            Rectangle r = *this;
            r *= n;
            return r;
        }

        /// 按比例缩小
        Rectangle &operator/=(double n) {
            x = T(x / n);
            y = T(y / n);
            width = T(width / n);
            height = T(height / n);
            return *this;
        }

        /// 按比例缩小
        Rectangle operator/(double n) const {
            Rectangle r = *this;
            r /= n;
            return r;
        }

        /// XY轴分别放大
        Rectangle &operator*=(Size2D<T> size) {
            x = T(x * size.width);
            y = T(y * size.height);
            width = T(width * size.width);
            height = T(height * size.height);
            return *this;
        }

        /// XY轴分别放大
        Rectangle operator*(Size2D<T> size) const {
            Rectangle s = *this;
            s *= size;
            return s;
        }

        /// XY轴分别缩小
        Rectangle &operator/=(Size2D<T> size) {
            x = T(x / size.width);
            y = T(y / size.height);
            width = T(width / size.width);
            height = T(height / size.height);
            return *this;
        }

        /// XY轴分别缩小
        Rectangle operator/(Size2D<T> size) const {
            Rectangle s = *this;
            s /= size;
            return s;
        }
        //@}

    public:

    public:
        /** @name 对象之间的关系.
            @{
            */

        /// 判断是否包含目标区域
        bool contains(const Rectangle &r) const {
            return x <= r.x
                   && y <= r.y
                   && right() >= r.right()
                   && bottom() >= r.bottom();
        }

        /// 判断是否包含指定点
        bool contains(const Point2D<T> &p) const {
            return x <= p.x
                   && y <= p.y
                   && right() >= p.x
                   && bottom() >= p.y;
        }

        /// 判断是否与目标相交
        bool intersect(const Rectangle &rect) const {
            T l = std::max(x, rect.x);
            T t = std::max(y, rect.y);
            T r = std::min(right(), rect.right());
            T b = std::min(bottom(), rect.bottom());
            return r > l && b > t;
        }

        //@}

        /// 矩形中心

        Point2D<T> center() const {
            return Point2D<T>(x + width / 2, y + height / 2);
        }

        /// 矩形面积
        T area() const {
            return height * width;
        }

        /// 转秩
        Rectangle transpose() const {
            return Rectangle(y, x, height, width);
        }

    private:
        //设置右下角点
        void set_point2(T right, T bottom) {
            width = right - x;
            height = bottom - y;
        }
    };

    cr_template_struct_4f(Rectangle, x, y, width, height);

    /// 从类型中获取矩形, 相关类型皆可可重载 get_rect 函数
    template<typename T>
    Rectangle<T> get_rect(Rectangle<T> r) { return r; }

    template<typename T>
    Rectangle<T> average(Rectangle<T> r1, Rectangle<T> r2) {
        return Rectangle<T>(
                (r1.x + r2.x) / 2,
                (r1.y + r2.y) / 2,
                (r1.width + r2.width) / 2,
                (r1.height + r2.height) / 2
        );
    }

    /// int Rectangle
    using Rect = Rectangle<int>;
    /// short Rectangle
    using RectS = Rectangle<short>;
    /// float Rectangle
    using RectF = Rectangle<float>;
    /// double Rectangle
    using RectD = Rectangle<double>;

    /// Rectangle集合
    template<typename T>
    using Rectangles = vector<Rectangle<T>>;

    /// int Rectangle集合
    using Rects = Rectangles<int>;
    /// int Rectangle集合
    using RectFs = Rectangles<float>;
    /// int Rectangle集合
    using RectDs = Rectangles<double>;


    /// 获取点集的外接矩形
    template<typename T>
    Rectangle<T> bounding_rect(const vector<Point2D<T>> &points) {
        if (points.empty()) return Rectangle<T>{};            //todo:异常？

        T x1 = points[0].x;
        T y1 = points[0].y;
        T x2 = x1;
        T y2 = y1;

        for (auto p: points) {
            if (p.x < x1) x1 = p.x;
            if (p.y < y1) y1 = p.y;
            if (p.x > x2) x2 = p.x;
            if (p.y > y2) y2 = p.y;
        }
        return Rectangle<T>(Point2D<T>(x1, y1), Point2D<T>(x2, y2));
    }


    /// 获取纵横比为指定值的最小外包Rect
    template<typename T>
    Rectangle<T> bounding_rect(Rectangle<T> src, Size2D<T> aspect) {
        auto dst_size = bounding_size(src.size(), aspect);
        return Rectangle<T>(dst_size, src.center());
    }


    /// 坐标对齐到偶数
    inline Rect to_even(Rect r) {
        return Rect{
                r.x / 2 * 2,
                r.y / 2 * 2,
                r.width / 2 * 2,
                r.height / 2 * 2,
        };
    }


    /// 遍历每个元素
    template<typename T, typename F>
    void for_xy(Rectangle<T> self, F fun, int step = 1) {
        for (int y = self.y; y < self.bottom(); y += step) {
            for (int x = self.x; x < self.right(); x += step) {
                fun(x, y);
            }
        }
    }


    /// 遍历每个元素
    template<typename T, typename F>
    void for_point(Rectangle<T> self, F fun, int step = 1) {
        for (int y = self.y; y < self.bottom(); y += step) {
            for (int x = self.x; x < self.right(); x += step) {
                fun(Point(x, y));
            }
        }
    }


    /// 矩形分块
    template<typename T>
    Rectangles<T> to_blocks(Rectangle<T> self, Size2D<T> block) {
        Rectangles<T> blocks;
        T w = block.width;
        T h = block.height;
        for (T y = self.y; y + h <= self.height; y += h) {
            for (T x = self.x; x + w <= self.width; x += w) {
                blocks.push_back(Rectangle<T>(x, y, w, h));
            }
        }
        return blocks;
    }
}
