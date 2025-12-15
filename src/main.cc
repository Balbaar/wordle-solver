#include <iostream>
#include <fstream>
#include "candidates.h"
#include "input.h"
#include "filter.h"


int main() {
    //1. read file from command line argument
    std::vector<std::string> candidates = read_candidates(std::cin);

    //Loop 2-3 until one candidate left
    //  2. prompt user for input
    //  3. filter candidates based on input
    while(true) {
        std::tuple<std::string, letters_and_indices, letters_and_indices> user_input = prompt(); //Prompt user for input
        
        //Filter candidates
        std::vector<std::string> filtered;
        exclude_word exclude(std::get<0>(user_input), std::get<1>(user_input), std::get<2>(user_input));
        for (const auto& c : candidates) {
            if (!exclude(c)) {
                filtered.push_back(c);
            }
        }
        candidates = filtered;
        
        std::cout << "candidates left: " << candidates.size() << "\n";
        for (const auto& c : candidates) {
            std::cout << c << "\n";
        }
    }

    
}


