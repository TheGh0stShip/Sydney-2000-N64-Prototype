typedef struct {
    unsigned char data[192];
    int flags;
    unsigned char rest[16];
} Part;

typedef struct {
    Part self;
    unsigned char pad[4];
    Part parts[8];
} Group;

void func_800CC310(Group *object)
{
    unsigned char bits = ((unsigned char *)object)[1927];
    unsigned char i;

    ((unsigned char *)object)[1927] = bits & ~2;
    bits &= 0x21;
    if (bits == 1) {
        i = 0;
    } else if (bits == 32) {
        i = 2;
    } else {
        i = 3;
    }
loop:
    if (i < 8) {
        ((Part *)((unsigned char *)object + 216))[i].flags |= 4;
        i++;
        goto loop;
    }
    object->self.flags |= 4;
}
