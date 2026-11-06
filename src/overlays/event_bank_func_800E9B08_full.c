typedef struct Anim {
    char pad[0x74];
} Anim;

typedef struct Obj {
    char pad0[0x1AD];
    unsigned char b1AD;
    short h1AE[8];
    char pad1BE[0x350 - 0x1BE];
    unsigned int *p350;
    char pad354[0x380 - 0x354];
    unsigned char b380;
    char pad381[0x39C - 0x381];
    Anim *p39C;
    char pad3A0[0x413 - 0x3A0];
    unsigned char b413;
    char b414;
    signed char b415;
} Obj;

extern unsigned int D_800F13F0;
extern Anim *D_8007879C;

void func_800E9B08(Obj *obj) {
    unsigned int word;
    unsigned int kind;
    unsigned int dir;
    unsigned char flag;
    int code;
    short *p;

    word = obj->p350[obj->b413 * 4];
    flag = (word >> 14) & 1;
    kind = word & 0x75F;
    dir = word & 0x3800;
    code = 0;
    if (obj->b415 == -1) {
        D_800F13F0 = (D_800F13F0 * 16807) & 0x7FFFFFFF;
        obj->b415 = D_800F13F0 >> 30;
    }
    p = obj->h1AE;
    switch (kind) {
    case 1:
    case 16:
        *p++ = 9;
        if (obj->b380 == 0) {
            code = 21;
        } else {
            code = 29;
        }
        break;
    case 2:
        *p++ = 10;
        code = 30;
        break;
    case 4:
    case 64:
        *p++ = 9;
        code = 32;
        break;
    case 8:
        *p++ = 10;
        code = 31;
        break;
    case 256:
        *p++ = 11;
        code = 33;
        break;
    case 1024:
        *p++ = 11;
        code = 35;
        break;
    case 512:
        *p++ = 12;
        code = 34;
        break;
    }
    *p++ = code;
    *p++ = -1;
    switch (kind) {
    case 16:
        code = 40;
        break;
    case 64:
        code = 49;
        break;
    case 1:
        if (flag) {
            code = 39;
            break;
        }
        switch (dir) {
        case 0x800:
            code = 39;
            break;
        case 0x2000:
            code = 38;
            break;
        case 0x1000:
            code = 37;
            if (obj->b415 == 0) {
                code = 36;
            }
            break;
        }
        break;
    case 2:
        if (flag) {
            code = 44;
            break;
        }
        switch (dir) {
        case 0x800:
            code = 44;
            break;
        case 0x2000:
            code = 43;
            break;
        case 0x1000:
            code = 42;
            if (obj->b415 == 0) {
                code = 41;
            }
            break;
        }
        break;
    case 4:
        if (flag) {
            code = 48;
            break;
        }
        switch (dir) {
        case 0x800:
            code = 48;
            break;
        case 0x2000:
            code = 47;
            break;
        case 0x1000:
            code = 46;
            if (obj->b415 == 0) {
                code = 45;
            }
            break;
        }
        break;
    case 8:
        if (flag) {
            code = 53;
            break;
        }
        switch (dir) {
        case 0x800:
            code = 53;
            break;
        case 0x2000:
            code = 52;
            break;
        case 0x1000:
            code = 51;
            if (obj->b415 == 0) {
                code = 50;
            }
            break;
        }
        break;
    case 256:
        switch (dir) {
        case 0x800:
            code = 57;
            break;
        case 0x2000:
            code = 56;
            break;
        case 0x1000:
            code = 55;
            if (obj->b415 == 0) {
                code = 54;
            }
            break;
        }
        break;
    case 1024:
        switch (dir) {
        case 0x800:
            code = 65;
            break;
        case 0x2000:
            code = 64;
            break;
        case 0x1000:
            code = 63;
            if (obj->b415 == 0) {
                code = 62;
            }
            break;
        }
        break;
    case 512:
        switch (dir) {
        case 0x800:
            code = 61;
            break;
        case 0x2000:
            code = 60;
            break;
        case 0x1000:
            code = 59;
            if (obj->b415 == 0) {
                code = 58;
            }
            break;
        }
        break;
    }
    p[0] = code;
    obj->p39C = D_8007879C + (code - 36);
    p[1] = -2;
    obj->b1AD = 0;
}
