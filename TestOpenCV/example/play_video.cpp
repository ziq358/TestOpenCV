//
//  play_video.cpp
//  ex_play_video
//
//  Created by 吴炎强 on 2020/6/27.
//  Copyright © 2020 johnwu. All rights reserved.
//

#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using std::string;

int main(int argc, const char * argv[]) {
    
    string path = "/Users/wuyanqiang/Documents/opencv/TestOpenCV/resource/test.avi";
    
    cv::namedWindow( "Example 2-3", cv::WINDOW_AUTOSIZE );

   
    cv::VideoCapture cap;

      cap.open( string(path) );
      std::cout <<"Opened file: " <<path <<std::endl;

      cv::Mat frame;

      for(;;) {

        cap >> frame;

        if( frame.empty() ) break; // Ran out of film

        cv::imshow( "Example 2-3", frame );

        if( (char)cv::waitKey(33) >= 0 ) break;
      }

    
    return 0;
}
