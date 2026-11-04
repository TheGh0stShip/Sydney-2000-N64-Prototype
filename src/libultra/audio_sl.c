#include <libaudio.h>

void alLink(ALLink *link, ALLink *to) {
    link->next = to->next;
    link->prev = to;
    if (to->next) {
        to->next->prev = link;
    }
    to->next = link;
}

void alUnlink(ALLink *link) {
    if (link->next) {
        link->next->prev = link->prev;
    }
    if (link->prev) {
        link->prev->next = link->next;
    }
}
