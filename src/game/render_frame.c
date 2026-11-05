/* Per-frame viewport rendering: build frustum planes, traverse visible object
 * lists, sort transparent objects by distance, and submit the graphics task.
 * Target: N64 big-endian MIPS o32. SN -O2 reproduces all 0x1480 text bytes
 * and the 0x30-byte constant pool placed at 0x80000C20.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;
typedef double f64;

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct ObjInfo {
    u32 flags;
    u8 pad04[0x4C];
    u8 *data;
} ObjInfo;

typedef struct Object {
    s32 type;
    u8 pad04[0x10];
    f32 mtx[4][4];
    Vec3f pos;
    u8 pad60[0x5C];
    struct Object *next;
    u32 flags;
    ObjInfo *info;
    u8 padC8[4];
    u32 viewMask;
} Object;

typedef struct Camera {
    u8 pad00[0x14];
    f32 mtx[4][4];
    Vec3f pos;
    u8 pad60[0x94];
    f32 fov;
} Camera;

typedef struct Viewport {
    s32 active;
    u8 pad04[0xA];
    u16 top;
    u8 pad10[2];
    u16 height;
    u8 pad14[0xC];
    Camera *camera;
    u8 pad24[0x4C];
    s32 unk70;
    s32 unk74;
    s32 unk78;
    u8 pad7C[8];
} Viewport;

typedef struct {
    f32 n[3];
    f32 d;
} Plane;

typedef struct {
    u8 count;
    u8 pad[3];
    Plane planes[6];
} Frustum;

typedef struct {
    Object *obj;
    f32 dist;
    s32 pad;
} SortEntry;

typedef struct {
    u8 pad[0x58];
} TaskEntry;

extern s32 D_8005A944;
extern s32 D_8005A948;
extern u32 D_800661D4;
extern u16 D_8005AAC0;
extern s32 D_8005A954;
extern s32 D_8005B7F8;
extern s32 D_8005B7E0;
extern s32 D_8005B7E4;
extern s32 D_8005B7E8;
extern s32 D_8005B7F0;
extern s32 D_8005B7F4;
extern Gfx *D_80039310[];
extern s32 D_80066490;
extern TaskEntry D_800663E0[];
extern Gfx *D_800663DC;
extern Frustum D_8005F800;
extern Plane D_8005F804[];
extern Viewport D_8005AAF0[];
extern s32 D_8005F990;
extern s32 D_8005A824;
extern s32 D_8005A828;
extern void *D_80039460;
extern void *D_80039454[];
extern s32 D_800661C8;
extern s32 D_8005A9F4;
extern s32 D_8005A9F8;
extern f32 D_8005B6D0[3];
extern f32 D_8005B6DC;
extern Gfx D_80065FB8[];
extern Gfx D_80065EC0[];
extern Gfx D_80065DC0[];
extern Gfx D_80065E30[];
extern Object *D_8005AAC4[];
extern Object *D_8005AAB0;
extern Object *D_8005AAB4;
/* The sort count and frame-buffer selector share this fixed RAM block.
 * Keeping their common base also describes the symbol-plus-offset relocation. */
typedef struct {
    u16 count;
    u8 reserved02[10];
    s32 frameBufferIndex;
} RenderSortState;
extern RenderSortState renderSortState __asm__("D_8005A930");
/* Scalar alias of the first member, used by the sorting loops. */
extern u16 D_8005A930;

#define FIELD_OFFSET(type, member) ((u32)&((type *)0)->member)
typedef char check_u32_width[sizeof(u32) == 4 ? 1 : -1];
typedef char check_pointer_width[sizeof(void *) == 4 ? 1 : -1];
typedef char check_gfx_size[sizeof(Gfx) == 8 ? 1 : -1];
typedef char check_vector_size[sizeof(Vec3f) == 12 ? 1 : -1];
typedef char check_object_size[sizeof(Object) == 0xD0 ? 1 : -1];
typedef char check_object_next[FIELD_OFFSET(Object, next) == 0xBC ? 1 : -1];
typedef char check_object_info[FIELD_OFFSET(Object, info) == 0xC4 ? 1 : -1];
typedef char check_camera_fov[FIELD_OFFSET(Camera, fov) == 0xF4 ? 1 : -1];
typedef char check_viewport_size[sizeof(Viewport) == 0x84 ? 1 : -1];
typedef char check_plane_size[sizeof(Plane) == 16 ? 1 : -1];
typedef char check_frustum_size[sizeof(Frustum) == 0x64 ? 1 : -1];
typedef char check_sort_entry_size[sizeof(SortEntry) == 12 ? 1 : -1];
typedef char check_task_entry_size[sizeof(TaskEntry) == 0x58 ? 1 : -1];
typedef char check_sort_state_size[sizeof(RenderSortState) == 16 ? 1 : -1];
typedef char check_frame_index_offset[
    FIELD_OFFSET(RenderSortState, frameBufferIndex) == 12 ? 1 : -1];
extern SortEntry D_8006A850[];
extern u8 D_800FFD30[];
extern s32 D_80038C50;

extern void func_8001B2AC(void);
extern void func_8000C030(void);
extern void func_800351A0(s32);
extern void func_800147F4(s32, Viewport *);
extern f32 func_8002EFF0(f32);
extern f32 func_8002E810(f32);
extern void func_800AD2A8(void *, Vec3f *, void *, s32);
extern void func_8000E53C(void *, s32, void *, f32, s32, s32);
extern void func_80011500(Object *, void *, s32, s32);
extern void func_800064D0(Gfx **, s32);
extern void func_8001891C(void);
extern void func_80018910(void);
extern void func_80018904(void);
extern s32 func_80018838(Object *);
extern void func_80018858(Object *);
extern void func_8001888C(Object *);
extern void func_800188C8(Object *);
extern void func_80018088(s32);
extern void func_8001A620(Gfx **);
extern void func_8001A63C(Gfx **);
extern void func_8001B238(Object *, s32);
extern void func_80019BA0(ObjInfo *, Object *);
extern void func_800EA5A4(void *);
extern void func_8001A660(void);
extern void func_800175F4(void);
extern void func_8000C280(void *, s32);
extern void func_8002E280(void);
extern void func_8001E420(TaskEntry *, Gfx *, s32, s32, s32);

static inline s32 is_hidden(Object *o, u32 m) {
    if (o == 0 || o->info == 0) {
        return 1;
    }
    return (o->flags & m) != 0;
}
#define HIDDEN(o) is_hidden(o, hm)

static inline void vec_sub(Vec3f *r, Vec3f *a, Vec3f *b) {
    r->x = a->x - b->x;
    r->y = a->y - b->y;
    r->z = a->z - b->z;
}

static inline f32 dot3(Vec3f *a, f32 *b) {
    return a->x * b[0] + a->y * b[1] + a->z * b[2];
}

#define CLEAR_SCREEN()                                                              \
    {                                                                               \
        Gfx *g;                                                                     \
        g = D_800663DC++;                                                           \
        g->w0 = 0xFE000000;                                                         \
        g->w1 = (u32)D_80039460 - 0x80000000;                                       \
        g = D_800663DC++;                                                           \
        g->w0 = 0xE7000000;                                                         \
        g->w1 = 0;                                                                  \
        g = D_800663DC++;                                                           \
        g->w0 = 0xE3000A01;                                                         \
        g->w1 = 0x300000;                                                           \
        g = D_800663DC++;                                                           \
        g->w0 = 0xFF100000 | ((D_8005A824 - 1) & 0xFFF);                            \
        g->w1 = (u32)D_80039460 - 0x80000000;                                       \
        g = D_800663DC++;                                                           \
        g->w0 = 0xF7000000;                                                         \
        g->w1 = 0xFFFCFFFC;                                                         \
        g = D_800663DC++;                                                           \
        g->w0 = 0xF6000000 | (((D_8005A824 - 1) & 0x3FF) << 14) |                   \
                (((D_8005A828 - 1) & 0x3FF) << 2);                                  \
        g->w1 = 0;                                                                  \
        g = D_800663DC++;                                                           \
        g->w0 = 0xE3000A01;                                                         \
        g->w1 = 0x300000;                                                           \
        g = D_800663DC++;                                                           \
        g->w0 = 0xE7000000;                                                         \
        g->w1 = 0;                                                                  \
        g = D_800663DC++;                                                           \
        g->w0 = 0xFF100000 | ((D_8005A824 - 1) & 0xFFF);                            \
        g->w1 = (u32)D_80039454[D_800661C8];                                        \
        if (D_8005A9F4 != 0) {                                                      \
            g = D_800663DC++;                                                       \
            g->w0 = 0xF7000000;                                                     \
            g->w1 = (D_8005A9F8 << 16) | D_8005A9F8;                                \
            g = D_800663DC++;                                                       \
            g->w0 = 0xF6000000 | (((D_8005A824 - 1) & 0x3FF) << 14) |               \
                    (((D_8005A828 - 1) & 0x3FF) << 2);                              \
            g->w1 = 0;                                                              \
        }                                                                           \
    }

#define DISPLAY_LIST(dl)                                                            \
    {                                                                               \
        Gfx *g;                                                                     \
        g = D_800663DC++;                                                           \
        g->w0 = 0xDE000000;                                                         \
        g->w1 = (u32)(dl);                                                          \
    }

#define PIPE_SYNC()                                                                 \
    {                                                                               \
        Gfx *g;                                                                     \
        g = D_800663DC++;                                                           \
        g->w0 = 0xE7000000;                                                         \
        g->w1 = 0;                                                                  \
    }

#define COPY_MTX(o, c)                                                              \
    {                                                                               \
        f32 *dm = (o)->mtx[0];                                                      \
        f32 *sm = (c)->mtx[0];                                                      \
        dm[0] = sm[0]; dm[4] = sm[4]; dm[8] = sm[8];                                \
        dm[1] = sm[1]; dm[5] = sm[5]; dm[9] = sm[9];                                \
        dm[2] = sm[2]; dm[6] = sm[6]; dm[10] = sm[10];                              \
    }

s32 func_80014A2C(void) {
    u32 i;
    s32 cleared;
    s32 idx;
    Viewport *vp;
    Frustum *fr;
    Plane *pl;
    Object *o;
    Object **lp;
    TaskEntry *task;
    Gfx *g;
    u32 mask;
    u32 mk0;
    f32 fov;
    f32 angle;
    f32 sx, cx, sy, cy;
    Vec3f v;
    Vec3f d;
    Vec3f campos;
    s32 j;
    s32 swapped;
    u32 k;
    SortEntry *se;
    u32 color;
    u32 prim;
    f32 scale;
    f32 nearOfs;
    u32 hm;

    D_8005A944 = 0;
    cleared = 0;
    D_8005A948 = 0;
    if (D_800661D4 >= 2) {
        return -994;
    }
    if (D_8005AAC0 != 0 && D_8005A954 == 0) {
        return 0;
    }
    D_8005B7F8 = 0;
    func_8001B2AC();
    func_8000C030();
    func_800351A0(0);
    hm = 0x20000;
    D_8005B7E0 = 0;
    D_8005B7E4 = 0;
    D_8005B7E8 = 0;
    D_8005B7F0 = 0;
    D_8005B7F4 = 0;
    idx = D_80066490;
    D_800663DC = D_80039310[idx];
    task = &D_800663E0[idx];
    scale = 4.0f;
    nearOfs = 1.63835f;

    i = 0;
    for (;;) {
    top:
        if (i >= 3) break;
        vp = &D_8005AAF0[i];
        D_8005F990 = 0;
        func_800147F4(i, vp);
        {
            Gfx *_g = (Gfx *)(D_800663DC++);
            _g->w0 = 0xED000000;
            _g->w1 = (((s32)((D_8005A824 - 1) * scale) & 0xFFF) << 12) |
                ((s32)((D_8005A828 - 1) * scale) & 0xFFF);
        }
        {
            Gfx *_g = (Gfx *)(D_800663DC++);
            _g->w0 = 0xE3000800;
            _g->w1 = 0;
        }
        if (vp->active == 0) {
            goto next;
        }
        if (vp->unk70 == 0 && vp->unk74 == 0 && vp->unk78 == 0) {
            goto next;
        }
        if (!cleared) {
            CLEAR_SCREEN();
            cleared = 1;
            PIPE_SYNC();
        }
        {
            Gfx *_g = (Gfx *)(D_800663DC++);
            s32 top = vp->top;
            u32 w0 = 0xED000000 | ((s32)(top * scale) & 0xFFF);
            s32 right = D_8005A824 - 1;
            s32 bot = top + vp->height - 1;
            _g->w0 = w0;
            _g->w1 = (((s32)(right * scale) & 0xFFF) << 12) | ((s32)(bot * scale) & 0xFFF);
        }

        fr = &D_8005F800;
        fov = vp->camera->fov;
        angle = (3.1415927f - fov * 57.29578f * 0.01745f) * 0.5f;
        sx = func_8002EFF0(angle);
        cx = func_8002E810(angle);
        sy = func_8002EFF0(angle);
        cy = func_8002E810(angle);

        D_8005F800.count = 4;
        v.x = sx;
        v.y = 0.0f;
        v.z = cx;
        func_800AD2A8(vp->camera->mtx, &v, &D_8005F804[0], 0);
        {
            Vec3f *p = &vp->camera->pos;
            fr->planes[0].d = p->x * fr->planes[0].n[0] +
                              p->y * D_8005F804[0].n[1] +
                              p->z * D_8005F804[0].n[2];
        }
        v.x = -sx;
        func_800AD2A8(vp->camera->mtx, &v, &fr->planes[1], 0);
        pl = &fr->planes[1];
        fr->planes[1].d = dot3(&vp->camera->pos, pl->n);
        v.x = 0.0f;
        v.y = sy;
        v.z = cy;
        pl = &fr->planes[2];
        func_800AD2A8(vp->camera->mtx, &v, pl, 0);
        fr->planes[2].d = dot3(&vp->camera->pos, pl->n);
        v.y = -sy;
        pl = &fr->planes[3];
        func_800AD2A8(vp->camera->mtx, &v, pl, 0);
        fr->planes[3].d = dot3(&vp->camera->pos, pl->n);
        v.x = 0.0f;
        v.y = 0.0f;
        v.z = 1.0f;
        pl = &fr->planes[4];
        func_800AD2A8(vp->camera->mtx, &v, pl, 0);
        fr->planes[4].d = dot3(&vp->camera->pos, pl->n) + nearOfs;
        v.z = -1.0f;
        pl = &fr->planes[5];
        func_800AD2A8(vp->camera->mtx, &v, pl, 0);
        fr->planes[5].d = dot3(&vp->camera->pos, pl->n) - 32767.0f;
        func_8000E53C(&D_8005F804[i], 4, vp->camera->mtx, fov, i, 0);

        D_8005B6D0[0] = vp->camera->pos.x;
        D_8005B6D0[1] = vp->camera->pos.y;
        D_8005B6DC = fov / 0.919662;
        D_8005B6D0[2] = vp->camera->pos.z;
        DISPLAY_LIST(D_80065FB8);

        mk0 = 1 << i;
        o = D_8005AAC4[0];
        j = 1;
        while (1) {
            if (o == 0) break;
            if ((o->viewMask & mk0) && !(o->flags & 4)) {
                if (!HIDDEN(o)) {
                    func_80011500(o, D_8005AAF0[i].camera->mtx, 1, i);
                }
                D_8005A944++;
            }
            o = D_8005AAC4[j++];
        }
        func_800064D0(&D_800663DC, i);
        func_8001891C();
        func_80018910();
        func_80018904();

        o = D_8005AAB0;
        while (1) {
            if (o == 0) break;
            if (o->viewMask & (1 << i)) {
                if (func_80018838(o)) {
                    func_80018858(o);
                    D_8005B7F0++;
                } else {
                    if (o->flags & 0x600) {
                        func_8001888C(o);
                    }
                    if (o->flags & 0x4000) {
                        func_800188C8(o);
                    }
                }
            }
            o = o->next;
        }

        if (D_8005F990 == 0) {
            o = D_8005AAB0;
            while (1) {
                if (o == 0) break;
                if ((o->viewMask & (1 << i)) && o->type == 0x56) {
                    if (!HIDDEN(o)) {
                        func_80011500(o, D_8005AAF0[i].camera->mtx, 0, i);
                    }
                    D_8005B7E0++;
                    D_8005F990++;
                }
                o = o->next;
            }
        }
        func_80018088(i);

        o = D_8005AAB0;
        while (1) {
            if (o == 0) break;
            if ((o->viewMask & (1 << i)) && !(o->flags & 0x20104)) {
                if (o->flags & 0x400000) {
                    COPY_MTX(o, D_8005AAF0[i].camera);
                }
                if (!HIDDEN(o)) {
                    func_80011500(o, 0, 0, i);
                }
                D_8005B7E0++;
            }
            o = o->next;
        }

        o = D_8005AAB0;
        if (o != 0) {
            u32 m;
            DISPLAY_LIST(D_80065EC0);
            func_8001A620(&D_800663DC);
            m = 1 << i;
            while (1) {
                if (o == 0) break;
                if (o->viewMask & m) {
                    if (o->type == 0x3D) {
                        if (!(o->flags & 4)) {
                            func_8001B238(o, i);
                        }
                    } else if (o->flags & hm) {
                        if (!(o->flags & 4)) {
                            if (!(o->flags & 0x10000)) {
                                if (o->info != 0) {
                                    D_8005B7F4++;
                                    func_80019BA0(o->info, o);
                                }
                            }
                        }
                    }
                }
                o = o->next;
            }
            func_8001A63C(&D_800663DC);
            DISPLAY_LIST(D_80065FB8);
        }

        o = D_8005AAB4;
        if (o != 0) {
            D_8005A930 = 0;
            DISPLAY_LIST(D_80065DC0);
            campos = vp->camera->pos;
            {
            Object *p = o;
            u32 m = 1 << i;
            while (1) {
                if (p == 0) break;
                if ((p->viewMask & m) && !(p->flags & 4) && p->info != 0) {
                    vec_sub(&d, &p->pos, &campos);
                    if (D_8005A930 < 0x37) {
                        D_8006A850[D_8005A930].obj = p;
                        D_8006A850[D_8005A930++].dist = d.x * d.x + d.y * d.y + d.z * d.z;
                    }
                }
                p = p->next;
            }
            }
            do {
                swapped = 0;
                for (j = 0; D_8005A930 - 1 > j; j++) {
                    if (D_8006A850[j].dist < D_8006A850[j + 1].dist) {
                        Object *to;
                        f32 td;
                        to = D_8006A850[j].obj;
                        td = D_8006A850[j].dist;
                        D_8006A850[j].obj = D_8006A850[j + 1].obj;
                        D_8006A850[j].dist = D_8006A850[j + 1].dist;
                        D_8006A850[j + 1].obj = to;
                        D_8006A850[j + 1].dist = td;
                        swapped++;
                    }
                }
            } while (swapped);

            k = 0;
            mask = 1 << i;
            while (({ u16 n_ = D_8005A930; k < n_; })) {
                o = D_8006A850[k].obj;
                k++;
                if (o->info == 0) continue;
                if (!(o->viewMask & mask)) continue;
                if (o->flags & 4) continue;
                if (o->flags & 0x400000) {
                    COPY_MTX(o, vp->camera);
                }
                if (o->flags & 0x40) {
                    if (!HIDDEN(o)) {
                        DISPLAY_LIST(D_80065E30);
                        func_80011500(o, 0, 1, i);
                        D_8005B7E8++;
                        DISPLAY_LIST(D_80065DC0);
                    }
                } else if (o->flags & 8) {
                    if (!HIDDEN(o)) {
                        if (o->type == 0x4F) {
                            {
                                Gfx *_g = (Gfx *)(D_800663DC++);
                                prim = 0xD9FFF9FF;
                                _g->w0 = prim;
                                _g->w1 = 0;
                            }
                            {
                                Gfx *_g = (Gfx *)(D_800663DC++);
                                _g->w0 = 0xFA000000;
                                _g->w1 = -0x2E;
                            }
                            func_80011500(o, 0, 1, i);
                            {
                                Gfx *_g = (Gfx *)(D_800663DC++);
                                _g->w0 = 0xD9FFFFFF;
                                _g->w1 = 0x400;
                            }
                        } else {
                            {
                                Gfx *_g = (Gfx *)(D_800663DC++);
                                u32 opcode = 0xFA000000;
                                /* Keep this packet's constant separate from the
                                 * other dispatch branches during SN loop CSE. */
                                __asm__("" : "+r"(opcode) : "r"(_g) : "memory");
                                _g->w0 = opcode;
                                _g->w1 = -0x2E;
                            }
                            func_80011500(o, 0, 1, i);
                        }
                        D_8005B7E8++;
                    }
                } else {
                    color = 0x96;
                    if (o->flags & 0x10) {
                    if (!HIDDEN(o)) {
                        if (o->type == 0x58) {
                            {
                                Gfx *_g = (Gfx *)(D_800663DC++);
                                prim = 0xFA0000FF;
                                _g->w0 = prim;
                                _g->w1 = -1;
                            }
                            func_80011500(o, 0, 1, i);
                            D_8005B7E8++;
                        } else if (o->type == 0x3C) {
                            if (o->info->flags & 2) {
                                color = o->info->data[0x19];
                            }
                            {
                                Gfx *_g = (Gfx *)(D_800663DC++);
                                prim = 0xFA0000FF;
                                _g->w0 = prim;
                                _g->w1 = color | 0xFFFFFF00;
                            }
                            func_80011500(o, 0, 1, i);
                            D_8005B7E8++;
                        } else {
                            if (o->info->flags & 2) {
                                color = o->info->data[0x19];
                            }
                            {
                                Gfx *_g = (Gfx *)(D_800663DC++);
                                prim = 0xFA0000FF;
                                _g->w0 = prim;
                                _g->w1 = color | 0xFFFFFF00;
                            }
                            func_80011500(o, 0, 1, i);
                            D_8005B7E8++;
                        }
                    }
                } else if (0x20 & o->flags) {
                    if (!HIDDEN(o)) {
                        {
                            Gfx *_g = (Gfx *)(D_800663DC++);
                            _g->w0 = 0xFA000000;
                            _g->w1 = -0xB0;
                        }
                        func_80011500(o, 0, 1, i);
                        D_8005B7E8++;
                    }
                }
                }
            }
        }
        DISPLAY_LIST(D_80065FB8);
    next:
        if (i == 0) {
            func_800EA5A4(D_800FFD30);
            DISPLAY_LIST(D_80065FB8);
        }
        i++;
    }

    if (D_8005AAF0[0].active == 0 && !cleared) {
        CLEAR_SCREEN();
        PIPE_SYNC();
    }
    func_8001A660();
    func_800175F4();
    {
        Gfx *_g = (Gfx *)(D_800663DC++);
        _g->w0 = 0xE9000000;
        _g->w1 = 0;
    }
    {
        Gfx *_g = (Gfx *)(D_800663DC++);
        _g->w0 = 0xDF000000;
        _g->w1 = 0;
    }
    D_800661D4++;
    func_8000C280(D_80039454[D_800661C8], D_8005A824);
    func_8002E280();
    func_8001E420(task, D_80039310[D_80066490],
                  (D_800663DC - D_80039310[D_80066490]) * sizeof(Gfx), 0, 0x40);
    /* Byte addressing within the complete typed block preserves the
     * symbol-plus-member-offset relocation without an intermediate base. */
    *(s32 *)((u8 *)&renderSortState +
             FIELD_OFFSET(RenderSortState, frameBufferIndex)) ^= 1;
    D_80038C50++;
    return 0;
}
