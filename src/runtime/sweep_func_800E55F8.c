/* Select a colour preset for the given mode and publish its RGB channels;
 * the bright presets also refresh the overlay widget and reset the fog. */
typedef struct Widget {
    char pad[192];
    int flags;
} Widget;

typedef struct Screen {
    char pad[192];
    Widget overlay;
} Screen;

typedef struct Rgb {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Rgb;

extern Rgb D_800FF3B0[];
extern int D_800FF3D4;
extern int D_800FF3D8;
extern int D_800FF3DC;
extern void func_800ADC1C(Widget *w);
extern void func_80017860(int on);
extern void func_80017820(int r, int g, int b, int a);

void func_800E55F8(Screen *s, unsigned int mode, unsigned int preset)
{
    Widget *w;

    switch (mode) {
    case 0:
        preset = 0;
        break;
    case 1:
        preset = 1;
        break;
    case 2:
        preset = 2;
        break;
    case 3:
        preset = 3;
        break;
    case 4:
        preset = 4;
        break;
    case 5:
        preset = 5;
        break;
    case 6:
        preset = 6;
        break;
    }
    D_800FF3D4 = D_800FF3B0[preset].r;
    D_800FF3D8 = D_800FF3B0[preset].g;
    D_800FF3DC = D_800FF3B0[preset].b;
    if (preset >= 4) {
        w = &s->overlay;
        func_800ADC1C(w);
        w->flags |= 4;
        func_80017860(1);
        func_80017820(0, 0, 0, 0);
    }
}
