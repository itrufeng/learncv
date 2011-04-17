/*
 * main.cpp
 *
 *  Created on: 2011-4-16
 *      Author: itrufeng
 */
#include <opencv/cv.h>
#include <opencv/highgui.h>

int main(int args,char *argv[]){
	IplImage *image;
	IplImage *outImage;
	cvNamedWindow("image",CV_WINDOW_AUTOSIZE);
	cvMoveWindow("image",100,100);
	cvNamedWindow("smoothing",CV_WINDOW_AUTOSIZE);
	cvMoveWindow("smoothing",200,200);
	//validate
	if (!argv[1]) {
		printf("缺少图片参数");
	}
	printf("传入参数：%s",argv[1]);
	image = cvLoadImage(argv[1],CV_LOAD_IMAGE_COLOR);
	// 处理图片平滑
	outImage = cvCreateImage(cvGetSize(image),image->depth,3);
	// CV_BLUR_NO_SCALE 简单不带尺度变换的模糊 5*5 容易把白色光照提取出来。
	// CV_BLUR 可以把图像较大程度处理模糊
	// CV_GAUSSIAN 对图像每个像素进行3X3的 高斯平滑处理。
	cvSmooth(image,outImage,CV_BLUR_NO_SCALE,5,5);
	// 显示图片
	cvShowImage("image",image);
	cvShowImage("smoothing",outImage);
	cvWaitKey(0);
	// relaese
	cvReleaseImage(&outImage);
	cvReleaseImage(&image);
	cvDestroyWindow("smoothing");
	cvDestroyWindow("image");
	return 0;
}
