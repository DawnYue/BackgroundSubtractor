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

int bgSub_demo()
{

	//----------------------读取视频文件--------------------------
	//VideoCapture capVideo("E:\\1\\2.MP4");
	VideoCapture capVideo(0);

	//如果视频打开失败
	if (!capVideo.isOpened()) {
		std::cout << "Unable to open video!" << std::endl;
		return -1;
	}

	//计数器
	int cnt = 0;
	Mat frame;
	Mat bgMat;
	Mat subMat;
	Mat bny_subMat;
	Mat bgModelMat;

	while (1) {
		capVideo >> frame;
		cvtColor(frame, frame, COLOR_BGR2GRAY);
		if (cnt == 0) {
			//第一帧，获得背景图像
			frame.copyTo(bgMat);
		}
		else {
			//第二帧开始背景差分
			//背景图像和当前图像相减
			absdiff(frame, bgMat, subMat);
			//差分结果二值化
			threshold(subMat, bny_subMat, 20, 255, CV_THRESH_BINARY);

			imshow("b_subMat", bny_subMat);
			imshow("frame", frame);
			waitKey(30);
		}
		cnt++;

	}
	return 0;
}

int main()
{
	//开始计时
	double start = static_cast<double>(cvGetTickCount());

	bgSub_demo();

	//结束计时
	double time = ((double)cvGetTickCount() - start) / cvGetTickFrequency();
	//显示时间
	cout << "processing time:" << time / 1000 << "ms" << endl;
	//等待键盘响应，按任意键结束程序
	system("pause");
	return 0;
}