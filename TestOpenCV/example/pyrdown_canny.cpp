//
//  pyrdown.cpp
//  ex_pyrdown
//
//  Created by 吴炎强 on 2020/6/27.
//  Copyright © 2020 johnwu. All rights reserved.
//

#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, const char * argv[]) {
    string path = "/Users/wuyanqiang/Documents/opencv/TestOpenCV/resource/testroom.jpg";
    
    
    cv::Mat img_rgb, img_gry, img_cny, img_pyr, img_pyr2;

    cv::namedWindow( "Example Gray", cv::WINDOW_AUTOSIZE );
    cv::namedWindow( "Example Canny", cv::WINDOW_AUTOSIZE );

    img_rgb = cv::imread( path );

    cv::cvtColor( img_rgb, img_gry, cv::COLOR_BGR2GRAY);

    cv::pyrDown( img_gry, img_pyr );
    cv::pyrDown( img_pyr, img_pyr2 );

    cv::Canny( img_pyr2, img_cny, 10, 100, 3, true );
    
    cv::imshow( "Example Gray", img_gry );

    cv::imshow( "Example Canny", img_cny );

    cv::waitKey(0);
}
