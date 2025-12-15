#include <fstream>
#include "candidates.h"

/*
@param filename: the file to read words from
@return a vector of strings containing all 5-letter words from the file
*/
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
