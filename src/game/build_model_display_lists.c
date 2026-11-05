/* Exact SN GCC 2.8 reconstruction of func_80008F3C (ROM 0x9B3C, 0xE34 bytes).
 * Count and build a model group's F3DEX draw lists through a 32-entry vertex
 * cache. Allocate the command block, register texture resources, emit sorted
 * vertex runs and triangle pairs, then shrink the block to its actual length.
 * Layouts are N64 big-endian o32. Empty input constraints retain group-stride
 * and cursor-address reuse and the mesh-index initialization boundary. Scoped
 * register bindings retain the vertex-address expression's scratch registers.
 * These compiler constraints emit no MIPS instructions.
 */
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct { u32 w0; u32 w1; } Gfx;
typedef struct { u8 b[16]; } Vtx;

typedef struct {
    u32 unk0;
    u16 count;
    u16 pad6;
    u16 *indices;
} Mesh; /* 0xC */

typedef struct {
    u32 unk0;
    u32 meshCount;
    Vtx *vertices;
    Mesh *meshes;
    u32 texture;
} Item; /* 0x14 */

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 itemCount;
    Item *items;
    u32 unk10;
    u32 unk14;
} Group; /* 0x18 */

typedef struct {
    u16 unk0;
    u16 flags;
    u8 pad4[0x1C];
    Group *groups;
    u8 pad24[0x20];
    Gfx *lists[4];
} Model;

typedef struct {
    u32 identifier;
    u32 resource;
    u16 flags;
    u8 unused0A[6];
    Gfx list[1];
    u8 pad[0xC8];
} QueuedResource;

typedef struct {
    u32 unk0;
    u16 ids[64];
} ResourceRow;

/* These are target layouts, not host-native pointer-bearing structures. */
typedef char check_u32_width[sizeof(u32) == 4 ? 1 : -1];
typedef char check_pointer_width[sizeof(void *) == 4 ? 1 : -1];
typedef char check_gfx_size[sizeof(Gfx) == 8 ? 1 : -1];
typedef char check_vertex_size[sizeof(Vtx) == 16 ? 1 : -1];
typedef char check_mesh_size[sizeof(Mesh) == 0x0C ? 1 : -1];
typedef char check_item_size[sizeof(Item) == 0x14 ? 1 : -1];
typedef char check_group_size[sizeof(Group) == 0x18 ? 1 : -1];
typedef char check_model_size[sizeof(Model) == 0x54 ? 1 : -1];
typedef char check_resource_size[sizeof(QueuedResource) == 0xE0 ? 1 : -1];
typedef char check_resource_row_size[sizeof(ResourceRow) == 0x84 ? 1 : -1];

extern char D_800005B8[];
extern u32 D_800477C4;
extern u16 D_800477C8[];
extern u32 D_800456B8;
extern void *D_800456B0;
extern u32 D_800477C0;
extern u32 D_800479C8;
extern ResourceRow D_800456C0[];
extern QueuedResource D_80049A28[];
extern Gfx *D_80068920[];
extern Gfx *D_80068A20[];

extern void func_800AA658(void *heap, Gfx **block);
extern void func_800AA804(void *heap, Gfx **block, u32 size, char *tag);
extern void func_800AA488(void *heap, Gfx **block, u32 size);
extern u32 func_8000C68C(u32 identifier, u32 first, u32 second, u32 third, u32 fourth);

#define GFXW(pkt, a, b) { Gfx *_g = (Gfx *)(pkt); _g->w0 = (a); _g->w1 = (b); }
#define VTXADDR(it, v) ((((u32)&(it)->vertices[v]) - D_800477C4) | 0x05000000)

#define EMIT_BATCH(GUARD) \
                    if (n >= 2) { \
                        s32 sortIndex; u16 tmp0, tmp1; \
                        do { \
                            swapped = 0; \
                            for (sortIndex = 0; sortIndex < n - 1; sortIndex++) { \
                                tmp0 = D_800477C8[sortIndex]; \
                                tmp1 = D_800477C8[sortIndex + 1]; \
                                if (tmp1 < tmp0) { \
                                    swapped = 1; \
                                    D_800477C8[sortIndex] = tmp1; \
                                    D_800477C8[sortIndex + 1] = tmp0; \
                                } \
                            } \
                        } while (swapped); \
                    } \
                    run = 0; \
                    { register u32 vertexOffset __asm__("$3"); register u32 vertexBase __asm__("$2"); register u32 address __asm__("$9"); vertexOffset = D_800477C8[0] * 16; vertexBase = (u32)model->groups[index].items[i].vertices; address = vertexBase + vertexOffset; prev = address - D_800477C4; prev |= 0x05000000; } \
                    for (v = 1; ; v++) { \
                        s32 unusedV; \
                        if (!(v < n)) break; \
                        addr = ((u32)&model->groups[index].items[i].vertices[D_800477C8[v]]); addr -= D_800477C4; addr |= 0x05000000; \
                        if (addr - prev == 16) { \
                            run++; \
                        } else { \
                            GFXW(gfx++, (((run + 1) & 0xFF) << 12) | 0x01000000 | ((v & 0x7F) << 1), prev - (run << 4)); \
                            run = 0; \
                        } \
                        prev = addr; \
                    } \
                    GFXW(gfx++, (((run + 1) & 0xFF) << 12) | 0x01000000 | ((v & 0x7F) << 1), prev - (run << 4)); \
                    for (t = first; ; t += 3) { \
                        u32 unusedT; \
                        if (!(t <= last GUARD)) break; \
                        second = -1; \
                        for (v = 0; v < n; v++) { \
                            if (mesh->indices[t] == D_800477C8[v]) a = v; \
                            if (mesh->indices[t + 1] == D_800477C8[v]) b = v; \
                            if (mesh->indices[t + 2] == D_800477C8[v]) d = v; \
                            if (t < last) { \
                                if (mesh->indices[t + 3] == D_800477C8[v]) second = v; \
                                if (mesh->indices[t + 4] == D_800477C8[v]) e = v; \
                                if (mesh->indices[t + 5] == D_800477C8[v]) f = v; \
                            } \
                        } \
                        if (second == -1) { \
                            GFXW(gfx++, ((((d * 2) & 0xFF) << 16) | (((b * 2) & 0xFF) << 8) | ((a * 2) & 0xFF)) | 0x05000000, 0); \
                        } else { \
                            t += 3; \
                            GFXW(gfx++, ((((d * 2) & 0xFF) << 16) | (((b * 2) & 0xFF) << 8) | ((a * 2) & 0xFF)) | 0x06000000, (((f * 2) & 0xFF) << 16) | (((e * 2) & 0xFF) << 8) | ((second * 2) & 0xFF)); \
                        } \
                    }

void func_80008F3C(Model *model, u32 index, u32 noTextures, u32 *textures)
{
    Gfx *gfx;
    Gfx *g;
    Gfx *start;
    u32 size;
    u32 i;
    u32 j;
    u32 k;
    u32 first;
    u32 last;
    u32 t;
    s32 n;
    s32 v;
    u32 c;
    s32 full;
    s32 found;
    s32 second;
    s32 a, b, d, e, f;
    u32 rec;
    u32 tex;
    u16 swapped;
    u16 tmp0;
    u16 tmp1;
    s32 run;
    u32 prev;
    u32 addr;
    Mesh *mesh;
    u32 countItem;


    size = 20;
    D_800477C4 = (u32)model->groups->items->vertices;
    for (countItem = 0; countItem < model->groups[index].itemCount; countItem++) {
        size += 20;
        for (j = 0; j < model->groups[index].items[countItem].meshCount; j++) {
            mesh = &model->groups[index].items[countItem].meshes[j];
            first = -1;
            D_800456B8 = 0;
            for (k = 0; k < mesh->count; k = last + 3) { __asm__("" : : "r"(index * sizeof(Group)));
                if (first == -1) {
                    first = k;
                }
                full = 0;
                for (v = 0; v < 3; v++) {
                    found = 0;
                    for (c = 0; c < D_800456B8; c++) {
                        if (D_800477C8[c] == mesh->indices[k + v]) {
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        if (D_800456B8 < 32) {
                            D_800477C8[D_800456B8++] = mesh->indices[k + v];
                        } else {
                            full = 1;
                            k -= 3;
                        }
                    }
                }
                if (full == 1) {
                    size += n;
                    for (t = first; t <= last; t += 3) {
                        second = -1;
                        for (v = 0; v < n; v++) {
                            if (t < last && mesh->indices[t + 3] == D_800477C8[v]) {
                                second = v;
                            }
                        }
                        if (second != -1) {
                            t += 3;
                        }
                        size++;
                    }
                    first = -1;
                    D_800456B8 = 0;
                }
                last = k;
                n = D_800456B8;
            }
            size += n;
            {
                for (t = first; t <= last && t != -1; t += 3) {
                    second = -1;
                    for (v = 0; v < n; v++) {
                        if (t < last && mesh->indices[t + 3] == D_800477C8[v]) {
                            second = v;
                        }
                    }
                    if (second != -1) {
                        t += 3;
                    }
                    size++;
                }
            }
            D_800456B8 = 0;
        }
        size++;
    }
    size++;

    if (model->lists[index] != 0) {
        func_800AA658(D_800456B0, &model->lists[index]);
    }
    gfx = 0;
    func_800AA804(D_800456B0, &gfx, size * 8, D_800005B8);
    model->lists[index] = gfx;
    if (gfx == 0) {
        return;
    }
    gfx[1].w0 = 0xD9EEFFFF;
    gfx[1].w1 = 0;
    gfx += 2;
    if (model->flags & 1) {
        GFXW(gfx++, 0xD9FDFFFF, 0);
    } else {
        GFXW(gfx++, 0xD9FFFFFF, 0x20000);
    }

    for (i = 0; ; i++) {
        u32 unused;
        if (!(i < model->groups[index].itemCount)) break;
        if (noTextures == 0) {
            tex = model->groups[index].items[i].texture;
            if (textures != 0) {
                tex = textures[tex];
            }
            rec = func_8000C68C(tex, 1, 1, index, 0);
            D_80049A28[rec].flags++;
            D_800456C0[D_800479C8].ids[D_800477C0++] = rec;
            GFXW(gfx++, 0xDE000000, (u32)D_80049A28[rec].list);
        }
        D_80068920[i] = gfx;
        gfx++;
    }
    GFXW(gfx++, 0xDF000000, 0);
    g = model->lists[index];
    g->w0 = 0xDE010000;
    g->w1 = (u32)gfx;
    for (i = 0; i < model->groups[index].itemCount; i++) {
        D_80068A20[i] = gfx;
        gfx++;
    }

    {
    { Gfx *packet = gfx++; g = packet; }
    for (i = 0; ; i++) {
        GFXW(g, 0xDF000000, 0);
        if (!(i < model->groups[index].itemCount)) break;
        start = gfx;
        { Gfx *_g = D_80068A20[i]; __asm__("" : : "r"(_g)); j = 0; __asm__("" : : "r"(_g)); _g->w0 = 0xDE000000; _g->w1 = (u32)start; }
        GFXW(D_80068920[i], 0xDE000000, (u32)start);
        for (; ; j++) {
            u32 unusedJ;
            if (!(j < model->groups[index].items[i].meshCount)) break;
            mesh = &model->groups[index].items[i].meshes[j];
            first = -1;
            D_800456B8 = 0;
            for (k = 0; ; k = last + 3) {
                u32 unusedK;
                if (!(k < mesh->count)) break;
                if (first == -1) {
                    first = k;
                }
                full = 0;
                for (v = 0; v < 3; v++) {
                    found = 0;
                    for (c = 0; c < D_800456B8; c++) {
                        if (D_800477C8[c] == mesh->indices[k + v]) {
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        if (D_800456B8 < 32) {
                            D_800477C8[D_800456B8++] = mesh->indices[k + v];
                        } else {
                            full = 1;
                            k -= 3;
                        }
                    }
                }
                if (full == 1) {
                    EMIT_BATCH()
                    first = -1;
                    D_800456B8 = 0;
                }
                last = k;
                n = D_800456B8;
            }
            EMIT_BATCH(&& t != -1)
            D_800456B8 = 0;
        }
        __asm__("" : : "r"(&gfx));
        { Gfx *packet = gfx++; g = packet; }
    }
    }
    func_800AA488(D_800456B0, &model->lists[index], (u32)gfx - (u32)model->lists[index]);
}
