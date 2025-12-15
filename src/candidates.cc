/*
This will take in a input stream to read all words
*/ 

#include <fstream>
#include "candidates.h"


std::vector<std::string> read_candidates(const std::string filename) {
    std::ifstream in(filename);

    if (!in) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    std::vector<std::string> candidates;
    std::string word;
    
    while (in >> word) {
        if (word.length() != 5) {
            continue; //skip non 5-letter words
        }
        candidates.push_back(word);
    }

    return candidates;
}
