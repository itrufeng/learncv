/*
 * main.cpp
 *
 *  Created on: 2011-4-25
 *      Author: egame
 */
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <iostream>

int main(int argc,char **argv) {
	// init
	IplImage *srcImage;
	IplImage *jiandanImage;
	IplImage *jiandanwuImage;
	IplImage *zhongzhiImage;
	IplImage *gaosiImage;
	IplImage *shuangbianImage;
	cvNamedWindow("srcImage",CV_WINDOW_AUTOSIZE);
	cvNamedWindow("jiandan",CV_WINDOW_AUTOSIZE);
	cvNamedWindow("jiandanwuImage",CV_WINDOW_AUTOSIZE);
	cvNamedWindow("zhongzhiImage",CV_WINDOW_AUTOSIZE);
	cvNamedWindow("gaosiImage",CV_WINDOW_AUTOSIZE);
	cvNamedWindow("shuangbianImage",CV_WINDOW_AUTOSIZE);
	// validate
	assert(argv[1]);
	srcImage = cvLoadImage(argv[1],CV_LOAD_IMAGE_ANYCOLOR);
		cvShowImage("srcImage",srcImage);
	// 简单模糊
	jiandanImage = cvCreateImage(cvGetSize(srcImage),srcImage->depth,srcImage->nChannels);
	cvSmooth(srcImage,jiandanImage,CV_BLUR,10,10);
	cvShowImage("jiandan",jiandanImage);
	// 简单无缩放的模糊
	jiandanwuImage = cvCreateImage(cvGetSize(srcImage),srcImage->depth,srcImage->nChannels);
	cvSmooth(srcImage,jiandanwuImage,CV_BLUR_NO_SCALE,3,1);
	cvShowImage("jiandanwuImage",jiandanwuImage);
	// 中值模糊
	zhongzhiImage = cvCreateImage(cvGetSize(srcImage),srcImage->depth,srcImage->nChannels);
	cvSmooth(srcImage,zhongzhiImage,CV_MEDIAN,9);
	cvShowImage("zhongzhiImage",zhongzhiImage);
	// 高斯模糊
	gaosiImage = cvCreateImage(cvGetSize(srcImage),srcImage->depth,srcImage->nChannels);
	cvSmooth(srcImage,gaosiImage,CV_GAUSSIAN,3,3,50);
	cvShowImage("gaosiImage",gaosiImage);
	// 双边滤波
	shuangbianImage = cvCreateImage(cvGetSize(srcImage),srcImage->depth,srcImage->nChannels);
	cvSmooth(srcImage,shuangbianImage,CV_BILATERAL,50,1,200,200);
	cvShowImage("shuangbianImage",shuangbianImage);
	// relase
	cvWaitKey(0);
	cvDestroyWindow("shuangbianImage");
	cvReleaseImage(&shuangbianImage);
	cvDestroyWindow("gaosiImage");
	cvReleaseImage(&gaosiImage);
	cvDestroyWindow("zhongzhiImage");
	cvReleaseImage(&zhongzhiImage);
	cvReleaseImage(&jiandanwuImage);
	cvDestroyWindow("jiandanwuImage");
	cvReleaseImage(&jiandanImage);
	cvDestroyWindow("jiandan");
	cvDestroyWindow("srcImage");
	cvReleaseImage(&srcImage);
	return 0;
}
