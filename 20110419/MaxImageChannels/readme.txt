// 处理饱和度
void saturation(IplImage *inputImage,int value);
	inputImage:处理的图像
	value:饱和度变化值
	
==========

cvSetImageROI
基于给定的矩形设置感兴趣区域 
// 只对OpenCV自己的函数起作用。

void cvSetImageROI( IplImage* image, CvRect rect );
image 
图像头. 
rect 
ROI 矩形. 
函数 cvSetImageROI 基于给定的矩形设置图像的 ROI（感兴趣区域） . 如果ROI是NULL 并且参数RECT的值不等于整个图像, ROI被分配. 不像 COI, 大多数的 OpenCV 函数支持 ROI 并且处理它就像它是一个分离的图像 (例如, 所有的像素坐标从ROI的左上角或左下角（基于图像的结构）计算。 

==========


ResetImageROI
释放图像的ROI 
// 如果不释放。则图片大小就会只显示感兴趣区域

void cvResetImageROI( IplImage* image );
image 
图像头. 
函数 cvResetImageROI 释放图像 ROI. 释放之后整个图像被认为是全部被选中的。相似的结果可以通过下述办法 

cvSetImageROI( image, cvRect( 0, 0, image->width, image->height ));
cvSetImageCOI( image, 0 );
但是后者的变量不分配 image->roi. 