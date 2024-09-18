#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include "compare_char.h"
#include "onegin.h"
#include "sort.h"

int replace_values(int y, char** ptr_to_new_line);
int sort_strings(int y, char**   ptr_to_new_line);
int check_characters(char a);

int sort(char** ptr_to_new_line)
{
    assert(ptr_to_new_line);

    for(int i = 1; i < MAXIMUM_NUMBER_OF_COLUMNS; i++)
    {
        for(int y = 1; y < MAXIMUM_NUMBER_OF_COLUMNS; y++)
        {
            sort_strings(y, ptr_to_new_line);
        }
    }
    return 0;
}

int replace_values(int y, char** ptr_to_new_line)
{
    assert(&ptr_to_new_line);

    char* copy_the_address = ptr_to_new_line[y-1];

    ptr_to_new_line[y - 1] = ptr_to_new_line[y];
    ptr_to_new_line[y] = copy_the_address;

    return 0;
}
int sort_strings(int y, char** ptr_to_new_line)
{
    assert(ptr_to_new_line);

    int skip_char_first_line  = 0;
    int skip_char_second_line = 0;

    for(int line_element = 0; (ptr_to_new_line[y-1])[line_element + skip_char_first_line] != '\n' &&
        (ptr_to_new_line[y])[line_element + skip_char_second_line] != '\n'; line_element++)
    {
        while(check_characters((ptr_to_new_line[y-1])[line_element + skip_char_first_line]))
        {
            skip_char_first_line++;
        }
        while(check_characters((ptr_to_new_line[y])[line_element + skip_char_second_line]))
        {
            skip_char_second_line++;
        }
        int solution_option = compare_caps_char(y, line_element, skip_char_first_line, skip_char_second_line, ptr_to_new_line);

        switch(solution_option)
        {
            case 1 :
            {
                replace_values(y, ptr_to_new_line);
                return 0;
            }
            case -1 :
            {
                return 0;
             }
            case 0 :
            {
                break;
            }
            default:
            {
                printf("ERROR\n");
                break;
            }
        }
    }
    return 0;
}

int check_characters(char a)
{
    return (isspace(a) || ispunct(a));
}
