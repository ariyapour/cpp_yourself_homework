#include <gtest/gtest.h>
#include <vector>
#include <no_strings_attached/string_split.h>

TEST(StringSplit, test1){
    std::vector<std::string> computed_result = no_strings_attached::Split("hello world", " ");
    std::vector<std::string> expected_result = std::vector<std::string>{"hello", "world"};
    EXPECT_EQ(computed_result, expected_result);
}

TEST(StringSplit, test2){
    std::vector<std::string> computed_result = no_strings_attached::Split("hello world", " ", 1);
    std::vector<std::string> expected_result = std::vector<std::string>{"hello"};
    EXPECT_EQ(computed_result, expected_result);
}

TEST(StringSplit, test3){
    std::vector<std::string> computed_result = no_strings_attached::Split("hello world", " ", 2);
    std::vector<std::string> expected_result = std::vector<std::string>{"hello", "world"};
    EXPECT_EQ(computed_result, expected_result);
}

TEST(StringSplit, test4){
    std::vector<std::string> computed_result = no_strings_attached::Split("aaabaaba", "aa");
    std::vector<std::string> expected_result = std::vector<std::string>{"", "ab", "ba"};
    EXPECT_EQ(computed_result, expected_result);
}

TEST(StringSplit, test5){
    std::vector<std::string> computed_result = no_strings_attached::Split("aaabaaba", "aa", 2);
    std::vector<std::string> expected_result = std::vector<std::string>{"", "ab"};
    EXPECT_EQ(computed_result, expected_result);
}