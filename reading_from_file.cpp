#include <stdio.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "reading_from_file.h"

void calculate_array_size(Info_about_text *info, char* fname);

void read_from_file_text(Info_about_text* info)
{
    assert(info);

    char* fname = "ONEGIN_2.txt";

    FILE * point_to_file = fopen(fname, "rb");

    if (!point_to_file)
    {
        printf("The file does not open\n");

        exit(EXIT_FAILURE);
    }

    calculate_array_size(info, fname);

    int number_successfully_read_chars = fread(info->text, 1, info->size_text, point_to_file);

    if (number_successfully_read_chars + 1 != info->size_text)
    {
        printf("ERROR: fread didn't read enough chars\n",
               "info->size_text = %d\n",
               "number_successfully_read_chars = %d\n",
               info->size_text, number_successfully_read_chars);

        exit(EXIT_FAILURE);
    }
    fclose(point_to_file);

    info->text[info->size_text - 1] = '\0';

    return;
}

void calculate_array_size(Info_about_text *info, char* fname)
{
    assert(info);
    assert(fname);

    struct stat data_for_file = {};

    stat(fname, &data_for_file);

    info->size_text = data_for_file.st_size + 1;

    if (!info->size_text)
    {
        printf("size_text = 0\n");

        exit(EXIT_FAILURE);
    }
    info->text = (char*)calloc(info->size_text, sizeof(char));

    if (info->text == NULL)
    {
        printf("ERROR: calculate_array_size; text = NULL\n");

        exit(EXIT_FAILURE);
    }
}
