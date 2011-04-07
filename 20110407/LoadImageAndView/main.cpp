/*
 * main.cpp
 *
 *  Created on: 2011-4-7
 *      Author: egame
 */
#include <opencv/cv.h>
#include <opencv/highgui.h>

int main(int args,char *argv[]){
	printf("图片路径:%s",argv[1]);
	// CV_LOAD_IMAGE_GRAYSCALE 是以灰度图来加载
	IplImage *image = cvLoadImage(argv[1],CV_LOAD_IMAGE_GRAYSCALE);
	// CV_WINDOW_AUTOSIZE 动态的以内容来改变窗口大小
	cvNamedWindow("load an image and view It",CV_WINDOW_AUTOSIZE);
	cvShowImage("load an image and view It",image);
	// 等待下一个指令
	cvWaitKey(0);
	return 0;
}
