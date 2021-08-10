#include "iostream"
#include "IniFile.h"


int main()
{

    IniFile *iniFile = new IniFile();

    iniFile->setIniFileName("Boot");
    iniFile->writeString("boot loader", "Default", "WINDOWS");
    iniFile->writeInteger("boot loader", "Timeout", 30);
    iniFile->writeFloat("boot loader", "RunExec", 15.82);
    iniFile->writeBoolean("operating system", "NoExec", false);
    iniFile->writeString("operating system", "OS", "Windows XP Home Edition");
    //iniFile->removeKey("boot loader","Default");
    //iniFile->removeSection("operating system");


    std::string fileName = iniFile->getIniFileName();
    std::string szDefault = iniFile->readString("boot loader", "Default", "");
    int iTimeout = iniFile->readInteger("boot loader", "Timeout", 10);
    float fltRunExec = iniFile->readFloat("boot loader", "RunExec", 1.80);
    std::string bNoExec = iniFile->readBoolean("operating system", "NoExec", true);
    std::string szOS = iniFile->readString("operating system", "OS", "Windows Vista");

    std::cout<<"File Name: "<<fileName<<std::endl
             <<"Default OS: "<<szDefault<<std::endl
             <<"Timeout: "<<iTimeout<<std::endl
             <<"Run Execution: "<<fltRunExec<<std::endl
             <<"No Execution: "<<bNoExec<<std::endl
             <<"Operating System: "<<szOS<<std::endl;

    delete iniFile;

    return 0;
}
