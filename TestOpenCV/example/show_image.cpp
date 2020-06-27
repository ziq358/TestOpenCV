//
//  main.cpp
//  TestOpenCV
//
//  Created by 吴炎强 on 2020/6/27.
//  Copyright © 2020 johnwu. All rights reserved.
//

#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using std::string;

int main(int argc, const char * argv[]) {
    
    string path = "/Users/wuyanqiang/Documents/opencv/TestOpenCV/resource/bg.jpg";
    Mat image = imread(path);
    namedWindow("origin");
    imshow("origin", image);
    
    Mat gray;
    cvtColor(image, gray, COLOR_RGBA2GRAY);
    namedWindow("gray");
    imshow("gray", gray);
    waitKey(0);
    
    return 0;
}
