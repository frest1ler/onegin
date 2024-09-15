#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "onegin.h"
#include "sort.h"

int main()
{
    printf("0\n");

    FILE * point_to_file = fopen("ONEGIN_SHORT.txt", "r");

    assert(point_to_file);

    char* text[THE_VOLUME_OF_THE_TEXT] = {};
    char** pointer_to_new_line[MAXIMUM_NUMBER_OF_COLUMNS] = {};

    printf("0.5\n");
    pointer_to_new_line[0] = &text[0];

    char symbol = 0;
    int  x      = 0;
    int  y      = 1;

    printf("1\n");
    while((symbol = getc(point_to_file)) != EOF)
    {
        text[x] = &symbol;
        x++;

        if (symbol == '\n')

        {
            pointer_to_new_line[y] = &text[x];
            y++  ;
        }
    }
    fclose(point_to_file);
    printf("2\n");

    sort(*text, pointer_to_new_line[0]);

    printf("2.5\n");

    for(y = 0; y < MAXIMUM_NUMBER_OF_COLUMNS; y++)
    {
        char length_actual_line = pointer_to_new_line[y + 1] - pointer_to_new_line[y];

        for(char line_element = 0; line_element < length_actual_line; line_element++)
        {
            putchar(**(pointer_to_new_line[y] + line_element));
        }
    }
    printf("3\n");

    return 0;
}
