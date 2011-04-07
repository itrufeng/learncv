CvCapture 
视频获取结构 

typedef struct CvCapture CvCapture;
结构CvCapture 没有公共接口，它只能被用来作为视频获取函数的一个参数。 

----------

cvCreateCameraCapture 
初始化从摄像头中获取视频 

CvCapture* cvCreateCameraCapture( int index );
index 
要使用的摄像头索引。如果只有一个摄像头或者用哪个摄像头也无所谓，那使用参数-1应该便可以。 
函数cvCreateCameraCapture给从摄像头的视频流分配和初始化CvCapture结构。目前在Windows下可使用两种接口：Video for Windows（VFW）和Matrox Imaging Library（MIL）； Linux下也有两种接口：V4L和FireWire（IEEE1394）。 

释放这个结构，使用函数cvReleaseCapture。 

----------

cvCreateFileCapture 
初始化从文件中获取视频 

CvCapture* cvCreateFileCapture( const char* filename );
filename 
视频文件名。 
函数cvCreateFileCapture给指定文件中的视频流分配和初始化CvCapture结构。 

当分配的结构不再使用的时候，它应该使用cvReleaseCapture函数释放掉。 