#include <stdio.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "reading_from_file.h"

int  output_string(int number_line, Text_processing* data);
int  check_empty_lines(int* line_element, char* symbol, Text_processing* data, FILE * point_to_file);
int  search_new_line(Text_processing* data);
void assign_array_size(Text_processing *data);

int read_from_file(Text_processing* data) //TODO rename
{
    assert(data);

    FILE * point_to_file = fopen("ONEGIN_SHORT.txt", "rb");

    assign_array_size(data);

    char symbol       = 0;
    int  line_element = 0;
    int  number_line  = 1;

    if (!fread(data->text, 1, data->size_text, point_to_file))
    {
        printf("ERROR: fread didn't read the characters\n");

        printf("data->size_text = %d\n", data->size_text);

        return 0;
    }

    fclose(point_to_file);

    for(line_element = 0; (symbol = data->text[line_element]) != EOF; line_element++)
    {
        if (symbol == '\n')
        {
            data->max_number_line++;
            data->text[line_element] = '\0';
        }
    }

    data->ptr_line = (char**)calloc(data->max_number_line, sizeof(char*));

    search_new_line(data);

    return 0;
}

void assign_array_size(Text_processing *data) //TODO rename
{
    assert(data);

    struct stat buf = {}; //TODO rename

    stat("ONEGIN_SHORT.txt", &buf);

    data->size_text = buf.st_size;

    data->text = (char*)calloc(data->size_text, sizeof(char));

    if (data->text == NULL)
    {
        printf("ERROR: assign_array_size; text = NULL\n");
    }
}

int check_empty_lines(int* line_element, char* symbol, Text_processing* data, FILE * point_to_file)
{
    assert(data);
    assert(point_to_file);
    assert(line_element);
    assert(symbol);

    data->text[*line_element] = '\n';

    while((*symbol = getc(point_to_file)) == '\n');

    *line_element++;

    return 0;
}

int search_new_line(Text_processing* data)
{
    int symbol       = 0;
    int line_element = 0;
    int number_line  = 1;

    data->ptr_line[0] = data->text;

    while((symbol = data->text[line_element]) != EOF)
    {
        line_element++;

        if (symbol == '\0')
        {
            data->ptr_line[number_line] = (char*)(data->text + line_element);

            line_element++;
            number_line++;

        }
    }
    return 0;
}

