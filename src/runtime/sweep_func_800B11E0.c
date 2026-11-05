/* Input handler: on a confirm press play the appropriate sound (and, when
 * allowed, post a select event); otherwise forward the key code. */
typedef struct Sound {
    char pad[104];
    int volume;
} Sound;

typedef struct Def {
    int pad0;
    unsigned int flags;
    char pad8[30 - 8];
    unsigned short eventId;
} Def;

typedef struct Widget {
    int pad0;
    int owner;
    char pad8[220 - 8];
    Def *def;
} Widget;

typedef struct Clock {
    int pad;
    int frame;
} Clock;

extern int func_8001D4B8(Sound *snd, int id, int a, int b);
extern void func_8001D640(Sound *snd, int voice, int volume);
extern void func_800AB2A4(void *queue, int frame, int type, int owner, int a, int b);
extern void func_800B1550(Widget *w, int key);
extern Sound D_800F1AE0;
extern char D_800F26E0[];
extern Clock D_800F2740;

static __inline__ int scale_volume(int volume, int level)
{
    return (volume * level) >> 15;
}

static __inline__ void play_sound(int id)
{
    int voice;

    voice = func_8001D4B8(&D_800F1AE0, id, 0, 1);
    func_8001D640(&D_800F1AE0, voice, scale_volume(D_800F1AE0.volume, 32767));
}

static __inline__ void post_event(int type, int owner, unsigned short id)
{
    func_800AB2A4(D_800F26E0, D_800F2740.frame, type, owner, 0, id);
}

void func_800B11E0(Widget *w, unsigned char *input)
{
    if (input[3] & 0x10) {
        if (w->def->flags & 0x80000) {
            play_sound(89);
        } else {
            play_sound(130);
            post_event(10, w->owner, w->def->eventId);
        }
    } else {
        func_800B1550(w, input[0]);
    }
}
