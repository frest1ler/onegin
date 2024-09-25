#include <stdio.h>
#include <assert.h>
#include "output_text.h"

int output_text(Info_about_text* info)
{
    assert(info);
    for(int number_line = 0; number_line < info->max_number_line; number_line++)
    {
        printf("%d. %s\n",number_line + 1, (info->ptr_line)[number_line]);
    }
    return 0;
}
