#include "iostream"
#include "IniWriter.h"
#include "IniReader.h"
int main()
{

    IniWriter *iniWriter = new IniWriter(".\\Boot.ini");

    iniWriter->writeString("boot loader", "Default", "WINDOWS");
    iniWriter->writeInteger("boot loader", "Timeout", 30);
    iniWriter->writeFloat("boot loader", "RunExec", 15.82);
    iniWriter->writeBoolean("operating system", "NoExec", false);
    iniWriter->writeString("operating system", "OS", "Windows XP Home Edition");
    /*iniWriter->setIniFileName(".\\Init.ini");
    iniWriter->writeInteger("boot loader", "Timeout", 22);*/


    IniReader *iniReader = new IniReader(".\\Boot.ini");

    char *fileName = iniReader->getIniFileName();
    char *szDefault = iniReader->readString("boot loader", "Default", "");
    int iTimeout = iniReader->readInteger("boot loader", "Timeout", 10);
    float fltRunExec = iniReader->readFloat("boot loader", "RunExec", 1.80);
    bool bNoExec = iniReader->readBoolean("operating system", "NoExec", true);
    char *szOS = iniReader->readString("operating system", "OS", "Windows Vista");

    std::cout<<"File Name: "<<fileName<<std::endl
             <<"Default OS: "<<szDefault<<std::endl
             <<"Timeout: "<<iTimeout<<std::endl
             <<"Run Execution: "<<fltRunExec<<std::endl
             <<"No Execution: "<<bNoExec<<std::endl
             <<"Operating System: "<<szOS<<std::endl;

    delete[] szDefault; //why?
    delete[] szOS;
    delete[] fileName;


    return 0;


}
