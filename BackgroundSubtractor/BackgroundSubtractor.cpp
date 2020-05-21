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

//课前准备（老师）
//https://github.com/lizhu1126/dip-class-demos/blob/feature12.bgSub/dip-class-demos/funtions.cpp
using namespace std;
using namespace cv;
//观察的位置
cv::Point vP;

//鼠标响应函数
void on_mouse(int EVENT, int x, int y, int flags, void* userdata)
{

	Mat hh;
	hh = *(Mat*)userdata;
	switch (EVENT)
	{
	case EVENT_LBUTTONDOWN:
	{
		vP.x = x;
		vP.y = y;
		drawMarker(hh, vP, Scalar(255, 255, 255));
		//circle(hh, vP, 4, cvScalar(255, 255, 255), -1);
		imshow("mouseCallback", hh);
		return;
	}
	break;
	}

}

//绘制直方图
int drawHist(cv::Mat & histMat, float * srcHist, int bin_width, int bin_heght)
{
	histMat.create(bin_heght, 256 * bin_width, CV_8UC3);

	histMat = Scalar(255, 255, 255);

	float maxVal = *std::max_element(srcHist, srcHist + 256);

	for (int i = 0; i < 256; i++) {
		Rect binRect;
		binRect.x = i * bin_width;
		float height_i = (float)bin_heght*srcHist[i] / maxVal;
		binRect.height = (int)height_i;
		binRect.y = bin_heght - binRect.height;
		binRect.width = bin_width;
		rectangle(histMat, binRect, CV_RGB(255, 0, 0), -1);
	}

	return 0;
}
//打开摄像头，手动选取视频中的一个像素，并描画在时间方向上的灰度分布
int verifyGaussian()
{
	//----------------------读取视频文件--------------------------
	VideoCapture capVideo("E:\\1\\2.MP4");

	//如果视频打开失败
	if (!capVideo.isOpened()) {
		std::cout << "Unable to open video!" << std::endl;
		return -1;
	}

	int cnt = 0;
	int bin_width = 3;
	int bin_heght = 50;
	float histgram[256] = { 0 };

	cv::Mat histMat;

	while (1) {

		Mat frame;
		Mat grayMat;
		capVideo >> frame;

		if (frame.empty()) {
			std::cout << "Unable to read frame!" << std::endl;
			return -1;
		}

		//第一帧选取像素
		if (cnt == 0) {
			Mat selectMat;
			frame.copyTo(selectMat);
			namedWindow("mouseCallback");
			imshow("mouseCallback", selectMat);
			setMouseCallback("mouseCallback", on_mouse, &selectMat);
			waitKey(0);
			destroyAllWindows();
		}

		cvtColor(frame, grayMat, COLOR_BGR2GRAY);

		//获得像素灰度值
		int index = grayMat.at<uchar>(vP.y, vP.x);
		//直方图相应的bin加1
		histgram[index]++;

		//绘制直方图
		drawHist(histMat, histgram, bin_width, bin_heght);

		drawMarker(frame, vP, Scalar(255, 255, 255));
		imshow("frame", frame);
		imshow("histMat", histMat);

		waitKey(30);
		cnt++;
	}

	return 0;
}
int bgSub_demo()
{

	//----------------------读取视频文件--------------------------
	VideoCapture capVideo("E:\\1\\2.MP4");

	//如果视频打开失败
	if (!capVideo.isOpened()) {
		std::cout << "Unable to open video!" << std::endl;
		return -1;
	}

	//使用几张图片进行背景建模
	int modelNum = 20;

	int cnt = 0;

	Mat bgModelMat;

	while (1) {



	}



	return 0;
}



int main()
{
	//开始计时
	double start = static_cast<double>(cvGetTickCount());

	//该demo验证并演示，视频中的像素灰度值变换是否呈高斯分布
	verifyGaussian();

	//结束计时
	double time = ((double)cvGetTickCount() - start) / cvGetTickFrequency();
	//显示时间
	cout << "processing time:" << time / 1000 << "ms" << endl;

	//等待键盘响应，按任意键结束程序
	system("pause");
	return 0;
}