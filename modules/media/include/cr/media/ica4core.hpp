#pragma once

#include "ica4traits.hpp"
#include <cr/image/image.hpp>
//#include "draw.hpp"
//#include "remap_param.hpp"

namespace ica {

    using cv::Mat;

    ///cv::Point_ -> cr::Point2D
    template<typename T>
    cr::Point2D<T> to_iv(const cv::Point_<T> &p) { return cr::Point2D<T>(p.x, p.y); }

    ///cv::Size_ -> cr::Size2D
    template<typename T>
    cr::Size2D<T> to_iv(const cv::Size_<T> &s) { return cr::Size2D<T>(s.width, s.height); }

    ///cv::Rect_ -> cr::Rect
    template<typename T>
    cr::Rectangle<T> to_iv(const cv::Rect_<T> &r) { return cr::Rectangle<T>(r.x, r.y, r.width, r.height); }

    ///cv::RotatedRect -> cr::RotatedRectF
    //inline cr::RotatedRectF to_iv(const cv::RotatedRect& r) { return cr::RotatedRectF(to_iv(r.center), to_iv(r.size), r.angle); }

    ///cr::Point2D -> cv::Point_
    template<typename T>
    cv::Point_<T> to_cv(const cr::Point2D<T> &p) { return cv::Point_<T>(p.x, p.y); }

    ///cr::Size2D -> cv::Size_
    template<typename T>
    cv::Size_<T> to_cv(const cr::Size2D<T> &s) { return cv::Size_<T>(s.width, s.height); }

    ///cr::Rectangle -> cv::Rect_
    template<typename T>
    cv::Rect_<T> to_cv(const cr::Rectangle<T> &r) { return cv::Rect_<T>(r.x, r.y, r.width, r.height); }

    ///cr::RotatedRectF -> cv::RotatedRect
    //inline cv::RotatedRect to_cv(const cr::RotatedRectF& r) { return cv::RotatedRect(to_cv(r.center), to_cv(r.size), r.angle); }

    ///cr::ImageChannel -> Mat
    inline Mat to_cv(cr::ImageChannel m, int _type = CV_8U) {
        auto size = to_cv(m.size());
        Mat ret;
        if (_type == CV_8U)
            ret = Mat(size, _type, m.data(), m.pitch());
        else if (_type == CV_16U) {
            size.width /= 2;
            ret = Mat(size, _type, m.data(), m.pitch());
        }
        return ret;
    }

    ///cr::Image -> Mat
    Mat to_cv(const cr::Image img);

#if 0
    ///cr::Color -> cv::Scalar
    inline cv::Scalar to_cv(cr::Color color)
    {
        return cv::Scalar(color.b, color.g, color.r, 0);
    }

    ///转换为iv类型向量
    template<typename T1, typename T2>
    vector<T1> to_iv(const vector<T2>& v1)
    {
        vector<T1> v2;
        v2.reserve(v2.size());
        for (auto& v : v1) {
            v2.push_back(to_iv(v));
        }
        return v2;
    }


    ///转换为iv类型向量
    template<typename T1, typename T2, typename  P1>
    vector<T1> to_iv(const vector<T2>& v1, const P1& p1)
    {
        vector<T1> v2;
        v2.reserve(v2.size());
        for (auto& v : v1) {
            v2.push_back(to_iv(v, p1));
        }
        return v2;
    }


    ///转换为cv类型向量
    template<typename T1, typename T2>
    vector<T1> to_cv(const vector<T2>& v1)
    {
        vector<T1> v2;
        v2.reserve(v2.size());
        for (auto& v : v1) {
            v2.push_back(to_cv(v));
        }
        return v2;
    }
#endif
}
