//
// Created by gabqu on 14/07/2021.
//

#include "IniReader.h"
#include <iostream>
#include <Windows.h>

IniReader::IniReader()
{
    const char* dc = ".\\Logger.ini";
    memcpy(this->m_szFileName, dc, strlen(dc));
    delete dc;
}

IniReader::IniReader(const char* szFileName)
{
    memset(m_szFileName, 0x00, 255);
    memcpy(m_szFileName, szFileName, strlen(szFileName));
}

void IniReader::setIniFileName(const char *szName)
{
    memcpy(this->m_szFileName, szName, strlen(szName));
}

char* IniReader::getIniFileName()
{
    return this->m_szFileName;
}

int IniReader::readInteger(const char* szSection, const char* szKey, int iDefaultValue)
{
    int iResult = GetPrivateProfileInt(szSection,  szKey, iDefaultValue, m_szFileName);
    return iResult;
}
float IniReader::readFloat(const char* szSection, const char* szKey, float fltDefaultValue)
{
    char szResult[255];
    char szDefault[255];
    float fltResult;
    sprintf(szDefault, "%f",fltDefaultValue);
    GetPrivateProfileString(szSection,  szKey, szDefault, szResult, 255, m_szFileName);
    fltResult =  atof(szResult);
    return fltResult;
}
bool IniReader::readBoolean(const char* szSection, const char* szKey, bool boolDefaultValue)
{
    char szResult[255];
    char szDefault[255];
    bool boolResult;
    sprintf(szDefault, "%s", boolDefaultValue? "True" : "False");
    GetPrivateProfileString(szSection, szKey, szDefault, szResult, 255, m_szFileName);
    boolResult = (strcmp(szResult, "True") == 0 ||
                  strcmp(szResult, "true") == 0);
    return boolResult;
}
char* IniReader::readString(const char* szSection,const char* szKey, const char* szDefaultValue)
{
    char* szResult = new char[255];
    memset(szResult, 0x00, 255);
    GetPrivateProfileString(szSection,  szKey, szDefaultValue, szResult, 255, m_szFileName);
    return szResult;
}

IniReader::~IniReader()
{
    const char* p = "";
    strcpy(m_szFileName,p);
    delete p;
}
