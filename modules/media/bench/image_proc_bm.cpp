#include <iostream>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;
//using namespace cr;

int main(int argc, const char* argv[])
{
    cv::Size size(6, 6);
    cv::Rect rect(1, 1, 4, 4);
    Scalar color(1, 2);

    Mat im1(size, CV_8UC2);
    cout << "im1:\n" << im1 << endl;

    cv::rectangle(im1, rect, color);

    cout << "im1:\n" << im1 << endl;

    cout << "CV_8U:\n" << CV_8U << endl;
    cout << "CV_8UC1:\n" << CV_8UC1 << endl;
    return 0;
}