#include <stdio.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "interaction_with_files.h"
#include "onegin.h"

int output_string(int y, char** ptr_to_new_line);

int output_text(char** ptr_to_new_line)
{
    assert(ptr_to_new_line);

    for(int y = 0; y < MAXIMUM_NUMBER_OF_COLUMNS-1; y++)
    {
        output_string(y, ptr_to_new_line);
    }
    return 0;
}

int output_string(int y, char** ptr_to_new_line)
{
    assert(ptr_to_new_line);

    int line_element = 0;

    while((ptr_to_new_line[y])[line_element] != '\n' &&
          (ptr_to_new_line[y])[line_element] != '\0')
    {
        putchar((ptr_to_new_line[y])[line_element]);
        line_element++;
    }
    putchar('\n');

    return 0;
}

int read_from_file(char** ptr_to_new_line, char* text)
{
    assert(ptr_to_new_line);

    FILE * point_to_file = fopen("ONEGIN_SHORT.txt", "r");

    assign_array_size(&text);

    ptr_to_new_line[0] = (char*)text;

    char symbol = 0;
    int  x      = 0;
    int  y      = 1;

    while((symbol = getc(point_to_file)) != EOF)
    {
        text[x] = symbol;
        x++;

        if (symbol == '\n')

        {
            ptr_to_new_line[y] = (char*)(text+x);
            y++  ;
        }
    }
    text[x + 1] = '\0';

    fclose(point_to_file);

    return 0;
}

int assign_array_size(char** text)
{

    struct stat buf = {};

    stat("ONEGIN_SHORT.txt", &buf);

    int size_text = buf.st_size + 1;

    *text = (char*)calloc(size_text, sizeof(char));

    if (text == 0)
    {
        printf("ERROR: assign_array_size; text = 0\n");
    }
    return 0;
}
