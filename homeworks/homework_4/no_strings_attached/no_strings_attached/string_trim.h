#pragma once
#include <string>
#include <vector>
namespace no_strings_attached {
enum class Side { kLeft, kRight, kBoth };
[[nodiscard]] std::string Trim(const std::string &str, char char_to_trim,
                               Side side);
[[nodiscard]] std::string Trim(const std::string &str);
} // namespace no_strings_attached