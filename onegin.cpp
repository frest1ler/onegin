#include <stdio.h>
#include "onegin.h"
#include "sort.h"
#include "reading_from_file.h"
#include "output_text.h"

int main()
{
    Text_processing data = {}; //TODO rename

    //printf("Text_processing data = {};\n");

    read_from_file(&data);

    //printf("read_from_file(&data);\n");

    bubble_sort(&data);

    //printf("bubble_sort(&data);\n");

    output_text(&data);

    //printf("output_text(&data);\n");

    return 0;
}
