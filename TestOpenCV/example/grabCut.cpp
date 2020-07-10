// Example 12-3. Using GrabCut for background removal

#include <iostream>
#include <opencv2/opencv.hpp>
 
using namespace std;
 
cv::Rect rect;
cv::Point2i cursor;
 
void onMouse(int event, int x, int y, int flags, void *param)
{
    cv::Mat* src = (cv::Mat*)param;
    cv::Mat roiImg;
    src->copyTo(roiImg);
    switch (event)
    {
    case CV_EVENT_LBUTTONDOWN:
        cursor = cv::Point2i(x, y);
        rect = cv::Rect(x, y, 1, 1);
        std::cout << "CV_EVENT_LBUTTONDOWN==" << rect << std::endl;
        break;
    
    case CV_EVENT_LBUTTONUP:
        rect.width = abs(x - rect.x);
        rect.height = abs(y - rect.y);
        std::cout << "CV_EVENT_LBUTTONUP==" << rect << std::endl;
        cv::rectangle(roiImg, rect, cv::Scalar(0, 0, 255), 2);
        cv::imshow("input", roiImg);
        break;
 
    case CV_EVENT_MOUSEMOVE:
        if (flags & CV_EVENT_FLAG_LBUTTON) {
            rect.x = MIN(x, cursor.x);
            rect.y = MIN(y, cursor.y);
            rect.width = abs(cursor.x - x);
            rect.height = abs(cursor.y - y);
        }
        break;
    }
}
 
int main()
{
    string path = "/Users/wuyanqiang/Documents/opencv/TestOpenCV/resource/ren.jpg";
    cv::Mat img = cv::imread(path);
 
    cv::namedWindow("SrcImage");
    cv::setMouseCallback("SrcImage", onMouse, &img);
    cv::imshow("SrcImage", img);
    cv::waitKey();
 
 
    cv::Mat result;
    cv::Mat bgModel, fgModel;
    cv::grabCut(img, result, rect, bgModel, fgModel, 5, cv::GC_INIT_WITH_RECT);
    cv::compare(result, cv::GC_PR_FGD, result, cv::CMP_EQ);
 
    cv::Mat foreground(img.size(), CV_8UC3, cv::Scalar(255, 255, 255));
    img.copyTo(foreground, result);
 
    cv::namedWindow("Foreground");
    cv::imshow("Foreground", foreground);
    cv::waitKey();
    return 0;
}

