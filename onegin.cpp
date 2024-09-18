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

    read_from_file(ptr_to_new_line, text);

    sort(ptr_to_new_line);

    output_text(ptr_to_new_line);

    return 0;
}
