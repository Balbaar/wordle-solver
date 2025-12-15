#include "filter.h"


/*
@param w: the word to check against the predicates. If the word matches any of the predicates, return true.
@return true if the word should be excluded, false otherwise.
*/
bool exclude_word::operator()(const std::string &w) {
    return !wrong(w) || !correct(w) || !misplaced(w);
}
