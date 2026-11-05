/* Runtime-stage C reconstruction: on activation, enable the audio service and start the stage cue. */
typedef struct {
    char pad0[0x64];
    int scale;            /* 0x64 */
} AudioService;

typedef struct {
    char pad0[0x284];
    int mode;             /* 0x284 */
    char pad288[0xAD0 - 0x288];
    int cue;              /* 0xAD0 */
    char padAD4[4];
    int cueSound;         /* 0xAD8 */
} Stage;

extern AudioService D_800F1AE0;
extern void func_8000F42C(void);
extern void func_800B4794(int);
extern int func_800A3404(void *object, int enable);
extern int func_8001D6CC(AudioService *service, int sound, int a, int b);
extern void func_8001D640(AudioService *service, int voice, int volume);

static inline void setVoiceVolume(AudioService *service, int voice, int volume) {
    func_8001D640(service, voice, (service->scale * volume) >> 15);
}

void func_800D5108(Stage *stage) {
    if (stage->mode == 1) {
        func_8000F42C();
        func_800B4794(1);
        func_800A3404(&D_800F1AE0, 1);
        if (stage->cue != -1) {
            setVoiceVolume(&D_800F1AE0, func_8001D6CC(&D_800F1AE0, stage->cueSound, 0, 0), 0x7FFF);
        }
    }
}
