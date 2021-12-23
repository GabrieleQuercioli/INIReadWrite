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
    explicit IniFile(const std::string& fileName);
    void setIniFileName(const std::string& name);
    std::string getIniFileName();
    void writeInteger(const std::string& sectionName, const std::string& key, int iValue);
    void writeFloat(const std::string& sectionName, const std::string& key, float fltValue);
    void writeBoolean(const std::string& sectionName, const std::string& key, bool bolValue);
    void writeString(const std::string& sectionName, const std::string& key, const std::string& value);
    int readInteger(const std::string& sectionName, const std::string& key, int iDefaultValue) const;
    float readFloat(const std::string& sectionName, const std::string& key, float fltDefaultValue) const;
    std::string readBoolean(const std::string& sectionName, const std::string& key, bool bolDefaultValue) const;
    std::string readString(const std::string& sectionName, const std::string& key, const std::string& defaultValue) const;
    void readSection(const std::string& sectionName) const;
    void removeSection(const std::string& sectionName);
    void removeKey(const std::string& sectionName, const std::string& key);
    void printMapElements() const;

private:
    std::string fileName;
    std::map<std::string, std::pair<std::string, std::string>> section;
    //In map: key=key and value=pair(Value,sectionName)
};

#endif //INIFILE_H
