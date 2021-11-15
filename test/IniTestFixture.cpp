//
// Created by gabqu on 14/07/2021.
//

#include <gtest/gtest.h>

#include "../IniFile.h"


class IniFileSuite : public testing::Test {

protected:
    virtual void SetUp() {
        iw.setIniFileName("Test");
        iw.writeInteger("sec1", "key1", 0);
        iw.writeString("sec1", "key2", "szValue");
        iw.writeFloat("sec2", "key3", 1.2);
        iw.writeBoolean("sec2", "key4", true);
    }
    IniFile iw;

};

TEST_F(IniFileSuite, TestMap)
{
    ASSERT_EQ(0, iw.readInteger("sec1", "key1", 10));
    ASSERT_EQ("szValue", iw.readString("sec1", "key2", "error"));
    ASSERT_FLOAT_EQ(1.2, iw.readFloat("sec2", "key3", 1.4));
    ASSERT_EQ("True", iw.readBoolean("sec2", "key4", false));
}

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
    EXPECT_THROW(iw.readString("section", "KeyS", "default"), std::logic_error);
    EXPECT_THROW(iw.readInteger("section", "KeyI", 10), std::logic_error);
}

TEST_F(IniFileSuite, TestRemoveKey)
{
    iw.writeInteger("section", "KeyI", 20);
    iw.removeKey("section", "KeyI");
    EXPECT_THROW(iw.readInteger("section", "KeyI", 10), std::logic_error);
}