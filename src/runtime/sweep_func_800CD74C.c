typedef struct {
    char pad[12];
    int value;
} Track;

Track *func_8001A154(void *anim);
Track *func_8001A148(void *anim);
void func_8001A188(void *anim, float t, int value);
void func_8001A1B0(void *anim, float t, int value);

void func_800CD74C(char *obj)
{
    float *src = *(float **)(obj + 464);
    void *anim;
    Track *a;
    Track *b;

    if (src != 0) {
        *(float *)(obj + 452) = src[3];
    }
    if (*(float *)(obj + 452) > *(float *)(obj + 460)) {
        *(float *)(obj + 452) = *(float *)(obj + 460);
    }
    if (*(float *)(obj + 452) < 0.0f) {
        *(float *)(obj + 452) = 0.0f;
    }
    if (*(float *)(obj + 460) != 1.0f) {
        *(float *)(obj + 456) = *(float *)(obj + 452) / *(float *)(obj + 460);
    } else {
        *(float *)(obj + 456) = *(float *)(obj + 452);
    }
    anim = obj + 424;
    *(float *)(obj + 436) = *(float *)(obj + 432);
    a = func_8001A154(anim);
    b = func_8001A148(anim);
    func_8001A188(anim, *(float *)(obj + 440) * *(float *)(obj + 456), a->value);
    func_8001A1B0(anim, *(float *)(obj + 456), b->value);
}
