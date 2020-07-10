//
//  warpPerspective.cpp
//  ex_warpPerspective
//
//  Created by 吴炎强 on 2020/7/9.
//  Copyright © 2020 johnwu. All rights reserved.
//

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
string path = "/Users/wuyanqiang/Documents/opencv/TestOpenCV/resource/ren.jpg";

  cv::Mat src = cv::imread(path,1);

  cv::Point2f srcQuad[] = {
    cv::Point2f(0, 0),                   // src Top left
    cv::Point2f(src.cols-1, 0),          // src Top right
    cv::Point2f(src.cols-1, src.rows-1), // src Bottom right
    cv::Point2f(0, src.rows-1)           // src Bottom left
  };

  cv::Point2f dstQuad[] = {
    cv::Point2f(src.cols*0.05f, src.rows*0.33f),
    cv::Point2f(src.cols*0.9f, src.rows*0.25f),
    cv::Point2f(src.cols*0.8f, src.rows*0.9f),
    cv::Point2f(src.cols*0.2f, src.rows*0.7f)
  };

  // COMPUTE PERSPECTIVE MATRIX
  //
  cv::Mat warp_mat = cv::getPerspectiveTransform(srcQuad, dstQuad);
  cv::Mat dst;
  cv::warpPerspective(src, dst, warp_mat, src.size(), cv::INTER_LINEAR,
                      cv::BORDER_CONSTANT, cv::Scalar());

  for( int i = 0; i < 4; i++ )
    cv::circle(dst, dstQuad[i], 5, cv::Scalar(255, 0, 255), -1, cv::LINE_AA);

  cv::imshow("Perspective Transform Test", dst);
  cv::waitKey();
  return 0;
}
