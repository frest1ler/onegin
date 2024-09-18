#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include "compare_char.h"
#include "onegin.h"
#include "sort.h"

int replace_values(Sorting_data *value, char** ptr_line);
int sort_strings  (Sorting_data *value, char** ptr_line);
int check_characters(char a);

int sort(Sorting_data *value, char** ptr_line)
{
    assert(ptr_line);

    for(int i = 1; i < MAXIMUM_NUMBER_OF_COLUMNS; i++)
    {
        //printf("i = %d\n", i);
        for(value->y = 1; value->y < MAXIMUM_NUMBER_OF_COLUMNS; value->y++)
        {
            sort_strings(value, ptr_line);
            //printf("value->y = %d\n", value->y);
            //printf("value->line_element = %d\n", value->line_element);
            //printf("value->skip_char_first_line = %d\n", value->skip_char_first_line);
            //printf("value->skip_char_second_line = %d\n", value->skip_char_second_line);
            //printf("\n");
        }
    }
    return 0;
}

int replace_values(Sorting_data *value, char** ptr_line)
{
    assert(&ptr_line);
    assert(value);

    char* copy_the_address = ptr_line[value->y - 1];

    ptr_line[value->y - 1] = ptr_line[value->y];
    ptr_line[value->y] = copy_the_address;

    return 0;
}
int sort_strings(Sorting_data *value, char** ptr_line)
{
    assert(ptr_line);
    assert(value);

    for(value->line_element = 0;
        (ptr_line[value->y - 1])[value->line_element + value->skip_char_first_line] != '\n' &&
        (ptr_line[value->y])[value->line_element + value->skip_char_second_line] != '\n';
        value->line_element++)
    {
        while(check_characters((ptr_line[value->y-1])[value->line_element + value->skip_char_first_line]))
        {
            value->skip_char_first_line++;
        }
        //printf("value->skip_char_first_line = %d\n", value->skip_char_first_line);

        while(check_characters((ptr_line[value->y])[value->line_element + value->skip_char_second_line]))
        {
            value->skip_char_second_line++;
        }
        //printf("value->skip_char_second_line = %d\n", value->skip_char_second_line);

        int solution_option = compare_caps_char(value, ptr_line);

        switch(solution_option)
        {
            case 1 :
            {
                value->line_element = 0;
                value->skip_char_first_line = 0;
                value->skip_char_second_line = 0;

                replace_values(value, ptr_line);
                return 0;
            }
            case -1 :
            {
                value->line_element = 0;
                value->skip_char_first_line = 0;
                value->skip_char_second_line = 0;

                return 0;
             }
            case 0 :
            {
                break;
            }
            default:
            {
                value->line_element = 0;
                value->skip_char_first_line = 0;
                value->skip_char_second_line = 0;

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
