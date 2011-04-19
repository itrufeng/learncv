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

==========

cvCreateImageHeader
分配，初始化，并且返回 IplImage结构 

IplImage* cvCreateImageHeader( CvSize size, int depth, int channels );
size 
图像宽、高. 
depth 
像深 (见 CreateImage). 
channels 
通道数 (见 CreateImage). 
函数 cvCreateImageHeader 分配, 初始化, 并且返回 IplImage结构. 这个函数相似于： 

iplCreateImageHeader( channels, 0, depth,
channels == 1 ? "GRAY" : "RGB",
channels == 1 ? "GRAY" : channels == 3 ? "BGR" :
channels == 4 ? "BGRA" : "",
IPL_DATA_ORDER_PIXEL, IPL_ORIGIN_TL, 4,
size.width, size.height,
0,0,0,0);
然而IPL函数不是作为默认的 (见 CV_TURN_ON_IPL_COMPATIBILITY 宏) 

==========

cvAddS
计算数量和数组的和
// 两个图像重叠

void cvAddS( const CvArr* src, CvScalar value, CvArr* dst, const CvArr* mask=NULL );
src 
原数组. 
value 
被加入数量 
dst 
输出数组 
mask 
操作的复盖面（8-bit单通道数组） ; 只有复盖面指定的输出数组被修改 
函数 cvAddS 用数量值与原数组src1的每个元素想加并存贮结果到 

dst(I)=src(I)+value if mask(I)!=0
除复盖面外所有数组都必须有相同的类型，相同的大小（或ROI大小） 