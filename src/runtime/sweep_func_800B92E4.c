typedef struct { char pad[0xC]; float *v; } Anim;

extern void func_800B8F68(char *o, short *ids, int n, int k);

void func_800B92E4(char *o)
{
    short ids[18] = { 11, 14, 13, 33, 22, 30, 3, 4, 5, 7, 8, 9, 17, 18, 19, 25, 26, 27 };

    func_800B8F68(o, ids, 18, 6);
    (*(Anim **)(o + 0xD0))->v[10] *= 4.0f;
    (*(Anim **)(o + 0xD0))->v[0] -= 0.9999997f;
    (*(Anim **)(o + 0xD0))->v[28] *= 3.0f;
    (*(Anim **)(o + 0xD0))->v[18] += 0.9999997f;
    (*(Anim **)(o + 0xD0))->v[46] *= 2.5f;
    (*(Anim **)(o + 0xD0))->v[36] -= 0.5000015f;
    (*(Anim **)(o + 0xD0))->v[38] += 1.5655353f;
}
