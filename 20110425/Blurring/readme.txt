平滑处理
	最常见的是用来减少图像上的噪声和失真
	降低分辨率时，平滑处理很重要
	Smooth有五种处理类型
	
平滑处理类型			输入与输出同一个图像		Nc			输入数据类型			输出数据类型			简要说明
	简单模糊				是						1,3			8u,32f				8u,32f				每个像素param1*param2临预求和，并做缩放1/(param1*param2)
	简单无缩放的模糊		否						1			8u					16s,32f,			每个像素param1*param2临预求和
	中值模糊				否						1,3			8u					8u					对图像进行核大小为param1*param1的中值滤波
	高斯模糊				是						1,3			8u,32f				8u,32f				对图像进行核大小为param1*param2的高斯卷积
	双边滤波				否						1,3			8u					8u					应用双线性3*3滤波，颜色sigma=param1,空间sigma=param2

==========

Smooth
各种方法的图像平滑 
// 简单无缩放的模糊 两个参数不可以相同。
// 中值模糊 取值0-9 且只有一个参数
// 高斯模糊 需要3个参数 
// 双边滤波 需要4个参数 技巧。多处理几次 效果会很明显哦^ ^

void cvSmooth( const CvArr* src, CvArr* dst,
int smoothtype=CV_GAUSSIAN,
int param1=3, int param2=0, double param3=0, double param4=0 );
src 
输入图像. 
dst 
输出图像. 
smoothtype 
平滑方法: 
CV_BLUR_NO_SCALE (简单不带尺度变换的模糊) - 对每个象素的 param1×param2 领域求和。如果邻域大小是变化的，可以事先利用函数 cvIntegral 计算积分图像。 
CV_BLUR (simple blur) - 对每个象素param1×param2邻域 求和并做尺度变换 1/(param1?param2). 
CV_GAUSSIAN (gaussian blur) - 对图像进行核大小为 param1×param2 的高斯卷积 
CV_MEDIAN (median blur) - 对图像进行核大小为param1×param1 的中值滤波 (i.e. 邻域是方的). 
CV_BILATERAL (双向滤波) - 应用双向 3x3 滤波，彩色 sigma=param1，空间 sigma=param2. 关于双向滤波，可参考 http://www.dai.ed.ac.uk/CVonline/LOCAL_COPIES/MANDUCHI1/Bilateral_Filtering.html 
param1 
平滑操作的第一个参数. 
param2 
平滑操作的第二个参数. 对于简单/非尺度变换的高斯模糊的情况，如果param2的值 为零，则表示其被设定为param1。 
param3 
对应高斯参数的 Gaussian sigma (标准差). 如果为零，则标准差由下面的核尺寸计算： 
sigma = (n/2 - 1)*0.3 + 0.8, 其中 n=param1 对应水平核,
n=param2 对应垂直核.
对小的卷积核 (3×3 to 7×7) 使用如上公式所示的标准 sigma 速度会快。如果 param3 不为零，而 param1 和 param2 为零，则核大小有 sigma 计算 (以保证足够精确的操作). 

函数 cvSmooth 可使用上面任何一种方法平滑图像。每一种方法都有自己的特点以及局限。 

没有缩放的图像平滑仅支持单通道图像，并且支持8位到16位的转换(与cvSobel和cvaplace相似)和32位浮点数到32位浮点数的变换格式。 

简单模糊和高斯模糊支持 1- 或 3-通道, 8-比特 和 32-比特 浮点图像。这两种方法可以（in-place）方式处理图像。 

中值和双向滤波工作于 1- 或 3-通道， 8-位图像，但是不能以 in-place 方式处理图像. 