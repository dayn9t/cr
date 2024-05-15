#include <cr/media/ica4core.hpp>
#include <opencv2/imgproc.hpp>

namespace ica {

    // to BGR
    Mat to_cv(const cr::Image img) {
        Mat dst;
        if (img.format() == CR_CF_BGR_P || img.format() == CR_CF_RGB_P) {
            std::vector<Mat> mats;
            for (auto c: img.channels()) {
                if (img.format() == CR_CF_BGR_P) {
                    mats.push_back(to_cv(c));
                } else {
                    mats.insert(mats.begin(), to_cv(c));
                }
            }
            cv::merge(mats, dst);
        } else if (img.format() == CR_CF_NV12) {
            auto size = img.size();
            size.height = size.height * 3 / 2;
            auto pitch = (size_t) img.channels()[0].pitch();
             Mat src(to_cv(size), CV_8U, (void *) img.data(), pitch);

            cv::cvtColor(src, dst, cv::COLOR_YUV2BGR_NV12);
        }
        return dst;
    }
}
