#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main()
{
    vector<Mat> channels;
    Mat img = imread("jpn.png");
    Mat hsv;
    cvtColor(img,hsv,CV_BGR2HSV);
    split(hsv,channels);
    Mat hue_orig = channels.at(0).clone();
    Mat low, high;
    Mat result;
    threshold(hue_orig,low,60,255,CV_THRESH_BINARY);
    threshold(hue_orig,high,180,255,CV_THRESH_BINARY_INV);
    result = low & high;
    imshow("Original", img);
    imshow("Thresholded", result);
    Mat edge;
    Canny(img,edge,100,200);
    imshow("Edge", edge);
    waitKey(0);
    return 0;
}

