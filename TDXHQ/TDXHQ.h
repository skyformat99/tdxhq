// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 TDXHQ_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// TDXHQ_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。

#ifdef TDXHQ_EXPORTS
#define TDXHQ_API  extern "C"  __declspec(dllexport)
#else
#define TDXHQ_API  extern "C"  __declspec(dllimport)
#endif

#define  TDXHQ_ERROR_OK   -1
#define  TDXHQ_ERROR_SEND -2
#define  TDXHQ_ERROR_RECV -3
#define	 TDXHQ_ERROR_CONT -4
#define  TDXHQ_ERROR_COFG -5

TDXHQ_API int TDXHQ_Init(DWORD dwChoiceFast ,DWORD dwAutoCon );

TDXHQ_API int TDXHQ_Connect( );

TDXHQ_API int TDXHQ_DisConnect(int conID );

/// 获取证券指定范围的的K线数据
///Category:K线种类, 0->5分钟K线    1->15分钟K线    2->30分钟K线  3->1小时K线    4->日K线  5->周K线  6->月K线  7->1分钟  8->1分钟K线  9->日K线  10->季K线  11->年K线
///Market:市场代码,   0->深圳     1->上海
///Zqdm:证券代码
///Start:范围的开始位置,最后一条K线位置是0, 前一条是1, 依此类推
///Count:范围的大小，API执行前,表示用户要请求的K线数目, API执行后,保存了实际返回的K线数目, 最大值800
///Result:此API执行返回后，Result内保存了返回的查询数据, 形式为表格数据，行数据之间通过\n字符分割，列数据之间通过\t分隔。一般要分配1024*1024字节的空间。出错时为空字符串。
///ErrInfo:此API执行返回后，如果出错，保存了错误信息说明。一般要分配256字节的空间。没出错时为空字符串。
/// returns:成功返货true, 失败返回false
TDXHQ_API int TDXHQ_GetSecurityBars( int connID,WORD Category, WORD Market, char* Zqdm, WORD Start, WORD& Count, char szResult[]);

TDXHQ_API int TDXHQ_GetSecurityQuotes(int connID,WORD Market, char* Zqdm, WORD& Count, char szResult[]);//获取盘口五档报价