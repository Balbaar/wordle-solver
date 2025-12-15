#include "../src/predicates.h"
#include <cassert>

void test_wrong_fn() {
    wrong_fn wrong("abc");
    assert(wrong("defgh") == true);
    assert(wrong("abxyz") == false);
}

void test_correct_fn() {
    letters_and_indices lae = { {0, "h"}, {1, "e"} };
    correct_fn correct(lae);
    assert(correct("hello") == true);
    assert(correct("jello") == false);
    assert(correct("helps") == true);
}

void test_misplaced_fn() {
    letters_and_indices lae = { {0, "h"}, {1, "e"} };
    misplaced_fn misplaced(lae);
    assert(misplaced("ehllo") == true);
    assert(misplaced("hello") == false);
    assert(misplaced("world") == false);
}




void test_contains_any_of() {
    assert(contains_any_of("hello", "aeiou") == true);
    assert(contains_any_of("xyz", "abc") == false);
}

void test_contains_at() {
    assert(contains_at("hello", 'e', 1) == true);
    assert(contains_at("hello", 'h', 0) == true);
    assert(contains_at("hello", 'o', 4) == true);
    assert(contains_at("hello", 'l', 2) == true);
    assert(contains_at("hello", 'x', 2) == false);
    assert(contains_at("hello", 'h', 5) == false); // out of bounds
}

void test_contains_but_not_at() {
    assert(contains_but_not_at("hello", 'e', 0) == true);
    assert(contains_but_not_at("hello", 'h', 0) == false);
    assert(contains_but_not_at("hello", 'l', 2) == true);
    assert(contains_but_not_at("hello", 'o', 4) == false);
    assert(contains_but_not_at("hello", 'x', 2) == false);
    assert(contains_but_not_at("hello", 'h', 5) == true); // out of bounds
}

int main() {
    test_wrong_fn();
    test_correct_fn();
    test_misplaced_fn();
    test_contains_any_of();
    test_contains_at();
    test_contains_but_not_at();
    return 0;
}

