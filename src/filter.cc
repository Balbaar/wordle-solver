/*
This will filter the words using the functors 
*/
#include "filter.h"

bool exclude_word::operator()(const std::string &w) {
    return !wrong(w) || !correct(w) || !misplaced(w);
}
