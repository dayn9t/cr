#include <cr/media/img_io.hpp>
#include <cr/media/ica4core.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>

namespace cr {

    void save(const Image src, string filename) {
        cv::Mat mat = ica::to_cv(src);
        cv::imwrite(filename, mat);
    }
}