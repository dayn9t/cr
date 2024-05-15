
#include <cr/media/draw.hpp>
//#include <iv/core/geo/trans.hpp>
#include <cr/media/ica4core.hpp>
#include <opencv2/imgproc.hpp>

using namespace ica;

namespace cr {
    void rectangle(Image image, Rect rect, Pen pen) {
        if (image.format() == CR_CF_NV12) {
            auto cs = image.channels();
            Mat y_plane = to_cv(cs[0]);
            //Mat uv_plane() = to_cv(cs[1]);    TODO: CV_8UC2
            auto r0= to_cv(rect);
            auto r1=to_cv(rect.scale(0.5));
            Yuv yuv(pen.color);

            cv::rectangle(y_plane, r0, cv::Scalar(yuv.y));

            //size.height = size.height * 3 / 2;

            //cv::cvtColor(src, image, cv::COLOR_YUV2BGR_NV12            );
        }
    }

#if 0
    template<typename I>
    void rectangle_int(I image, Rect rect, Pen pen)
    {
        cv::Point p1(rect.x, rect.y);
        cv::Point p2(rect.right(), rect.bottom());
        cv::rectangle(to_cv(image), p1, p2, to_cv(pen.color), int(pen.thickness), pen.line_type);
    }

    void rectangle(OutImage image, Rect rect, Pen pen)
    {
        rectangle_int(image, rect, pen);
    }

    void rectangle(OutImage3C image, Rect rect, Pen pen)
    {
        rectangle_int(image, rect, pen);
    }

    template<typename I, typename T>
    void rectangle_norm(I image, Rectangle<T> rect_norm, Pen pen)
    {
        auto rect = absolutize(rect_norm, image.size());
        rectangle(image, rect, pen);
    }

    void rectangle(OutImage image, RectF rect, Pen pen)
    {
        rectangle_norm(image, rect, pen);
    }

    void rectangle(OutImage3C image, RectF rect, Pen pen)
    {
        rectangle_norm(image, rect, pen);
    }

    void rectangle(OutImage image, RectD rect, Pen pen)
    {
        rectangle_norm(image, rect, pen);
    }

    void rectangle(OutImage3C image, RectD rect, Pen pen)
    {
        rectangle_norm(image, rect, pen);
    }


    template<typename I>
    void circle_int(I image, Point center, int radius, Pen pen)
    {
        cv::circle(to_cv(image), to_cv(center), radius, to_cv(pen.color), int(pen.thickness), pen.line_type);
    }

    void circle(OutImage image, Point center, int radius, Pen pen)
    {
        circle_int(image, center, radius, pen);
    }

    void circle(OutImage3C image, Point center, int radius, Pen pen)
    {
        circle_int(image, center, radius, pen);
    }


    template<typename I>
    void circle_double(I image, PointD center, int radius, Pen pen)
    {
        auto c = absolutize(center, image.size());
        circle_int(image, c, radius, pen);
    }

    void circle(OutImage image, PointD center, int radius, Pen pen)
    {
        circle_double(image, center, radius, pen);
    }

    void circle(OutImage3C image, PointD center, int radius, Pen pen)
    {
        circle_double(image, center, radius, pen);
    }


    void ellipse(OutImage image, Rect rect, Pen pen)
    {
        cv::Size axes(rect.width / 2, rect.height / 2);
        cv::ellipse(to_cv(image), to_cv(rect.center()), axes, 0, 0, 360, to_cv(pen.color), int(pen.thickness), pen.line_type);
    }


    void ellipse(OutImage image, const RotatedRectF& box, Pen pen)
    {
        cv::ellipse(to_cv(image), to_cv(box), to_cv(pen.color), int(pen.thickness), pen.line_type);
    }


    void ellipse(OutImage3C image, const RotatedRectF& box, Pen pen)
    {
        cv::ellipse(to_cv(image), to_cv(box), to_cv(pen.color), int(pen.thickness), pen.line_type);
    }


    template<typename I>
    void line_int(I image, Point p1, Point p2, Pen pen)
    {
        cv::line(to_cv(image), to_cv(p1), to_cv(p2), to_cv(pen.color), int(pen.thickness), pen.line_type);
    }

    void line(OutImage image, Point p1, Point p2, Pen pen)
    {
        line_int(image, p1, p2, pen);
    }

    void line(OutImage3C image, Point p1, Point p2, Pen pen)
    {
        line_int(image, p1, p2, pen);
    }

    template<typename I, typename T>
    void line_norm(I image, Point2D<T> p1, Point2D<T> p2, Pen pen)
    {
        auto a = absolutize(p1, image.size());
        auto b = absolutize(p2, image.size());
        line_int(image, a, b, pen);
    }

    void line(OutImage image, PointF p1, PointF p2, Pen pen)
    {
        line_norm(image, p1, p2, pen);
    }

    void line(OutImage3C image, PointF p1, PointF p2, Pen pen)
    {
        line_norm(image, p1, p2, pen);
    }

    void line(OutImage image, PointD p1, PointD p2, Pen pen)
    {
        line_norm(image, p1, p2, pen);
    }

    void line(OutImage3C image, PointD p1, PointD p2, Pen pen)
    {
        line_norm(image, p1, p2, pen);
    }


    template<typename I>
    void polyline_int(I image, const Points& points, Pen pen, bool closed)
    {
        auto ps = to_cv<cv::Point>(points);
        cv::polylines(to_cv(image), ps, closed, to_cv(pen.color), int(pen.thickness), pen.line_type);
    }

    void polyline(OutImage image, const Points& points, Pen pen, bool closed)
    {
        polyline_int(image, points, pen, closed);
    }

    void polyline(OutImage3C image, const Points& points, Pen pen, bool closed)
    {
        polyline_int(image, points, pen, closed);
    }

    template<typename I, typename T>
    void polyline_norm(I image, const Point2Ds<T>& points_norm, Pen pen, bool closed)
    {
        auto points = absolutize(points_norm, image.size());
        polyline(image, points, pen, closed);
    }

    void polyline(OutImage image, const PointFs& points, Pen pen, bool closed)
    {
        polyline_norm(image, points, pen, closed);
    }

    void polyline(OutImage3C image, const PointFs& points, Pen pen, bool closed)
    {
        polyline_norm(image, points, pen, closed);
    }

    void polyline(OutImage image, const PointDs& points, Pen pen, bool closed)
    {
        polyline_norm(image, points, pen, closed);
    }

    void polyline(OutImage3C image, const PointDs& points, Pen pen, bool closed)
    {
        polyline_norm(image, points, pen, closed);
    }


    template<typename I>
    void cross_int(I image, Point pos, Size size, Pen pen)
    {
        int dx = size.width / 2;
        int dy = size.height / 2;

        Point p1(pos.x, pos.y - dy);
        Point p2(pos.x, pos.y + dy);
        line(image, p1, p2, pen);

        Point p3(pos.x - dx, pos.y);
        Point p4(pos.x + dx, pos.y);
        line(image, p3, p4, pen);
    }

    void cross(OutImage image, Point pos, Size size, Pen pen)
    {
        cross_int(image, pos, size, pen);
    }

    void cross(OutImage3C image, Point pos, Size size, Pen pen)
    {
        cross_int(image, pos, size, pen);
    }


    template<typename I, typename T>
    void cross_double(I image, Point2D<T> pos, Size size, Pen pen)
    {
        auto p = absolutize(pos, image.size());
        cross_int(image, p, size, pen);
    }

    void cross(OutImage image, PointF pos, Size size, Pen pen)
    {
        cross_double(image, pos, size, pen);
    }

    void cross(OutImage3C image, PointF pos, Size size, Pen pen)
    {
        cross_double(image, pos, size, pen);
    }

    void cross(OutImage image, PointD pos, Size size, Pen pen)
    {
        cross_double(image, pos, size, pen);
    }

    void cross(OutImage3C image, PointD pos, Size size, Pen pen)
    {
        cross_double(image, pos, size, pen);
    }


    void bar_chart(OutImage image, const int* data, int step)
    {
        int sum = 0;
        for (int i = 0; i < image.width() / step; ++i) {
            sum += data[i];
        }
        if (sum == 0) sum = 1;
        for (int i = 0; i < image.width() / step; ++i) {
            int v = image.height() * data[i] / sum;
            Rect rect(i * step, 0, step, v);
            rectangle(image, rect);
        }
    }


    template<typename I>
    void put_text_int(I image, InString text, Point org, Font font, Pen pen)
    {
        cv::putText(to_cv(image), text, to_cv(org), font.face, font.scale, to_cv(pen.color), int(pen.thickness), pen.line_type);
    }

    void put_text(OutImage image, InString text, Point org, Font font, Pen pen)
    {
        put_text_int(image, text, org, font, pen);
    }

    void put_text(OutImage3C image, InString text, Point org, Font font, Pen pen)
    {
        put_text_int(image, text, org, font, pen);
    }


    template<typename I, typename T>
    void put_text_double(I image, InString text, Point2D<T> org, Font font, Pen pen)
    {
        auto o = absolutize(org, image.size());
        put_text_int(image, text, o, font, pen);
    }

    void put_text(OutImage image, InString text, PointF org, Font font, Pen pen)
    {
        put_text_double(image, text, org, font, pen);
    }

    void put_text(OutImage3C image, InString text, PointF org, Font font, Pen pen)
    {
        put_text_double(image, text, org, font, pen);
    }

    void put_text(OutImage image, InString text, PointD org, Font font, Pen pen)
    {
        put_text_double(image, text, org, font, pen);
    }

    void put_text(OutImage3C image, InString text, PointD org, Font font, Pen pen)
    {
        put_text_double(image, text, org, font, pen);
    }

#endif
}
