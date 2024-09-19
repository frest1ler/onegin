#include <stdio.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "interaction_with_files.h"

int output_string(Interaction_files *value, char** ptr_line);
int assign_array_size(char** text);

int output_text(Interaction_files *value, char** ptr_line)
{
    assert(ptr_line);

    for(value->number_line = 0; value->number_line < MAXIMUM_NUMBER_OF_COLUMNS-1; value->number_line++)
    {
        output_string(value, ptr_line);
    }
    return 0;
}

int output_string(Interaction_files *value, char** ptr_line)
{
    assert(ptr_line);

    value->line_element = 0;

    while((ptr_line[value->number_line])[value->line_element] != '\n' &&
          (ptr_line[value->number_line])[value->line_element] != '\0')
    {
        putchar((ptr_line[value->number_line])[value->line_element]);
        value->line_element++;
    }
    putchar('\n');

    return 0;
}

int read_from_file(Interaction_files *value, char** ptr_line, char* text)
{
    assert(ptr_line);

    FILE * point_to_file = fopen("ONEGIN_SHORT.txt", "r");

    assign_array_size(&text);

    ptr_line[0] = (char*)text;

    value->symbol       = 0;
    value->line_element = 0;
    value->number_line  = 1;

    while((value->symbol = getc(point_to_file)) != EOF)
    {
        text[value->line_element] = value->symbol;
        value->line_element++;

        if (value->symbol == '\n')

        {
            ptr_line[value->number_line] = (char*)(text+value->line_element);
            value->number_line++  ;
        }
    }
    text[value->line_element + 1] = '\0';

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
