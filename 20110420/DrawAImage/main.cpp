/*
 * main.cpp
 *
 *  Created on: 2011-4-20
 *      Author: egame
 */
#include <opencv/cv.h>
#include <opencv/highgui.h>

int main(int args,char *argv[]){
	IplImage *image;
	cvNamedWindow("draw",CV_WINDOW_AUTOSIZE);
	//
	image = cvCreateImage(cvSize(400,300),IPL_DEPTH_8U,3);
	// 画直线
	cvLine(image,cvPoint(0,0),cvPoint(100,100),cvScalar(255,0,0),1,32);
	// 画圆
	cvCircle(image,cvPoint(250,50),20,cvScalar(0,255,0),1,32);
	// 画椭圆
	cvEllipse(image,cvPoint(200,100),cvSize(100,50),0,0,360,cvScalar(0,0,255),1,32);
	// 多边形1
//	CvPoint *points[] = {&cvPoint(50,150),&cvPoint(50,250),&cvPoint(150,250),&cvPoint(150,150)};
//	int number[] = {4};
//	cvFillPoly(image,points,number,4,cvScalar(0,0,255),1);
	// 多边形2
	CvPoint points[] = {cvPoint(50,150),cvPoint(50,250),cvPoint(150,250),cvPoint(150,150)};
	cvFillConvexPoly(image,points,4,cvScalar(50,50,50),32);
	// 多边形3
//	CvPoint *points[] = {&cvPoint(50,150),&cvPoint(50,250),&cvPoint(150,250),&cvPoint(150,150)};
//	int number[] = {4};
//	cvPolyLine(image,points,number,4,true,cvScalar(56,73,23),1);
	// 文字
	CvFont font;
	cvInitFont(&font,CV_FONT_HERSHEY_SIMPLEX,1.0f,1.0f,0,4,32);
	cvPutText(image,"I love you.",cvPoint(200,200),&font,cvScalar(78,92,34));
	//
	cvShowImage("draw",image);
	cvWaitKey(0);
	//
	cvReleaseImage(&image);
	cvDestroyWindow("draw");
	return 0;
}
