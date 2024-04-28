#ifndef UNTITLED1_REPLACE_DIGIT_TO_SPACE_H
#define UNTITLED1_REPLACE_DIGIT_TO_SPACE_H

#include "../../string/string_.h"

#define ASCII_SHIFT_FOR_DIGIT 48

void replace_digit_to_space(char* s) {
    char* rec_ptr = s;
    char* read_ptr = _string_buffer;

    char* end = get_end_of_string(s);
    char* end_in_buff = copy(s, end, _string_buffer);
    *end_in_buff = '\0';

    while (*read_ptr != '\0') {
        if (isdigit(*read_ptr))
            for (int i = 0; i < *read_ptr - ASCII_SHIFT_FOR_DIGIT; i++) {
                *rec_ptr = ' ';
                rec_ptr++;
            }
        else {
            *rec_ptr = *read_ptr;
            rec_ptr++;
        }

        read_ptr++;
    }

    *rec_ptr = '\0';
    free_string(_string_buffer);
}

void test_4_empty() {
    char s[] = "";
    replace_digit_to_space(s);
    ASSERT_STRING("", s);
}

void test_4_non_digit() {
    char s[] = "a";
    replace_digit_to_space(s);
    ASSERT_STRING("a", s);
}

void test_4_non_letters() {
    char s[] = "1";
    replace_digit_to_space(s);
    ASSERT_STRING(" ", s);
}

void test_4_letters_and_digit() {
    char s[] = "a2b";
    replace_digit_to_space(s);
    ASSERT_STRING("a  b", s);
}

void test_4_replace_digit_to_space() {
    test_4_empty();
    test_4_non_digit();
    test_4_non_letters();
    test_4_letters_and_digit();
}

#endif //UNTITLED1_REPLACE_DIGIT_TO_SPACE_H
