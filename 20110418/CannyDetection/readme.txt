Canny
采用 Canny 算法做边缘检测 

void cvCanny( const CvArr* image, CvArr* edges, double threshold1,
double threshold2, int aperture_size=3 );
image 
输入图像. 
edges 
输出的边缘图像 
threshold1 
第一个阈值 
threshold2 
第二个阈值 
aperture_size 
Sobel 算子内核大小 (见 cvSobel). 
函数 cvCanny 采用 CANNY 算法发现输入图像的边缘而且在输出图像中标识这些边缘。threshold1和threshold2 当中的小阈值用来控制边缘连接，大的阈值用来控制强边缘的初始分割。