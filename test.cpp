#include <gtest/gtest.h>
#include <limits>
#include "interpreter.h"

TEST(Numbers_And_Command_Point, Correct_Work_Push_To_Stack) {
    std::string result = Interpreter::getInstance().interpret("5 -2 4 . . .");
    EXPECT_EQ(result, " 4 -2 5");
}

TEST(Numbers_And_Command_Point, Not_Command) {
    std::string result = Interpreter::getInstance().interpret("d4 4 . .");
    EXPECT_EQ(result, "\nno such command: 'd4'");
}

TEST(Numbers_And_Command_Point, Incorrect_Work_Add_Number) {
    std::string result = Interpreter::getInstance().interpret("5f 4 . .");
    EXPECT_EQ(result, "\nno such command: '5f'");
}

TEST(Numbers_And_Command_Point, No_Numbers_To_Stack) {
    std::string result = Interpreter::getInstance().interpret(".");
    EXPECT_EQ(result, "\nError point: not enough numbers");
}

// Add command

TEST(ArithCommand, Correct_Work_Add) {
    std::string result = Interpreter::getInstance().interpret("3 4 + .");
    EXPECT_EQ(result, " 7");
}

TEST(ArithCommand, Incorrect_Work_Add_One_Number) {
    std::string result = Interpreter::getInstance().interpret("1 + .");
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
    result = Interpreter::getInstance().interpret(".");
    EXPECT_EQ(result, " 1");
}

TEST(ArithCommand, Incorrect_Work_Add_No_Numbers) {
    std::string result = Interpreter::getInstance().interpret("+ .");
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
}

// Sub command

TEST(ArithCommand, Correct_Work_Sub) {
    std::string result = Interpreter::getInstance().interpret("3 4 - .");
    EXPECT_EQ(result, " 1");
}

TEST(ArithCommand, Incorrect_Work_Sub_No_Numbers) {
    std::string result = Interpreter::getInstance().interpret("- .");
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
}

TEST(ArithCommand, Incorrect_Work_Sub_One_Number) {
    std::string result = Interpreter::getInstance().interpret("1 - .");
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
    result = Interpreter::getInstance().interpret(".");
    EXPECT_EQ(result, " 1");
}

// Mod command

TEST(ArithCommand, Correct_Work_Mod) {
    std::string result = Interpreter::getInstance().interpret("3 4 % .");
    EXPECT_EQ(result, " 1");
}

TEST(ArithCommand, Incorrect_Work_Mod_No_Numbers) {
    std::string result = Interpreter::getInstance().interpret("% .");
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
}

TEST(ArithCommand, Incorrect_Work_Mod_One_Number) {
    std::string result = Interpreter::getInstance().interpret("1 % .");
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
    result = Interpreter::getInstance().interpret(".");
    EXPECT_EQ(result, " 1");
}

TEST(ArithCommand, Incorrect_Work_Mod_One_Number_Zero) {
    std::string result = Interpreter::getInstance().interpret("3 0 % .");
    EXPECT_EQ(result, "\nError mod: first number is null");
    result = Interpreter::getInstance().interpret(". .");
    EXPECT_EQ(result, " 0 3");
}

// Div command

TEST(ArithCommand, Correct_Work_Div) {
    std::string result = Interpreter::getInstance().interpret("3 4 / .");
    EXPECT_EQ(result, " 1");
}

TEST(ArithCommand, Incorrect_Work_Div_Zero_Number) {
    std::string result = Interpreter::getInstance().interpret("/ .");
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
}

TEST(ArithCommand, Incorrect_Work_Div_One_Number) {
    std::string result = Interpreter::getInstance().interpret("1 / .");
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
    result = Interpreter::getInstance().interpret(".");
    EXPECT_EQ(result, " 1");
}

TEST(ArithCommand, Incorrect_Work_Div_One_Number_Zero) {
    std::string result = Interpreter::getInstance().interpret("3 0 / .");
    EXPECT_EQ(result, "\nError div: first number is null");
    result = Interpreter::getInstance().interpret(". .");
    EXPECT_EQ(result, " 0 3");
}

// Mul command

TEST(ArithCommand, Correct_Work_Mul) {
    std::string result = Interpreter::getInstance().interpret("3 4 * .");
    EXPECT_EQ(result, " 12");
}

TEST(ArithCommand, Incorrect_Work_Mul_Zero_Number) {
    std::string result = Interpreter::getInstance().interpret("* .");
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
}

TEST(ArithCommand, Incorrect_Work_Mul_One_Number) {
    std::string result = Interpreter::getInstance().interpret("1 * .");
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
    result = Interpreter::getInstance().interpret(".");
    EXPECT_EQ(result, " 1");
}

// Great command

TEST(ArithCommand, Correct_Work_Great) {
    std::string result = Interpreter::getInstance().interpret("2 6 > . 6 2 > .");
    EXPECT_EQ(result, " 1 0");
}

TEST(ArithCommand, Incorrect_Work_Great_Zero_Number) {
    std::string result = Interpreter::getInstance().interpret(">");
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
}

TEST(ArithCommand, Incorrect_Work_Great_One_Number) {
    std::string result = Interpreter::getInstance().interpret("1 > .");
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
    result = Interpreter::getInstance().interpret(".");
    EXPECT_EQ(result, " 1");
}

// Less command

TEST(ArithCommand, Correct_Work_Less) {
    std::string result = Interpreter::getInstance().interpret("2 6 < . 6 2 < .");
    EXPECT_EQ(result, " 0 1");
}

TEST(ArithCommand, Incorrect_Work_Less_Zero_Number) {
    std::string result = Interpreter::getInstance().interpret("<");
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
}

TEST(ArithCommand, Incorrect_Work_Less_One_Number) {
    std::string result = Interpreter::getInstance().interpret("1 < .");
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
    result = Interpreter::getInstance().interpret(".");
    EXPECT_EQ(result, " 1");
}

// Equal command

TEST(ArithCommand, Correct_Work_Equal) {
    std::string result = Interpreter::getInstance().interpret("2 6 = . 7 7 = .");
    EXPECT_EQ(result, " 0 1");
}

TEST(ArithCommand, Incorrect_Work_Equal_One_Number) {
    std::string result = Interpreter::getInstance().interpret("=");
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
}

TEST(ArithCommand, Incorrect_Work_Equl_One_Number) {
    std::string result = Interpreter::getInstance().interpret("1 = .");
    EXPECT_EQ(result, "\nError arithmetic operation: not enough numbers");
    result = Interpreter::getInstance().interpret(".");
    EXPECT_EQ(result, " 1");
}

// Dup command

TEST(Other_Command, Correct_Work_Dup) {
    std::string result = Interpreter::getInstance().interpret("2 dup . .");
    EXPECT_EQ(result, " 2 2");
}

TEST(Other_Command, Call_Dup_When_Stack_Is_Empty) {
    std::string result = Interpreter::getInstance().interpret("dup 2 dup . .");
    EXPECT_EQ(result, "\nError optional operator: not enough numbers");
}

// Drop command

TEST(Other_Command, Correct_Work_Drop) {
    std::string result = Interpreter::getInstance().interpret("2 4 drop .");
    EXPECT_EQ(result, " 2");
}

TEST(Other_Command, Call_Drop_When_Stack_Is_Empty) {
    std::string result = Interpreter::getInstance().interpret("drop . .");
    EXPECT_EQ(result, "\nError optional operator: not enough numbers");
}

// Emit command

TEST(Other_Command, Correct_Work_Emit) {
    std::string result = Interpreter::getInstance().interpret("65 emit");
    EXPECT_EQ(result, " A");
}

TEST(Other_Command, Incorrect_Work_Emit_No_Number) {
    std::string result = Interpreter::getInstance().interpret("emit");
    EXPECT_EQ(result, "\nError emit: not enough numbers");
}

TEST(Other_Command, Incorrect_Work_Emit_Not_Ascii) {
    std::string result = Interpreter::getInstance().interpret("-2 emit");
    EXPECT_EQ(result, "\nError emit: number on stack is out of ASCII range");
}

// Swap command

TEST(Other_Command, Correct_Work_Swap) {
    std::string result = Interpreter::getInstance().interpret("2 3 swap . .");
    EXPECT_EQ(result, " 2 3");
}

TEST(Other_Command, Incorrect_Work_Swap_One_Number) {
    std::string result = Interpreter::getInstance().interpret("3 swap . .");
    EXPECT_EQ(result, "\nError swap: not enough numbers");
    result = Interpreter::getInstance().interpret(".");
    EXPECT_EQ(result, " 3");
}

TEST(Other_Command, Incorrect_Work_Swap_No_Numbers) {
    std::string result = Interpreter::getInstance().interpret("swap . .");
    EXPECT_EQ(result, "\nError swap: not enough numbers");
}

// Rot command

TEST(Other_Command, Correct_Work_Rot) {
    std::string result = Interpreter::getInstance().interpret("2 3 4 rot . . .");
    EXPECT_EQ(result, " 3 2 4");
}

TEST(Other_Command, Incorrect_Work_Rot_No_Number) {
    std::string result = Interpreter::getInstance().interpret("3 4 rot . . .");
    EXPECT_EQ(result, "\nError rot: not enough numbers");
    result = Interpreter::getInstance().interpret(". .");
    EXPECT_EQ(result, " 4 3");
}

TEST(Other_Command, Incorrect_Work_Rot_No_Numbers) {
    std::string result = Interpreter::getInstance().interpret("rot . . .");
    EXPECT_EQ(result, "\nError rot: not enough numbers");
}

// Over command

TEST(Other_Command, Correct_Work_Over) {
    std::string result = Interpreter::getInstance().interpret("2 3 over . . .");
    EXPECT_EQ(result," 2 3 2");
}

TEST(Other_Command, Incorrect_Work_Over_No_Numbers) {
    std::string result = Interpreter::getInstance().interpret("over . . .");
    EXPECT_EQ(result, "\nError over: not enough numbers");
}

TEST(Other_Command, Incorrect_Work_Over_One_Number) {
    std::string result = Interpreter::getInstance().interpret("1 over . . .");
    EXPECT_EQ(result, "\nError over: not enough numbers");
}

// Cr command

TEST(Other_Command, Correct_Work_Cr) {
    std::string result = Interpreter::getInstance().interpret(" 23 45 . cr .");
    EXPECT_EQ(result, " 45\n 23");
}

// Print string command

TEST(Other_Command, Correct_Work_PrintString) {
    std::string result = Interpreter::getInstance().interpret(".\" wef awd\"");
    EXPECT_EQ(result, " wef awd");
}

TEST(Other_Command, Incorrect_Work_PrintString_No_Closing_Bracket) {
    std::string result = Interpreter::getInstance().interpret(".\" wef awd");
    EXPECT_EQ(result, "\nError .\": no \"");
}

TEST(Other_Command, Incorrect_Work_PrintString_Two_Closing_Brackets) {
    std::string result = Interpreter::getInstance().interpret(R"(." wef awd"")");
    EXPECT_EQ(result, " wef awd\nno such command: '\"'");
}

// Underflow operator - and overflow operator +

TEST(Underflow_And_Overflow, Correct_Work_Underflow) {
    std::stringstream ss;
    ss << " " << 1 << " " << std::numeric_limits<int>::min() << " - .";
    auto actual = Interpreter::getInstance().interpret(ss.str());
    std::stringstream expected;
    expected << " " << std::numeric_limits<int>::max();
    EXPECT_EQ(actual, expected.str());
}

TEST(Underflow_And_Overflow, Correct_Work_Overflow) {
    std::stringstream ss;
    ss << " " << 1 << " " << std::numeric_limits<int>::max() << " + .";
    auto actual = Interpreter::getInstance().interpret(ss.str());
    std::stringstream expected;
    expected << " " << std::numeric_limits<int>::min();
    EXPECT_EQ(actual, expected.str());
}