#include "iostream"
#include "IniFile.h"


int main()
{

    IniFile *iniFile = new IniFile();

    iniFile->setIniFileName("Boot");
    try{
        iniFile->writeString("boot loader", "Default", "Windows 10");
        iniFile->writeInteger("boot loader", "Timeout", 30);
        iniFile->writeFloat("boot loader", "RunExec", 15.82);
        iniFile->writeBoolean("operating system", "NoExec", false);
        iniFile->writeString("operating system", "OS", "Windows XP Home Edition");
    } catch (std::logic_error &e) {
        std::cout<<e.what()<<std::endl;
    }

    //iniFile->removeKey("boot loader","RunExec");
    //iniFile->removeSection("boot loader");
    //iniFile->setIniFileName("Init");
    //iniFile->writeInteger("boot loader", "Timeout", 25);

    std::string fileName = iniFile->getIniFileName();
    try {
        iniFile->readSection("boot loader");
    } catch (std::logic_error &e) {
        std::cout<<e.what()<<std::endl;
    }
    try{
        std::string szDefault = iniFile->readString("boot loader", "Default", "Def");
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
    }catch (std::logic_error &e){
        std::cout<<e.what()<<std::endl;
    }


    //iniFile->printMapElements();

    delete iniFile;

    return 0;
}
