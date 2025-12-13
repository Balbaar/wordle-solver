#include <string>
#include "predicates.h"
using size_type = std::string::size_type;


bool contains_any_of(const std::string s, const std::string& cs) {
    for (char c : cs) {
        if (s.find(c) != std::string::npos) {
            return true;
        }
    }
    return false;
}

bool contains_at(const std::string& s, char c, size_type pos) {
    if (pos >= s.size()) {
        return false;
    }
    return s[pos] == c;
}

bool contains_but_not_at(const std::string& s, char c, size_type pos) {
    if (pos >= s.size()) {
        return s.find(c) != std::string::npos;
    }
    for (size_type i = 0; i < s.size(); ++i) {
        if (s[i] == c && i != pos) {
            return true;
        }
    }
    return false;
}



