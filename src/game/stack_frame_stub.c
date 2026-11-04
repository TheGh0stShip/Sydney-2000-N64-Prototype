#ifndef STUB_NAME
#define STUB_NAME stackFrameStub
#endif

#ifndef FRAME_SIZE
#define FRAME_SIZE 1
#endif

void STUB_NAME(void) {
    volatile unsigned char frame[FRAME_SIZE];
}
