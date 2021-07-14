//
// Created by gabqu on 14/07/2021.
//

#ifndef INIWRITER_H
#define INIWRITER_H

class IniWriter
{
public:
    IniWriter();
    explicit IniWriter(const char* szFileName);
    ~IniWriter();
    void setIniFileName(const char* szName);
    char* getIniFileName();
    void writeInteger(const char* szSection, const char* szKey, int iValue);
    void writeFloat(const char* szSection, const char* szKey, float fltValue);
    void writeBoolean(const char* szSection, const char* szKey, bool bolValue);
    void writeString(const char* szSection, const char* szKey, const char* szValue);

private:
    char m_szFileName[255];
};

#endif //INIWRITER_H
