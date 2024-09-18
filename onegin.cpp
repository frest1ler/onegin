#include <stdio.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "onegin.h"
#include "sort.h"
#include "interaction_with_files.h"

int main()
{
    char* ptr_to_new_line[MAXIMUM_NUMBER_OF_COLUMNS] = {};
    char* text = 0;

    int size_text = 0;

    FILE * point_to_file = fopen("ONEGIN_SHORT.txt", "r");

    struct stat buf = {};

    stat("ONEGIN_SHORT.txt", &buf);

    size_text = buf.st_size + 1;

    text = (char*)calloc(size_text, sizeof(char));

    fclose(point_to_file);

    read_from_file(ptr_to_new_line, text);

    sort(ptr_to_new_line);

    output_text(ptr_to_new_line);

    return 0;
}
