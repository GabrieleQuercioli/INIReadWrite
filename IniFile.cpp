//
// Created by gabqu on 14/07/2021.
//

#include "IniFile.h"
#include <iostream>
#include <Windows.h>

IniFile::IniFile()
{
    m_szFileName = ".\\Untitled.ini";
}

IniFile::IniFile(std::string szFileName)
{
    m_szFileName = ".\\"+szFileName+".ini";
}

void IniFile::setIniFileName(std::string szName)
{
    if(strcmp(m_szFileName.c_str(),szName.c_str()) != 0) {
        std::string newName = szName+".ini";
        rename(m_szFileName.c_str(), newName.c_str());
    }
    m_szFileName = ".\\"+szName+".ini";
}

std::string IniFile::getIniFileName()
{
    return m_szFileName;
}

void IniFile::writeInteger(std::string szSection, std::string  szKey, int iValue)
{
    std::string szValue = std::to_string(iValue);
    WritePrivateProfileString(szSection.c_str(), szKey.c_str(), szValue.c_str(), m_szFileName.c_str());
}

void IniFile::writeFloat(std::string szSection, std::string szKey, float fltValue)
{
    std::string szValue = std::to_string(fltValue);
    WritePrivateProfileString(szSection.c_str(),  szKey.c_str(), szValue.c_str(), m_szFileName.c_str());
}

void IniFile::writeBoolean(std::string szSection, std::string szKey, bool bolValue)
{
    std::string szValue = bolValue ? "True" : "False";
    WritePrivateProfileString(szSection.c_str(),  szKey.c_str(), szValue.c_str(), m_szFileName.c_str());
}

void IniFile::writeString(std::string szSection, std::string szKey, std::string szValue)
{
    WritePrivateProfileString(szSection.c_str(),  szKey.c_str(), szValue.c_str(), m_szFileName.c_str());
}

int IniFile::readInteger(std::string szSection, std::string szKey, int iDefaultValue)
{
    int iResult = GetPrivateProfileInt(szSection.c_str(),  szKey.c_str(), iDefaultValue, m_szFileName.c_str());
    return iResult;
}

float IniFile::readFloat(std::string szSection, std::string szKey, float fltDefaultValue)
{
    char szResult[255];
    std::string szDefault = std::to_string(fltDefaultValue);
    float fltResult;
    GetPrivateProfileString(szSection.c_str(),  szKey.c_str(), szDefault.c_str(), szResult, 255, m_szFileName.c_str());
    fltResult =  atof(szResult);
    return fltResult;
}

std::string IniFile::readBoolean(std::string szSection, std::string szKey, bool boolDefaultValue)
{
    char szResult[255];
    std::string szDefault = boolDefaultValue ? "True" : "False";
    GetPrivateProfileString(szSection.c_str(), szKey.c_str(), szDefault.c_str(), szResult, 255, m_szFileName.c_str());
    return szResult;
}

std::string IniFile::readString(std::string szSection, std::string szKey, std::string szDefaultValue)
{
    char szResult[255];
    memset(szResult, 0x00, 255);
    GetPrivateProfileString(szSection.c_str(),  szKey.c_str(), szDefaultValue.c_str(), szResult, 255, m_szFileName.c_str());
    return szResult;
}

void IniFile::removeSection(std::string szSection)
{
    WritePrivateProfileString(szSection.c_str(),NULL,NULL,m_szFileName.c_str());
}

void IniFile::removeKey(std::string szSection, std::string szKey)
{
    WritePrivateProfileString(szSection.c_str(),szKey.c_str(),NULL,m_szFileName.c_str());
}
