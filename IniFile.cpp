//
// Created by gabqu on 14/07/2021.
//

#include "IniFile.h"
#include <iostream>
#include <Windows.h>
#include <vector>


IniFile::IniFile()
{
    fileName = ".\\Untitled.ini";
}

IniFile::IniFile(const std::string& name)
{
    fileName = ".\\"+name+".ini";
}

void IniFile::setIniFileName(const std::string& name)
{
    if(strcmp(fileName.c_str(),name.c_str()) != 0) {
        std::string newName = name+".ini";
        rename(fileName.c_str(), newName.c_str());
    }
    fileName = ".\\"+name+".ini";
}

std::string IniFile::getIniFileName()
{
    return fileName;
}

void IniFile::writeInteger(const std::string& sectionName, const std::string& key, int iValue)
{
    std::string value = std::to_string(iValue);
    section.emplace(key, std::pair<std::string, std::string> (value, sectionName));
    WritePrivateProfileString(sectionName.c_str(), key.c_str(), value.c_str(), fileName.c_str());
}

void IniFile::writeFloat(const std::string& sectionName, const std::string& key, float fltValue)
{
    std::string value = std::to_string(fltValue);
    section.emplace(key, std::pair<std::string, std::string> (value, sectionName));
    WritePrivateProfileString(sectionName.c_str(),  key.c_str(), value.c_str(), fileName.c_str());
}

void IniFile::writeBoolean(const std::string& sectionName, const std::string& key, bool bolValue)
{
    std::string value = bolValue ? "True" : "False";
    section.emplace(key, std::pair<std::string, std::string> (value, sectionName));
    WritePrivateProfileString(sectionName.c_str(),  key.c_str(), value.c_str(), fileName.c_str());
}

void IniFile::writeString(const std::string& sectionName, const std::string& key, const std::string& value)
{
    if(value.empty() || key.empty() || sectionName.empty())
        throw std::invalid_argument("Invalid argument");
    section.emplace(key, std::pair<std::string, std::string> (value, sectionName));
    WritePrivateProfileString(sectionName.c_str(),  key.c_str(), value.c_str(), fileName.c_str());
}

int IniFile::readInteger(const std::string& sectionName, const std::string& key, int iDefaultValue) const
{
    char result[255];
    std::string defaultValue = std::to_string(iDefaultValue);
    GetPrivateProfileString(sectionName.c_str(),  key.c_str(), defaultValue.c_str(), result, 255, fileName.c_str());
    for (auto it = section.cbegin(); it != section.cend(); ++it)
    {
        if (strcmp(result, it->second.first.c_str()) == 0) {
            int intResult = atoi(it->second.first.c_str());
            return intResult;
        }
    }
    throw std::invalid_argument("Result doesn't exists anymore");
}

float IniFile::readFloat(const std::string& sectionName, const std::string& key, float fltDefaultValue) const
{
    char result[255];
    std::string defaultValue = std::to_string(fltDefaultValue);
    GetPrivateProfileString(sectionName.c_str(),  key.c_str(), defaultValue.c_str(), result, 255, fileName.c_str());
    for (auto it = section.cbegin(); it != section.cend(); ++it)
    {
        if (strcmp(result, it->second.first.c_str()) == 0) {
            float fltResult = atof(it->second.first.c_str());
            return fltResult;
        }
    }
    throw std::invalid_argument("Result doesn't exists anymore");
}

std::string IniFile::readBoolean(const std::string& sectionName, const std::string& key, bool boolDefaultValue) const
{
    char result[255];
    std::string defaultValue = boolDefaultValue ? "True" : "False";
    GetPrivateProfileString(sectionName.c_str(), key.c_str(), defaultValue.c_str(), result, 255, fileName.c_str());
    for (auto it = section.cbegin(); it != section.cend(); ++it)
    {
        if (strcmp(result, it->second.first.c_str()) == 0 && strcmp(key.c_str(), it->first.c_str()) == 0)
            return it->second.first;
    }
    throw std::invalid_argument("Result doesn't exists anymore");
}

std::string IniFile::readString(const std::string& sectionName, const std::string& key, const std::string& defaultValue) const
{
    char result[255];
    GetPrivateProfileString(sectionName.c_str(), key.c_str(), defaultValue.c_str(), result, 255, fileName.c_str());
    for (auto it = section.cbegin(); it != section.cend(); ++it)
    {
        if (strcmp(result, it->second.first.c_str()) == 0)
            return it->second.first;
    }
    throw std::invalid_argument("Result doesn't exists anymore");
}

void IniFile::readSection(const std::string& sectionName) const
{
    bool find = false;
    for(auto it = section.cbegin(); it != section.cend(); ++it){
        if (strcmp(sectionName.c_str(), it->second.second.c_str()) == 0)
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

        charsRead = GetPrivateProfileSection(sectionName.c_str(), buffer, bufferSize, fileName.c_str());

        if( (0 < charsRead) && ((bufferSize - 2) > charsRead) )
        {
            const char* pSubstr = buffer;
            while('\0' != *pSubstr)
            {
                size_t substrLen = strlen(pSubstr);
                const char* pos = strchr(pSubstr, '=');
                if(nullptr != pos)
                {
                    nameValuePairs.emplace_back(pSubstr);
                }
                pSubstr += (substrLen + 1);
            }
        }
        std::cout << "[" << sectionName << "]" << std::endl;
        for (auto it = nameValuePairs.cbegin(); it != nameValuePairs.cend(); ++it)
        {
            std::cout << it->c_str() << ";" << std::endl;
        }
    }
}

void IniFile::removeSection(const std::string& sectionName)     //while structure because erase(key) but section
{                                                               //is not a key
    bool find = false;
    for(auto it = section.cbegin(); it != section.cend(); ++it){
        if (strcmp(sectionName.c_str(), it->second.second.c_str()) == 0)
            find = true;
    }
    if (!find) {
        throw std::invalid_argument("Insert an existent Section name");
    }
    auto it = section.cbegin();
    while (it != section.cend()){
        if(strcmp(sectionName.c_str(), it->second.second.c_str()) == 0){
            it = section.erase(it);                   // iterator doesn't run out of scope with it=
        }
        else{
            ++it;
        }
    }
    WritePrivateProfileString(sectionName.c_str(),NULL,NULL,fileName.c_str());
}

void IniFile::removeKey(const std::string& sectionName,  const std::string& key)
{
    bool find = false;
    for(auto it = section.cbegin(); it != section.cend(); ++it){
        if (strcmp(key.c_str(), it->first.c_str()) == 0)
            find = true;
    }
    if (!find) {
        throw std::invalid_argument("Insert an existent Section name");
    }
    section.erase(key);
    WritePrivateProfileString(sectionName.c_str(),key.c_str(),NULL,fileName.c_str());
}

void IniFile::printMapElements() const
{
    std::cout<<"\nI valori della mappa sono:"<<std::endl;
    for(auto it = section.cbegin(); it != section.cend(); ++it)
    {
        std::cout << "((" << it->first << ", " << it->second.first << "), " << it->second.second << ");" <<std::endl;
    }
}
