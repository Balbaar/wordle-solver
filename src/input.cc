/*
Ask user for green, yellow, gray letters
*/
#include "input.h"
#include <iostream>
#include <sstream>

/*
Prompts the user for wrong, correct and misplaced letters.
@returns tuple of (wrong letters, correct letters with indices, misplaced letters with indices)
*/
std::tuple<std::string, letters_and_indices, letters_and_indices> prompt() {
    std::string wrong;
    std::cout << "enter wrong letters:\n";
    std::getline(std::cin, wrong);
    
    std::string correct;
    std::cout << "enter correct letters (letter index)*:\n";
    std::getline(std::cin, correct);
    auto corr = build_list(correct);
    
    std::string misplaced;
    std::cout << "enter misplaced letters (letter index)*:\n";
    std::getline(std::cin, misplaced);
    auto misp = build_list(misplaced);
    return {wrong, corr, misp};
}

/*
Helper function for taking user input and converting it into latters_and_indices data type.
@param line: string of user input (ex: e 1 b 3)
@return letters_and_indices of the user input
*/
letters_and_indices build_list(const std::string& line) {
    letters_and_indices result;
    std::istringstream iss(line);
    std::string letter;
    size_type index;
    while (iss >> letter >> index) {
        result[index] = letter;
    }
    return result;
}