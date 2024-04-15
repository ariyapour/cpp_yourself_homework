#include <iostream>
#include <no_strings_attached/string_trim.h>
int main() {
  std::cout << "Example program that trims strings." << std::endl;
  std::cout << "Please enter a string:" << std::endl;

  // Define the input string
  std::string str{};

  // Ask the user for the input string
  std::getline(std::cin, str);

  std::string result = no_strings_attached::Trim(str);

  std::cout << "Your trimmed string: '" << result << "'";
  return 0;
}