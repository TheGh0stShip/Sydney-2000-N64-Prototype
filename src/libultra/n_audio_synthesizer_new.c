/* Compact audio synthesizer constructor from the Nintendo 64 SDK source. */
#include "n_audio_private.h"

extern s32 func_80101320();
extern s32 func_800FFA90();
extern void alN_PVoiceNew(N_PVoice *pv, void *dma, ALHeap *hp);
extern ALFx *func_80102980(s16 bus, ALSynConfig *c, ALHeap *hp);

void n_alSynNew(ALSynConfig *c)
{
    s32 i;
    N_PVoice *pvoices;
    ALHeap *hp = c->heap;
    ALParam *params;
    ALParam *paramPtr;

    n_syn->head = 0;
    n_syn->numPVoices = c->maxPVoices;
    n_syn->curSamples = 0;
    n_syn->paramSamples = 0;
    n_syn->outputRate = c->outputRate;
    n_syn->maxOutSamples = 184;
    n_syn->dma = c->dmaproc;
    n_syn->sv_dramout = 0;
    n_syn->sv_first = 1;

    n_syn->auxBus = alHeapAlloc(hp, 1, sizeof(N_ALAuxBus));
    n_syn->auxBus->sourceCount = 0;
    n_syn->auxBus->maxSources = c->maxPVoices;
    n_syn->auxBus->sources = alHeapAlloc(hp, c->maxPVoices, sizeof(N_PVoice *));

    n_syn->mainBus = alHeapAlloc(hp, 1, 0x14);

    if (c->fxType) {
        n_syn->auxBus->fx = func_80102980(0, c, hp);
        n_syn->mainBus->filter.handler = func_80101320;
    } else {
        n_syn->mainBus->filter.handler = func_800FFA90;
    }

    n_syn->pFreeList.next = 0;
    n_syn->pFreeList.prev = 0;
    n_syn->pLameList.next = 0;
    n_syn->pLameList.prev = 0;
    n_syn->pAllocList.next = 0;
    n_syn->pAllocList.prev = 0;

    pvoices = alHeapAlloc(hp, c->maxPVoices, sizeof(N_PVoice));
    for (i = 0; i < c->maxPVoices; i++) {
        N_PVoice *pv = &pvoices[i];
        alLink((ALLink *)pv, &n_syn->pFreeList);
        pv->vvoice = 0;
        alN_PVoiceNew(pv, n_syn->dma, hp);
        n_syn->auxBus->sources[n_syn->auxBus->sourceCount++] = pv;
    }

    params = alHeapAlloc(hp, c->maxUpdates, sizeof(ALParam));
    n_syn->paramList = 0;
    for (i = 0; i < c->maxUpdates; i++) {
        paramPtr = &params[i];
        paramPtr->next = n_syn->paramList;
        n_syn->paramList = paramPtr;
    }
    n_syn->heap = hp;
}
