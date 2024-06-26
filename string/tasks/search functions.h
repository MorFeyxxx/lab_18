#ifndef UNTITLED1_SEARCH_FUNCTIONS_H
#define UNTITLED1_SEARCH_FUNCTIONS_H

#include "../../string/string_.h"

void test_find_the_desired_element_in_the_range(){
    char s[] = "Hello";
    char *find_element = find(s, &s[3], 'l');

    assert(find_element == &s[2]);
}

void test_find_the_desired_element_is_not_in_the_range(){
    char s[] = "Hello";
    char *find_element = find(s, &s[3], 'o');

    assert(find_element == &s[3]);
}

void test_find(){
    test_find_the_desired_element_in_the_range();
    test_find_the_desired_element_is_not_in_the_range();
}


void test_find_non_space_the_desired_element_in_the_range(){
    char s[] = "   a   ";
    char *find_element = find_non_space(s);

    assert(find_element == &s[3]);
}

void test_find_non_space_the_desired_element_is_not_in_the_range(){
    char s[] = "   ";
    char *find_element = find_non_space(s);

    assert(find_element == &s[3]);
}

void test_find_non_space_is_no_space(){
    char s[] = "abc";
    char *find_element = find_non_space(s);

    assert(find_element == &s[0]);
}

void test_find_non_space(){
    test_find_non_space_the_desired_element_in_the_range();
    test_find_non_space_the_desired_element_is_not_in_the_range();
    test_find_non_space_is_no_space();
}


void test_find_space_a_space_between_two_elements(){
    char s[] = "a b";
    char *find_element = find_space(s);

    assert(find_element == &s[1]);
}

void test_find_space_is_no_space(){
    char s[] = "abc";
    char *find_element = find_space(s);

    assert(find_element == &s[3]);
}

void test_find_space_space_is_the_first_element(){
    char s[] = " b";
    char *find_element = find_space(s);

    assert(find_element == &s[0]);
}

void test_find_space(){
    test_find_space_a_space_between_two_elements();
    test_find_space_is_no_space();
    test_find_space_space_is_the_first_element();
}


void test_find_non_space_reverse_the_desired_element_in_the_range(){
    char s[] = " 5  ";
    char *find_element = find_non_space_reverse(&s[3], s - 1);

    assert(find_element == &s[1]);
}

void test_find_non_space_reverse_the_desired_element_is_not_in_the_range(){
    char s[] = "   ";
    char *find_element = find_non_space_reverse(&s[2], s - 1);

    assert(find_element == s - 1);
}

void test_find_non_space_reverse_is_no_space(){
    char s[] = "123";
    char *find_element = find_non_space_reverse(&s[2], s - 1);

    assert(find_element == &s[2]);
}

void test_find_non_space_reverse(){
    test_find_non_space_reverse_the_desired_element_in_the_range();
    test_find_non_space_reverse_the_desired_element_is_not_in_the_range();
    test_find_non_space_reverse_is_no_space();
}


void test_find_space_reverse_the_desired_element_in_the_range(){
    char s[] = "ab de";
    char *find_element = find_space_reverse(&s[4], s - 1);

    assert(find_element == &s[2]);
}

void test_find_space_reverse_is_no_space(){
    char s[] = "abcde";
    char *find_element = find_space_reverse(&s[4], s - 1);

    assert(find_element == s - 1);
}

void test_find_space_reverse(){
    test_find_space_reverse_the_desired_element_in_the_range();
    test_find_space_reverse_is_no_space();
}

#endif //UNTITLED1_SEARCH_FUNCTIONS_H
