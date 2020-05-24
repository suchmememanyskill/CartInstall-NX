#include <switch.h>
#include "mainmenu.h"
#include "linklist.h"
#include "../gfx/shape.h"
#include "../gfx/text.h"

#define GFX_CREATEANDADD(type, ptr, link) GfxEntryLinkAdd(GfxEntryLinkCreateLink(type, ptr), link)

void test(){
    GfxEntry_Link *link = NULL;
    GFX_CREATEANDADD(Type_Shape, create_shape_ptr(Colour_Nintendo_Red, 0, 0, SCREEN_W, SCREEN_H, true), &link);
    GFX_CREATEANDADD(Type_Shape, create_shape_ptr(Colour_Nintendo_LightBlack, 30, 90, 375, 555, true), &link);
    GFX_CREATEANDADD(Type_Shape, create_shape_ptr(Colour_Nintendo_White, 30, (SCREEN_H / 8), SCREEN_W - (30 * 2), 2, true), &link);
    GFX_CREATEANDADD(Type_Shape, create_shape_ptr(Colour_Nintendo_White, 30, 650, SCREEN_W - (30 * 2), 2, true), &link);
    GFX_CREATEANDADD(Type_Shape, create_shape_ptr(Colour_Nintendo_Cyan, 90, 230, 4, 45, true), &link);
    GFX_CREATEANDADD(Type_Text , create_text(&FONT_TEXT[QFontSize_25], 130, 40, Colour_Nintendo_White, "Does this work?"), &link);

    while (1){
        hidScanInput();
        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
        if (kDown & KEY_PLUS)
            break;

        SDL_ClearRenderer();
        DrawMenuListItems(link);
        SDL_UpdateRenderer();
    }
}

void DrawMenuListItems(GfxEntry_Link *items){
    GfxEntry_Link *iter = items;
    while (iter != NULL){
        switch (iter->type){
            case Type_Image:
                break; //stubbed
            case Type_Shape:
                draw_shape((shape_t*)iter->obj);
                break;
            case Type_Text:
                draw_text((text_t*)iter->obj);
                break;
        }

        iter = iter->next;
    }
}