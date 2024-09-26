#include <ctype.h>
#include "comparators.h"
#include "onegin.h"

int compare_chars(char a, char b)
{
    a = toupper(a);
    b = toupper(b);

    return (a - b);
}

int check_chars(char a)
{
    return (isspace(a) || ispunct(a));
}

int compare_string(char* line1, char* line2)
{
    char value_skip_char_1line  = 0;
    char value_skip_char_2line  = 0;

    for(int line_element = 0;
        line1[line_element + value_skip_char_1line] != '\0' &&
        line2[line_element + value_skip_char_2line] != '\0';
        line_element++)
    {
        while(check_chars(line1[line_element + value_skip_char_1line]))
        {
            value_skip_char_1line++;
        }
        while(check_chars(line2[line_element + value_skip_char_2line]))
        {
            value_skip_char_2line++;
        }
        int solution_option = compare_chars(line1[line_element + value_skip_char_1line],
                                            line2[line_element + value_skip_char_2line]);
        if (solution_option != 0)
        {
            return solution_option;
        }
    }
    return 0;
}
