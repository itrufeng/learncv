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
	IplImage *inputImage;
	IplImage *outputImage;
	cvNamedWindow("inputImage",CV_WINDOW_AUTOSIZE);
	cvMoveWindow("inputImage",100,100);
	cvNamedWindow("outputImage",CV_WINDOW_AUTOSIZE);
	cvMoveWindow("outputImage",200,200);
	//
	printf("%s",argv[1]);
	assert(argv[1]);
	// 只有灰度图才可以canny
	inputImage = cvLoadImage(argv[1],CV_LOAD_IMAGE_GRAYSCALE);
	cvShowImage("inputImage",inputImage);
	// float lowThresh 内部轮廓。数字越大越模糊
	// float highThresh //外部轮廓。数字越大越模糊
	// float aperture
	outputImage = canny(inputImage,100,100,3);
	cvShowImage("outputImage",outputImage);
	cvWaitKey(0);
	//
	cvDestroyWindow("outputImage");
	cvDestroyWindow("inputImage");
	cvReleaseImage(&outputImage);
	cvReleaseImage(&inputImage);
	return 0;
}
