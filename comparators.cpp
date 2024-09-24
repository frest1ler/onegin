#include <ctype.h>
#include "comparators.h"

int compare_char(char a, char b)
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

int check_characters(char a)
{
    return (isspace(a) || ispunct(a));
}

int compare_string(int j, char** ptr_line)
{
    char value_skip_char_1line  = 0;
    char value_skip_char_2line  = 0;

    for(int line_element = 0;
        (ptr_line[j - 1])[line_element + value_skip_char_1line] != '\n' &&
        (ptr_line[j])[line_element + value_skip_char_2line]    != '\n';
        line_element++)
    {
        while(check_characters((ptr_line[j-1])[line_element + value_skip_char_1line]))
        {
            value_skip_char_1line++;
        }

        while(check_characters((ptr_line[j])[line_element + value_skip_char_2line]))
        {
            value_skip_char_2line++;
        }

        int solution_option = compare_caps_char((ptr_line[j - 1])[line_element + value_skip_char_1line]
                                                , (ptr_line[j])[line_element + value_skip_char_2line]);
        if (solution_option != 0)
        {
            return solution_option;
        }
    }
    return 0;
}
