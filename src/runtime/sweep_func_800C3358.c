typedef struct { char p0[160]; float x; char p1[192 - 164]; unsigned int flags; } Btn;
typedef struct { void *ptr; int type; int min; int max; } Var;
typedef struct { char p0[28]; Var *var; } Info;
typedef struct { char p0[220]; Info *info; char p1[712 - 224]; Btn *b0; Btn *b1; Btn *b2; } Obj;

void func_800C3358(Obj *o)
{
    Var *v = o->info->var;
    int val = 0;

    switch (v->type) {
    case 0: val = *(int *)v->ptr; break;
    case 1: val = *(short *)v->ptr; break;
    case 2: val = *(signed char *)v->ptr; break;
    }
    if (val < v->min || v->max < val) {
        if (v->max < val) val = v->max;
        else val = v->min;
        switch (v->type) {
        case 0: *(int *)v->ptr = val; break;
        case 1: *(short *)v->ptr = val; break;
        case 2: *(signed char *)v->ptr = val; break;
        }
    }
    o->b0->x = 130.0f / (v->max - v->min) * val + 267.0f;
    if (val == v->max) o->b2->flags |= 4;
    else o->b2->flags &= ~4;
    if (val == v->min) o->b1->flags |= 4;
    else o->b1->flags &= ~4;
}
