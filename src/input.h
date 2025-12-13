#include <string>
#include <map>
#include <tuple>
#include "predicates.h"

letters_and_indices build_list(const std::string& line);
std::tuple<std::string, letters_and_indices, letters_and_indices> prompt();

void append(letters_and_indices& dest,const letters_and_indices& src);
