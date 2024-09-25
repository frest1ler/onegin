#include <stdio.h>
#include <assert.h>
#include "initialize_pointer_array.h"
#include "onegin.h"

static void search_new_line(Info_about_text* info);
static void count_number_lines(Info_about_text* info);

void initialize_pointer_array(Info_about_text* info)
{
    assert(info);

    count_number_lines(info);

    search_new_line(info);
}

static void search_new_line(Info_about_text* info)
{
    assert(info);
    assert(info->text);
    assert(info->ptr_line);

    int symbol       = 0;
    int line_element = 0;
    int number_line  = 1;

    info->ptr_line[0] = info->text;

    while((symbol = info->text[line_element]) != EOF)
    {
        line_element++;

        if (symbol == '\0')
        {
            info->ptr_line[number_line] = (char*)(info->text + line_element);

            line_element++;
            number_line++;

        }
    }
}

static void count_number_lines(Info_about_text* info)
{
    assert(info);

    char symbol = 0;

    for(int line_element = 0; (symbol = info->text[line_element]) && line_element < info->size_text; line_element++)
    {
        if (symbol == '\n')
        {
            //check_empty_lines(&line_element, info);
            info->max_number_line++;
            info->text[line_element] = '\0';
        }
    }
    info->ptr_line = (char**)calloc(info->max_number_line, sizeof(char*));
}
