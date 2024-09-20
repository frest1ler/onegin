#include <stdio.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "interaction_with_files.h"

int output_string(Interaction_files* value, Text_processing* data);
int check_empty_lines(Interaction_files *value, Text_processing* data, FILE * point_to_file);
int assign_array_size(Text_processing *data);

int output_text(Interaction_files *value, Text_processing* data)
{
    assert(value);
    assert(data);

    for(value->number_line = 0; value->number_line < data->max_number_line -1; value->number_line++)
    {
        output_string(value, data);
    }
    return 0;
}

int output_string(Interaction_files *value, Text_processing* data)
{
    assert(value);
    assert(data);

    value->line_element = 0;

    while((data->ptr_line[value->number_line])[value->line_element] != '\n' &&
          (data->ptr_line[value->number_line])[value->line_element] != '\0')
    {
        putchar((data->ptr_line[value->number_line])[value->line_element]);
        value->line_element++;
    }
    putchar('\n');

    return 0;
}

int read_from_file(Text_processing* data, Interaction_files *value)
{
    assert(value);
    assert(data);

    FILE * point_to_file = fopen("ONEGIN_SHORT.txt", "r");

    assign_array_size(data);
    //ptr_line[0] = (char*)text;

    value->symbol       = 0;
    value->line_element = 0;
    value->number_line  = 1;

    while((value->symbol = getc(point_to_file)) != EOF)
    {
        if (value->symbol == '\n')
        {
            check_empty_lines(value, data, point_to_file);

            data->max_number_line++;
        }
        data->text[value->line_element] = value->symbol;

        value->line_element++;
    }
    data->text[value->line_element + 1] = '\0';

    fclose(point_to_file);

    data->ptr_line = (char**)calloc(data->max_number_line, sizeof(char*));

    value->symbol       = 0;
    value->line_element = 0;
    value->number_line  = 1;

    data->ptr_line[0] = data->text;

    while((value->symbol = data->text[value->line_element]) != EOF)
    {
        data->text[value->line_element] = value->symbol;
        value->line_element++;

        if (value->symbol == '\n')
        {
            data->ptr_line[value->number_line] = (char*)(data->text + value->line_element);

            value->line_element++;
            value->number_line++;

        }
    }
    return 0;
}

int assign_array_size(Text_processing *data)
{

    struct stat buf = {};

    stat("ONEGIN_SHORT.txt", &buf);

    data->size_text = buf.st_size + 1;

    data->text = (char*)calloc(data->size_text, sizeof(char));

    if (data->text == 0)
    {
        printf("ERROR: assign_array_size; text = 0\n");
    }
    return 0;
}

int check_empty_lines(Interaction_files *value, Text_processing* data, FILE * point_to_file)
{
    assert(value);
    assert(data);

    data->text[value->line_element] = '\n';

    while((value->symbol = getc(point_to_file)) == '\n');

    value->line_element++;

    return 0;
}
