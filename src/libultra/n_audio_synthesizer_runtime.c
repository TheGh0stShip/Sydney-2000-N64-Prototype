/* Compact audio synthesizer runtime from the Nintendo 64 SDK source. */
#include "n_audio_private.h"

typedef union {
    struct {
        u32 w0;
        u32 w1;
    } words;
    long long force_structure_alignment;
} Acmd;

typedef s32 (*ALVoiceHandler)(void *);

extern Acmd *func_801028B0(s32 sampleOffset, Acmd *p);

s32 func_80102804(s32 micros);
void func_8010276C(void);

Acmd *func_801025C0(Acmd *cmdList, s32 *cmdLen, s16 *outBuf, s32 outLen)
{
    ALPlayer *client;
    Acmd *cmdlEnd = cmdList;
    s32 nOut;
    s16 *lOutBuf = outBuf;

    if (n_syn->head == 0) {
        *cmdLen = 0;
        return cmdList;
    }

    client = n_syn->head;
    while (client->samplesLeft - n_syn->curSamples < outLen) {
        n_syn->paramSamples = client->samplesLeft & ~0xF;
        client->samplesLeft += func_80102804(((ALVoiceHandler)client->handler)(client));
    }
    n_syn->paramSamples = n_syn->paramSamples & ~0xF;

    while (outLen > 0) {
        nOut = n_syn->maxOutSamples;
        if (outLen < nOut)
            nOut = outLen;
        n_syn->sv_dramout = (s32)lOutBuf;
        cmdlEnd = func_801028B0(n_syn->curSamples, cmdlEnd);
        outLen -= nOut;
        lOutBuf += nOut << 1;
        n_syn->curSamples += nOut;
    }
    *cmdLen = cmdlEnd - cmdList;
    func_8010276C();
    return cmdlEnd;
}

ALParam *__allocParam(void)
{
    ALParam *update = 0;

    if (n_syn->paramList) {
        update = n_syn->paramList;
        n_syn->paramList = n_syn->paramList->next;
        update->next = 0;
    }
    return update;
}

void __freeParam(ALParam *param)
{
    param->next = n_syn->paramList;
    n_syn->paramList = param;
}

void func_8010276C(void)
{
    ALLink *dl;

    while ((dl = n_syn->pLameList.next) != 0) {
        alUnlink(dl);
        alLink(dl, &n_syn->pFreeList);
    }
}

void _n_freePVoice(N_PVoice *pvoice)
{
    alUnlink((ALLink *)pvoice);
    alLink((ALLink *)pvoice, &n_syn->pLameList);
}

inline s32 func_80102804(s32 micros)
{
    f32 tmp = ((f32)micros) * n_syn->outputRate / 1000000.0 + 0.5;

    return (s32)tmp;
}

s32 func_80102854(s32 micros)
{
    return func_80102804(micros) & ~0xF;
}
