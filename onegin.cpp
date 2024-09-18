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
    Sorting_data value = {0, 0, 0, 0};

    char* ptr_line[MAXIMUM_NUMBER_OF_COLUMNS] = {};
    char* text = 0;

    read_from_file(ptr_line, text);

    sort(&value, ptr_line);

    output_text(ptr_line);

    return 0;
}
