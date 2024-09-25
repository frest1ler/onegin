#include <ctype.h>
#include "comparators.h"
#include "onegin.h"

int compare_char(char a, char b)
{
    if (a > b)
    {
        return FIRST_CHAR_IS_BIGGER;
    }
    if (a < b)
    {
        return SECOND_CHAR_IS_BIGGER;
    }
    return CHARS_ARE_EQUAL;
}

int compare_caps_char(char a, char b)
{
    char first  = toupper(a);
    char second = toupper(b);

    return compare_char(first, second);
}

int check_characters(char a)
{
    return (isspace(a) || ispunct(a));
}

int compare_string(char* line1, char* line2)
{
    char value_skip_char_1line  = 0;
    char value_skip_char_2line  = 0;

    for(int line_element = 0;
        (line1)[line_element + value_skip_char_1line] != '\n' &&
        (line2)[line_element + value_skip_char_2line]    != '\n';
        line_element++)
    {
        while(check_characters((line1)[line_element + value_skip_char_1line]))
        {
            value_skip_char_1line++;
        }

        while(check_characters((line2)[line_element + value_skip_char_2line]))
        {
            value_skip_char_2line++;
        }

        int solution_option = compare_caps_char((line1)[line_element + value_skip_char_1line]
                                                , (line2)[line_element + value_skip_char_2line]);
        if (solution_option != 0)
        {
            return solution_option;
        }
    }
    return 0;
}
