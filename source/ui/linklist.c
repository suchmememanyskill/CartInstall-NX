#include "linklist.h"
#include <stdio.h> 
#include <stdlib.h> 

int GfxEntryLinkAdd(GfxEntry_Link *in, GfxEntry_Link **start){
    int offset = 0;

    if ((*start) == NULL){
        (*start) = in;
        return 0;
    }
    else {
        GfxEntry_Link *iter = (*start);
        while (iter != NULL){
            if (iter->next == NULL){
                iter->next = in;
                return offset;
            }

            iter = iter->next;
            offset++;
        }
    }
    return -1;
}

GfxEntry_Link *GfxEntryLinkOffset(int offset, GfxEntry_Link **start){
    GfxEntry_Link *iter = (*start);
    if (offset == 0 && iter != NULL){
        return iter;
    }

    for (int i = 0; i < offset && iter != NULL; i++){
        iter = iter->next;
    }

    return iter;
}

void GfxEntryLinkClear(GfxEntry_Link **start){
    return; // stubbed
}

GfxEntry_Link *GfxEntryLinkCreateLink(int type, void *ptr){
    GfxEntry_Link *link = calloc(sizeof(GfxEntry_Link), 1);
    link->obj = ptr;
    link->type = type;
    return link;
}