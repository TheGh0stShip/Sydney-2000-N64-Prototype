typedef struct { char pad[14]; short height; char pad2[16]; } Node;
extern Node *func_800DCCF4(void *);

void func_800B19D8(char *obj)
{
    char *owner = *(char **)(obj + 4);
    Node *nodes = func_800DCCF4(owner);
    short a = (*(Node **)(obj + 220))->height;
    short b = nodes[*(unsigned char *)(owner + 477)].height;
    float fd;
    fd = (a > b) ? a - b : b - a;
    fd += 658.0f;

    *(float *)(obj + 160) = *(float *)(obj + 772) + fd;
}
