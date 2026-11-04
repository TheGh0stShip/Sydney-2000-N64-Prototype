/* Custom compact-audio initialization preserved by the upstream libmus source. */
#include "n_synth_types.h"

extern N_ALGlobals *n_alGlobals;
extern N_ALSynth *alGlobals;
extern N_ALSynth *D_803AD9E0;

extern void func_800FEE60(ALSynConfig *c);
extern void func_800FE778(ALSynConfig *c);

void func_800FE710(N_ALGlobals *g, ALSynConfig *c)
{
    if (!n_alGlobals) {
        n_alGlobals = g;
        if (!alGlobals) {
            func_800FEE60(c);
            D_803AD9E0 = &n_alGlobals->drvr;
            alGlobals = &n_alGlobals->drvr;
            func_800FE778(c);
        }
    }
}
