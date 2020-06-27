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
using namespace std;

int main(int argc, const char * argv[]) {
    
    string path = "/Users/wuyanqiang/Documents/opencv/TestOpenCV/resource/bg.jpg";
    
     // Load an image specified on the command line.
     //
     cv::Mat image = cv::imread(path,-1);

     // Create some windows to show the input
     // and output images in.
     //
     cv::namedWindow( "Example 2-5-in", cv::WINDOW_AUTOSIZE );
     cv::namedWindow( "Example 2-5-out", cv::WINDOW_AUTOSIZE );

     // Create a window to show our input image
     //
     cv::imshow( "Example 2-5-in", image );

     // Create an image to hold the smoothed output
     //
     cv::Mat out;

     // Do the smoothing
     // ( Note: Could use GaussianBlur(), blur(), medianBlur() or
     // bilateralFilter(). )
     //
     cv::GaussianBlur( image, out, cv::Size(5,5), 3, 3);
     cv::GaussianBlur( out, out, cv::Size(5,5), 3, 3);

     // Show the smoothed image in the output window
     //
     cv::imshow( "Example 2-5-out", out );

     // Wait for the user to hit a key, windows will self destruct
     //
     cv::waitKey( 0 );

    
    return 0;
}
