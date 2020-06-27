//
//  showVideo.cpp
//  TestOpenCV
//
//  Created by johnwu on 2019/11/14.
//  Copyright © 2019年 johnwu. All rights reserved.
//

#include "showVideo.hpp"

using std::string;

void testVideo(){
    string path = "/Users/wuyanqiang/Documents/opencv/TestOpenCV/resource/bg.jpg";
    cv::Mat image = cv::imread(path);
    cv::namedWindow("origin");
    cv::imshow("origin", image);
    
    cv::Mat gray;
    cvtColor(image, gray, cv::COLOR_RGBA2GRAY);
    cv::namedWindow("gray");
    cv::imshow("gray", gray);
    cv::waitKey(0);
}
