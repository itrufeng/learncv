/*
 * main.cpp
 *
 *  Created on: 2011-4-8
 *      Author: egame
 */

#include <opencv/cv.h>
#include <opencv/highgui.h>

using namespace cv;

Mat rotateImage(const Mat& source, double angle){
    Point2f src_center(source.cols/2.0F, source.rows/2.0F);
    Mat rot_mat = getRotationMatrix2D(src_center, angle, 1.0);
    Mat dst;
    warpAffine(source, dst, rot_mat, source.size());
    return dst;
}

int main(int args,char *argv[]){
	// 缩放比
	float scale = 0.5;
	// 旋转角
	double roation = 45.0;
	// 加载图
	IplImage *image = 0;
	// 缩放后图片
	IplImage *targetImage = 0;
	// 旋转后的图片
	IplImage roatationImage;
	// ----------
	// 验证
	if(!argv[1]){
		printf("缺少运行参数 图像路径");
		exit(0);
	}
	// 创建窗体
	cvNamedWindow("src",CV_WINDOW_AUTOSIZE);
	cvMoveWindow("src",100,100);
	cvNamedWindow("target",CV_WINDOW_AUTOSIZE);
	cvMoveWindow("target",200,200);
	cvNamedWindow("rotationtarget",CV_WINDOW_AUTOSIZE);
	cvMoveWindow("rotationtarget",300,300);
	// 加载图片
	image = cvLoadImage(argv[1],CV_LOAD_IMAGE_COLOR);
	if(!image){
		printf("image can't load");
		exit(0);
	}
	// 创建缩放图片
	CvSize targetSize;targetSize.width = image->width * scale;targetSize.height = image->height * scale;
	targetImage = cvCreateImage(targetSize,image->depth,3);
	// 缩放
	cvResize(image,targetImage,CV_INTER_LINEAR);
	// 原图像的多通道矩阵
	const Mat imgMat(image,0);
	// 旋转
	Mat rotateMat = rotateImage(imgMat,roation);
	roatationImage = IplImage(rotateMat);
	// 显示图片
	cvShowImage("src",image);
	cvShowImage("target",targetImage);
	cvShowImage("rotationtarget",&roatationImage);
	// 等待输入
	cvWaitKey(0);
	// 释放窗体
	cvDestroyWindow("src");
	cvDestroyWindow("target");
	cvDestroyWindow("rotationtarget");
	// 释放图片
	cvReleaseImage(&image);
	cvReleaseImage(&targetImage);
	return 0;
}
