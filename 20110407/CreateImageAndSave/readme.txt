CreateImage
创建头并分配数据 

IplImage* cvCreateImage( CvSize size, int depth, int channels );
size 
图像宽、高. 
depth 
图像元素的位深度，可以是下面的其中之一： 
IPL_DEPTH_8U - 无符号8位整型 
IPL_DEPTH_8S - 有符号8位整型 
IPL_DEPTH_16U - 无符号16位整型 
IPL_DEPTH_16S - 有符号16位整型 
IPL_DEPTH_32S - 有符号32位整型 
IPL_DEPTH_32F - 单精度浮点数 
IPL_DEPTH_64F - 双精度浮点数 
channels 
每个元素（像素）的颜色通道数量.可以是 1, 2, 3 或 4.通道是交叉存取的，例如通常的彩色图像数据排列是： 
b0 g0 r0 b1 g1 r1 ... 
虽然通常 IPL 图象格式可以存贮非交叉存取的图像，并且一些OpenCV 也能处理他, 但是这个函数只能创建交叉存取图像. 
函数 cvCreateImage 创建头并分配数据，这个函数是下列的缩写型式 

header = cvCreateImageHeader(size,depth,channels);
cvCreateData(header); //只是创建空间，并不会初始化空间内的数据

----------

Copy
拷贝一个数组给另一个数组 

void cvCopy( const CvArr* src, CvArr* dst, const CvArr* mask=NULL );
src 
输入数组。 
dst 
输出数组。 
mask 
操作掩码是8比特单通道的数组，它指定了输出数组中被改变的元素。 
函数cvCopy从输入数组中复制选定的成分到输出数组： 
如果mask(I)!=0,则dst(I)=src(I)。 
如果输入输出数组中的一个是IplImage类型的话，其ROI和COI将被使用。输入输出数组必须是同样的类型、维数和大小。函数也可以用来复制散列数组（这种情况下不支持mask）。 

----------

cvSaveImage 
保存图像到文件 

int cvSaveImage( const char* filename, const CvArr* image );
filename 
文件名。 
image 
要保存的图像。 
函数cvSaveImage保存图像到指定文件。图像格式的的选择依赖于filename的扩展名，请参考cvLoadImage。只有8位单通道或者3通道（通道顺序为'BGR' ）可以使用这个函数保存。如果格式，深度或者通道不符合要求，请先用cvCvtScale 和cvCvtColor转换；或者使用通用的cvSave保存图像为XML或者YAML格式。 