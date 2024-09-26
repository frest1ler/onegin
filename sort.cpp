#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include "comparators.h"
#include "onegin.h"
#include "sort.h"

static void sort_strings  (int j, Info_about_text* info);
static void replace_values(int j, Info_about_text* info);

void bubble_sort(Info_about_text* info)
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
}

static void replace_values(int j, Info_about_text* info)
{
    assert(info);
    assert(info->ptr_line);

    char* copy_the_address = info->ptr_line[j - 1];

    info->ptr_line[j - 1] = info->ptr_line[j];
    info->ptr_line[j] = copy_the_address;
}

static void sort_strings(int j, Info_about_text* info)
{
    assert(info);

    int comparation_result = compare_string(info->ptr_line[j - 1], info->ptr_line[j]);

    if (comparation_result > 0)
    {
        replace_values(j, info);
    }
}
