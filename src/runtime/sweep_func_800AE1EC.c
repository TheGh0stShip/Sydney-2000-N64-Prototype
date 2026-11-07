typedef struct {
    char pad0[184]; int active;
    char pad1[200 - 188]; float val; float v204; float v208; float v212; float v216; float v220;
    int t224; int t228; int t232; int state;
} Obj;
extern void func_800AE17C(Obj *);
void func_800AE1EC(Obj *o, int now)
{
    if (now > o->t232) {
        if (o->active) {
            func_800AE17C(o);
            o->val = o->v212;
        }
    } else if (o->state == 3 || o->state == 4) {
        if (!(now > o->t224)) o->val = o->v204;
        else if (!(now > o->t228) && o->val < o->v208) o->val = o->val + o->v216;
        else if (now > o->t224 && !(now > o->t228)) o->val = o->v208;
        else if (now > o->t228 && o->val > o->v212) o->val = o->val + o->v220;
        else o->val = o->v212;
    }
}
