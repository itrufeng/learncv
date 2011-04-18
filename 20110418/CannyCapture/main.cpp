/*c
 * main.cpp
 *
 *  Created on: 2011-4-17
 *      Author: itrufeng
 */

#include <opencv/cv.h>
#include <opencv/highgui.h>
// aperture 光圈
IplImage* canny(IplImage *inputImage,float lowThresh,float highThresh,float aperture){
	IplImage *outputImage;
	if(inputImage->nChannels>1){
		printf("not gray image.");
	}
	outputImage = cvCreateImage(cvGetSize(inputImage),IPL_DEPTH_8U,1);
	cvCanny(inputImage,outputImage,lowThresh,highThresh,aperture);
	return outputImage;
}

int main(int args,char *argv[]){
	CvCapture *capture = NULL;
	IplImage *image;
	cvNamedWindow("inputImage",CV_WINDOW_AUTOSIZE);
	cvMoveWindow("inputImage",100,100);
	capture = cvCreateCameraCapture(CV_CAP_ANY);
	while(image=cvQueryFrame(capture)){
		IplImage *grayImage = cvCreateImage(cvGetSize(image),image->depth,1);
		IplImage *cannyImage = cvCreateImage(cvGetSize(grayImage),IPL_DEPTH_8U,1);
		cvCvtColor(image,grayImage,CV_RGB2GRAY);
		// float lowThresh 内部轮廓。数字越大越模糊
		// float highThresh //外部轮廓。数字越大越模糊
		// float aperture
		cannyImage = canny(grayImage,20,20,3);
		cvShowImage("inputImage",cannyImage);
		if(cvWaitKey(2)>0)
			break;
		cvReleaseImage(&cannyImage);
		cvReleaseImage(&grayImage);
	}
	//
	cvDestroyWindow("inputImage");
	cvReleaseCapture(&capture);
	return 0;
}
