//
// Created by gabqu on 14/07/2021.
//

#ifndef INIFILE_H
#define INIFILE_H

#include "string"
#include <vector>
#include <map>

class IniFile
{
public:
    IniFile();
    explicit IniFile(std::string m_szFileName);
    void setIniFileName(std::string szName);
    std::string getIniFileName();
    void writeInteger(std::string szSection, std::string szKey, int iValue);
    void writeFloat(std::string szSection, std::string szKey, float fltValue);
    void writeBoolean(std::string szSection, std::string szKey, bool bolValue);
    void writeString(std::string szSection, std::string szKey, std::string szValue);
    int readInteger(std::string szSection, std::string szKey, int iDefaultValue);
    float readFloat(std::string szSection, std::string szKey, float fltDefaultValue);
    std::string readBoolean(std::string szSection, std::string szKey, bool bolDefaultValue);
    std::string readString(std::string szSection, std::string szKey, std::string szString);
    void readSection(std::string szSection);
    void removeSection(std::string szSection);
    void removeKey(std::string szSection, std::string szKey);
    void printMapElements();

private:
    std::string m_szFileName;
    std::vector<std::string> sections;
    std::map<std::string, std::pair<std::string, std::string>> section;
};

#endif //INIFILE_H
