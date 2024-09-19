#include <stdio.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "onegin.h"
#include "sort.h"
#include "interaction_with_files.h"

int main() //TODO аргументы командной строки (имя входного файла и выходного)
{
    Interaction_files value = {};

    char* ptr_line[MAXIMUM_NUMBER_OF_COLUMNS] = {}; //TODO calloc
    char* text = 0;

    read_from_file(&value, ptr_line, text);

    sort(&value, ptr_line);

    output_text(&value, ptr_line);

    return 0;
}
