typedef struct RuntimeState {
    unsigned char pad[4493];
    unsigned char phase;
    unsigned char mode;
    unsigned char flags;
} RuntimeState;

void func_8009A64C(RuntimeState *state)
{
    if (state->phase >= 4) {
        state->mode = 0xFF;
        state->flags |= 0x40;
    }
}
