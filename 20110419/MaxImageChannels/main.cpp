/*
 * main.cpp
 *
 *  Created on: 2011-4-19
 *      Author: egame
 */
#include <opencv/cv.h>
#include <opencv/highgui.h>

// 处理饱和度
void saturation(IplImage *inputImage,int value){
	for(int y=0;y<inputImage->height;y++){
		// 从图像的内存开始(inputImage->imageDate) 跨幅(y*inputImage->widthStep)
		// 图像矩阵每行的内存开始 (uchar*)inputImage->imageData+(y*inputImage->widthStep)
		uchar *ptr = (uchar*)inputImage->imageData+(y*inputImage->widthStep);
		for(int x=0;x<inputImage->width;x++){
			// 3维通道图，所以为3*x.每间隔3个位有一个RGB，则+1为R +2为G +3为B.
			ptr[3*x] += value;
			ptr[3*x+1] += value;
			ptr[3*x+2] += value;
		}
	}
}
// 提取区域图像
IplImage* getsubimage(IplImage *inputImage,CvRect interest_rect){
	IplImage *sub_img = cvCreateImageHeader(cvSize(interest_rect.width,interest_rect.height),inputImage->depth,inputImage->nChannels);
	sub_img->origin = inputImage->origin;
	sub_img->widthStep = inputImage->widthStep;
	// inputImage->imageData + interest_rect.y * inputImage->widthStep：开始点下移interest_rect.y行，+ interest_rect.x * inputImage->nChannels:开始点右移动interest_rect.x列.
	sub_img->imageData = inputImage->imageData + interest_rect.y * inputImage->widthStep + interest_rect.x * inputImage->nChannels;
	return sub_img;
}

int main(int args,char *argv[]){
	IplImage *oneimage;
	cvNamedWindow("saturation",CV_WINDOW_AUTOSIZE);
	//
	assert(argv[1]);
	//
	oneimage = cvLoadImage(argv[1],CV_LOAD_IMAGE_ANYCOLOR);
	CvRect rect = cvRect(30,30,280,280);
	// 设置感兴趣区域，只对这部分。设置后之对这部分处理 需要调用OpenCV系统函数.也不是所有的OpenCV函数都会处理ROI 下面注释区域为 系统函数。调用时候需要注掉saturation(oneimage,-50);
//	cvSetImageROI(oneimage,rect);
//	cvAddS(oneimage,cvScalar(180),oneimage);
	// 提取区域图像
	IplImage *subimage =getsubimage(oneimage,rect);
	saturation(subimage,20);
	// 取消感兴趣区域
//	cvResetImageROI(oneimage);
	cvShowImage("saturation",oneimage);
	cvWaitKey(0);
	//
	cvReleaseImage(&oneimage);
	cvDestroyWindow("saturation");
	return 0;
}
