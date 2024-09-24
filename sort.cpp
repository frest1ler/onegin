#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include "comparators.h"
#include "onegin.h"
#include "sort.h"

int sort_strings  (int j, Text_processing* data);
int replace_values(int j, Text_processing* data);

int bubble_sort(Text_processing* data)
{
    assert(data);
    assert(data->ptr_line);
    assert(data->text);

        for(int i = 1; i < data->max_number_line; i++)
        {
            for(int j = 1; j < data->max_number_line; j++)
            {
                sort_strings(j, data);
            }
        }
    return 0;
}

int replace_values(int j, Text_processing* data)
{
    assert(data);

    char* copy_the_address = data->ptr_line[j - 1];

    data->ptr_line[j - 1] = data->ptr_line[j];
    data->ptr_line[j] = copy_the_address;

    return 0;
}
int sort_strings(int j, Text_processing* data)
{
    assert(data);

    int solution_option = compare_string(j, data->ptr_line);

    switch(solution_option)
    {
            case 1 :
            {
                replace_values(j, data);
                return 0;
            }
            case -1 :
            {
                return 0;
            }
            default:
            {
                printf("ERROR\n");
                break;
            }
    }
    return 0;
}
