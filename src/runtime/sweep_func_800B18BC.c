typedef struct {
    void *dest;
    int type;
    int value;
    int extra;
    int pad10;
    unsigned short *source;
    short tag;
} ParamBinding;

typedef struct {
    unsigned char pad0[18];
    unsigned short id;
    unsigned char pad14[8];
    ParamBinding *binding;
} ParamNode;

typedef struct {
    unsigned char pad0[220];
    ParamNode *node;
} ParamOwner;

extern void func_800B0F60();

void func_800B18BC(ParamOwner *owner, unsigned short *source, int value, int extra, int tag, int refresh)
{
    ParamBinding *binding;

    binding = owner->node->binding;
    binding->tag = tag;
    if (binding->source == source) {
        return;
    }
    owner->node->id = *source;
    binding->source = source;
    binding->extra = extra;
    binding->value = value;
    switch (binding->type) {
    case 2:
        *(char *)binding->dest = value;
        break;
    case 1:
        *(short *)binding->dest = value;
        break;
    case 0:
        *(int *)binding->dest = value;
        break;
    }
    if (refresh) {
        func_800B0F60();
    }
}
