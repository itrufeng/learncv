cvSave
存储对象到文件中 
// 保存CvMat* 对象 或者 IplImage*

void cvSave( const char* filename, const void* struct_ptr,
const char* name=NULL,
const char* comment=NULL,
CvAttrList attributes=cvAttrList());
filename 
初始化文件名。 
struct_ptr 
指定要存储的对象。 
name 
可选择的对象名 。如果为 NULL, 对象名将从filename中列出。 
comment 
可选注释。加在文件的开始处。 
attributes 
可选属性。 传递给cvWrite。 
函数 cvSave存储对象到文件。它给cvWrite提供一个简单的接口。 

==========

CvFileStorage
文件存储结构 
// 文件句柄

typedef struct CvFileStorage
{
... // hidden fields
} CvFileStorage;
构造函数 CvFileStorage 是将磁盘上存储的文件关联起来的“黑匣子” 。在下列函数描述中利用CvFileStorage 作为输入，允许存储或载入各种格式数据组成的层次集合，这些数据由标量值（scalar ）,或者CXCore 对象(例如 矩阵,序列，图表 ) 和用户自定义对象。 

CXCore 能将数据读入或写入 XML (http://www.w3c.org/XML) or YAML (http://www.yaml.org) 格式. 下面这个例子是利用CXCore函数将3×3单位浮点矩阵存入XML 和 YAML文档。 

XML: 

<?xml version="1.0">
<opencv_storage>
<A type_id="opencv-matrix">
<rows>3</rows>
<cols>3</cols>
<dt>f</dt>
<data>1. 0. 0. 0. 1. 0. 0. 0. 1.</data>
</A>
</opencv_storage>
YAML: 

%YAML:1.0
A: !!opencv-matrix
rows: 3
cols: 3
dt: f
data: [ 1., 0., 0., 0., 1., 0., 0., 0., 1.]
从例子中可以看到, XML是用嵌套标签来表现层次，而 YAML用缩排来表现（类似于Python语言） 。 

相同的 CXCore 函数也能够在这两种格式下读写数据，特殊的格式决定了文件的扩展名， .xml 是 XML 的扩展名， .yml 或 .yaml 是 YAML的扩展名。 

==========

cvOpenFileStorage
打开文件存储器读/写数据。 
// CvMemStorage* memstorage: 给NULL 一般

CvFileStorage* cvOpenFileStorage( const char* filename, CvMemStorage* memstorage, int flags );
filename 
内存中的相关文件的文件名。 
memstorage 
内存中通常存储临时数据和动态结构，例如 CvSeq 和 CvGraph。如果memstorage 为空,将建立和使用一个暂存器。 
flags 
读/写选择器。 
CV_STORAGE_READ - 内存处于读状态。 
CV_STORAGE_WRITE - 内存处于写状态。 
函数cvOpenFileStorage打开文件存储器读写数据，之后建立文件或继续使用现有的文件 。文件扩展名决定读文件的类型 ： .xml 是 XML的扩展名, .yml 或 .yaml 是 YAML的扩展名。该函数的返回指针指向CvFileStorage结构。 

==========

cvWriteInt
写入一个整型值 

void cvWriteInt( CvFileStorage* fs, const char* name, int value );
fs 
初始的文件存储器。 
name 
写入值的名称 。如果母结构是一个序列，把name的值置为NULL。 
value 
写入的整型值。 
函数 cvWriteInt 将一个单独的整型值（有符号的或无符号的）写入文件存储器。

==========

cvStartWriteStruct
向文件存储器中写数据 
// const char* name：给 NULL　如果　int struct_flags为　CV_NODE_SEQ。

void cvStartWriteStruct( CvFileStorage* fs, const char* name,
int struct_flags, const char* type_name=NULL,
CvAttrList attributes=cvAttrList());
fs 
初始化文件存储器。 
name 
被写入的数据结构的名称。在存储器被读取时可以通过名称访问数据结构。 
struct_flags 
有下列两个值： 
CV_NODE_SEQ - 被写入的数据结构为序列结构。这样的数据没有名称。 
CV_NODE_MAP - 被写入的数据结构为图表结构。这样的数据含有名称。 
这两个标志符必须被指定一个 
CV_NODE_FLOW - 这个可选择标识符只能作用于YAML流。被写入的数据结构被看做一个数据流（不是数据块），它更加紧凑，当结构或数组里的数据是标量时，推荐用这个标志。 
type_name 
可选参数 - 对象类型名称。如果是XML用打开标识符type_id 属性写入。如果是YAML 用冒号后面的数据结构名写入，:: 基本上它是伴随用户对象出现的。当读存储器时，编码类型名通常决定对象类型（见Cvtypeinfo和cvfindtypeinfo） 。 
attributes 
这个参数当前版本没有使用。 
函数 cvStartWriteStruct 开始写复合的数据结构（数据集合）包括序列或图表, 在结构体中所有的字段（可以是标量和新的结构）被写入后， 需要调用 cvEndWriteStruct . 该函数能够合并一些对象或写入一些用户对象（参考 CvTypeInfo ）。

==========

cvEndWriteStruct
结束数据结构的写操作 

void cvEndWriteStruct( CvFileStorage* fs );
fs 
初始化文件存储器。 
函数cvEndWriteStruct 结束普通的写数据操作。 

==========

cvWrite
存储对象到文件中 
// const void* struct_ptr：给CvMat*或者IplImage*

void cvSave( const char* filename, const void* struct_ptr,
const char* name=NULL,
const char* comment=NULL,
CvAttrList attributes=cvAttrList());
filename 
初始化文件名。 
struct_ptr 
指定要存储的对象。 
name 
可选择的对象名 。如果为 NULL, 对象名将从filename中列出。 
comment 
可选注释。加在文件的开始处。 
attributes 
可选属性。 传递给cvWrite。 
函数 cvSave存储对象到文件。它给cvWrite提供一个简单的接口。 

==========

cvReleaseFileStorage
释放文件存储单元 

void cvReleaseFileStorage( CvFileStorage** fs );
fs 
双指针指向被关闭的文件存储器。 
函数cvReleaseFileStorage 关闭一个相关的文件存储器并释放所有的临时内存。只有在内存的I/O操作完成后才能关闭文件存储器。 

==========

cvReadIntByName
查找文件节点返回它的值 
// const CvFileNode* map: 一般为NULL

int cvReadIntByName( const CvFileStorage* fs, const CvFileNode* map,
const char* name, int default_value=0 );
fs 
初始化文件存储器 。 
map 
设置父图表。如果为NULL，函数 在所有的高层节点（流）中检索。 
name 
设置节点名。 
default_value 
如果文件节点为NULL，返回一个值。 
函数 cvReadIntByName是 cvGetFileNodeByName 和 cvReadInt的简单重叠. 

==========

cvGetFileNodeByName
在图表或者文件存储器中查找节点 
// 如果要读取子级节点　使用CvSeq *seq = cvGetFileNodeByName(xxx)->data.seq;int one = cvReadInt((CvFileNode*)cvGetSeqElem(seq,0));//　得到one

CvFileNode* cvGetFileNodeByName( const CvFileStorage* fs,
const CvFileNode* map,
const char* name );
fs 
初始化文件存储器。 
map 
设置父图表。如果为NULL，函数 在所有的高层节点（流）中检索， 从第一个开始。 
name 
设置文件节点名。 
函数 cvGetFileNodeByName 文件节点通过name 查找文件节点 该节点在图表中被查找，或者如果指针为NULL，那么在内存中的高层文件节点中查找。 在图表中或者在序列调用cvGetSeqElem中使用到这个函数，这样可能遍历整个文件存储器。 为了加速确定某个关键字的多重查询（例如 结构数组 ），可以在cvGetHashedKey 和cvGetFileNode之中用到一个。 

==========

cvGetSeqElem
返回索引所指定的元素指针 

char* cvGetSeqElem( const CvSeq* seq, int index );
#define CV_GET_SEQ_ELEM( TYPE, seq, index ) (TYPE*)cvGetSeqElem( (CvSeq*)(seq), (index) )
seq 
序列 
index 
索引 
函数 cvGetSeqElem 查找序列中索引所指定的元素，并返回指向该元素的指针。如果元素不存在，则返回 0。 函数支持负数，即： -1 代表 序列的最后一个元素， -2 代表最后第二个元素，等。如果序列只包含一个块，或者所需的元素在第一个块中，那么应当使用宏, CV_GET_SEQ_ELEM( elemType, seq, index )宏中的参数 elemType 是序列中元素的类型（如：CvPoint), 参数 seq 表示序列， 参数 index 代表所需元素的索引。 该宏首先核查所需的元素是否属于第一个块，如果是，则返回该元素，否则，该宏就调用主函数 GetSeqElem. 如果索引为负数的话，则总是调用函数 cvGetSeqElem。函数的时间复杂度为 O(1), 假设块的大小要比元素的数量要小。 

==========

cvReadInt
从文件节点中得到整形值 

int cvReadInt( const CvFileNode* node, int default_value=0 );
node 
初始化文件节点 
default_value 
如果node为NULL，返回一个值。 
函数 cvReadInt 从文件节点中返回整数。如果文件节点为NULL， default_value 被返回 。另外如果文件节点有类型 CV_NODE_INT, 则 node->data.i 被返回 。如果文件节点有类型 CV_NODE_REAL, 则 node->data.f 被修改成整数后返回。 其他的情况是则结果不确定。 

==========

cvReadByName
查找对象并解释 
// 直接得到一个CvMat* 或者　IplImage* 需要强制()转换

void* cvReadByName( CvFileStorage* fs, const CvFileNode* map,
const char* name, CvAttrList* attributes=NULL );
fs 
初始化文件存储器。 
map 
设置父节点。如果它为NULL，函数从高层节点中查找。 
name 
设置节点名称。 
attributes 
不被使用的参数. 
函数 cvReadByName 是由cvGetFileNodeByName 和 cvRead叠合的。