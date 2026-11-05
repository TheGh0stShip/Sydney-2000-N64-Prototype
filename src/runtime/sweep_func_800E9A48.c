typedef struct {
    short offset;
    short pad;
    void (*func)(void *self);
} VtEntry;

typedef struct {
    char pad[64];
    VtEntry start;
    VtEntry stop;
} Vtable;

typedef struct {
    char pad[180];
    Vtable *vtable;
    int queued;
    int playing;
    char tail[40];
} Channel;

typedef struct {
    char pad[26488];
    Channel music;
    Channel ambience;
} AudioOwner;

extern void func_8001A024(int paused);

void func_800E9A48(AudioOwner *owner, int resume)
{
    Channel *music;
    Channel *ambience;
    int active;

    if (resume) {
        music = &owner->music;
        active = 1;
        if (music->playing == 0) {
            active = music->queued != 0;
        }
        if (!active) {
            owner->music.vtable->start.func((char *)music + owner->music.vtable->start.offset);
            ambience = &owner->ambience;
            owner->ambience.vtable->start.func((char *)ambience + owner->ambience.vtable->start.offset);
            func_8001A024(1);
        }
    } else {
        music = &owner->music;
        active = 1;
        if (music->playing == 0) {
            active = music->queued != 0;
        }
        if (active) {
            owner->music.vtable->stop.func((char *)music + owner->music.vtable->stop.offset);
            ambience = &owner->ambience;
            owner->ambience.vtable->stop.func((char *)ambience + owner->ambience.vtable->stop.offset);
            func_8001A024(0);
        }
    }
}
