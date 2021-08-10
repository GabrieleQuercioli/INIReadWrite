//
// Created by gabqu on 14/07/2021.
//

#include <gtest/gtest.h>

#include "../IniFile.h"


class IniFileSuite : public testing::Test {

protected:
    virtual void SetUp() {
        iw.setIniFileName("Test");

    }
    IniFile iw;

};

TEST_F(IniFileSuite, TestSetString)
{
    iw.writeString("section", "keyS", "value");
    ASSERT_EQ("value", iw.readString("section", "keyS", "error"));
}

TEST_F(IniFileSuite, TestSetFloat)
{
    iw.writeFloat("section", "keyF", 1.8);
    ASSERT_FLOAT_EQ(1.8, iw.readFloat("section", "keyF", 0.2));
}

TEST_F(IniFileSuite, TestSetInt)
{
    iw.writeInteger("section", "keyI", 20);
    ASSERT_EQ(20, iw.readInteger("section", "keyI", 10));
}

TEST_F(IniFileSuite, TestSetBoolean)
{
    iw.writeBoolean("section", "keyB", false);
    ASSERT_EQ("False",iw.readBoolean("section", "keyB", true));
}

TEST_F(IniFileSuite, TestRemoveSection)
{
    iw.writeString("section", "KeyS", "value");
    iw.writeInteger("section", "KeyI", 20);
    iw.removeSection("section");
    ASSERT_NE("value", iw.readString("section", "KeyS", "default"));
    ASSERT_NE(20, iw.readInteger("section", "KeyI", 10));
}

TEST_F(IniFileSuite, TestRemoveKey)
{
    iw.writeInteger("section", "KeyI", 20);
    iw.removeKey("section", "KeyI");
    ASSERT_NE(20, iw.readInteger("section", "KeyI", 10));
}