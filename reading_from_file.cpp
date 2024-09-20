#include <stdio.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "reading_from_file.h"

int output_string(int number_line, Text_processing* data);
int check_empty_lines(int* line_element, char* symbol, Text_processing* data, FILE * point_to_file);
int assign_array_size(Text_processing *data);

int read_from_file(Text_processing* data) //TODO rename
{
    assert(data);

    FILE * point_to_file = fopen("ONEGIN_SHORT.txt", "r");

    assign_array_size(data);

    char symbol       = 0;
    int  line_element = 0;
    int  number_line  = 1;

    while((symbol = getc(point_to_file)) != EOF) //TODO fread
    {
        if (symbol == '\n')
        {
            //check_empty_lines(&line_element, &symbol, data, point_to_file);

            data->max_number_line++;
        }
        data->text[line_element] = symbol;

        line_element++;
    }
    data->text[line_element + 1] = '\0';

    fclose(point_to_file);

    data->ptr_line = (char**)calloc(data->max_number_line, sizeof(char*));

    symbol       = 0;
    line_element = 0;
    number_line  = 1;

    data->ptr_line[0] = data->text;

    while((symbol = data->text[line_element]) != EOF) //TODO func
    {
        data->text[line_element] = symbol;
        line_element++;

        if (symbol == '\n')
        {
            data->ptr_line[number_line] = (char*)(data->text + line_element);

            line_element++;
            number_line++;

        }
    }
    return 0; //TODO func '\r' and '\n' = \0
}

int assign_array_size(Text_processing *data) //TODO rename
{

    struct stat buf = {}; //TODO rename

    stat("ONEGIN_SHORT.txt", &buf);

    data->size_text = buf.st_size + 1;

    data->text = (char*)calloc(data->size_text, sizeof(char));

    if (data->text == 0) //TODO !data->text == NULL
    {
        printf("ERROR: assign_array_size; text = 0\n"); //TODO NULL
    }
    return 0; //TODO return value
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

