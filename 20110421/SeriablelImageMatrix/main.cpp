/*
 * main.cpp
 *
 *  Created on: 2011-4-21
 *      Author: egame
 */
#include <opencv/cv.h>
#include <opencv/highgui.h>

int main(int args,char *argv[]){
	assert(argv[1]);
	IplImage *matTmage = cvLoadImage(argv[1],CV_LOAD_IMAGE_ANYCOLOR);
	IplImage *readTmage;
	cvNamedWindow("viewSeriableImage",CV_WINDOW_AUTOSIZE);
	// 保存一个矩阵
	CvMat matA = cvMat(5,5,CV_32F);
	cvSave("/Users/egame/Documents/workspaceforC/SeriablelImageMatrix/Debug/matA.xml",&matA);
	// 载入矩阵
	CvMat *matInput = (CvMat*)cvLoad("/Users/egame/Documents/workspaceforC/SeriablelImageMatrix/Debug/matA.xml");
	// 查看一下矩阵是否有在内存空间
	printf("0x%0.8x\n",matInput);
	printf("0x00%x\n",matInput);
	// 手动写入配置
	CvFileStorage *fs = cvOpenFileStorage("/Users/egame/Documents/workspaceforC/SeriablelImageMatrix/Debug/cfg.xml",NULL,CV_STORAGE_WRITE);
	cvWriteInt(fs,"size",10);
	cvStartWriteStruct(fs,"diy",CV_NODE_SEQ);
	cvWriteInt(fs,NULL,20);
	cvWriteInt(fs,NULL,10);
	cvWriteInt(fs,NULL,100);
	cvEndWriteStruct(fs);
	// 写入矩阵数据
	cvWrite(fs,"dataIt",matTmage);
	cvReleaseFileStorage(&fs);
	// 手动载入配置
	CvFileStorage *fs2 = cvOpenFileStorage("/Users/egame/Documents/workspaceforC/SeriablelImageMatrix/Debug/cfg.xml",NULL,CV_STORAGE_READ);
	int size = cvReadIntByName(fs2,NULL,"size");
	printf("size:%d\n",size);
	CvSeq *seq = cvGetFileNodeByName(fs2,NULL,"diy")->data.seq;
	int one = cvReadInt((CvFileNode*)cvGetSeqElem(seq,0));
	int two = cvReadInt((CvFileNode*)cvGetSeqElem(seq,1));
	int three = cvReadInt((CvFileNode*)cvGetSeqElem(seq,2));
	printf("one:%d,two:%d,three:%d\n",one,two,three);
	// 读取矩阵数据
	readTmage = (IplImage*)cvReadByName(fs2,NULL,"dataIt");
	cvShowImage("viewSeriableImage",readTmage);
	cvReleaseFileStorage(&fs2);
	//
	cvWaitKey(0);
	//
	cvReleaseImage(&readTmage);
	cvReleaseImage(&matTmage);
	return 0;
}
