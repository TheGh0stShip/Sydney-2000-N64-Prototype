/* Run each non-null callback while retaining the original state argument. */
typedef struct AudioState AudioState;
struct AudioState { unsigned int unused[3]; void (*callbacks[4])(AudioState *); };
void func_800A2FCC(AudioState *state) {
    int index = 0;
    AudioState *entry = state;
    do {
        if (entry->callbacks[0]) entry->callbacks[0](state);
        index++;
        entry = (AudioState *)((unsigned char *)entry + 4);
    } while (index < 4);
}
