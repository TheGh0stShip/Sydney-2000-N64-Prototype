/* Optionally draw the layer (shifted by the object's offset) and optionally
 * start a sound at full volume scaled by the channel volume. */
typedef struct View {
    short x;
    short y;
} View;

typedef struct Sound {
    char pad[104];
    int volume;
} Sound;

extern void func_800D33A0(void *layer, View *view, int a, int b);
extern int func_8001D4B8(Sound *snd, int id, int a, int b);
extern void func_8001D640(Sound *snd, int voice, int volume);
extern View D_800F1888;
extern Sound D_800F1AE0;

static __inline__ int scale_volume(int volume, int level)
{
    return (volume * level) >> 15;
}

void func_8009D708(char *obj, int playSound, int draw)
{
    int off;
    int voice;

    if (draw) {
        off = *(short *)(obj + 19076);
        D_800F1888.y += off;
        func_800D33A0(obj + 19088, &D_800F1888, 0, -1);
        off = *(short *)(obj + 19076);
        D_800F1888.y -= off;
    }
    if (playSound) {
        voice = func_8001D4B8(&D_800F1AE0, 183, 0, 1);
        func_8001D640(&D_800F1AE0, voice, scale_volume(D_800F1AE0.volume, 32767));
    }
}
