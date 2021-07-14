//
// Created by gabqu on 14/07/2021.
//

#ifndef INIREADER_H
#define INIREADER_H


class IniReader
{
public:
    IniReader();
    explicit IniReader(const char* szFileName);
    ~IniReader();
    void setIniFileName(const char* szName);
    char* getIniFileName();
    int readInteger(const char* szSection, const char* szKey, int iDefaultValue);
    float readFloat(const char* szSection, const char* szKey, float fltDefaultValue);
    bool readBoolean(const char* szSection, const char* szKey, bool bolDefaultValue);
    char* readString(const char* szSection, const char* szKey, const char* szDefaultValue);
private:
    char m_szFileName[255]{};
};


#endif //INIREADER_H
