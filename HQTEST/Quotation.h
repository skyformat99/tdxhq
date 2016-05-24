#pragma once
#include "redisclient.h"

extern "C"
{
#include "sqlite3.h"
};

typedef struct _stockcode
{
	char code[7];
	char market[2];
}
STOCKCODE;

// CQuotation

class CQuotation : public CWinThread
{
	DECLARE_DYNCREATE(CQuotation)

protected:
public:	
	CQuotation();
	CQuotation(DWORD dwID, STOCKCODE * pStockCode, int iStockNum );           // 动态创建所使用的受保护的构造函数
	virtual ~CQuotation();


	virtual BOOL InitInstance();
	virtual int ExitInstance();
	BOOL g_bGetQuotation;

	int m_iStockNum;
	STOCKCODE m_stockcode[ 400 ];

	DWORD m_dwID;
	int conID;

	redis::client *redis;//& c

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual int Run();
};


