#include <stdio.h>
#include <assert.h>
#include "interaction_with_files.h"
#include "onegin.h"

int output_string(int y, char** pointer_to_new_line);

int output_text(char** pointer_to_new_line)
{
    assert(pointer_to_new_line);

    for(int y = 0; y < MAXIMUM_NUMBER_OF_COLUMNS-1; y++)
    {
        output_string(y, pointer_to_new_line);
    }
    return 0;
}

int output_string(int y, char** pointer_to_new_line)
{
    int line_element = 0;

    while((pointer_to_new_line[y])[line_element] != '\n' &&
          (pointer_to_new_line[y])[line_element] != '\0')
    {
        putchar((pointer_to_new_line[y])[line_element]);
        line_element++;
    }
    putchar('\n');

    return 0;
}
