/*
This will take in a input stream to read all words
*/ 

#include "candidates.h"

std::vector<std::string> read_candidates(std::istream& in) {
    std::vector<std::string> candidates;
    std::string word;
    while (in >> word) {
        if (word.size() != 5) {
            continue; // skip words that are not 5 letters long
        }
        candidates.push_back(word);
    }
    return candidates;
}
