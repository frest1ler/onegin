#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include "comparators.h"
#include "onegin.h"
#include "sort.h"

static int sort_strings  (int j, Info_about_text* info);
static int replace_values(int j, Info_about_text* info);

int bubble_sort(Info_about_text* info)
{
    assert(info);
    assert(info->ptr_line);
    assert(info->text);

        for(int i = 1; i < info->max_number_line; i++)
        {
            for(int j = 1; j < info->max_number_line; j++)
            {
                sort_strings(j, info);
            }
        }
    return 0;
}

static int replace_values(int j, Info_about_text* info)
{
    assert(info);
    assert(info->ptr_line);

    char* copy_the_address = info->ptr_line[j - 1];

    info->ptr_line[j - 1] = info->ptr_line[j];
    info->ptr_line[j] = copy_the_address;

    return 0;
}
static int sort_strings(int j, Info_about_text* info)
{
    assert(info);

    int comparation_result = compare_string(info->ptr_line[j - 1], info->ptr_line[j]);

    switch(comparation_result)
    {
            case FIRST_LINE_IS_BIGGER :
            {
                replace_values(j, info);
                return 0;
            }
            case SECOND_LINE_IS_BIGGER :
            {
                return 0;
            }
            case LINE_ARE_EQUAL :
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
