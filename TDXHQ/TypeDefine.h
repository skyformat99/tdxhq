#pragma once

//=====================loginlbs==================
/* 发
//登录第一个包数据格式
//协商获取登录服务器地址和端口
DWORD dwSize;//包大小
DWORD ProtolNum;//协议号 0x00001401
WORD  wStatus;//0x00C8
DWORD Version;//0x60900000 协议版本
DWORD unknow;//0XFFFFFFFF

WORD  wUserNameLen;//用户名长
char  UserName[ wUserNameLen ];//用户名

WORD  wUnknow;//0x 0000
DWORD  wLangId;// 0x 0804 = 2052

DWORD  dwUnknowLen;//未知数组长度
DWORD Unknow[ dwUnknowLen ];//未知数组

DWORD  dwIPLen;//IP数组大小
DWORD  IP[ dwIPLen ]; //IP 数组

DWORD  dwIP2Len;
DWORD  IP2[ dwIP2Len ];
*/

/* 收
//返回登录服务器地址和端口
DWORD dwSize;//包大小
DWORD ProtolNum;//协议号 0x0000 1501
DWORD  dwStatus;//0x0000 00C8
DWORD  dwStatus2;//0x0000 00C8 返回结果

DWORD dwIPsize;//IP数量

	DWROD dwIP;//IP地址
	DWORD dwUnknow;//未知
	WORD  wUnknow;//未知
	DWORD dwPortSize;
	WORD  wPort[ dwPortSize ];

	DWROD dwIP;//IP地址
	DWORD dwUnknow;//未知
	WORD  wUnknow;//未知
	DWORD dwPortSize;
	WORD  wPort[ dwPortSize ];

DWORD dwUnknow;//未知
DWORD dwUnknow;//未知 0x 00 12 00 01
DWORD dwIP;//本机WANIP
DWORD dwUnknow;//未知
DWORD dwUnknow;//未知
*/
//=====================loginlbs==================





//====================dologinlink===============
/*第二数据包
//发
//=======协商密钥========
DWORD dwSize;
DWORD dwProtocal;//0x 00001104
WORD  wRes;// 0x 00c8
WORD  wKey_N_Size;//0x 0040
char key_n[wKey_N_Size];
WORD  wKeySize;
char key_e[wKey_e_Size];
*/

//收
//====================dologinlink===============



#include <sys/types.h>

#if defined(_MSC_VER)
	//
	// Windows/Visual C++
	//
	typedef signed __int8			int8;
	typedef unsigned __int8			uint8;
	typedef signed __int16			int16;
	typedef unsigned __int16		uint16;
	typedef signed __int32			int32;
	typedef unsigned __int32		uint32;
	typedef signed __int64			int64;
	typedef unsigned __int64		uint64;
#endif


#ifdef _STLP_HASH_MAP
	#define HashMap ::std::hash_map
#else
	#define HashMap ::stdext::hash_map
#endif