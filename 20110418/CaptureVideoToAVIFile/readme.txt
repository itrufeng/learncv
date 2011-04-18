cvGetCaptureProperty 
获得视频获取结构的属性 

double cvGetCaptureProperty( CvCapture* capture, int property_id );
capture 
视频获取结构。 
property_id 
属性标识。可以是下面之一： 
CV_CAP_PROP_POS_MSEC - 影片目前位置，为毫秒数或者视频获取时间戳 
CV_CAP_PROP_POS_FRAMES - 将被下一步解压／获取的帧索引，以0为起点 
CV_CAP_PROP_POS_AVI_RATIO - 视频文件的相对位置（0 - 影片的开始，1 - 影片的结尾) 
CV_CAP_PROP_FRAME_WIDTH - 视频流中的帧宽度 
CV_CAP_PROP_FRAME_HEIGHT - 视频流中的帧高度 
CV_CAP_PROP_FPS - 帧率 
CV_CAP_PROP_FOURCC - 表示codec的四个字符 
CV_CAP_PROP_FRAME_COUNT - 视频文件中帧的总数 
函数cvGetCaptureProperty获得摄像头或者视频文件的指定属性。 

译者注：有时候这个函数在cvQueryFrame被调用一次后，再调用cvGetCaptureProperty才会返回正确的数值。 

==========

cvCreateVideoWriter [Bug for mac.opencv2.2]
创建视频文件写入器 

typedef struct CvVideoWriter CvVideoWriter;
CvVideoWriter* cvCreateVideoWriter( const char* filename, int fourcc, double fps, CvSize frame_size, int is_color=1 );
filename 
输出视频文件名。 
fourcc 
四个字符用来表示压缩帧的codec 例如，CV_FOURCC('P','I','M','1')是MPEG-1 codec， CV_FOURCC('M','J','P','G')是motion-jpeg codec等。 在Win32下，如果传入参数-1，可以从一个对话框中选择压缩方法和压缩参数。 
fps 
被创建视频流的帧率。 
frame_size 
视频流的大小。 
is_color 
如果非零，编码器将希望得到彩色帧并进行编码；否则，是灰度帧（只有在Windows下支持这个标志）。 
函数cvCreateVideoWriter创建视频写入器结构。

==========

LogPolar

把图像映射到极指数空间

void cvLogPolar( const CvArr* src, CvArr* dst,
                 CvPoint2D32f center, double M,
                 int flags=CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS );
src
输入图像。
dst
输出图像。
center
变换的中心，输出图像在这里最精确。
M
幅度的尺度参数，见下面公式。
flags
插值方法和以下选择标志的结合
CV_WARP_FILL_OUTLIERS -填充输出图像所有像素，如果这些点有和外点对应的，则置零。
CV_WARP_INVERSE_MAP - 表示矩阵由输出图像到输入图像的逆变换，并且因此可以直接用于像素插值。否则，函数从map_matrix中寻找逆变换。

==========

cvWriteFrame 
写入一帧到一个视频文件中 

int cvWriteFrame( CvVideoWriter* writer, const IplImage* image );
writer 
视频写入器结构。 
image 
被写入的帧。 
函数cvWriteFrame写入／附加到视频文件一帧。 