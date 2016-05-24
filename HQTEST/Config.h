#pragma once
#include "StdAfx.h"
#include <vector>

class CConfig
{
public:
	CConfig(void);
	~CConfig(void);

	CString m_csDataPath;

	CString g_cs_mysql_host;
	DWORD g_cs_mysql_port;
	CString g_cs_mysql_user;
	CString g_cs_mysql_password;
	CString g_cs_mysql_dbname;
};
