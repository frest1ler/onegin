#include <ctype.h>
#include "compare_char.h"

int compare_char(char a, char b) //TODO func compare string
{
    if ((a - b) > 0)
    {
        return 1;
    }
    if ((a - b) < 0)
    {
        return -1;
    }
    return 0;
}

int compare_caps_char(char a, char b)
{
    char first  = toupper(a);
    char second = toupper(b);

    return compare_char(first, second);
}

int check_characters(char a)    //TODO rename use lib-func
{
    return (isspace(a) || ispunct(a));
}

int compare_string()
{
}
