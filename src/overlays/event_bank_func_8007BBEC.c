typedef struct GameState {
    char pad0[2560];
    int mode;
} GameState;

typedef struct SoundBank {
    char pad0[0x68];
    int volume;
} SoundBank;

typedef struct Cue {
    int unk0;
    float pitch;
    int unk8;
    int sample;
} Cue;

typedef struct EventCtl {
    char pad0[0xC94];
    int state;
    unsigned char row;
    unsigned char col;
    char padC9A[3];
    unsigned char kind;
    char padC9E[2];
    int timer;
    char padCA4[0x14];
    Cue *cues;
    unsigned char *rowTags;
    char padCC0[0x4638 - 0xCC0];
    int voice;
    int loopVoice;
} EventCtl;

extern GameState *D_800FC270;
extern SoundBank D_800F1AE0;
extern char D_800F4D00[];
extern void func_8007D8A4(void *obj, Cue *row);
extern void func_8007B194(void *obj, int on);
extern void func_8001D5D8(SoundBank *bank, int voice, int a, int id, int b, int c);
extern int func_8001D4B8(SoundBank *bank, int id, int a, int b);
extern void func_8001D640(SoundBank *bank, int voice, int vol);
extern void func_80077EEC(char *self, int sample, int a, int b);
extern void func_800CFE1C(char *dst, int col, Cue *row);
extern void func_800D29E0(char *obj);
extern void func_800A9BE8(char *obj, int mode);
extern void func_8007DAA4(void *obj, int a, int b, int tag, Cue *cue, char *info);
extern void func_8009B9EC(int a, int b);

void func_8007BBEC(char *self)
{
    EventCtl *ctl = (EventCtl *)(self + 0x8000);
    int voice;
    char *info;

    ctl->timer -= 256;
    if (ctl->timer <= 0) {
        if (D_800FC270->mode == 4) {
            func_8007D8A4(*(void **)(self + 0x536C), &ctl->cues[ctl->row * 5]);
            func_8007B194(*(void **)(self + 0x536C), 1);
            ctl->state = 4;
            if (ctl->kind != 4) {
                int prev = ctl->voice;
                func_8001D5D8(&D_800F1AE0, prev, 0, 270, 1, 0);
            }
            {
                SoundBank *bank = &D_800F1AE0;
                voice = func_8001D4B8(bank, 270, 0, 1);
                {
                    int scale = 32767;
                    func_8001D640(bank, voice, (bank->volume * scale) >> 15);
                }
            }
            *(float *)(self + 0x5374) = ctl->cues[ctl->row * 5 + ctl->col].pitch;
            if (ctl->kind != 2) {
                func_80077EEC(self, ctl->cues[ctl->row * 5 + ctl->col].sample, 0, 0xF000);
                func_800CFE1C(self + 0x5394, ctl->col, &ctl->cues[ctl->row * 5]);
                func_800D29E0(self + 0x2E18);
                func_800D29E0(self + 0x3908);
                func_800D29E0(self + 0x3E80);
                func_800D29E0(self + 0x43F8);
            }
            if ((*(unsigned char **)(self + 0x536C))[0x380]) {
                func_800A9BE8(self + 0x86F8, 12);
            } else {
                func_800A9BE8(self + 0x86F8, 2);
            }
        } else {
            ctl->state = 2;
            if (ctl->kind != 4) {
                SoundBank *bank = &D_800F1AE0;
                {
                    int prev = ctl->voice;
                    func_8001D5D8(bank, prev, 0, 270, 1, 0);
                }
                voice = func_8001D4B8(bank, 269, 0, -1);
                func_8001D640(bank, voice, 0);
                {
                    int scale = 8191;
                    func_8001D5D8(bank, voice, (bank->volume * scale) >> 15, 195, 0, 0);
                }
                ctl->loopVoice = voice;
            }
            func_800A9BE8(self + 0x86F8, 3);
            func_800D29E0(self + 0x2E18);
            func_800D29E0(self + 0x3908);
            func_800D29E0(self + 0x3E80);
            func_800D29E0(self + 0x43F8);
            func_8007DAA4(*(void **)(self + 0x536C), 1, 0, ctl->rowTags[ctl->row],
                          &ctl->cues[ctl->row * 5 + ctl->col], (info = D_800F4D00) + 0xDC);
        }
    }
    if (((EventCtl *)(self + 0x8000))->kind != 4) {
        func_8009B9EC(19200, 24575);
    }
}
