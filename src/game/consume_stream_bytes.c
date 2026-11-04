#ifndef LEAF_NAME
#define LEAF_NAME consumeStreamBytes
#endif

typedef signed char s8;
typedef unsigned char u8;
typedef signed int s32;
typedef unsigned int u32;

typedef struct StreamState {
    u8 padding0000[0x11A8];
    s32 countdown;
    u8 padding11AC[0x28];
    u32 cursor;
    u32 end;
    u8 padding11DC;
    s8 state;
} StreamState;

u32 LEAF_NAME(StreamState *stream, u32 amount) {
    register s32 state __asm__("$14") = stream->state;
    register s32 expected __asm__("$1") = 3;
    register u32 result __asm__("$2") = 0;

    __asm__("" : "=r"(state), "=r"(expected), "=r"(result)
            : "0"(state), "1"(expected), "2"(result));
    if (state != expected) {
        return result;
    }

    {
        register s32 countdown __asm__("$2") = stream->countdown;

        if (countdown > 0) {
            register s32 remaining __asm__("$15") = countdown - amount;

            __asm__("" : "=r"(remaining) : "0"(remaining));
            stream->countdown = remaining;
            if (remaining <= 0) {
                register s32 finishedState __asm__("$25") = 4;

                __asm__("" : "=r"(finishedState) : "0"(finishedState));
                stream->state = finishedState;
                stream->countdown = 0;
            }
        }
    }

    {
        register u32 cursor __asm__("$3") = stream->cursor;
        register u32 end __asm__("$8") = stream->end;
        register u32 available __asm__("$2") = end - cursor;
        register u32 compare __asm__("$1") = amount < available;
        register u32 consumed __asm__("$6") = available;
        register u32 updated __asm__("$9");

        __asm__("" : "=r"(cursor), "=r"(end), "=r"(available),
                "=r"(compare), "=r"(consumed)
                : "0"(cursor), "1"(end), "2"(available),
                "3"(compare), "4"(consumed));
        if (compare) {
            consumed = amount;
        }
        updated = cursor + consumed;
        __asm__("" : "=r"(updated), "=r"(consumed)
                : "0"(updated), "1"(consumed));
        stream->cursor = updated;
        return consumed;
    }
}
