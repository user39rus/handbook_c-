#include <iostream>
#include <string>
#include <vector>

std::string Join(const std::vector<std::string>& tokens, char delimiter);

std::string Join(const std::vector<std::string>& tokens, char delimiter) {
    std::string return_string = "";
    for (size_t i=0; i<tokens.size(); ++i) {
        if (i != 0) return_string.push_back(delimiter);
        return_string.append(tokens[i]);
    }
    return return_string;
}

int main() {
    std::cout<<Join({"What", "is", "your", "name?"}, '_')<<std::endl;
}