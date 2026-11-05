extern int func_8007AD10(void *object);

float func_80101828(void *object, unsigned char count)
{
    float total;
    float step;
    unsigned char index;

    total = 0.0f;
    index = 0;
    if (count != 0) {
        step = *(float *)0x80078B40;
        do {
            if (func_8007AD10(object) != 0) {
                total += step;
            }
            index++;
        } while (index < count);
    }
    return total;
}
