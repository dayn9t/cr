#pragma once

// 几何类型泛型算法

#include <cr/basic.hpp>
#include <math.h>

namespace cr {

#pragma region Point

    /// Point相等判断
    template<typename P1, typename P2>
    bool point_equal(const P1 &p1, const P2 &p2) {
        return p1.x == p2.x && p1.y == p2.y;
    }

    /// Point类型间转换
    template<typename P1, typename P2>
    P1 point_cast(const P2 &point) {
        P1 p;
        typedef decltype(p.x) T;
        p.x = static_cast<T>(point.x);
        p.y = static_cast<T>(point.y);
        return p;
    }

    /// 缩放Point
    template<typename P, typename S>
    P point_scale(const P &point, S s) {
        P p;
        typedef decltype(p.x) T;
        p.x = static_cast<T>(point.x * s);
        p.y = static_cast<T>(point.y * s);
        return p;
    }

    /// 计算点之间距离的平方
    template<typename P1, typename P2>
    double dist2(P1 p1, P2 p2) {
        auto dx = p2.x - p1.x;
        auto dy = p2.y - p1.y;
        return dx * dx + dy * dy;
    }


    /// 判断变量v是否处于[v1, v2]区间内
    template<typename T>
    bool in_range(T v, T v1, T v2) {
        return v >= std::min(v1, v2) && v <= std::max(v1, v2);
    }

    //多边形周长
    template<typename Points>
    double perimeter(Points polygen) {
        double s = 0;
        for (size_t i = 0; i < polygen.size(); ++i) {
            auto d = dist2(polygen[i], polygen[(i + 1) % polygen.size()]);
            s += sqrt(d);
        }
        return s;
    }


    template<typename Points>
    double area(const Points &region) {
        if (region.size() < 3) return 0;

        double s = 0;
        const size_t n = region.size();

        for (size_t i = 0; i < n; ++i) {
            int j = (i + 1) % n;
            s += region[i].x * region[j].y - region[j].x * region[i].y;
        }
        return s * 0.5;
    }

    /// 判断点是否在多边形内(含边界)
    template<typename P, typename A>
    bool point_in_polygon1(P p, const A &polygon) {
        int cross = 0;
        for (size_t i = 0; i < polygon.size(); i++) {
            P p1 = polygon[i];
            P p2 = polygon[(i + 1) % polygon.size()];

            if (!in_range(p.y, p1.y, p2.y)) continue;        //交点在[p1, p2]延长线上，忽略

            if (p1.y == p2.y) {
                if (in_range(p.x, p1.x, p2.x)) return true;    //p在[p1, p2]上
            } else {
                //求解 y = p.y 与 (p1, p2)交点X坐标
                double x = (double) (p.y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y) + p1.x;
                if (x == p.x) return true;                    //p在[p1, p2]上
                if (x > p.x) cross++;                        //只统计正无穷的交点
            }
        }
        // 单边交点为偶数，点在多边形之外
        return (cross % 2 == 1);
    }

    /// 点带入直线方程的值
    template<typename Point>
    inline double _equation(Point p, Point p1, Point p2) {
        auto a = (p.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p.x - p1.x);
        return (p.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p.x - p1.x);
    }

    /// 判断点p0,p1是否在p2,p3所在直线同一侧
    template<typename Point>
    inline bool same_side(Point p0, Point p1, Point p2, Point p3) {
        return _equation(p0, p2, p3) * _equation(p1, p2, p3) > 0;
    }

    /// 判断点p0,p1是否在p2,p3所在直线不同侧
    template<typename Point>
    inline bool diff_side(Point p0, Point p1, Point p2, Point p3) {
        return _equation(p0, p2, p3) * _equation(p1, p2, p3) < 0;
    }

    /// 判断线段是否相交
    template<typename Point>
    inline bool segment_cross(Point p0, Point p1, Point p2, Point p3) {
        return diff_side(p0, p1, p2, p3) && diff_side(p2, p3, p0, p1);
    }

#pragma endregion
#pragma region Size

    /// Size相等判断
    template<typename S1, typename S2>
    bool size_equal(const S1 &s1, const S2 &s2) {
        return s1.width == s2.width && s1.height == s2.height;
    }

    /// Size类型间转换
    template<typename S1, typename S2>
    S1 size_cast(const S2 &size) {
        S1 s;
        typedef decltype(s.width) T;
        s.width = static_cast<T>(size.width);
        s.height = static_cast<T>(size.height);
        return s;
    }

    /// Size缩放
    template<typename S, typename D>
    S size_scale(const S &size, D d) {
        S s;
        typedef decltype(s.width) T;
        s.width = static_cast<T>(size.width * d);
        s.height = static_cast<T>(size.height * d);
        return s;
    }

    /// 纵横比
    template<typename S>
    double aspect_ratio(S size) {
        return 1.0 * size.height / size.width;
    }

#pragma endregion
#pragma region Rect

    /// Rect相等判断
    template<typename R1, typename R2>
    bool rect_equal(const R1 &r1, const R2 &r2) {
        return r1.x == r2.x && r1.y == r2.y && r1.width == r2.width && r1.height == r2.height;
    }

    /// Rect类型间转换
    template<typename R1, typename R2>
    R1 rect_cast(const R2 &rect) {
        R1 r;
        typedef decltype(r.x) T;
        r.x = static_cast<T>(rect.x);
        r.y = static_cast<T>(rect.y);
        r.width = static_cast<T>(rect.width);
        r.height = static_cast<T>(rect.height);
        return r;
    }

    /// static_cast<decltype(rect.x)>(rect.x * d);			todo

    /// 缩放Rect
    template<typename R, typename S>
    R rect_scale(const R &rect, S s) {
        R r;
        typedef decltype(r.x) T;
        r.x = T(rect.x * s);
        r.y = T(rect.y * s);
        r.width = T(rect.width * s);
        r.height = T(rect.height * s);
        return r;
    }

    /// Rect中心点
    template<typename P, typename R>
    P rect_center(const R &rect) {
        typedef decltype(rect.x) T;
        P p;
        p.x = T(rect.x) + T(rect.width - 1) / 2;
        p.y = T(rect.y) + T(rect.height - 1) / 2;
        return p;
    }

    /// Rect包含Point判断
    template<typename R, typename P>
    bool rect_contains_point(const R &r, const P &p) {
        return r.x <= p.x
               && r.y <= p.y
               && r.x + r.width > p.x
               && r.y + r.height > p.y;
    }

    /// Rect包含判断
    template<typename R1, typename R2>
    bool rect_contains(const R1 &r1, const R2 &r2) {
        return r1.x <= r2.x
               && r1.y <= r2.y
               && r1.x + r1.width >= r2.x + r2.width
               && r1.y + r1.height >= r2.y + r2.height;
    }

    /// Rect分块
    template<typename R>
    std::vector<R> rect_blocks(const R &rect, int col, int row) {
        std::vector<R> blocks;

        typedef decltype(rect.x) T;
        T block_w = T(rect.width / col);
        T block_h = T(rect.height / row);
        T right = rect.x + rect.width;
        T bottom = rect.y + rect.height;

        for (T y = rect.y; y + block_h <= bottom; y += block_h) {
            for (T x = rect.x; x + block_w <= right; x += block_w) {
                blocks.push_back(R{x, y, block_w, block_h});
            }
        }
        return blocks;
    }

#pragma endregion
#pragma region Misc

    /// 缩放指定倍数
    template<typename T, typename N>
    T scale(const T &s, const N &n) {
        T s1 = s;
        s1.scale_me(n);
        return s1;
    }

    /// 集合内所有元素缩放指定倍数
    template<typename T, typename N>
    void scale_me(std::vector<T> &v, const N &n) {
        for (auto &e: v) e.scale_me(n);
    }


#pragma endregion
}
