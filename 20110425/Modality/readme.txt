CreateStructuringElementEx
创建结构元素 

IplConvKernel* cvCreateStructuringElementEx( int cols, int rows, int anchor_x, int anchor_y,
int shape, int* values=NULL );
cols 
结构元素的列数目 
rows 
结构元素的行数目 
anchor_x 
锚点的相对水平偏移量 
anchor_y 
锚点的相对垂直偏移量 
shape 
结构元素的形状，可以是下列值： 
CV_SHAPE_RECT, 长方形元素; 
CV_SHAPE_CROSS, 交错元素 a cross-shaped element; 
CV_SHAPE_ELLIPSE, 椭圆元素; 
CV_SHAPE_CUSTOM, 用户自定义元素。这种情况下参数 values 定义了 mask,即象素的那个邻域必须考虑。 
values 
指向结构元素的指针，它是一个平面数组，表示对元素矩阵逐行扫描。(非零点表示该点属于结构元)。如果指针为空，则表示平面数组中的所有元素都是非零的，即结构元是一个长方形(该参数仅仅当shape参数是 CV_SHAPE_CUSTOM 时才予以考虑)。 
函数 cv CreateStructuringElementEx 分配和填充结构 IplConvKernel, 它可作为形态操作中的结构元素。 

==========

Erode
使用任意结构元素腐蚀图像 

void cvErode( const CvArr* src, CvArr* dst, IplConvKernel* element=NULL, int iterations=1 );
src 
输入图像. 
dst 
输出图像. 
element 
用于腐蚀的结构元素。若为 NULL, 则使用 3×3 长方形的结构元素 
iterations 
腐蚀的次数 
函数 cvErode 对输入图像使用指定的结构元素进行腐蚀，该结构元素决定每个具有最小值象素点的邻域形状： 

dst=erode(src,element): dst(x,y)=min((x',y') in element))src(x+x',y+y')
函数可能是本地操作，不需另外开辟存储空间的意思。腐蚀可以重复进行 (iterations) 次. 对彩色图像，每个彩色通道单独处理。 

==========

Dilate
使用任意结构元素膨胀图像 

void cvDilate( const CvArr* src, CvArr* dst, IplConvKernel* element=NULL, int iterations=1 );
src 
输入图像. 
dst 
输出图像. 
element 
用于膨胀的结构元素。若为 NULL, 则使用 3×3 长方形的结构元素 
iterations 
膨胀的次数 
函数 cvDilate 对输入图像使用指定的结构元进行膨胀，该结构决定每个具有最小值象素点的邻域形状： 

dst=dilate(src,element): dst(x,y)=max((x',y') in element))src(x+x',y+y')
函数支持（in-place）模式。膨胀可以重复进行 (iterations) 次. 对彩色图像，每个彩色通道单独处理。 

==========

MorphologyEx
高级形态学变换 

void cvMorphologyEx( const CvArr* src, CvArr* dst, CvArr* temp,
IplConvKernel* element, int operation, int iterations=1 );
src 
输入图像. 
dst 
输出图像. 
temp 
临时图像，某些情况下需要 
element 
结构元素 
operation 
形态操作的类型: 
CV_MOP_OPEN - 开运算 
CV_MOP_CLOSE - 闭运算 
CV_MOP_GRADIENT - 形态梯度 
CV_MOP_TOPHAT - "顶帽" 
CV_MOP_BLACKHAT - "黑帽" 
iterations 
膨胀和腐蚀次数. 
函数 cvMorphologyEx 在膨胀和腐蚀基本操作的基础上，完成一些高级的形态变换： 

开运算
dst=open(src,element)=dilate(erode(src,element),element) 
闭运算
dst=close(src,element)=erode(dilate(src,element),element) 
形态梯度 
dst=morph_grad(src,element)=dilate(src,element)-erode(src,element) 
"顶帽"
dst=tophat(src,element)=src-open(src,element) 
"黑帽"
dst=blackhat(src,element)=close(src,element)-src 
临时图像 temp 在形态梯度以及对“顶帽”和“黑帽”操作时的 in-place 模式下需要。 