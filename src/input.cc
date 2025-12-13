/*
Ask user for green, yellow, gray letters
*/
#include "input.h"
#include <iostream>


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

letters_and_indices build_list(const std::string& line) {

}