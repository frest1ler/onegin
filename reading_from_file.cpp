#include <stdio.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "reading_from_file.h"

static int  check_empty_lines(int* line_element, Info_about_text* info);
static void calculate_array_size(Info_about_text *info, char* fname);

void read_from_file_text(Info_about_text* info)
{
    assert(info);

    char fname[] = "ONEGIN_SHORT.txt";

    FILE * point_to_file = fopen(fname, "rb");

    assert(point_to_file);

    calculate_array_size(info, fname);

    if (!fread(info->text, 1, info->size_text, point_to_file))
    {
        printf("ERROR: fread didn't read the characters\n",
               "info->size_text = %d\n", info->size_text);
    }
    fclose(point_to_file);

    return;
}

static void calculate_array_size(Info_about_text *info, char* fname)
{
    assert(info);

    struct stat data_for_file = {};

    stat(fname, &data_for_file);

    info->size_text = data_for_file.st_size;

    info->text = (char*)calloc(info->size_text, sizeof(char));

    if (info->text == NULL)
    {
        printf("ERROR: calculate_array_size; text = NULL\n");
    }
}

static int check_empty_lines(int* line_element, Info_about_text* info)
{
    assert(info);
    assert(line_element);
    assert(info->text);

    while(info->text[*line_element + 1] == '\n')
    {
        *line_element++;
    }
    return 0;
}
