#include <stdio.h>
#include <assert.h>
#include "output_text.h"

int output_text(Text_processing* data)
{
    assert(data);

    for(int number_line = 0; number_line < data->max_number_line -1; number_line++)
    {
        printf("%s\n", (data->ptr_line)[number_line]);
    }
    return 0;
}
