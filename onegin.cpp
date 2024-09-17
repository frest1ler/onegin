#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "onegin.h"
#include "sort.h"

int main()
{
    printf("0\n");

    FILE * point_to_file = fopen("ONEGIN_SHORT.txt", "r");

    assert(point_to_file);

    char text[THE_VOLUME_OF_THE_TEXT] = {};
    char* pointer_to_new_line[MAXIMUM_NUMBER_OF_COLUMNS] = {};

    printf("0.5\n");
    pointer_to_new_line[0] = (char*)text;

    char symbol = 0;
    int  x      = 0;
    int  y      = 1;

    printf("1\n");
    while((symbol = getc(point_to_file)) != EOF)
    {
        text[x] = symbol;
        x++;

        if (symbol == '\n')

        {
            pointer_to_new_line[y] = (char*)(text+x);
            y++  ;
        }
    }

    fclose(point_to_file);
    printf("2\n");

    //printf("%s", (pointer_to_new_line[0]));

    sort(pointer_to_new_line);

    printf("2.5\n");

    for(y = 0; y < MAXIMUM_NUMBER_OF_COLUMNS-1; y++)
    {
        int line_element = 0;
        //printf("2.75\n");
        while((pointer_to_new_line[y])[line_element] != '\n')
        {
            putchar((pointer_to_new_line[y])[line_element]);
            //printf("%d ", line_element);
            line_element++;
        }
        putchar('\n');
    }
    printf("\n3\n");

    return 0;
}
