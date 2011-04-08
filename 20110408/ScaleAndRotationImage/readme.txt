using namespace cv;
	引用OpenCV C++类库。cv
	
----------

Mat rotateImage(const Mat& source, double angle){
    Point2f src_center(source.cols/2.0F, source.rows/2.0F);
    Mat rot_mat = getRotationMatrix2D(src_center, angle, 1.0);
    Mat dst;
    warpAffine(source, dst, rot_mat, source.size());
    return dst;
}
	旋转的封装。遇到Mat&这样的引用传递。传入Mat source类型即可。const Mat& source则是常量的Mat source。
	
----------

Mat
	cv::Mat cv库中的Mat类，是多通道的矩阵类型。
	可用 Mat Mat(const IplImage* img, bool copyData=false); 来构造，将一个IplImage* 提取出多通道矩阵 用来数学计算
	可用 IplImage IplImage(Mat) 来构造，将一个Mat多通道矩阵 指向图像 用来显示或者处理图像
	
----------

Resize
图像大小变换 

void cvResize( const CvArr* src, CvArr* dst, int interpolation=CV_INTER_LINEAR );
src 
输入图像. 
dst 
输出图像. 
interpolation 
插值方法: 
CV_INTER_NN - 最近邻插值, 
CV_INTER_LINEAR - 双线性插值 (缺省使用) 
CV_INTER_AREA - 使用象素关系重采样。当图像缩小时候，该方法可以避免波纹出现。当图像放大时，类似于 CV_INTER_NN 方法.. 
CV_INTER_CUBIC - 立方插值. 
函数 cvResize 将图像 src 改变尺寸得到与 dst 同样大小。若设定 ROI，函数将按常规支持 ROI. 


	