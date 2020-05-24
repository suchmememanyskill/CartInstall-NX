#pragma once

enum GfxTypes{
    Type_Shape = 0,
    Type_Text,
    Type_Image
};

typedef struct _GfxEntry_Link {
    int type;
    void *obj;
    struct _GfxEntry_Link *next;
} GfxEntry_Link;

int GfxEntryLinkAdd(GfxEntry_Link *in, GfxEntry_Link **start);
GfxEntry_Link *GfxEntryLinkOffset(int offset, GfxEntry_Link **start);
void GfxEntryLinkClear(GfxEntry_Link **start);
GfxEntry_Link *GfxEntryLinkCreateLink(int type, void *ptr);