#ifndef PREDICATES_H
#define PREDICATES_H
#include <string>
#include <map>

using size_type = std::string::size_type;
using letters_and_indices = std::map<size_type, std::string>;

bool contains_any_of(const std::string s, const std::string& cs); //which returns true if the string s contains any of the characters in cs
bool contains_at(const std::string& s, char c, size_type pos); //which return true if the string s has the character c at position pos
bool contains_but_not_at(const std::string& s, char c, size_type pos); //contains c but at any other position than pos

inline void append(letters_and_indices &m, const letters_and_indices &to_append);

//All gray letters
struct wrong_fn
{
    wrong_fn(const std::string &letters);
    bool operator()(const std::string &c);

private:
    std::string l = "";
};

//All correct letters with indices - Green letters
struct correct_fn
{
    correct_fn(const letters_and_indices &idxs);
    bool operator()(const std::string &c);

private:
    letters_and_indices m = {};
};

//All misplaced letters with indices - Yellow letters
struct misplaced_fn
{
    misplaced_fn(const letters_and_indices &idxs);
    bool operator()(const std::string &c);

private:
    letters_and_indices m = {};

};



#endif // PREDICATES_H