#include "../src/predicates.h"
#include <cassert>

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
    test_contains_any_of();
    test_contains_at();
    test_contains_but_not_at();
    return 0;
}

