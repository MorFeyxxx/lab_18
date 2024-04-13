#include "string_.h"

size_t strlen_(const char* begin){
    char *end = begin;
    while (*end != '\0')
        end++;

    return end - begin;
}

char* find(char *begin, char *end, int ch){
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char* find_non_space(char *begin){
    while (*begin != '\0' && isspace(*begin))
        begin++;

    return begin;
}