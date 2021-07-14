//
// Created by gabqu on 14/07/2021.
//

#include <gtest/gtest.h>

#include "../IniWriter.h"
#include "../IniReader.h"

TEST(IniTest, DefaultConstructor)
{
    IniWriter iw;
    IniReader ir;
    ASSERT_EQ(".\\Logger.ini", iw.getIniFileName());
    ASSERT_EQ(".\\Logger.ini", ir.getIniFileName());
}

TEST(IniTest, Constructor)
{
    IniWriter iw(".\\Logger.ini");
    IniReader ir(".\\Logger.ini");
    ASSERT_EQ(".\\Logger.ini",iw.getIniFileName());
    ASSERT_EQ(".\\Logger.ini",ir.getIniFileName());
}

TEST(IniTest, SetConstructor)
{
    IniWriter iw;
    IniReader ir;
    iw.setIniFileName(".\\Logger.ini");
    ir.setIniFileName(".\\Logger.ini");
    ASSERT_EQ(".\\Logger.ini",iw.getIniFileName());
    ASSERT_EQ(".\\Logger.ini",ir.getIniFileName());
}