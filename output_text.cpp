#include <stdio.h>
#include <assert.h>
#include "output_text.h"

int output_string(int number_line, Text_processing* data);

int output_text(Text_processing* data) //TODO file output
{
    assert(data);

    for(int number_line = 0; number_line < data->max_number_line -1; number_line++)
    {
        output_string(number_line, data);
    }
    return 0;
}

int output_string(int number_line, Text_processing* data)
{
    assert(data);

    int line_element = 0;

    while((data->ptr_line[number_line])[line_element] != '\n' &&
          (data->ptr_line[number_line])[line_element] != '\0')
    {
        putchar((data->ptr_line[number_line])[line_element]); //TODO printf
        line_element++;
    }
    putchar('\n');

    return 0;
}
