#include <iostream>
#include <no_strings_attached/string_trim.h>
namespace no_strings_attached {
[[nodiscard]] std::string Trim(const std::string &str, char char_to_trim,
                               Side side) {
  std::size_t trim_index_left{0};
  std::size_t trim_index_right{str.size() - 1};
  std::string result{};
  switch (side) {
  case no_strings_attached::Side::kLeft:
    while (str.at(trim_index_left) == char_to_trim) {
      trim_index_left++;
    }
    result = str.substr(trim_index_left, str.size() - 1);
    break;
  case no_strings_attached::Side::kRight:
    while (str.at(trim_index_right) == char_to_trim) {
      trim_index_right--;
    }
    result = str.substr(0, trim_index_right + 1);
    break;
  default:
    while (str.at(trim_index_left) == char_to_trim) {
      trim_index_left++;
    }
    result = str.substr(trim_index_left, str.size() - 1);
    trim_index_right = result.size() - 1;
    while (result.at(trim_index_right) == char_to_trim) {
      trim_index_right--;
    }
    result = result.substr(0, trim_index_right + 1);
    break;
  }
  return result;
}

[[nodiscard]] std::string Trim(const std::string &str) {
  std::size_t trim_index_left{0};
  std::size_t trim_index_right{str.size() - 1};
  std::string result{};

  while (str.at(trim_index_left) == ' ') {
    trim_index_left++;
  }
  result = str.substr(trim_index_left, str.size() - 1);
  trim_index_right = result.size() - 1;
  while (result.at(trim_index_right) == ' ') {
    trim_index_right--;
  }
  result = result.substr(0, trim_index_right + 1);
  return result;
}
} // namespace no_strings_attached