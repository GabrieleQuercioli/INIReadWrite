//
// Created by gabqu on 14/07/2021.
//

#ifndef INIFILE_H
#define INIFILE_H

#include "string"
#include <map>

class IniFile
{
public:
    IniFile();
    explicit IniFile(std::string fileName);
    void setIniFileName(std::string name);
    std::string getIniFileName();
    void writeInteger(std::string sectionName, std::string key, int iValue);
    void writeFloat(std::string sectionName, std::string key, float fltValue);
    void writeBoolean(std::string sectionName, std::string key, bool bolValue);
    void writeString(std::string sectionName, std::string key, std::string value);
    int readInteger(std::string sectionName, std::string key, int iDefaultValue);
    float readFloat(std::string sectionName, std::string key, float fltDefaultValue);
    std::string readBoolean(std::string sectionName, std::string key, bool bolDefaultValue);
    std::string readString(std::string sectionName, std::string key, std::string defaultValue);
    void readSection(std::string sectionName);
    void removeSection(std::string sectionName);
    void removeKey(std::string sectionName, std::string key);
    void printMapElements();

private:
    std::string fileName;
    std::map<std::string, std::pair<std::string, std::string>> section;
    //key=key and value=pair(szValue,sectionName)
};

#endif //INIFILE_H
