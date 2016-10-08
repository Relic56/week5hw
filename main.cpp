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
    Mat edge;
    Canny(img,edge,100,200);
    vector<vector<Point> > contours;
    findContours(edge,contours,CV_RETR_LIST,CV_CHAIN_APPROX_SIMPLE, Point(0,0) );
    Mat contoured = Mat::zeros(img.rows, img.cols, CV_8UC3);
    Scalar color = Scalar(255,255,255);
    drawContours(contoured, contours, -1, color);
    imshow("Contours", contoured);
    imshow("Thresholded", result);
    waitKey(0);
    return 0;
}

