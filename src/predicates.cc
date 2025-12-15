#include <string>
#include "predicates.h"
using size_type = std::string::size_type;


/*
Constructor for wrong_fn that appends wrong letters to exisisting string, empty if this is first call
@param letters: string of wrong letters
*/ 
wrong_fn::wrong_fn(const std::string &letters) {
    l.append(letters);
}

/*
Checks a word against wrong letters
@return true if word contains none of the wrong letters
*/
bool wrong_fn::operator()(const std::string &c) {
    return !contains_any_of(c, l);
}

/*
Constructor for correct_fn that appends correct letters with indices to existing map, empty if this is first call
@param idxs: map of indices to correct letters
*/
correct_fn::correct_fn(const letters_and_indices &idxs) {
    append(m, idxs);
}

/*
Checks a word against correct letters
@return true if word contains all correct letters at correct indices
*/
bool correct_fn::operator()(const std::string &c) {
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (!contains_at(c, it->second[0], it->first)) {
            return false;
        }
    }
    return true;
}

/*
Constructor for misplaced_fn that appends misplaced letters with indices to existing map, empty if this is first call
@param idxs: map of indices to misplaced letters
*/
misplaced_fn::misplaced_fn(const letters_and_indices &idxs) {
    append(m, idxs);
}

/*
Checks a word against misplaced letters
@return true if word contains all misplaced letters but not at the given indices
*/
bool misplaced_fn::operator()(const std::string &c) {
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (!contains_but_not_at(c, it->second[0], it->first)) {
            return false;
        }
    }
    return true;
}

// HELPER FUNCTIONS

/*
@param s: string to check
@param cs: characters to check for
@return true if s contains any character from cs
*/
bool contains_any_of(const std::string s, const std::string& cs) {
    for (char c : cs) {
        if (s.find(c) != std::string::npos) {
            return true;
        }
    }
    return false;
}

/*
@param s: string to check
@param c: character to check for
@param pos: position to check
@return true if strings contains char c at position pos
*/
bool contains_at(const std::string& s, char c, size_type pos) {
    return s[pos] == c;
}

/*
@param s: string to check
@param c: character to check for
@param pos: position to avoid
@return true if string s contains char c but not at position pos
*/
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

/*
Used for re-prompting the used. Appends letters_and_indices.
@param m: is the source to append to
@param to_append: what to append
*/
inline void append(letters_and_indices &m, const letters_and_indices &to_append) {
    for (const auto& it : to_append) {
        m[it.first] += it.second;
    }
}


