#ifndef ONEGIN_H
#define ONEGIN_H

struct Interaction_files
{
    char symbol;
    int  number_line;
    int  line_element;
    int  skip_char_first_line;
    int  skip_char_second_line;
};

struct Text_processing 
{
    int    max_number_line;
    int    size_text;
    char*  text;
    char** ptr_line;
};

const int MAXIMUM_NUMBER_OF_COLUMNS = 15;

#endif /*ONEGIN_H*/
