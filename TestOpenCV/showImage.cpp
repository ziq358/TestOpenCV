//
//  showImage.cpp
//  TestOpenCV
//
//  Created by johnwu on 2019/11/14.
//  Copyright © 2019年 johnwu. All rights reserved.
//

#include "showImage.hpp"
using namespace cv;
using std::string;

void testImage(){
    string path = "./resource/bg.jpg";
    Mat image = imread(path);
    namedWindow("origin");
    imshow("origin", image);
    
    Mat gray;
    cvtColor(image, gray, COLOR_RGBA2GRAY);
    namedWindow("gray");
    imshow("gray", gray);
    waitKey(0);
}
