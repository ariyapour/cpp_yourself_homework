#include <gtest/gtest.h>
#include <vector>
#include <no_strings_attached/string_trim.h>

TEST(StringTrim, test1){
    std::string computed_result = no_strings_attached::Trim("  hello ", ' ', no_strings_attached::Side::kLeft);
    std::string expected_result = std::string{"hello "};
    EXPECT_EQ(computed_result, expected_result);
}

TEST(StringTrim, test2){
    std::string computed_result = no_strings_attached::Trim("  hello ", ' ', no_strings_attached::Side::kRight);
    std::string expected_result = std::string{"  hello"};
    EXPECT_EQ(computed_result, expected_result);
}

TEST(StringTrim, test3){
    std::string computed_result = no_strings_attached::Trim("  hello ", ' ', no_strings_attached::Side::kBoth);
    std::string expected_result = std::string{"hello"};
    EXPECT_EQ(computed_result, expected_result);
}

TEST(StringTrim, test4){
    std::string computed_result = no_strings_attached::Trim("hello", 'h', no_strings_attached::Side::kLeft);
    std::string expected_result = std::string{"ello"};
    EXPECT_EQ(computed_result, expected_result);
}

TEST(StringTrim, test5){
    std::string computed_result = no_strings_attached::Trim("  hello ");
    std::string expected_result = std::string{"hello"};
    EXPECT_EQ(computed_result, expected_result);
}

TEST(StringTrim, test6){
    std::string computed_result = no_strings_attached::Trim("hello", ' ', no_strings_attached::Side::kLeft);
    std::string expected_result = std::string{"hello"};
    EXPECT_EQ(computed_result, expected_result);
}