void func_800C8278(void *obj);


void func_800C8644(char *obj, int id, int keepPos)
{
    id--;
    if (*(int *)(obj + 764) == id) {
        return;
    }
    *(int *)(obj + 764) = id;
    if (id == 1023) {
        obj[777] = 0;
        *(int *)(obj + 192) |= 4;
    } else {
        if (obj[778] == 0) {
            func_800C8278(obj);
        }
        *(int *)(obj + 768) = 1;
        obj[777] = 1;
        if (keepPos) {
            float *src = (float *)(obj + 780);
            float *dst = (float *)(obj + 368);
            dst[0] = src[0];
            dst[1] = src[1];
            dst[2] = src[2];
            *(int *)(obj + 192) &= ~4;
        } else {
            *(int *)(obj + 192) |= 4;
        }
    }
    *(int *)(obj + 756) = 15;
    *(int *)(obj + 192) |= 4;
    *(float *)(obj + 772) = 180.21849060058594f;
}
