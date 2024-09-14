#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "compare_char.h"
#include "onegin.h"
#include "sort.h"

int replace_values(int y, char text, char*  pointer_to_new_line);
int sort_strings(int y, char text,   char*  pointer_to_new_line);
//int skip_punctuation_character();
int check_characters(char a);

int sort(char text, char* pointer_to_new_line)+
{
    assert(text);
    assert(pointer_to_new_line);

    for(int i = 1; i < MAXIMUM_NUMBER_OF_COLUMNS; i++)
    {
        //printf("%d\n ", i);
        for(int y = 1; y < MAXIMUM_NUMBER_OF_COLUMNS; y++)
        {
            //printf(" %d ", y);
            sort_strings(y, text, pointer_to_new_line);
        }
    }
    return 0;
}

int replace_values(int y, char text, char* pointer_to_new_line)
{
    assert(text);
    assert(pointer_to_new_line);

    char copy_the_address = pointer_to_new_line[y-1];

    pointer_to_new_line[y-1] = pointer_to_new_line[y];
    pointer_to_new_line[y] = copy_the_address;

    return 0;
}
int sort_strings(int y, char text, char* pointer_to_new_line)
{
    assert(text);
    assert(pointer_to_new_line);

    char skip_symbols_first_string  = 0;
    char skip_symbols_second_string = 0;

    char length_first_line  = &pointer_to_new_line[y]     - &pointer_to_new_line[y-1];
    char length_second_line = &pointer_to_new_line[y + 1] - &pointer_to_new_line[y  ];

    for(char line_element = 0;(line_element + skip_symbols_first_string < length_first_line) ||
        (line_element + skip_symbols_second_string < length_second_line); line_element++)
    {
        while(check_characters(pointer_to_new_line[y - 1] + line_element + skip_symbols_first_string))
        {
            skip_symbols_first_string++;
        }
        while(check_characters(pointer_to_new_line[y] + line_element + skip_symbols_second_string))
        {
            skip_symbols_second_string++;
        }
        if ((pointer_to_new_line[y - 1] + line_element + skip_symbols_first_string) != '\n' &&
            (pointer_to_new_line[y]   + line_element + skip_symbols_first_string) != '\n')
        {
            char first  = toupper(pointer_to_new_line[y - 1] + line_element + skip_symbols_first_string);
            char second = toupper(pointer_to_new_line[y - 1] + line_element + skip_symbols_first_string);

            int solution_option = compare_char(first, second);
            switch(solution_option)
            {
                case 1 :
                {
                    replace_values(y, text, pointer_to_new_line);
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
        else
        {
            return 0;
        }
    }
    return 0;
}

int check_characters(char a)
{
    return (isspace(a) || ispunct(a));
}
