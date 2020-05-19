#include <iostream>  
#include <opencv2\core\core.hpp>  
#include <opencv2\highgui\highgui.hpp>  
#include <opencv2\imgproc\imgproc.hpp>  
#include<cmath>
#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
#include <vector>
#include "cv.h"
using namespace cv;
using namespace std;

//课前准备

int main() {
	VideoCapture video("1.avi");
	Mat frame, mask, thresholdImage, output;
	video >> frame;
	BackgroundSubtractorMOG bgSubtractor(20, 10, 0.5, false);
	while (true) {
		video >> frame;
		++frameNum;
		bgSubtractor(frame, mask, 0.001);
		imshow("mask", mask);
		waitKey(10);
	}
	return 0;

、