typedef struct { int a[3]; } Item;
typedef struct { void *ptr; int type; int min; int max; int pad; Item *items; } Var;
typedef struct { char p0[28]; Var *var; } Info;
typedef struct { char p0[220]; Info *info; } Obj;

Item *func_800C3C0C(Obj *o)
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
    return &v->items[val];
}
