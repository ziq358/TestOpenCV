//
//  threshold_weighted.cpp
//  ex_threshold_weighted
//
//  Created by 吴炎强 on 2020/7/9.
//  Copyright © 2020 johnwu. All rights reserved.
//

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

void sum_rgb( const cv::Mat& src, cv::Mat& dst ) {

    // Split image onto the color planes.
    //
    vector< cv::Mat> planes;
    cv::split(src, planes);
    cv::Mat b = planes[0], g = planes[1], r = planes[2], s;

    // Add equally weighted rgb values.
    //
    cv::addWeighted( r, 1./3., g, 1./3., 0.0, s );
    cv::addWeighted( s, 1., b, 1./3., 0.0, s );

    // Truncate values above 100.
    //
    cv::threshold( s, dst, 100, 100, cv::THRESH_TRUNC );
}

int main(int argc, char** argv) {
    string path = "/Users/wuyanqiang/Documents/opencv/TestOpenCV/resource/ren.jpg";
    cv::Mat src = cv::imread( path ), dst;
    sum_rgb( src, dst);

    // Create a named window with the name of the file and
    // show the image in the window
    //
    cv::imshow( argv[1], dst );

    // Idle until the user hits any key.
    //
    cv::waitKey(0);
    return 0;
}
