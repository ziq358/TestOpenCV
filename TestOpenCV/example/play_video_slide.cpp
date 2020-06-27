//
//  play_video_slide.cpp
//  ex_play_video_slide
//
//  Created by 吴炎强 on 2020/6/27.
//  Copyright © 2020 johnwu. All rights reserved.
//

#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int g_slider_position = 0;
int g_run = 1, g_dontset = 0; //start out in single step mode
cv::VideoCapture g_cap;

void onTrackbarSlide( int pos, void *) {

  g_cap.set( CV_CAP_PROP_POS_FRAMES, pos );
cout << "g_dontset11 = " << g_dontset << endl;
    cout << "run11 = " << g_run << endl;
  if( !g_dontset ) g_run = 1;

  g_dontset = 0;
cout << "run22 = " << g_run << endl;
    cout << "g_dontset22 = " << g_dontset << endl;
}

    

int main( int argc, char** argv ) {
    

  cv::namedWindow( "Example 2-4", cv::WINDOW_AUTOSIZE );
string path = "/Users/wuyanqiang/Documents/opencv/TestOpenCV/resource/test.avi";
  g_cap.open( string(path) );

  int frames = (int) g_cap.get( CV_CAP_PROP_FRAME_COUNT  );
  int tmpw   = (int) g_cap.get( CV_CAP_PROP_FRAME_WIDTH  );
  int tmph   = (int) g_cap.get( CV_CAP_PROP_FRAME_HEIGHT );

  cout << "Video has " << frames << " frames of dimensions("
       << tmpw << ", " << tmph << ")." << endl;

  cv::createTrackbar(
    "Position",
    "Example 2-4",
    &g_slider_position,
    frames,
    onTrackbarSlide
  );
  cv::Mat frame;

  for(;;) {

    if( g_run != 0 ) {
      g_cap >> frame;
      if(frame.empty()) break;
      int current_pos = (int)g_cap.get( CV_CAP_PROP_POS_FRAMES );
      g_dontset = 1;
        cout << "for run = " << g_run << endl;
      cv::setTrackbarPos("Position", "Example 2-4", current_pos);
      cv::imshow( "Example 2-4", frame );
      g_run-=1;
    }

    char c = (char) cv::waitKey(10);

    if( c == 's' ) { // single step
      g_run = 1;
      cout << "Single step, run = " << g_run << endl;
    }

    if( c == 'r' ) { // run mode
      g_run = -1;
      cout << "Run mode, run = " << g_run <<endl;
    }

    if( c == 27 ) break;
  }

  return(0);

}
