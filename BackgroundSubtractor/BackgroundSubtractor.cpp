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

//练习1
using namespace std;
using namespace cv;

int main()
{
	VideoCapture capVideo(0);
	if (!capVideo.isOpened()) {//打开失败
		std::cout << "can not open" << std::endl;
		return -1;
	}

	int cnt = 0;//计数器
	Mat frame;
	Mat bgMat;
	Mat subMat;
	Mat bny_subMat;
	Mat bgModelMat;

	while(1){
		capVideo >> frame;
		cvtColor(frame, frame, COLOR_BGR2GRAY);
		if (cnt == 0) {//获得背景图像
			frame.copyTo(bgMat);
		}
		else {//背景差分
			absdiff(frame, bgMat, subMat);//背景图像和当前图像相减		
			threshold(subMat, bny_subMat, 20, 255, CV_THRESH_BINARY);//二值化

			imshow("b_subMat", bny_subMat);
			imshow("frame", frame);
			waitKey(30);
		}
		cnt++;
	}
	return 0;
}
