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
    string path = "/Users/wuyanqiang/Documents/opencv/TestOpenCV/resource/BlueCup.jpg";
    
    
    cv::Mat img1,img2;

    cv::namedWindow( "Example 2-6-in", cv::WINDOW_AUTOSIZE );
    cv::namedWindow( "Example 2-6-out", cv::WINDOW_AUTOSIZE );

    img1 = cv::imread( path);

    cv::imshow( "Example 2-6-in", img1 );
    cv::pyrDown( img1, img2);

    cv::imshow( "Example 2-6-out", img2 );
    cv::waitKey(0);
}
