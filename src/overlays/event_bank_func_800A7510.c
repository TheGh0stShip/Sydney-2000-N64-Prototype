/* Grade the current attempt against target values and play rating sounds. */
typedef struct {
    unsigned char pad0[0x2E4];
    unsigned char inactive;
    unsigned char pad2E5[0x2F4 - 0x2E5];
    float limit;
    float vec[3];
    unsigned char pad304[0x34C - 0x304];
    float value;
} GradeObj;

typedef struct {
    unsigned char pad0[0xA00];
    int column;
    unsigned char padA04[0xD53 - 0xA04];
    unsigned char row;
} GradeTable;

typedef struct {
    unsigned char pad0[0x2FB4];
    GradeObj *obj;
    unsigned char pad2FB8[0x7CAF - 0x2FB8];
    unsigned char mode;
    unsigned char pad7CB0[0x7D0C - 0x7CB0];
    unsigned char grade;
} GradeOwner;

extern GradeTable *D_800FC270;
extern float D_80077450[][7];
extern char D_800F3BC0[];
extern void func_800C0110(char *bank, int id, int a, int b);

#define K(addr) (*(float *)(addr))
#define QUIET(p) ((unsigned char)((p)->mode - 3) < 2)

void func_80076510(GradeOwner *p)
{
    unsigned char s4 = 0;
    unsigned char s3 = s4;
    unsigned char s0 = s4;
    GradeObj *o = p->obj;
    float limit = o->limit;
    float x = 0.0f;
    float *vec;
    float t;
    float d;
    float v;
    p->grade = 0;
    vec = o->vec;
    if (p->obj->inactive == 0) x = p->obj->value;
    if (x <= 0.0f) {
        return;
    }
    t = D_80077450[D_800FC270->row][D_800FC270->column];
    if (limit < t * K(0x80071628)) {
        if (!QUIET(p)) {
            func_800C0110(D_800F3BC0, 542, 7680, 23040);
        }
    } else if (limit < t) {
        if (!QUIET(p)) {
            func_800C0110(D_800F3BC0, 541, 7680, 23040);
        }
        s4 = 4;
    } else {
        if (!QUIET(p)) {
            func_800C0110(D_800F3BC0, 543, 7680, 23040);
        }
        s4 = 8;
    }

    v = vec[0];
    d = K(0x8007162C);
    d = d - v;
    if (d < 0.0f) {
        d = -d;
    }
    if (d < K(0x80071630)) {
        if (!QUIET(p)) {
            func_800C0110(D_800F3BC0, 546, 0xB400, 0x12C00);
        }
        s3 = 4;
    } else if (d < K(0x80071634)) {
        if (!QUIET(p)) {
            func_800C0110(D_800F3BC0, 544, 0xB400, 0x12C00);
        }
        s3 = 2;
    } else {
        if (!QUIET(p)) {
            func_800C0110(D_800F3BC0, 545, 0xB400, 0x12C00);
        }
    }

    v = vec[1];
    d = K(0x80071638);
    d = d - v;
    if (d < 0.0f) {
        d = -d;
    }
    if (d < K(0x8007163C)) {
        s0 += 2;
    } else if (d < K(0x80071640)) {
        s0 += 1;
    }

    v = vec[2];
    d = K(0x80071644);
    d = d - v;
    if (d < 0.0f) {
        d = -d;
    }
    if (d < K(0x80071648)) {
        s0 += 2;
    } else if (d < K(0x8007164C)) {
        s0 += 1;
    }

    if (s0 < 2) {
        if (!QUIET(p)) {
            func_800C0110(D_800F3BC0, 548, 0x16800, 0x25800);
        }
    } else if (s0 < 4) {
        if (!QUIET(p)) {
            func_800C0110(D_800F3BC0, 547, 0x16800, 0x25800);
        }
    } else {
        if (!QUIET(p)) {
            func_800C0110(D_800F3BC0, 549, 0x16800, 0x25800);
        }
    }
    p->grade = s0 + (s4 + s3);
}
