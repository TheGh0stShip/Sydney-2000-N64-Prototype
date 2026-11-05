/* Runtime-stage C reconstruction: detach a record from its owner and release its two linked blocks. */
typedef struct RuntimeLink {
    void *owner;
    void *first;
    void *second;
    int state;
    unsigned short pending;
} RuntimeLink;

extern void func_800AA658(void *owner, void **slot);

void func_800AB684(RuntimeLink *link) {
    void *owner = link->owner;

    if (owner) {
        link->owner = 0;
        if (link->first) {
            unsigned short n = link->pending;

            while (n) n--;
            link->pending = 0;
            func_800AA658(owner, &link->first);
        }
        if (link->second) func_800AA658(owner, &link->second);
        link->state = 0;
    }
}
