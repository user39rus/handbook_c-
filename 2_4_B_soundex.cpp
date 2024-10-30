#include <iostream>
#include <string>

int main() {
  std::string incoming_string, outcoming_string = "";
  std::string str_one = "bfpv", str_two = "cgjkqsxz", str_tree = "dt",
              str_four = "l", str_five = "mn", str_six = "r";
  std::getline(std::cin, incoming_string);
  outcoming_string.push_back(incoming_string[0]);
  for (size_t i = 1; i != incoming_string.size(); ++i) {
    int number_sound = -1;
    if (str_one.find(incoming_string[i]) != std::string::npos)
      number_sound = 1;
    if (str_two.find(incoming_string[i]) != std::string::npos)
      number_sound = 2;
    if (str_tree.find(incoming_string[i]) != std::string::npos)
      number_sound = 3;
    if (str_four.find(incoming_string[i]) != std::string::npos)
      number_sound = 4;
    if (str_five.find(incoming_string[i]) != std::string::npos)
      number_sound = 5;
    if (str_six.find(incoming_string[i]) != std::string::npos)
      number_sound = 6;
    if (number_sound > 0 && number_sound != outcoming_string.back() - 48)
      outcoming_string.push_back(number_sound + 48);
  }
  while (outcoming_string.size() < 4)
    outcoming_string.push_back(48);
  outcoming_string.resize(4);
  std::cout << outcoming_string << "\n";
}