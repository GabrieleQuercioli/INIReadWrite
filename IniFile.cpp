//
// Created by gabqu on 14/07/2021.
//

#include "IniFile.h"
#include <iostream>
#include <Windows.h>
#include <vector>


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
    section.emplace(szKey, std::pair<std::string, std::string> (szValue, szSection));
    WritePrivateProfileString(szSection.c_str(), szKey.c_str(), szValue.c_str(), m_szFileName.c_str());
}

void IniFile::writeFloat(std::string szSection, std::string szKey, float fltValue)
{
    std::string szValue = std::to_string(fltValue);
    section.emplace(szKey, std::pair<std::string, std::string> (szValue, szSection));
    WritePrivateProfileString(szSection.c_str(),  szKey.c_str(), szValue.c_str(), m_szFileName.c_str());
}

void IniFile::writeBoolean(std::string szSection, std::string szKey, bool bolValue)
{
    std::string szValue = bolValue ? "True" : "False";
    section.emplace(szKey, std::pair<std::string, std::string> (szValue, szSection));
    WritePrivateProfileString(szSection.c_str(),  szKey.c_str(), szValue.c_str(), m_szFileName.c_str());
}

void IniFile::writeString(std::string szSection, std::string szKey, std::string szValue)
{
    if(szValue.empty() || szKey.empty() || szSection.empty())
        throw std::logic_error("Invalid argument");  //is right to be an exception?
    section.emplace(szKey, std::pair<std::string, std::string> (szValue, szSection));
    WritePrivateProfileString(szSection.c_str(),  szKey.c_str(), szValue.c_str(), m_szFileName.c_str());
}

int IniFile::readInteger(std::string szSection, std::string szKey, int iDefaultValue)
{
    char szResult[255];
    std::string szDefault = std::to_string(iDefaultValue);
    GetPrivateProfileString(szSection.c_str(),  szKey.c_str(), szDefault.c_str(), szResult, 255, m_szFileName.c_str());
    for (auto it = section.cbegin(); it != section.cend(); ++it)
    {
        if (strcmp(szResult, it->second.first.c_str()) == 0) {
            int intResult = atoi(it->second.first.c_str());
            return intResult;
        }
    }
    throw std::invalid_argument("Result doesn't exists anymore");
}

float IniFile::readFloat(std::string szSection, std::string szKey, float fltDefaultValue)
{
    char szResult[255];
    std::string szDefault = std::to_string(fltDefaultValue);
    GetPrivateProfileString(szSection.c_str(),  szKey.c_str(), szDefault.c_str(), szResult, 255, m_szFileName.c_str());
    for (auto it = section.cbegin(); it != section.cend(); ++it)
    {
        if (strcmp(szResult, it->second.first.c_str()) == 0) {
            float fltResult = atof(it->second.first.c_str());
            return fltResult;
        }
    }
    throw std::invalid_argument("Result doesn't exists anymore");
}

std::string IniFile::readBoolean(std::string szSection, std::string szKey, bool boolDefaultValue)
{
    char szResult[255];
    std::string szDefault = boolDefaultValue ? "True" : "False";
    GetPrivateProfileString(szSection.c_str(), szKey.c_str(), szDefault.c_str(), szResult, 255, m_szFileName.c_str());
    for (auto it = section.cbegin(); it != section.cend(); ++it)
    {
        if (strcmp(szResult, it->second.first.c_str()) == 0)
            return it->second.first;
    }
    throw std::invalid_argument("Result doesn't exists anymore");
}

std::string IniFile::readString(std::string szSection, std::string szKey, std::string szDefault)
{
    char szResult[255];
    GetPrivateProfileString(szSection.c_str(), szKey.c_str(), szDefault.c_str(), szResult, 255, m_szFileName.c_str());
    for (auto it = section.cbegin(); it != section.cend(); ++it)
    {
        if (strcmp(szResult, it->second.first.c_str()) == 0)
            return it->second.first;
    }
    throw std::invalid_argument("Result doesn't exists anymore");
}

void IniFile::readSection(std::string szSection)
{
    bool find = false;
    for(auto it = section.cbegin(); it != section.cend(); ++it){
        if (strcmp(szSection.c_str(), it->second.second.c_str()) == 0)
            find = true;
    }
    if (!find) {
        throw std::invalid_argument("Insert an existent Section name");
    }
    else {
        std::vector<std::string> nameValuePairs;
        const int bufferSize = 1000;
        char buffer[bufferSize] = "";
        int charsRead;

        charsRead = GetPrivateProfileSection(szSection.c_str(), buffer, bufferSize, m_szFileName.c_str());

        if( (0 < charsRead) && ((bufferSize - 2) > charsRead) )
        {
            const char* pSubstr = buffer;
            while('\0' != *pSubstr)
            {
                size_t substrLen = strlen(pSubstr);           //size_t is unsigned int type
                const char* pos = strchr(pSubstr, '=');
                if(NULL != pos)
                {
                    nameValuePairs.emplace_back(pSubstr);
                }
                pSubstr += (substrLen + 1);
            }
        }
        std::cout << "[" << szSection << "]" << std::endl;
        for (auto it = nameValuePairs.cbegin(); it != nameValuePairs.cend(); ++it)
        {
            std::cout << it->c_str() << ";" << std::endl;
        }
    }
}

void IniFile::removeSection(std::string szSection)     //while struct because erase(key) but section
{                                                      //is not a key
    auto it = section.cbegin();
    while (it != section.cend()){
        if(strcmp(szSection.c_str(), it->second.second.c_str()) == 0){
            it = section.erase(it);                   // iterator doesn't run out of scope with it=
        }
        else{
            ++it;
        }
    }
    WritePrivateProfileString(szSection.c_str(),NULL,NULL,m_szFileName.c_str());
}

void IniFile::removeKey(std::string szSection,  std::string szKey)
{
    section.erase(szKey);
    WritePrivateProfileString(szSection.c_str(),szKey.c_str(),NULL,m_szFileName.c_str());
}

void IniFile::printMapElements() {
    for(auto it = section.cbegin(); it != section.cend(); ++it)
    {
        std::cout << "((" << it->first << ", " << it->second.first << "), " << it->second.second << ");" <<std::endl;
    }
}
