#include "initialize_pointer_array.h"
#include "onegin.h"
#include "sort.h"
#include "reading_from_file.h"
#include "output_text.h"

int main()
{
    Info_about_text info = {};

    read_from_file_text(&info);

    initialize_pointer_array(&info);

    bubble_sort(&info);

    output_text(&info);

    return 0;
}
