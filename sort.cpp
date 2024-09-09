#include <stdio.h>
#include <ctype.h>
#include "compare_char.h"
#include "onegin.h"
#include "sort.h"

int replace_values(int y, char * text);
int sort_columns(int y, char * text);

int sort(char * text)
{
    for(int y = 1; y < MAXIMUM_NUMBER_OF_COLUMNS; y++)
    {
        sort_columns(y, text);
    }
    return 0;
}

int replace_values(int y, char * text)
{
    for(int x = 0; x < MAXIMUM_LINE_LENGTH; x++)
    {
        char storage_symbol = text[y-1][x];
        text[y-1][x] = text[y][x];
        text[y][x] = storage_symbol;
    }
    return 0;
}
int sort_columns(int y, char * text)
{
    for(int x = 0; x < MAXIMUM_LINE_LENGTH; x++)
    {
        if (text[y-1][x] != '\n' && text[y][x] != '\n')
        {
            char first  = toupper(text[y-1][x]);
            char second = toupper(text[y  ][x]);

            int solution_option = compare_char(first, second);
            switch(solution_option)
            {
                case 1 :
                {
                    replace_values(y, text);
                    break;
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
