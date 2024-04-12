#include <array>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {

  // Using string literal
  using std::string_literals::operator""s;
  // Print the welcome message
  std::cout << "Welcome to the fortune teller program!"s << std::endl;

  // Define the name variable
  std::string name{};

  // Ask the user to input their name
  std::cout << "Please enter your name:"s << std::endl;
  std::cin >> name;

  // Define the seasn the user was born
  std::string season{};

  // Ask the user when they were born
  std::cout << "Please enter the time of year when you were born:" << std::endl;
  std::cout << "(pick from 'spring', 'summer', 'autumn', 'winter')"
            << std::endl;
  std::cin >> season;

  // Define the adjective vector
  std::vector<std::string> adjectives(2, "");
  // Ask for an adjective
  std::cout << "Please enter an adjective:"s << std::endl;
  std::cin >> adjectives[0];

  // Ask for the second adjective
  std::cout << "Please enter another adjective:"s << std::endl;
  std::cin >> adjectives[1];

  // Select the appropriate adjective based on modulo and the size of adjectives
  // and name
int adjective_index = adjectives.size() % name.size();
  if (adjective_index == adjectives.size()) {
    adjective_index = 0;
  }
  std::string adjective = adjectives[adjective_index];

  // Define the noun map datastructure
  std::map<std::string, std::string> nouns = {
      {"spring", "STL guru"},
      {"summer", "C++ expert"},
      {"autumn", "coding beast"},
      {"winter", "software design hero"}};

  // Define endings array
  std::array<std::string, 3> endings = {
      "eats UB for breakfast", "finds errors quicker than the compiler",
      "is not afraid of C++ error messages"};

  // Select the appropriate ending based on modulo and the size of endings and
  // name
  int ending_index = endings.size() % name.size();
  if (ending_index == endings.size()) {
    ending_index = 0;
  }
  std::string ending = endings[ending_index];

  // Define the sentence place holder. We assume that the sentence is a fixed
  // size of an vector containing strings with size of
  std::string sentence =
      name + ", the "s + adjective + " "s + nouns[season] + " that "s + ending;

  std::cout << "\nHere is your description:" << std::endl;
  // Print out the final results.
  std::cout << sentence << std::endl;
}