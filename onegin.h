#ifndef ONEGIN_H
#define ONEGIN_H

struct Info_about_text
{
    int    max_number_line;
    int    size_text      ;
    char*  text           ;
    char** ptr_line       ;
};

enum Compare_const
{
    FIRST_CHAR_IS_BIGGER  =  1,
    CHARS_ARE_EQUAL       =  0,
    SECOND_CHAR_IS_BIGGER = -1,
    FIRST_LINE_IS_BIGGER  =  1,
    LINE_ARE_EQUAL        =  0,
    SECOND_LINE_IS_BIGGER = -1,
};

#endif /*ONEGIN_H*/
