PyrDown
图像的下采样 

void cvPyrDown( const CvArr* src, CvArr* dst, int filter=CV_GAUSSIAN_5x5 );
src 
输入图像. 
dst 
输出图像, 宽度和高度应是输入图像的一半 ,传入前必须已经完成初始化 
filter 
卷积滤波器的类型，目前仅支持 CV_GAUSSIAN_5x5 
函数 cvPyrDown 使用 Gaussian 金字塔分解对输入图像向下采样。首先它对输入图像用指定滤波器进行卷积，然后通过拒绝偶数的行与列来下采样图像。