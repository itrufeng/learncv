/*
 * main.cpp
 *
 *  Created on: 2011-4-18
 *      Author: egame
 */
#include <opencv/cv.h>
#include <opencv/highgui.h>
// 缩放方法
IplImage* scaleImage(IplImage *inputImage,float scale){
	IplImage *outputImage = cvCreateImage(cvSize(inputImage->width*scale,inputImage->height*scale),inputImage->depth,3);
	cvPyrDown(inputImage,outputImage,CV_GAUSSIAN_5x5);
	return outputImage;
}

int main(int args,char *argv[]){
	CvCapture *capture = NULL;
	CvVideoWriter *writer = NULL;
	cvNamedWindow("capture",CV_WINDOW_AUTOSIZE);
	//
	assert(argv[1]);
	//
	capture = cvCreateCameraCapture(CV_CAP_ANY);
	// 获得fps帧数
	float fps = cvGetCaptureProperty(capture,CV_CAP_PROP_FPS);
	// 获得视频尺寸
	CvSize size = cvSize((int)cvGetCaptureProperty(capture,CV_CAP_PROP_FRAME_WIDTH)/3,(int)cvGetCaptureProperty(capture,CV_CAP_PROP_FRAME_WIDTH)/3);
	// 初始化时IO写入
	writer = cvCreateVideoWriter(argv[1],CV_FOURCC('X', 'V', 'I', 'D'),fps,size);
	// 捕捉第一帧
	IplImage *oneFrame = cvQueryFrame(capture);
	IplImage *log_polar = cvCreateImage(size,IPL_DEPTH_8U,3);
	// 捕捉画面oneFrame
	while((oneFrame = cvQueryFrame(capture))!=NULL){
		cvShowImage("capture",oneFrame);
		cvLogPolar(oneFrame,log_polar,cvPoint2D32f(size.width,size.height),40,CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS);
		cvWriteFrame(writer,log_polar);
		if(cvWaitKey(2)>0)
			break;
	}
	//
	cvReleaseImage(&log_polar);
	cvDestroyWindow("capture");
	cvReleaseVideoWriter(&writer);
	cvReleaseCapture(&capture);
	return 0;
}
