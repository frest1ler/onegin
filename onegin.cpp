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

    Text_processing data    = {};

    read_from_file(&data, &value);

    sort(&value, &data);

    output_text(&value, &data);

    return 0;
}
