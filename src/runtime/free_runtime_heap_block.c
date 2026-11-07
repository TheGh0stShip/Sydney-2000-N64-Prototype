typedef struct { char pad[9]; unsigned char state; unsigned char first; unsigned char last; int size; } Block;
extern unsigned int func_800AA650(void *heap);
void func_800AA658(void *heap, void **output)
{
    char *data = *output;
    Block *block;
    Block *next;
    Block *prev;
    int *footer;
    int size;
    int bsize;
    int nsize;
    int extent;
    unsigned char last;
    if (data) {
        block = (Block *)(data - 16);
        bsize = block->size;
        footer = (int *)(data + bsize);
        if (bsize != *footer) return;
        size = bsize;
        block->state = 0xFF;
        last = block->last;
        if (last != 0xFF) {
            next = (Block *)(footer + 1);
            if (next->state == 0xFF) {
                bsize = next->size;
                footer = (int *)((char *)next + (bsize + 16));
                if (bsize != *footer) return;
                extent = size + 20;
                size = extent + bsize;
                last = next->last;
            }
        }
        if (block->first != 0xFF) {
            bsize = ((int *)block)[-1];
            prev = (Block *)((char *)block - (bsize + 20));
            nsize = prev->size;
            if (nsize != bsize) return;
            if (prev->state == 0xFF) {
                block = prev;
                extent = size + 20;
                size = extent + nsize;
            }
        }
        block->last = last;
        block->size = size;
        *footer = size;
        *output = 0;
        func_800AA650(heap);
    }
}
