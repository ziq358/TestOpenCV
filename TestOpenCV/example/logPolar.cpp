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
    
    string inputPath = "/Users/wuyanqiang/Documents/opencv/TestOpenCV/resource/rainbow.jpg";
    string outputPath = "/Users/wuyanqiang/Downloads/logPolar.jpg";
    
    cv::namedWindow( "Example 2-11", cv::WINDOW_AUTOSIZE );
    cv::namedWindow( "Log_Polar", cv::WINDOW_AUTOSIZE );

    // ( Note: could capture from a camera by giving a camera id as an int.)
    //

    cv::VideoCapture capture( inputPath);
    double fps = capture.get( CV_CAP_PROP_FPS );
    cv::Size size(
      (int)capture.get( CV_CAP_PROP_FRAME_WIDTH ),
      (int)capture.get( CV_CAP_PROP_FRAME_HEIGHT )
    );

    cv::VideoWriter writer;
    writer.open( outputPath, CV_FOURCC('M','J','P','G'), fps, size );

    cv::Mat logpolar_frame, bgr_frame;

    for(;;) {

      capture >> bgr_frame;
      if( bgr_frame.empty() ) break; // end if done

      cv::imshow( "Example 2-11", bgr_frame );

      cv::logPolar(
        bgr_frame, // Input color frame
        logpolar_frame, // Output log-polar frame
        cv::Point2f( // Centerpoint for log-polar transformation
          bgr_frame.cols/2, // x
          bgr_frame.rows/2 // y
        ),
        40, // Magnitude (scale parameter)
        CV_WARP_FILL_OUTLIERS // Fill outliers with 'zero'
      );

      cv::imshow( "Log_Polar", logpolar_frame );

      writer << logpolar_frame;

      char c = cv::waitKey(10);

      if( c == 27 ) break; // allow the user to break out

    }
    
    cv::waitKey(0);
    writer.release();
    capture.release();

    return 0;
}
