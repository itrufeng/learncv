Line
绘制连接两个点的线段 
// int line_type = 32 的时候很圆滑
void cvLine( CvArr* img, CvPoint pt1, CvPoint pt2, CvScalar color,
int thickness=1, int line_type=8, int shift=0 );
img 
图像。 
pt1 
线段的第一个端点。 
pt2 
线段的第二个端点。 
color 
线段的颜色。 
thickness 
线段的粗细程度。 
line_type 
线段的类型。 
8 (or 0) - 8-connected line（8邻接)连接 线。 
4 - 4-connected line(4邻接)连接线。 
CV_AA - antialiased 线条。 
shift 
坐标点的小数点位数。 
函数cvLine 在图像中的点1和点2之间画一条线段。线段被图像或感兴趣的矩形(ROI rectangle)所裁剪。对于具有整数坐标的non-antialiasing 线条，使用8-连接或者4-连接Bresenham 算法。画粗线条时结尾是圆形的。画 antialiased 线条使用高斯滤波。要指定线段颜色，用户可以使用使用宏CV_RGB( r, g, b )。 

==========

Circle
绘制圆形。 

void cvCircle( CvArr* img, CvPoint center, int radius, CvScalar color,
int thickness=1, int line_type=8, int shift=0 );
img 
图像。 
center 
圆心坐标。 
radius 
圆形的半径。 
color 
线条的颜色。 
thickness 
如果是正数，表示组成圆的线条的粗细程度。否则，表示圆是否被填充。 
line_type 
线条的类型。见 cvLine 的描述 
shift 
圆心坐标点和半径值的小数点位数。 
函数cvCircle绘制或填充一个给定圆心和半径的圆。圆被感兴趣矩形所裁剪。 若指定圆的颜色，可以使用宏 CV_RGB ( r, g, b )。 

==========

Ellipse

绘制椭圆圆弧和椭圆扇形。
// angle 圆转多少度
// start_angle 开始从那个角度画
// end_angle 画到哪个角度

void cvEllipse( CvArr* img, CvPoint center, CvSize axes, double angle,
                double start_angle, double end_angle, CvScalar color,
                int thickness=1, int line_type=8, int shift=0 );
img
图像。
center
椭圆圆心坐标。
axes
轴的长度。
angle
偏转的角度。
start_angle
圆弧起始角的角度。.
end_angle
圆弧终结角的角度。
color
线条的颜色。
thickness
线条的粗细程度。
line_type
线条的类型,见CVLINE的描述。
shift
圆心坐标点和数轴的精度。
函数cvEllipse用来绘制或者填充一个简单的椭圆弧或椭圆扇形。圆弧被ROI矩形所忽略。反走样弧线和粗弧线使用线性分段近似值。所有的角都是以角度的形式给定的。下面的图片将解释这些参数的含义。

==========

FillConvexPoly
填充凸多边形 
// CvPoint* pts 有的是一个点的数组。例如 CvPoint points[] = {cvPoint(50,150),cvPoint(50,250),cvPoint(150,250),cvPoint(150,150)};

void cvFillConvexPoly( CvArr* img, CvPoint* pts, int npts,
CvScalar color, int line_type=8, int shift=0 );
img 
图像。 
pts 
指向单个多边形的指针数组。 
npts 
多边形的顶点个数。 
color 
多边形的颜色。 
line_type 
组成多边形的线条的类型。参见cvLine 
shift 
顶点坐标的小数点位数。 
　 

函数cvFillConvexPoly填充凸多边形内部。这个函数比函数cvFillPoly 更快。它除了可以填充凸多边形区域还可以填充任何的单调多边形。例如：一个被水平线（扫描线）至多两次截断的多边形。

==========

PutText
在图像中显示文本字符串。 

void cvPutText( CvArr* img, const char* text, CvPoint org, const CvFont* font, CvScalar color );
img 
输入图像。 
text 
要显示的字符串。 
org 
第一个字符左下角的坐标。 
font 
字体结构体。 
color 
文本的字体颜色。 
函数cvPutText将具有指定字体的和指定颜色的文本加载到图像中。加载到图像中的文本被感兴趣的矩形框(ROI rectangle)剪切。不属于指定字体库的字符用矩形字符替代显示。　 