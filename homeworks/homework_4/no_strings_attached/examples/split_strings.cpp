#include <iostream>
#include <no_strings_attached/string_split.h>
int main() {
  std::cout << "Example program that splits strings." << std::endl;
  std::cout << "Please enter a string:" << std::endl;

  // Define the input string
  std::string str{"hello world"};

  // Ask the user for the input string
  std::getline(std::cin, str);

  // Perform the split using the defined split function
  std::vector<std::string> results = no_strings_attached::Split(str, " ");

  // Print the results
  std::cout << "Your split string:";
  for (const auto &str : results) {
    std::cout << " '" << str << "' ";
  }
  return 0;
}