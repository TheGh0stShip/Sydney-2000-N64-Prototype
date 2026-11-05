typedef unsigned char u8;

extern u8 ceremonyGlobalObject[];
extern u8 ceremonyAudioState[];
extern u8 ceremonyInputState[];
extern u8 ceremonyOutputState[];

extern void func_800A7910(void *);
extern void func_80072364(void *);
extern void func_800C013C(void *);
extern void func_8001D550(void *, int);
extern void func_800A3240(void *);
extern void func_800A32CC(void *);
extern void func_800AC334(void *);
extern void func_800C0168(void *);
extern void func_800F01A8(void *);
extern void func_800BC274(void *);
extern void func_800AB240(void *);
extern void func_800A8850(void *);
extern void func_800AEFA0(void *);
extern void func_800AC308(void *);
extern void func_80017B24(void *);
extern void func_800BAC24(void);
extern void func_8007E7A0(void *);
extern void func_80014384(void);
extern void func_800137FC(void);
extern void func_80017A90(void *);

void func_80071838(u8 *state) {
    u8 *record;

    func_800A7910(state + 0xE8);
    if (state[0x235D] != 0) {
        func_80072364(state);
    }
    func_800C013C(ceremonyGlobalObject);
    func_8001D550(ceremonyAudioState, 1);
    func_800A3240(ceremonyAudioState);
    func_800A32CC(ceremonyAudioState);
    func_800AC334(ceremonyGlobalObject);
    func_800C0168(ceremonyGlobalObject);
    func_800F01A8(state + 0x1FD8);
    func_800BC274(ceremonyInputState);
    func_800AB240(ceremonyOutputState);
    record = state + 0x9AC;
    func_800AC334(record);
    func_800A8850(record);
    func_800AEFA0(state + 0x99C);
    func_800AEFA0(state + 0x98C);
    func_800AC308(state);
    func_800AC334(state + 0x250);
    func_80017B24(*(void **)(state + 0x230));
    record = state + 0xAA0;
    func_800BAC24();
    func_8007E7A0(record);
    func_800AC334(record);
    func_80014384();
    func_800137FC();
    func_80017A90((void *)0x80000000);
}
