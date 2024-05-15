#pragma once

#include "basic.hpp"
//#include <iv/core/config.hpp>
#include <cr/reflect/template_struct.hpp>

namespace cr {
    template<typename T>
    struct Size2D;

    /**
     *	平面上的点.
     *
     *	平面上的点,接口设计参考了GDI+。
     */
    template<typename T>
    struct Point2D {
        T x;
        T y;

    public:
        /// 用不同精度点构造
        template<typename T1>
        explicit Point2D(Point2D<T1> p)
                : x((T) p.x), y((T) p.y) {}

        /// 构造原点
        Point2D()
                : x(), y() {}

        /// 根据x, y构造
        Point2D(T x, T y)
                : x(x), y(y) {}

        /// 根据Size2D构造
        explicit Point2D(Size2D<T> size)
                : x(size.width), y(size.height) {}

    public:

        /// 判断是否存在非零成员
        explicit operator bool() const {
            return x || y;
        }

        /// 判断是否为正
        bool positive() const { return x > 0 && y > 0; }

        /// 计算点的模的平方
        T abs2() const {
            return x * x + y * y;
        }

    public:
        Point2D operator-() const { return {-x, -y}; }

    public:

        /// Point2D之间的加法
        Point2D &operator+=(const Point2D &point) {
            x += point.x;
            y += point.y;
            return *this;
        }

        /// Point2D之间的减法
        Point2D &operator-=(const Point2D &point) {
            x -= point.x;
            y -= point.y;
            return *this;
        }

        /// Point2D之间差
        Point2D operator+(const Point2D &point) const {
            return Point2D(x + point.x, y + point.y);
        }

        /// Point2D之间差
        Point2D operator-(const Point2D &point) const {
            return Point2D(x - point.x, y - point.y);
        }

        /// 按比例缩放
        template<typename N>
        Point2D scale(N n) const {
            return Point2D(T(x * n), T(y * n));
        }

        /// 按比例缩放
        Point2D &operator*=(double n) {
            x = T(x * n);
            y = T(y * n);
            return *this;
        }

        /// 按比例缩放
        Point2D operator*(double n) {
            Point2D p = *this;
            p *= n;
            return p;
        }

        /// 按比例缩放
        Point2D &operator/=(double n) {
            x = T(x / n);
            y = T(y / n);
            return *this;
        }

        /// 按比例缩放
        Point2D operator/(double n) {
            Point2D p = *this;
            p /= n;
            return p;
        }

        /// 比较（行先序）
        bool operator<(Point2D p) const {
            return y < p.y || (y == p.y && x < p.x);
        }
    };

    cr_template_struct_2f(Point2D, x, y);

    /// 从类型中获取点, 相关类型皆可可重载 get_point 函数
    template<typename T>
    Point2D<T> get_point(Point2D<T> p) { return p; }

    /// 整数表示的2D点
    using Point = Point2D<int>;
    /// 浮点表示的2D点
    using PointF = Point2D<float>;
    /// 浮点表示的2D点
    using PointD = Point2D<double>;

    using Points = vector<Point>;
    using PointFs = vector<PointF>;
    using PointDs = vector<PointD>;

    template<typename T>
    using Point2Ds = vector<Point2D<T>>;    /// 点集定义

    /// 计算点之间距离的平方
    template<typename T>
    T dist2(Point2D<T> p1, Point2D<T> p2) {
        T dx = p2.x - p1.x;
        T dy = p2.y - p1.y;
        return dx * dx + dy * dy;
    }

    /// 两点之间的中点
    template<typename T>
    Point2D<T> center(const Point2D<T> &p1, const Point2D<T> &p2) {
        return Point2D<T>((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
    }

    /// 多边形几何中心
    Point center(const Points &polygen);

    PointF center(const PointFs &polygen);

    PointD center(const PointDs &polygen);


    /// 点是否在多边形内
    bool within(Point point, const Points &polygen);

    /// 点舍入取整
    template<typename T>
    Point round(Point2D<T> p) {
        return Point((int) (p.x + 0.5), (int) (p.y + 0.5));
    }

    /// 点截断取整
    template<typename T>
    Point f2i(Point2D<T> p) {
        return Point((int) p.x, (int) p.y);
    }

    /**
     *	计算(P1-P0)*(P2-P0)的叉积.
     *	若结果为r，则:
     *		r > 0，<P0,P1>在<P0,P2>的顺时针方向；
     *		r = 0，<P0,P1><P0,P2>共线；
     *		r < 0，<P0,P1>在<P0,P2>的在逆时针方向;
     */
    template<typename T>
    inline T multiply(const Point2D<T> &p1, const Point2D<T> &p2, const Point2D<T> &p0) {
        return
                (p1.x - p0.x) * (p2.y - p0.y) -
                (p2.x - p0.x) * (p1.y - p0.y);
    }
}

