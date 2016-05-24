
#include "Config.h"

CConfig::CConfig(void)
{
	CString csExe;
	CString csPath;
	//下载文件到 .\proxy.dat
	char buf[MAX_PATH+1];
	GetModuleFileNameA( NULL , buf , MAX_PATH );
	csExe = buf;
	csExe = csExe.Left( csExe.ReverseFind( '\\') );
	csPath = csExe;

	CString csIni;
	csIni = csPath;
	csIni += "\\HQTEST.ini";
	
	CString csMode;
	::GetPrivateProfileString("GLOBAL","DataPath","D:\\", csMode.GetBuffer(MAX_PATH),MAX_PATH ,csIni.GetBuffer());
	m_csDataPath = csMode;

	::GetPrivateProfileString("GLOBAL","Mysql_host","", csMode.GetBuffer(MAX_PATH),MAX_PATH ,csIni.GetBuffer());
	g_cs_mysql_host = csMode;

	g_cs_mysql_port = ::GetPrivateProfileInt("GLOBAL","Mysql_port",3306,csIni.GetBuffer());

	::GetPrivateProfileString("GLOBAL","Mysql_user","", csMode.GetBuffer(MAX_PATH),MAX_PATH ,csIni.GetBuffer());
	g_cs_mysql_user = csMode;

	::GetPrivateProfileString("GLOBAL","Mysql_password","", csMode.GetBuffer(MAX_PATH),MAX_PATH ,csIni.GetBuffer());
	g_cs_mysql_password = csMode;

	::GetPrivateProfileString("GLOBAL","Mysql_dbname","", csMode.GetBuffer(MAX_PATH),MAX_PATH ,csIni.GetBuffer());
	g_cs_mysql_dbname = csMode;
}

CConfig::~CConfig(void)
{
}
