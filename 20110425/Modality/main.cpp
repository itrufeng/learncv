/*
 * main.cpp
 *
 *  Created on: 2011-4-25
 *      Author: egame
 */
#include <opencv/cv.h>
#include <opencv/highgui.h>

int main(int argc, char **argv) {
	// intit
	IplImage *srcImage;
	cvNamedWindow("srcImage",CV_WINDOW_AUTOSIZE);
	IplImage *erodeImage;
	cvNamedWindow("erodeImage",CV_WINDOW_AUTOSIZE);
	IplImage *dilateImage;
	cvNamedWindow("dilateImage",CV_WINDOW_AUTOSIZE);
	IplImage *gaojiImage;
	cvNamedWindow("gaojiImage",CV_WINDOW_AUTOSIZE);
	// vaildate
	assert(argv[1]);
	// load image
	srcImage = cvLoadImage(argv[1],CV_LOAD_IMAGE_ANYCOLOR);
	cvShowImage("srcImage",srcImage);
	// 自定义核
	IplConvKernel *k = cvCreateStructuringElementEx(9,9,1,1,CV_SHAPE_ELLIPSE,NULL);
	// 腐蚀
	erodeImage = cvCreateImage(cvGetSize(srcImage),srcImage->depth,srcImage->nChannels);
	cvErode(srcImage,erodeImage,k,1);
	cvShowImage("erodeImage",erodeImage);
	// 膨胀
	dilateImage = cvCreateImage(cvGetSize(srcImage),srcImage->depth,srcImage->nChannels);
	cvDilate(srcImage,dilateImage,k,1);
	cvShowImage("dilateImage",dilateImage);
	// 高级形态 更通用
	gaojiImage = cvCreateImage(cvGetSize(srcImage),srcImage->depth,srcImage->nChannels);
	cvMorphologyEx(srcImage,gaojiImage,NULL,k,CV_MOP_OPEN,1);
	cvShowImage("gaojiImage",gaojiImage);
	// release
	cvWaitKey(0);
	cvDestroyWindow("gaojiImage");
	cvReleaseImage(&gaojiImage);
	cvDestroyWindow("dilateImage");
	cvReleaseImage(&dilateImage);
	cvDestroyWindow("erodeImage");
	cvReleaseImage(&erodeImage);
	cvDestroyWindow("srcImage");
	cvReleaseImage(&srcImage);
	return 0;
}
