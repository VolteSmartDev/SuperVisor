#include "qglobal.h"
#include <QtNetwork\QNetworkInterface>
 
int char2int(char ch);
char* GenLicenseKey(char *pKey);
QString GenMD5LicenKey(char *pKey);
char* GetMacAddress();
int char2int(char ch);
bool BuildExpectInfo(char* inbuf, char* outbuf);
char * GetComputerProductKey();
char* DecryptDate(char *eKey, char *pKey);
int ConfigKey(char *eKey, char *pKey);