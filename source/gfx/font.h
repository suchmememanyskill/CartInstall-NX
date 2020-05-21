#ifndef _FONT_H_
#define _FONT_H_


#include <stdbool.h>
#include <SDL2/SDL_ttf.h>


#define FONT_MAX 15
typedef enum
{
    QFontSize_15,
    QFontSize_18,
    QFontSize_20,
    QFontSize_23,
    QFontSize_25,
    QFontSize_28,
    QFontSize_30,
    QFontSize_33,
    QFontSize_35,
    QFontSize_45,
    QFontSize_48,
    QFontSize_60,
    QFontSize_63,
    QFontSize_72,
    QFontSize_170,
} QFontSize;

typedef struct
{
    TTF_Font *fnt;
} font_t;

extern font_t FONT_TEXT[];
extern font_t FONT_BUTTON[];

//
bool init_font();

//
font_t create_font_file(const char *file, int font_size);

//
font_t create_font_mem(void *mem, int mem_size, int font_size);

//
void free_font(font_t *font);

//
void exit_font();

#endif