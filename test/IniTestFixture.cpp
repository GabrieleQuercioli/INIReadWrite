//
// Created by gabqu on 14/07/2021.
//

#include <gtest/gtest.h>

#include "../IniWriter.h"
#include "../IniReader.h"

class IniFileSuite : public testing::Test {

protected:
    virtual void SetUp() {
        iw.setIniFileName(".\\Test.ini");
        ir.setIniFileName(".\\Test.ini");
    }
    IniWriter iw;
    IniReader ir;
};

TEST_F(IniFileSuite, TestSetString)
{
    iw.writeString("section", "keyS", "value");
    ASSERT_EQ("value", ir.readString("section", "keyS", "error"));
}

TEST_F(IniFileSuite, TestSetFloat)
{
    iw.writeFloat("section", "keyF", 1.8);
    ASSERT_EQ(1.8, ir.readFloat("section", "keyF", 0.2));
}

TEST_F(IniFileSuite, TestSetInt)
{
    iw.writeInteger("section", "keyI", 20);
    ASSERT_EQ(20, ir.readInteger("section", "key", 10));
}

TEST_F(IniFileSuite, TestSetBoolean)
{
    iw.writeBoolean("section", "keyB", false);
    ASSERT_FALSE(ir.readBoolean("section", "keyB", true));
}