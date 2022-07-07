#include "Security_Custom.h"
#include <QtNetwork\QNetworkInterface>
#include <qobject.h>
#include <qdatetime.h>
#include <QCryptographicHash>


char* GenLicenseKey(char *pKey)
{
	int ServerPwd[] = { 3, 7, 11, 13, 17, 19, 29, 31, 37, 43 };
	static char strbuf[] = "IJKLMBCDEFGHNOPQRSTZ012345UVWXYA6789";

	int len = strlen(pKey);
	char * buf = new char[64];
	memset(buf, 0, 64);

	int bufid = 0;

	for (int i = 0; i<len; i++)
	{
		char c;

		if (pKey[i] == '-') {
			buf[i] = '-';
			continue;
		}
		c = pKey[i];
		bufid = c * ServerPwd[i % 10];
		buf[i] = strbuf[(bufid) % 36];
	}

	return buf;
}

QString GenMD5LicenKey(char *pKey)
{
	char *licensekey = GenLicenseKey(pKey);
	
	QByteArray byte = QCryptographicHash::hash(licensekey, QCryptographicHash::Md5).toHex();
	
	return QString(byte).right(24);
}

char* GetMacAddress() {
	QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
	QString hdAddr = "00:34:AE:K3:B4:C5";
    foreach (QNetworkInterface curInterface , interfaces)
	{
		if (curInterface.humanReadableName() == "Local Area Connection" || curInterface.humanReadableName() == "Ethernet") {
			hdAddr = curInterface.hardwareAddress();
			break;
		}
	}
	char * aa = new char[hdAddr.length()+1];
	strcpy(aa, hdAddr.toLatin1());
	return aa;
}

char* DecryptDate(char *eKey, char *pKey)
{
	int ServerPwd[] = { 3, 7, 11, 13, 17, 19, 29, 31, 37, 43 };
	static char strbuf[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

	int len = strlen(eKey);
	char * buf = new char[64];
	memset(buf, 0, 64);
	int id = 0;
	for (int i = 10; i<len; i++)
	{
		char c = eKey[i];
		if (c == '-')
		{
			continue;
		}
		
		int curId = 0;
		for (int j = 0; j < 36; j++)
		{
			if (strbuf[j] == c) {
				curId = j;
				break;
			}
		}

		while (curId / (ServerPwd[i % 10] * pKey[i]) < 48 || curId % (ServerPwd[i % 10] * pKey[i]) > 0) {
			if (curId > 348300)
				return buf;
			curId += 36;
		}

		int curCId = curId / (ServerPwd[i % 10] * pKey[i]);

		buf[id++] = (char)curCId;
	}
	return buf;
}

int ConfigKey(char *eKey, char *pKey) {

	//![1] config computer serial, if true, continue date confirm, else return 0
	char *lKey = new char[64];
	memset(lKey, 0, 64);
	lKey = GenLicenseKey(pKey);
	
	for (int i = 0; i < 9; i++)
	{
		if (eKey[i] != lKey[i])
			return 0;
	}
	//![1]

	//![2] config code, if true, contine date confirm, else return 0
	char *theDate = new char[64];
	memset(theDate, 0, 64);
	strcpy(theDate, DecryptDate(eKey, pKey));
	int len = strlen(theDate);
	if (len != 8) return 0;
	
	QString DateCode(theDate);

	QString qCodeStr = DateCode.mid(6);
	if (qCodeStr.toInt() != 59 && qCodeStr.toInt() != 99)
		return 0;
	//![2]

	//![3] config date, if true but expired, return -1, true return daystocurrent, if true and full return 2;
	int theY = QObject::tr("20%1").arg(DateCode.mid(0, 2)).toInt();
	int theM = DateCode.mid(2, 2).toInt();
	int theD = DateCode.mid(4, 2).toInt();

	if (theY < 2000 || theY > 2099) return 0;
	if (theM < 0 || theM > 12) return 0;
	if (theD < 0 || theD > 31) return 0;

	QDate thisDate = QDate::fromString(QObject::tr("%1/%2/%3").arg(theY).arg(theM).arg(theD), "yyyy/M/dd");
	QDate curDate = QDate::currentDate();

	thisDate = thisDate.addMonths(3);

	int daysToCurrent = curDate.daysTo(thisDate);

	if (qCodeStr.toInt() == 59 && daysToCurrent <= 0) return -1;
	if (qCodeStr.toInt() == 99) return 2;
	if (qCodeStr.toInt() == 59 && daysToCurrent > 0) return daysToCurrent;
	//![3]
	//// 
	//// id date is not configured return 1

	//strcmp()
	return 0;
}

int char2int(char ch)
{
	int id = 0;
	switch (ch)
	{
	case '0': id = 0; break;
	case '1': id = 1; break;
	case '2': id = 2; break;
	case '3': id = 3; break;
	case '4': id = 4; break;
	case '5': id = 5; break;
	case '6': id = 6; break;
	case '7': id = 7; break;
	case '8': id = 8; break;
	case '9': id = 9; break;
	case 'a': case 'A': id = 10; break;
	case 'b': case 'B': id = 11; break;
	case 'c': case 'C': id = 12; break;
	case 'd': case 'D': id = 13; break;
	case 'e': case 'E': id = 14; break;
	case 'f': case 'F': id = 15; break;
	case 'g': case 'G': id = 16; break;
	case 'h': case 'H': id = 17; break;
	case 'i': case 'I': id = 18; break;
	case 'j': case 'J': id = 19; break;
	case 'k': case 'K': id = 20; break;
	case 'l': case 'L': id = 21; break;
	case 'm': case 'M': id = 22; break;
	case 'n': case 'N': id = 23; break;
	case 'o': case 'O': id = 24; break;
	case 'p': case 'P': id = 25; break;
	case 'q': case 'Q': id = 26; break;
	case 'r': case 'R': id = 27; break;
	case 's': case 'S': id = 28; break;
	case 't': case 'T': id = 29; break;
	case 'u': case 'U': id = 30; break;
	case 'v': case 'V': id = 31; break;
	case 'w': case 'W': id = 32; break;
	case 'x': case 'X': id = 33; break;
	case 'y': case 'Y': id = 34; break;
	case 'z': case 'Z': id = 35; break;
	default: id = 0; break;
	}
	return id;
}

bool BuildExpectInfo(char* inbuf, char* outbuf)
{
	int id = 0, i;
	char *p;

	static char strbuf[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA9876543210";

	if (!inbuf) return false;
	if (!outbuf) return false;
	if (strcmp(inbuf, "") == 0) return false;

	p = inbuf;
	int nOutIndex = 0;
	for (i = 0; i < 16; i++)
	{
		if (i % 4 == 0 && i != 0)
		{
			outbuf[i + nOutIndex] = '-';
			nOutIndex++;
		}
		id = (id + 3) * 7;
		id %= 20000;
		if (*(p + 1)) {
			id += char2int(*p) * char2int(*(p + 1));
			p++;
		}
		else
		{
			id += char2int(*p);
			p = inbuf;
		}
		outbuf[i + nOutIndex] = strbuf[id % 34];
	}
	return true;
}

char * GetComputerProductKey()
{
	char deviceID[64];
	char * serial = new char[64];

	memset(deviceID, 0, 64);
	memset(serial, 0, 64);

	strcpy(deviceID, GetMacAddress());

	BuildExpectInfo(deviceID, serial);
	return serial;
}
