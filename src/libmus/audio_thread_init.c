/* Audio-thread initialization preserved by the upstream libmus source. */
#include "os_types.h"
#include "n_synth_types.h"

typedef struct {
    u32 control_flag;
    s32 channels;
    void *sched;
    s32 thread_priority;
    u8 *heap;
    s32 heap_length;
    u8 *ptr;
    u8 *wbk;
    void *default_fxbank;
    s32 fifo_length;
    s32 syn_updates;
    s32 syn_output_rate;
    s32 syn_rsp_cmds;
    s32 syn_retraceCount;
    s32 syn_num_dma_bufs;
    s32 syn_dma_buf_size;
} musConfig;

typedef struct {
    s16 *ptr;
    s32 len;
} audio_buf_t;

typedef u64 Acmd;

extern N_ALGlobals D_803ADC30;
extern Acmd *D_803ADC28;
extern audio_buf_t *D_803ADC24;
extern void *D_803ADC20;
extern u8 D_803ADA70[];

extern void *__MusIntMemMalloc(s32 size);
extern void *func_800FEF60(s32 count, s32 size);
extern ALHeap *func_800FF9E4(void);
extern void func_800FE710(N_ALGlobals *g, ALSynConfig *c);
extern s32 func_800FF820(s32 retraceCount, s32 outputRate, s32 viRate, s32 extraPercent);
extern s32 osAiSetFrequency(u32 frequency);
extern void osCreateThread(void *t, s32 id, void (*entry)(void *), void *arg, void *sp, s32 pri);
extern void osStartThread(void *t);

void func_800FF698(void *arg);

void func_800FF560(musConfig *config, s32 viRate, s32 fxType)
{
    ALSynConfig c;
    s32 frameSize;
    u32 i;
    u8 *stack;

    c.maxVVoices = c.maxPVoices = config->channels;
    c.maxUpdates = config->syn_updates;
    c.dmaproc = func_800FEF60(config->syn_num_dma_bufs, config->syn_dma_buf_size);
    c.fxType = fxType;
    c.outputRate = osAiSetFrequency(config->syn_output_rate);
    c.heap = func_800FF9E4();
    func_800FE710(&D_803ADC30, &c);
    frameSize = func_800FF820(config->syn_retraceCount, c.outputRate, viRate, 15);
    D_803ADC28 = __MusIntMemMalloc(config->syn_rsp_cmds * sizeof(Acmd));
    D_803ADC24 = __MusIntMemMalloc(3 * sizeof(audio_buf_t));
    for (i = 0; i < 3; i++)
        D_803ADC24[i].ptr = __MusIntMemMalloc(frameSize * 4);
    stack = __MusIntMemMalloc(0x2000);
    D_803ADC20 = stack;
    osCreateThread(D_803ADA70, 3, func_800FF698, 0, stack + 0x2000, config->thread_priority);
    osStartThread(D_803ADA70);
}
