//
//  houghCircles.cpp
//  ex_HoughCircles
//
//  Created by 吴炎强 on 2020/7/10.
//  Copyright © 2020 johnwu. All rights reserved.
//

#include <math.h>

#include <iostream>
#include <vector>

#include <opencv2/opencv.hpp>

using std::cout;
using std::endl;
using std::vector;
using namespace std;

int main(int argc, char** argv) {
string path = "/Users/wuyanqiang/Documents/opencv/TestOpenCV/resource/ren.jpg";
    cv::Mat src, image;

    src = cv::imread(path, 1);

    cv::cvtColor(src, image, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(image, image, cv::Size(5, 5), 0, 0);

    vector<cv::Vec3f> circles;
    cv::HoughCircles(image, circles, cv::HOUGH_GRADIENT, 2, image.cols/4);

    for (size_t i = 0; i < circles.size(); ++i) {
        cv::circle(src,
            cv::Point(cvRound(circles[i][0]), cvRound(circles[i][1])),
            cvRound(circles[i][2]),
            cv::Scalar(0, 0, 255),
            2,
            cv::LINE_AA);
    }

    cv::imshow("Hough Circles", src);
    cv::waitKey(0);

    return 0;
}
