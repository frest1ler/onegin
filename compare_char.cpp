#include <ctype.h>
#include <assert.h>
#include "compare_char.h"

int compare_char(char a, char b)
{
    if ((a - b) > 0)
    {
        return 1;
    }
    if ((a - b) < 0)
    {
        return -1;
    }
    return 0;
}

int compare_caps_char(Interaction_files* value, Text_processing* data)
{
    assert(value);
    assert(data);

    char first  = toupper((data->ptr_line[value->number_line - 1])[value->line_element + value->skip_char_first_line]);
    char second = toupper((data->ptr_line[value->number_line])[value->line_element + value->skip_char_second_line]);

    return compare_char(first, second);
}
