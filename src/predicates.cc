#include <string>
#include "predicates.h"
using size_type = std::string::size_type;

bool wrong_fn::operator()(const std::string &c) {
    return !contains_any_of(c, l);
}

bool correct_fn::operator()(const std::string &c) {
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (!contains_at(c, it->second[0], it->first)) {
            return false;
        }
    }
    return true;
}

bool misplaced_fn::operator()(const std::string &c) {
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (!contains_but_not_at(c, it->second[0], it->first)) {
            return false;
        }
    }
    return true;
}

bool contains_any_of(const std::string s, const std::string& cs) {
    for (char c : cs) {
        if (s.find(c) != std::string::npos) {
            return true;
        }
    }
    return false;
}

bool contains_at(const std::string& s, char c, size_type pos) {
    return s[pos] == c;
}

bool contains_but_not_at(const std::string& s, char c, size_type pos) {
    if (pos >= s.size()) {
        return s.find(c) != std::string::npos;
    }
    for (size_type i = 0; i < s.size(); ++i) { //? change s.size to fixed number 5
        if (s[i] == c && i != pos) {
            return true;
        }
    }
    return false;
}



