#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include "compare_char.h"
#include "onegin.h"
#include "sort.h"

int replace_values(Interaction_files *value, Text_processing* data);
int sort_strings  (Interaction_files *value, Text_processing* data);
int check_characters(char a);

int sort(Interaction_files* value, Text_processing* data)
{
    assert(value);
    assert(data);

    for(int i = 1; i < data->max_number_line; i++)
    {
        //printf("i = %d\n", i);
        for(value->number_line = 1; value->number_line < data->max_number_line; value->number_line++)
        {
            sort_strings(value, data);
            //printf("value->number_line = %d\n", value->number_line);
            //printf("value->line_element = %d\n", value->line_element);
            //printf("value->skip_char_first_line = %d\n", value->skip_char_first_line);
            //printf("value->skip_char_second_line = %d\n", value->skip_char_second_line);
            //printf("\n");
        }
    }
    return 0;
}

int replace_values(Interaction_files* value, Text_processing* data)
{
    assert(value);
    assert(data);

    char* copy_the_address = data->ptr_line[value->number_line - 1];

    data->ptr_line[value->number_line - 1] = data->ptr_line[value->number_line];
    data->ptr_line[value->number_line] = copy_the_address;

    return 0;
}
int sort_strings(Interaction_files* value, Text_processing* data)
{
    assert(value);
    assert(data);

    for(value->line_element = 0;
        (data->ptr_line[value->number_line - 1])[value->line_element + value->skip_char_first_line] != '\n' &&
        (data->ptr_line[value->number_line])[value->line_element + value->skip_char_second_line] != '\n';
        value->line_element++)
    {
        while(check_characters((data->ptr_line[value->number_line-1])[value->line_element + value->skip_char_first_line]))
        {
            value->skip_char_first_line++;
        }
        //printf("value->skip_char_first_line = %d\n", value->skip_char_first_line);

        while(check_characters((data->ptr_line[value->number_line])[value->line_element + value->skip_char_second_line]))
        {
            value->skip_char_second_line++;
        }
        //printf("value->skip_char_second_line = %d\n", value->skip_char_second_line);

        int solution_option = compare_caps_char(value, data);

        switch(solution_option)
        {
            case 1 :
            {
                value->line_element = 0;
                value->skip_char_first_line = 0;
                value->skip_char_second_line = 0;

                replace_values(value, data);
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
