#pragma once

#include <cr/image/image.hpp>
#include <cr/image/color.hpp>

namespace cr {


    /// 画笔
    struct Pen
    {
        Color color = Color::white;
        double thickness = 1;
        int	line_type = 0;
    };

    /// 字体
    struct Font
    {
        int face = 0;
        double scale = 1;
    };

    /// 画矩形
    void rectangle(Image image, Rect rect, Pen pen = Pen());
#if 0
    void rectangle(OutImage3C image, Rect rect, Pen pen = Pen());
    void rectangle(OutImage image, RectF rect, Pen pen = Pen());
    void rectangle(OutImage3C image, RectF rect, Pen pen = Pen());
    void rectangle(OutImage image, RectD rect, Pen pen = Pen());
    void rectangle(OutImage3C image, RectD rect, Pen pen = Pen());


    /// 画圆
    void circle(OutImage image, Point center, int radius, Pen pen = Pen());
    void circle(OutImage3C image, Point center, int radius, Pen pen = Pen());
    void circle(OutImage image, PointD center, int radius, Pen pen = Pen());
    void circle(OutImage3C image, PointD center, int radius, Pen pen = Pen());

    /// 画椭圆 - 矩形内接椭圆
    void ellipse(OutImage image, Rect rect, Pen pen = Pen());
    /// 画椭圆 - 任意角度
    void ellipse(OutImage image, const RotatedRectF& box, Pen pen = Pen());
    void ellipse(OutImage3C image, const RotatedRectF& box, Pen pen = Pen());

    /// 画线
    void line(OutImage image, Point p1, Point p2, Pen pen = Pen());
    void line(OutImage3C image, Point p1, Point p2, Pen pen = Pen());
    void line(OutImage image, PointF p1, PointD p2, Pen pen = Pen());
    void line(OutImage3C image, PointF p1, PointD p2, Pen pen = Pen());
    void line(OutImage image, PointD p1, PointD p2, Pen pen = Pen());
    void line(OutImage3C image, PointD p1, PointD p2, Pen pen = Pen());

    /// 画折线
    void polyline(OutImage image, const Points& points, Pen pen = Pen(), bool closed = false);
    void polyline(OutImage3C image, const Points& points, Pen pen = Pen(), bool closed = false);
    void polyline(OutImage image, const PointFs& pointds, Pen pen = Pen(), bool closed = false);
    void polyline(OutImage3C image, const PointFs& points, Pen pen = Pen(), bool closed = false);
    void polyline(OutImage image, const PointDs& pointds, Pen pen = Pen(), bool closed = false);
    void polyline(OutImage3C image, const PointDs& points, Pen pen = Pen(), bool closed = false);

    /// 画十字
    void cross(OutImage image, Point pos, Size size, Pen pen = Pen());
    void cross(OutImage3C image, Point pos, Size size, Pen pen = Pen());
    void cross(OutImage image, PointF pos, Size size, Pen pen = Pen());
    void cross(OutImage3C image, PointF pos, Size size, Pen pen = Pen());
    void cross(OutImage image, PointD pos, Size size, Pen pen = Pen());
    void cross(OutImage3C image, PointD pos, Size size, Pen pen = Pen());

    /// 画条形图
    void bar_chart(OutImage image, const int* data, int step);

    /// 显示文字
    void put_text(OutImage image, InString text, Point org, Font font = Font(), Pen pen = Pen());
    void put_text(OutImage3C image, InString text, Point org, Font font = Font(), Pen pen = Pen());
    void put_text(OutImage image, InString text, PointF org, Font font = Font(), Pen pen = Pen());
    void put_text(OutImage3C image, InString text, PointF org, Font font = Font(), Pen pen = Pen());
    void put_text(OutImage image, InString text, PointD org, Font font = Font(), Pen pen = Pen());
    void put_text(OutImage3C image, InString text, PointD org, Font font = Font(), Pen pen = Pen());
#endif
}