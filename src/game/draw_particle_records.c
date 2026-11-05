/* NONMATCHING: func_80016120 (0x11AC bytes), SN gcc -O2. Lane07 score 662 under the explicit-symbol
 * --no-infer check (compiled 0x11BC vs 0x11AC); .rodata (7 literals @0x80000C64) and the 0xE0 frame match.
 * History: lane e09 reached 764 (standard command) with unrotated for(;;)+label loops and an inline
 * initTransform. Lane07: (u32)depth is written as an explicit inline fixuns (floatToU32, the
 * `!(limit <= f)` form, `| 0x80000000`), so gcc no longer merges and hoists the 2^31 constant into
 * f24/f26 (764 -> 675). Permuter-found orderings, ported by hand: lastTexture before matrix, sy before
 * sx in the rect pass, inverted 0x100 color select in the rect pass, E4 operand order (-> 662).
 * Remaining differences:
 * - the original keeps record in stack slot 0x94 (plus an s3 giv at record+0x34); this build keeps
 *   record in a register and fills next_record branches with branch-likely + `addiu s3,0x40`;
 * - the original allocates rectCount/lastColor to t8/t9 with caller-saves around the calls.
 * Callee symbols: updateRenderObject=0x80012834 testSpherePlane=0x800179A0
 *   applyRenderObjectState=0x80012BD8 buildFlaggedModelMatrix=0x8000D41C.
 */
#ifndef LEAF_NAME
#define LEAF_NAME drawParticleRecords
#endif

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    u32 w0;
    u32 w1;
} DisplayWords;

typedef union {
    DisplayWords words;
    long long alignment;
} DisplayCommand;

typedef struct {
    u8 data[0x40];
} Mtx;

typedef struct {
    float m[4][4];
    float pos[3];
} Transform;

typedef struct {
    s16 scale[4];
    s16 trans[4];
} Viewport;

typedef struct {
    u32 identifier;
    u8 padding04[4];
    u16 field08;
    u8 padding0A[6];
    DisplayWords commands[25];
    u8 *info;
    u8 paddingDC[4];
} TextureEntry;

typedef struct ParticleModel {
    u32 flags;
    u8 padding04[0x34];
    float width;
    float height;
    u8 padding40[0x1C];
    void *displayLists[2];
    u8 padding64[0x0C];
    u16 texture;
    u8 padding72[0x06];
    float radius;
} ParticleModel;

typedef struct ParticleRecord {
    u16 flags;
    u8 padding02[0x02];
    float x;
    float y;
    float z;
    u8 padding10[0x14];
    float scale;
    u8 padding28[0x04];
    u16 blend;
    u8 padding2E[0x06];
    u32 color;
    u32 color2;
    ParticleModel *model;
} ParticleRecord;

typedef struct ParticleNode {
    u8 padding00[0x04];
    u32 count;
    ParticleRecord *records;
    struct ParticleNode *next;
} ParticleNode;

typedef struct ParticleOwner {
    u8 padding00[0xBC];
    ParticleNode *nodes;
} ParticleOwner;

extern DisplayCommand *displayListHead __asm__("D_800663DC");
extern DisplayCommand *listStarts[] __asm__("D_80039310");
extern u32 listIndex __asm__("D_80066490");
extern u32 currentPlayer __asm__("D_8005A93C");
extern u32 screenWidth __asm__("D_8005A824");
extern u32 screenHeight __asm__("D_8005A828");
extern float viewMatrix[4][4] __asm__("D_8005A538");
extern Viewport viewports[] __asm__("D_8005F910");
extern DisplayCommand *rectLists[] __asm__("D_8005AA90");
extern u32 rectCapacity __asm__("D_8005ACA4");
extern u32 depthEnabled __asm__("D_8005A934");
extern u32 alphaLimitEnabled0 __asm__("D_800F125C");
extern u32 alphaLimitEnabled1 __asm__("D_800F125C");
extern u32 alphaLimitEnabled2 __asm__("D_800F125C");
extern u32 alphaLimitEnabled3 __asm__("D_800F125C");
extern u32 alphaLimit __asm__("D_8005A950");
extern TextureEntry textures[] __asm__("D_80049A28");
extern DisplayCommand skeletonEndList[] __asm__("D_80065FB8");
extern u32 allocationCount __asm__("D_8005B7F8");
extern Mtx scratchMatrices[][2] __asm__("D_8005B800");

extern void updateRenderObject(ParticleModel *);
extern int testSpherePlane(float *, float, u32);
extern void applyRenderObjectState(ParticleModel *, u32);
extern void buildFlaggedModelMatrix(DisplayCommand **, void *, Mtx *, u32);

static __inline__ Mtx *allocateMatrix(void)
{
    u32 allocation = allocationCount;

    if (allocation >= 128) {
        return &scratchMatrices[0][currentPlayer];
    }
    allocationCount = allocation + 1;
    return &scratchMatrices[allocation][currentPlayer];
}

static __inline__ u32 blendColor(ParticleRecord *record)
{
    u32 t = record->blend;
    u32 from = record->color;
    u32 to = record->color2;
    u32 r;
    u32 g;
    u32 b;
    u32 a;

    if (t == 0) {
        return from;
    }
    if (t >= 0xFFF) {
        return to;
    }
    r = ((to & 0xFF) * t + (from & 0xFF) * (0x1000 - t)) >> 12;
    g = (((to >> 8) & 0xFF) * t + ((from >> 8) & 0xFF) * (0x1000 - t)) >> 12;
    b = (((to >> 16) & 0xFF) * t + ((from >> 16) & 0xFF) * (0x1000 - t)) >> 12;
    a = ((to >> 24) * t + (from >> 24) * (0x1000 - t)) >> 12;
    if (r > 0xFF) {
        r = 0xFF;
    }
    if (g > 0xFF) {
        g = 0xFF;
    }
    if (b > 0xFF) {
        b = 0xFF;
    }
    if (a > 0xFF) {
        a = 0xFF;
    }
    return r | (g << 8) | (b << 16) | (a << 24);
}

static __inline__ void initTransform(Transform *t)
{
    t->m[2][1] = 0.0f;
    t->m[2][0] = 0.0f;
    t->m[1][2] = 0.0f;
    t->m[1][0] = 0.0f;
    t->m[0][2] = 0.0f;
    t->m[0][1] = 0.0f;
    t->pos[2] = 0.0f;
    t->pos[1] = 0.0f;
    t->pos[0] = 0.0f;
    t->m[2][2] = 1.0f;
    t->m[1][1] = 1.0f;
    t->m[0][0] = 1.0f;
}

static __inline__ u32 floatToU32(float f)
{
    register float value __asm__("$f2") = f;
    float limit = 2147483648.0f;
    if (!(limit <= value)) {
        int number = (int)value;
        __asm__("" : : "r"(number) : "$2");
        
        return number;
    }
    {
        register float lower __asm__("$f0") = value - limit;
        int number = (int)lower;
        
        return number | 0x80000000;
    }
}

#define EMIT(first, second)                           \
    {                                                 \
        DisplayCommand *command_ = displayListHead++; \
        command_->words.w0 = (first);                 \
        command_->words.w1 = (u32)(second);           \
    }

#define EMIT_TO(cursor, first, second)                \
    {                                                 \
        DisplayCommand *command_ = (cursor)++;        \
        command_->words.w0 = (first);                 \
        command_->words.w1 = (u32)(second);           \
    }

void LEAF_NAME(ParticleOwner *owner)
{
    Transform transform;
    u32 rectCount;
    u32 lastColor;
    int pass;
    int view;
    ParticleNode *node;
    ParticleRecord *record;
    u32 count;
    Viewport *vp;
    u32 lastPrim;
    int halfWidth;
    int halfHeight;
    int dsdx;
    int dtdy;
    int bottom;
    int white;
    register u32 clearMode __asm__("$5");
    register u32 height __asm__("$4");
    u16 lastTexture;
    float (*matrix)[4];

    rectCount = 0;
    lastColor = 0;
    view = 0;
    lastPrim = 0;
    lastTexture = 0xFFFF;
    height = screenHeight;
    white = -1;
    __asm__("" : "+r"(white) :  : "$5", "$6", "$7", "$8", "$9", "$10", "$11");
    bottom = height + white;
    clearMode = 0xD9FFF9FF;
    initTransform(&transform);

    EMIT(0xF8000000, white);
    EMIT(clearMode, 0);

    pass = 0;
    matrix = viewMatrix;
    for (;;) {
    pass_top:
        if (pass >= 3) {
            break;
        }
        if (pass == 0) {
            EMIT(0xE7000000, 0);
            EMIT(0xE3000A01, 0);
            if (alphaLimitEnabled0 != 0) {
                EMIT(0xE200001C, 0x055A4B50);
            }
            EMIT(0xF9000000, 0xFFFFFF01);
            EMIT(0xE2001E01, 1);
            EMIT(0xFC119623, 0xFF2FFFFF);
        } else if (pass == 1) {
            EMIT(0xE7000000, 0);
            if (alphaLimitEnabled1 != 0) {
                EMIT(0xE200001C, 0x055A4B50);
            }
            EMIT(0xE2001D00, 4);
            EMIT(0xEE000000, 0x00FF0000);
            EMIT(0xE3000C00, 0);
        } else if (pass == 2) {
            if (rectLists[0] == 0) {
                goto finish;
            }
            EMIT(0xE7000000, 0);
            EMIT(0xDE000000, skeletonEndList);
            EMIT(0xE2001E01, 1);
            EMIT(0xFC119623, 0xFF2FFFFF);
        }

        node = owner->nodes;
        for (;;) {
        node_top:
            if (node == 0) {
                break;
            }
            record = node->records;
            count = node->count;
            if (record == 0 || count == 0) {
                goto next_node;
            }
            { Viewport *base = viewports; u32 offset; __asm__("" : "+r"(base)); offset = view * sizeof(Viewport); vp = (Viewport *)(offset + (u32)base); }
            for (;;) {
            record_top:
                if (count-- == 0) {
                    break;
                }
                {
                u16 flags = record->flags;
                float x;
                float y;
                float z;
                float sx;
                float sy;
                float w;
                u32 ix;
                u32 iy;
                u32 color;

                if (flags == 0) {
                    goto next_record;
                }
                if (displayListHead - listStarts[listIndex] >= 6024) {
                    goto next_record;
                }
                if (pass == 0 && (flags & 1)) {
                    goto next_record;
                }
                if (pass == 1 && !(flags & 1)) {
                    goto next_record;
                }
                if ((pass == 0 || pass == 1) && (flags & 0x10)) {
                    goto next_record;
                }
                if (pass == 2 && !(flags & 0x10)) {
                    goto next_record;
                }
                if ((flags & 0x10) && pass == 2) {
                    DisplayCommand *cursor;

                    x = record->x;
                    y = record->y;
                    z = record->z;
                    sx = matrix[0][0] * x + matrix[1][0] * y + matrix[2][0] * z + matrix[3][0];
                    sy = matrix[0][1] * x + matrix[1][1] * y + matrix[2][1] * z + matrix[3][1];
                    w = x * matrix[0][3] + y * matrix[1][3] + z * matrix[2][3] + matrix[3][3];
                    if (w <= 0.0f) {
                        goto next_record;
                    }
                    sx /= w;
                    sx *= vp->scale[0];
                    sx += vp->trans[0];
                    sy /= w;
                    sy *= vp->scale[1];
                    sy += vp->trans[1];
                    ix = (int)sx;
                    iy = (int)sy;
                    ix = (int)ix >> 2;
                    iy = (int)iy >> 2;
                    iy = bottom - iy;
                    if (ix >= screenWidth) {
                        goto next_record;
                    }
                    if (iy >= screenHeight) {
                        goto next_record;
                    }
                    if (rectCapacity - 6 < rectCount) {
                        goto next_record;
                    }
                    cursor = &rectLists[currentPlayer][rectCount];
                    if (depthEnabled != 0) {
                        float depth = (matrix[0][2] * x + matrix[1][2] * y + matrix[2][2] * z +
                                       matrix[3][2]) / w * 16352.0f + 16352.0f;

                        EMIT_TO(cursor, 0xEE000000, floatToU32(depth) << 16);
                    }
                    if (flags & 0x100) {
                        color = blendColor(record);
                    } else {
                        color = record->color;
                    }
                    if (color != lastColor) {
                        DisplayCommand *c_ = cursor++;
                        lastColor = color;
                        c_->words.w0 = 0xFA000000;
                        { u32 red = lastColor >> 16;
                          u32 green = (lastColor >> 8) & 0xFF;
                          u32 blue = lastColor & 0xFF;
                          
                          c_->words.w1 = (red << 24) | (green << 16) | (blue << 8) | 0xFF;
                        }
                    }
                    ix <<= 2;
                    iy <<= 2;
                    EMIT_TO(cursor, 0xE4000000 | (((ix + 4) & 0xFFF) << 12) | ((4 + iy) & 0xFFF),
                            ((ix & 0xFFF) << 12) | (iy & 0xFFF));
                    EMIT_TO(cursor, 0xE1000000, 0);
                    EMIT_TO(cursor, 0xF1000000, 0);
                    rectCount += cursor - &rectLists[currentPlayer][rectCount];
                } else if (flags & 1) {
                    float size;
                    u32 texture;

                    x = record->x;
                    y = record->y;
                    z = record->z;
                    sx = matrix[0][0] * x + matrix[1][0] * y + matrix[2][0] * z + matrix[3][0];
                    sy = matrix[0][1] * x + matrix[1][1] * y + matrix[2][1] * z + matrix[3][1];
                    w = x * matrix[0][3] + y * matrix[1][3] + z * matrix[2][3] + matrix[3][3];
                    if (w <= 0.0f) {
                        goto next_record;
                    }
                    sx /= w;
                    sx *= vp->scale[0];
                    sx += vp->trans[0];
                    sy /= w;
                    sy *= vp->scale[1];
                    sy += vp->trans[1];
                    size = 1.0f;
                    if (flags & 0x200) {
                        size = record->scale;
                    }
                    ix = (int)sx;
                    iy = (int)sy;
                    ix = (int)ix >> 2;
                    iy = (int)iy >> 2;
                    if (ix >= screenWidth) {
                        goto next_record;
                    }
                    if (iy >= screenHeight) {
                        goto next_record;
                    }
                    texture = record->model->texture;
                    iy = bottom - iy;
                    if (flags & 0x100) {
                        color = blendColor(record);
                    } else {
                        color = record->color;
                    }
                    if (color != lastPrim) {
                        u32 alpha = color >> 24;
                        u8 a8;

                        if (alphaLimitEnabled2 != 0) {
                            if (alpha > alphaLimit) {
                                alpha = alphaLimit;
                            }
                        }
                        a8 = alpha;
                        lastPrim = color;
                        EMIT(0xFA000000, (a8 << 24) | (a8 << 16) | (a8 << 8) | a8);
                    }
                    if (texture != lastTexture) {
                        u8 *info;


                        { u32 opcode = 0xDE000000; __asm__("" : "+r"(texture), "+r"(opcode)); lastTexture = texture; EMIT(opcode, textures[lastTexture].commands); }
                        info = textures[lastTexture].info;
                        halfWidth = (int)((float)(int)record->model->width * size);
                        dsdx = (1 << info[0]) << 10;
                        dsdx /= halfWidth;
                        halfHeight = (int)((float)(int)record->model->height * size);
                        dtdy = (1 << info[1]) << 10;
                        dtdy /= halfHeight;
                    }
                    __asm__("" : : "r"(ix));
                    ix <<= 2;
                    iy <<= 2;
                    if (depthEnabled != 0) {
                        float depth = (matrix[0][2] * x + matrix[1][2] * y + matrix[2][2] * z +
                                       matrix[3][2]) / w * 16352.0f + 16352.0f;

                        EMIT(0xEE000000, floatToU32(depth) << 16);
                    }
                    EMIT((((ix + halfWidth) & 0xFFF) << 12) | 0xE4000000 | ((iy + halfHeight) & 0xFFF),
                         (((ix - halfWidth) & 0xFFF) << 12) | ((iy - halfHeight) & 0xFFF));
                    EMIT(0xE1000000, 0);
                    EMIT(0xF1000000, (dsdx << 16) | (dtdy & 0xFFFF));
                } else {
                    ParticleModel *model = record->model;
                    int visible;
                    u32 i;
                    float radius;
                    register float scale __asm__("$f2");

                    if (!(model->flags & 2)) {
                        goto next_record;
                    }
                    updateRenderObject(model);
                    transform.pos[0] = record->x;
                    transform.pos[1] = record->y;
                    transform.pos[2] = record->z;
                    visible = 1;
                    radius = model->radius;
                    for (i = 0; i < 4; i++) {
                        if (testSpherePlane(transform.pos, radius, i) == 0) {
                            visible = 0;
                            break;
                        }
                    }
                    if (!visible) {
                        goto next_record;
                    }
                    if (flags & 0x200) {
                        register double scaled __asm__("$f0") = record->scale;
                        scaled *= 2.0;
                        scale = scaled;
                    } else {
                        scale = 1.0f;
                    }
                    transform.m[0][0] = scale;
                    transform.m[1][1] = scale;
                    transform.m[2][2] = scale;
                    applyRenderObjectState(model, 0);
                    if (flags & 0x100) {
                        color = blendColor(record);
                    } else {
                        color = record->color;
                    }
                    if (color != lastPrim) {
                        u8 alpha = color >> 24;
                        u8 a8;

                        if (alphaLimitEnabled3 != 0) {
                            if (alpha > 50) {
                                alpha = 50;
                            }
                        }
                        a8 = alpha;
                        lastPrim = color;
                        EMIT(0xFA000000, (a8 << 24) | (a8 << 16) | (a8 << 8) | a8);
                    }
                    if (model->flags & 8) {
                        buildFlaggedModelMatrix(&displayListHead, &transform, allocateMatrix(), 2);
                    } else {
                        buildFlaggedModelMatrix(&displayListHead, &transform, allocateMatrix(), 1);
                    }
                    EMIT(0xDE000000, model->displayLists[currentPlayer]);
                }
                }
            next_record:
                __asm__("" : : "r"(&record->color));
                record++;

            }
        next_node:
            node = node->next;
        }
        pass++;
    }

    if (rectCount != 0) {
        DisplayCommand *end;

        EMIT(0xFCFFFFFF, 0xFFFDF6FB);
        end = &rectLists[currentPlayer][rectCount];
        end->words.w0 = 0xDF000000;
        end->words.w1 = 0;
        EMIT(0xDE000000, rectLists[currentPlayer]);
    }
finish:
    EMIT(0xD9FFFFFF, 0x200);
    EMIT(0xE7000000, 0);
}
