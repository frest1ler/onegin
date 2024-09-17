#include <stdio.h>
#include <assert.h>
#include "onegin.h"
#include "sort.h"
#include "interaction_with_files.h"

int main()
{

    FILE * point_to_file = fopen("ONEGIN_SHORT.txt", "r");

    assert(point_to_file);

    char text[THE_VOLUME_OF_THE_TEXT] = {};
    char* pointer_to_new_line[MAXIMUM_NUMBER_OF_COLUMNS] = {};

    pointer_to_new_line[0] = (char*)text;

    char symbol = 0;
    int  x      = 0;
    int  y      = 1;

    while((symbol = getc(point_to_file)) != EOF)
    {
        text[x] = symbol;
        x++;

        if (symbol == '\n')

        {
            pointer_to_new_line[y] = (char*)(text+x);
            y++  ;
        }
    }
    text[x + 1] = '\0';

    fclose(point_to_file);

    sort(pointer_to_new_line);

    output_text(pointer_to_new_line);

    return 0;
}
