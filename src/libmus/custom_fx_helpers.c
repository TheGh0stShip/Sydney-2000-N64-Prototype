/* Custom compact-audio effects helpers preserved by the upstream libmus source. */
#include "n_synth_types.h"

extern N_ALSynth *D_803AD9E0;
extern s32 D_801266B8[];
extern s32 D_80126840;
extern s32 *D_80126844[];
extern s32 alFxParam(void *filter, s32 paramID, void *param);
extern void func_800FEB80(s32 *param);

void func_800FEE60(ALSynConfig *c)
{
    c->fxType = 6;
    c->params = D_801266B8;
}

s32 func_800FEE78(void)
{
    s32 i = 0;
    s32 max = 0;

    while (D_80126844[i]) {
        if (max < D_80126844[i][0])
            max = D_80126844[i][0];
        i++;
    }
    return max;
}

s32 func_800FEEBC(void)
{
    s32 i = 0;
    s32 max = 0;

    while (D_80126844[i]) {
        if (max < D_80126844[i][1])
            max = D_80126844[i][1];
        i++;
    }
    return max;
}

s32 ChangeCustomEffect(s32 type)
{
    if (type >= D_80126840)
        return 1;
    func_800FEB80(D_80126844[type]);
    alFxParam(D_803AD9E0->auxBus->fx, 1, D_803AD9E0->auxBus);
    return 0;
}
