#include <string>
#include <vector>
#include "predicates.h"

struct exclude_word
{
    exclude_word(const std::string &wrong,
                const letters_and_indices &correct,
                const letters_and_indices &misplaced) :
                wrong{wrong},
                correct{correct},
                misplaced{misplaced} {}
    
    bool operator()(const std::string &w);

private:
    wrong_fn wrong;
    correct_fn correct;
    misplaced_fn misplaced;
};

