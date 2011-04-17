/*
 * main.cpp
 *
 *  Created on: 2011-4-16
 *      Author: itrufeng
 */
#include <opencv/cv.h>
#include <opencv/highgui.h>

IplImage* scaleImage(IplImage *inputImage,float scale){
	IplImage *outputImage = cvCreateImage(cvSize(inputImage->width*scale,inputImage->height*scale),inputImage->depth,3);
	cvPyrDown(inputImage,outputImage,CV_GAUSSIAN_5x5);
	return outputImage;
}
int main(int args,char *argv[]){
	IplImage *inputImage;
	IplImage *outputImage;
	cvNamedWindow("inputImage",CV_WINDOW_AUTOSIZE);
	cvMoveWindow("inputImage",100,100);
	cvNamedWindow("outputImage",CV_WINDOW_AUTOSIZE);
	cvMoveWindow("outputImage",200,200);
	//
	assert(argv[1]);
	inputImage = cvLoadImage(argv[1],CV_LOAD_IMAGE_COLOR);
	outputImage = scaleImage(inputImage,0.5);
	cvShowImage("inputImage",inputImage);
	cvShowImage("outputImage",outputImage);
	//
	cvWaitKey(0);
	cvDestroyWindow("inputImage");
	cvDestroyWindow("outputImage");
	cvReleaseImage(&outputImage);
	cvReleaseImage(&inputImage);
	return 0;
}

