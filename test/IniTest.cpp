//
// Created by gabqu on 14/07/2021.
//

#include <gtest/gtest.h>

#include "../IniFile.h"


TEST(IniTest, DefaultConstructor)
{
    IniFile iw;
    ASSERT_EQ(".\\Untitled.ini", iw.getIniFileName());
}

TEST(IniTest, Constructor)
{
    IniFile iw("Logger");
    ASSERT_EQ(".\\Logger.ini",iw.getIniFileName());
}

TEST(IniTest, SetConstructor)
{
    IniFile iw;
    iw.setIniFileName("Logger");
    ASSERT_EQ(".\\Logger.ini",iw.getIniFileName());
}