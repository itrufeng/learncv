/*
 * main.cpp
 *
 *  Created on: 2011-4-7
 *      Author: egame
 */
#include <opencv/cv.h>
#include <opencv/highgui.h>
int main(int args,char *argv[]){
	// 视频结构
	CvCapture *capture = NULL;
	// 获得摄像头数据
	// CV_CAP_ANY 自动
	capture = cvCreateCameraCapture(CV_CAP_ANY);
	if (!capture) {
		exit(0);
	}
	cvNamedWindow("camera",CV_WINDOW_AUTOSIZE);
	// 图片结构
	IplImage *image = NULL;
	while(image = cvQueryFrame(capture)){
		// 反色处理
		cvNot(image,image);
		// 现实图像
		cvShowImage("camera",image);
		// 监听键盘输入，如果有输入则跳出while
		if( cvWaitKey(2) >= 0 )
			break;
	}
	// 释放视频
	cvReleaseCapture(&capture);
	return 0;
}
