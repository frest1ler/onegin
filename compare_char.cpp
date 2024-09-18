#include <ctype.h>
#include "compare_char.h"

int compare_char(char a, char b)
{
    if ((a - b) > 0)
    {
        return 1;
    }
    if ((a - b) < 0)
    {
        return -1;
    }
    return 0;
}

int compare_caps_char(int y, int line_element, int skip_char_first_line,
                      int skip_char_second_line, char** ptr_to_new_line)
{
    char first  = toupper((ptr_to_new_line[y-1])[line_element + skip_char_first_line]);
    char second = toupper((ptr_to_new_line[y])[line_element + skip_char_second_line]);

    return compare_char(first, second);
}
