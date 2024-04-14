#include <iostream>
#include <no_strings_attached/string_split.h>
namespace no_strings_attached {
std::vector<std::string> Split(const std::string &str,
                               const std::string &delimiter) {
  // Define the necessary variables
  std::string::size_type previous_delimiter_position{0};
  std::string::size_type next_delimiter_position{str.find(delimiter)};
  std::vector<std::string> splitted_strings;

  // Perform search and spliting untill we find no delimiter in the str
  while (next_delimiter_position != str.npos) {
    // Add the sub string to the vector of splitted strings
    splitted_strings.push_back(
        str.substr(previous_delimiter_position,
                   next_delimiter_position - previous_delimiter_position));

    // replace the previous delimiter position with the current delimiter
    // position plus the length of the delimiter to continue the search for the
    // rest of the string
    previous_delimiter_position = next_delimiter_position + delimiter.size();

    // find the next delimiter in the rest of the string
    next_delimiter_position = str.find(delimiter, previous_delimiter_position);
  }
  // Add the last chunk of the string
  splitted_strings.push_back(
      str.substr(previous_delimiter_position,
                 next_delimiter_position - previous_delimiter_position));
  return splitted_strings;
}

std::vector<std::string> Split(const std::string &str,
                               const std::string &delimiter,
                               int number_of_chunks_to_keep) {
  // Define the necessary variables
  std::string::size_type previous_delimiter_position{0};
  std::string::size_type next_delimiter_position{str.find(delimiter)};
  std::vector<std::string> splitted_strings;

  // Perform the search and spliting untill we find no delimiter in the str or
  // until we have enough chunks
  while (next_delimiter_position != str.npos && number_of_chunks_to_keep != 0) {
    // Add the sub string to the vector of splitted strings
    splitted_strings.push_back(
        str.substr(previous_delimiter_position,
                   next_delimiter_position - previous_delimiter_position));

    // replace the previous delimiter position with the current delimiter
    // position plus the length of the delimiter to continue the search for the
    // rest of the string
    previous_delimiter_position = next_delimiter_position + delimiter.size();

    // find the next delimiter in the rest of the string
    next_delimiter_position = str.find(delimiter, previous_delimiter_position);

    // Decrease the number of chunks variable by 1
    number_of_chunks_to_keep--;
  }

  // Add the last chunk of the string if the number of requested chunks has not
  // yet been satisfied
  if (number_of_chunks_to_keep != 0) {
    splitted_strings.push_back(
        str.substr(previous_delimiter_position,
                   next_delimiter_position - previous_delimiter_position));
  }
  return splitted_strings;
}
} // namespace no_strings_attached