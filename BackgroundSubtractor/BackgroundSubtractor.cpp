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

//打开摄像头，手动选取视频中的一个像素，并描画在时间方向上的灰度分布
int verifyGaussian()
{





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