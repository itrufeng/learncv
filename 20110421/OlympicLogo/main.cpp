/*
 * main.cpp
 *
 *  Created on: 2011-4-21
 *      Author: egame
 */
#include <opencv/cv.h>
#include <opencv/highgui.h>

int main(int args,char *argv[]){
	IplImage *drawImage;
	cvNamedWindow("OlympicLogo",CV_WINDOW_AUTOSIZE);
	cvMoveWindow("OlympicLogo",800,400);
	// vaildate
	if (!argv[1]){
		printf("对不起，您没有跟参数。自动退出。格式:OlympicLogo yourname\n");
		exit(0);
	}
	// init
	CvSize size;
	size.width = 300;
	size.height = 200;
	drawImage = cvCreateImage(size,IPL_DEPTH_8U,3);
	// draw
	CvPoint points[] = {cvPoint(0,0),cvPoint(300,0),cvPoint(300,200),cvPoint(0,200)};
	cvFillConvexPoly(drawImage,points,4,cvScalar(255,255,255),64);
	cvCircle(drawImage,cvPoint(60,60),30,cvScalar(197,130,0),5,64);
	cvCircle(drawImage,cvPoint(130,60),30,cvScalar(33,32,36),5,64);
	cvCircle(drawImage,cvPoint(200,60),30,cvScalar(44,28,236),5,64);
	cvCircle(drawImage,cvPoint(95,90),30,cvScalar(49,177,252),5,64);
	cvCircle(drawImage,cvPoint(165,90),30,cvScalar(80,166,0),5,64);
	CvFont font;
	cvInitFont(&font,CV_FONT_HERSHEY_SCRIPT_SIMPLEX,1.0f,1.0f,0,1,32);
	cvPutText(drawImage,argv[1],cvPoint(150,170),&font,cvScalar(0,0,0));
	cvShowImage("OlympicLogo",drawImage);
	cvWaitKey(0);
	// release
	cvReleaseImage(&drawImage);
	cvDestroyWindow("OlympicLogo");
	return 0;
}
