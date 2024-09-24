#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include "compare_char.h"
#include "onegin.h"
#include "sort.h"

int replace_values(int j, Text_processing* data);
int sort_strings  (int j, Text_processing* data);
int check_characters(char a);

int bubble_sort(Text_processing* data)
{
    assert(data);
    assert(data->ptr_line);
    assert(data->text);

        int i = 1;

        for(int j = 1, i = 1; j < data->max_number_line &&
            i < data->max_number_line * data->max_number_line; j++, i++)
        {
            sort_strings(j, data);
        }
    return 0;
}

int replace_values(int j, Text_processing* data)
{
    assert(data);

    char* copy_the_address = data->ptr_line[j - 1];

    data->ptr_line[j - 1] = data->ptr_line[j];
    data->ptr_line[j] = copy_the_address;

    return 0;
}
int sort_strings(int j, Text_processing* data)
{
    assert(data);

    char value_skipped_characters_1line  = 0;
    char value_skipped_characters_2line = 0;

    for(int line_element = 0;
        (data->ptr_line[j - 1])[line_element + value_skipped_characters_1line] != '\n' &&
        (data->ptr_line[j])[line_element + value_skipped_characters_2line]    != '\n';
        line_element++)
    {
        while(check_characters((data->ptr_line[j-1])[line_element + value_skipped_characters_1line]))
        {
            value_skipped_characters_1line++;
        }
        //printf("value->value_skipped_characters_1line = %d\n", value->value_skipped_characters_1line);

        while(check_characters((data->ptr_line[j])[line_element + value_skipped_characters_2line]))
        {
            value_skipped_characters_2line++;
        }
        //printf("value->value_skipped_characters_2line = %d\n", value->value_skipped_characters_2line);

        int solution_option = compare_caps_char((data->ptr_line[j - 1])[line_element + value_skipped_characters_1line]
                                                , (data->ptr_line[j])[line_element + value_skipped_characters_2line]);
                                                 //TODO compare string(char* str_1, char* str_2)

        switch(solution_option)
        {
            case 1 :
            {
                replace_values(j, data);
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

int check_characters(char a)    //TODO rename use lib-func
{
    return (isspace(a) || ispunct(a));
}
