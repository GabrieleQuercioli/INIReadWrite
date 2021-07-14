//
// Created by gabqu on 14/07/2021.
//

#include "IniWriter.h"
#include <iostream>
#include <Windows.h>

IniWriter::IniWriter()
{
    const char* dc = ".\\Logger.ini";
    memcpy(this->m_szFileName, dc, strlen(dc));
    delete dc;
}

IniWriter::IniWriter(const char* szFileName)
{
    memset(m_szFileName, 0x00, 255);
    memcpy(m_szFileName, szFileName, strlen(szFileName));
}

void IniWriter::setIniFileName(const char *szName)
{
    memcpy(this->m_szFileName, szName, strlen(szName));
}

char* IniWriter::getIniFileName()
{
    return this->m_szFileName;
}

void IniWriter::writeInteger(const char* szSection, const char*  szKey, int iValue)
{
    char szValue[255];
    sprintf(szValue, "%d", iValue);
    WritePrivateProfileString(szSection,  szKey, szValue, this->m_szFileName);
}
void IniWriter::writeFloat(const char* szSection, const char* szKey, float fltValue)
{
    char szValue[255];
    sprintf(szValue, "%f", fltValue);
    WritePrivateProfileString(szSection,  szKey, szValue, m_szFileName);
}
void IniWriter::writeBoolean(const char* szSection, const char* szKey, bool bolValue)
{
    char szValue[255];
    sprintf(szValue, "%s", bolValue ? "True" : "False");
    WritePrivateProfileString(szSection,  szKey, szValue, m_szFileName);
}
void IniWriter::writeString(const char* szSection, const char* szKey, const char* szValue)
{
    WritePrivateProfileString(szSection,  szKey, szValue, m_szFileName);
}

IniWriter::~IniWriter()
{
    const char* d = "";
    memcpy(m_szFileName, d, strlen(d));
    delete d;
}