/*
 * main.cpp
 *
 *  Created on: 2011-4-7
 *      Author: egame
 */
#include <opencv/cv.h>
#include <opencv/highgui.h>

int main(int args,char *argv[]){
	printf("%s",argv[0]);
	// load an image
	IplImage *loadImage = cvLoadImage(argv[1],CV_LOAD_IMAGE_ANYCOLOR);
	// 获得图像大小
	CvSize size;
	size.width = loadImage->width;
	size.height = loadImage->height;
	// 创建一个大小为size的空图像
	IplImage *newImage = cvCreateImage(size,loadImage->depth,3);
	// 把加载的图像复制写入新图像中
	cvCopy(loadImage,newImage,NULL);
	// 创建图像
	cvNamedWindow("new Image",CV_WINDOW_AUTOSIZE);
	// 展示图像
	cvShowImage("new Image",newImage);
	// 保存图像
	char *newImageStr = strcpy(argv[0],"newImage.jpg");
	cvSaveImage(newImageStr,newImage);
	cvWaitKey(0);
	return 0;
}
