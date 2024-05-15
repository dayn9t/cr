#include <cr/geo.hpp>
#include <cr/test.hpp>

namespace {

    template<typename T>
    void test_equal() {
        Point2D<T> p0;
        Point2D<T> p1;
                TR(p0 == p1);

        Point2D<T> p2(1, 1);
        Point2D<T> p3(1, 1);
                TR(p2 == p3);

                TR(p0 != p2);
    }
}

TEST(Point, equal) {
    test_equal<int>();
    test_equal<double>();
}


TEST(Point, sub) {
    Point p1{1, 1};
    Point p2{-1, -1};

            TR(p1 == -p2);
}


TEST(Point, line_side)
{
    const int w = 352;
    const int h = 288;

    Point p[4] = {
        Point(0, 0),
        Point(0, w),
        Point(h, w),
        Point(h, 0),
    };

    TR(same_side(p[0], p[1], p[2], p[3]));
    TR(same_side(p[1], p[2], p[3], p[0]));
    TR(!same_side(p[0], p[2], p[1], p[3]));

}
