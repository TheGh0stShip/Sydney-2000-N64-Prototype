/* NONMATCHING func_8000D880: cull object parts and link their display lists.
 * SN -O2: exact 0xCBC size, branches, opcode sequence and scheduling;
 * remaining score63 consists of FPR/GPR allocation and operand differences.
 * Empty allocator constraints emit no instructions. No matching credit.
 * Structure names are provisional; all layouts are N64 o32.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    u32 w0;
    u32 w1;
} DisplayCommand;

typedef struct {
    u32 record;
    u16 nextList[4];
    u16 linkList[4];
} PartEntry;

typedef struct {
    s16 sphere[4][4];
    s16 box[4][6];
    PartEntry *entries[4];
    u16 entryCount[4];
    u8 lodCount;
    u8 pad69;
    u16 flags;
    u16 group;
    u16 pad6E;
} RenderPart;

typedef struct {
    u32 flags;
    u32 partCount;
    u8 pad08[0x04];
    RenderPart *parts;
    u8 pad10[0x08];
    DisplayCommand *list;
    u8 pad1C[0x0C];
    u32 secondaryFlags;
} RenderObject;

typedef struct {
    u8 pad00[0x40];
    float x;
    float y;
    float z;
} RenderView;

typedef struct {
    u8 pad00[0xD0];
    DisplayCommand *lists[4];
} ResourceRecord;

typedef char draw_object_pointer_width[sizeof(void *) == 4 ? 1 : -1];
typedef char draw_object_word_width[sizeof(u32) == 4 ? 1 : -1];
typedef char draw_part_size[sizeof(RenderPart) == 0x70 ? 1 : -1];
typedef char draw_part_entry_size[sizeof(PartEntry) == 20 ? 1 : -1];
typedef char draw_resource_size[sizeof(ResourceRecord) == 0xE0 ? 1 : -1];
typedef char draw_object_size[sizeof(RenderObject) == 0x2C ? 1 : -1];
extern ResourceRecord resourceRecords[] __asm__("D_80049A28");
extern u32 currentPlayer __asm__("D_8005A93C");
extern float originX __asm__("D_8005A52C");
extern float originY __asm__("D_8005A530");
extern float originZ __asm__("D_8005A534");
extern float lodDistanceScale __asm__("D_8005B6DC");
typedef struct {
    u32 pad00;
    float normal[3];
    float distance;
} CullPlane;

extern CullPlane cullPlane __asm__("D_8005F800");

static __inline__ float dot3(float *a, float *b) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

extern int testRenderObjectPlanes(float *, float) __asm__("func_80017A1C");

#define SPHERE_CENTER(i)                                                    \
    center[0] = obj->parts[i].sphere[obj->parts[i].flags & 3][0];           \
    center[1] = obj->parts[i].sphere[obj->parts[i].flags & 3][1];           \
    center[2] = obj->parts[i].sphere[obj->parts[i].flags & 3][2];           \
    center[0] *= 2.0f;                                                      \
    center[1] *= 2.0f;                                                      \
    center[2] *= 2.0f;                                                      \
    center[0] += originX;                                                   \
    center[1] += originY;                                                   \
    center[2] += originZ

#define VIEW_DELTA()                                                        \
    delta[0] = center[0] - view->x;                                         \
    delta[1] = center[1] - view->y;                                         \
    delta[2] = center[2] - view->z

#define CORNER(i, xi, yi, zi)                                               \
    corner[0] = obj->parts[i].box[lod][xi];                                 \
    corner[1] = obj->parts[i].box[lod][yi];                                 \
    corner[2] = obj->parts[i].box[lod][zi];                                 \
    corner[0] *= 2.0f;                                                      \
    corner[1] *= 2.0f;                                                      \
    corner[2] *= 2.0f;                                                      \
    corner[0] += originX;                                                   \
    corner[1] += originY;                                                   \
    corner[2] += originZ

#define BEHIND(v) (dot3((v), normal) < plane->distance)

int drawRenderObject(RenderObject *obj, int group, RenderView *view, u32 mode) __asm__("func_8000D880");

int drawRenderObject(RenderObject *obj, int group, RenderView *view, u32 mode) {
    u32 listIndex;
    u32 slotOffset;
    u32 drawn;
    u32 i;

    listIndex = 0;
    drawn = 0;
    slotOffset = 0;
    if (obj->flags & 0x80) {
        slotOffset = (mode == 1) ? 2 : 0;
    }
    if (!(obj->secondaryFlags & 1)) {
        listIndex = 1;
    }

    if (group == -1 || group == 0) {
        for (i = 0;; i++) {
            float center[3];
            float delta[3];

            if (!(i < obj->partCount)) break;

            if (obj->secondaryFlags & 2) {
                int lodCount = obj->parts[i].lodCount;
                if (lodCount - 1 >= 2) {
                    register u32 lod __asm__("$3");
                    float distance;

                    obj->parts[i].flags = lodCount - 1;
                    obj->parts[i].flags |= 4;
                    SPHERE_CENTER(i);
                    VIEW_DELTA();
                    distance = (delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2]) * lodDistanceScale;
                    lod = 0;
                    if (distance > 6250000.0) {
                        lod = 1;
                    }
                    if (distance > 9000000.0) {
                        lod = 2;
                    }
                    if (lod >= lodCount - 2) {
                        lod = lodCount - 2;
                    }
                    obj->parts[i].flags = lod;
                    obj->parts[i].flags |= 4;
                } else {
                    obj->parts[i].flags = 0;
                    obj->parts[i].flags |= 4;
                    if (obj->parts[i].lodCount == 0) {
                        obj->parts[i].flags &= ~4;
                    }
                    SPHERE_CENTER(i);
                    VIEW_DELTA();
                }
            } else {
                obj->parts[i].flags = 0;
                obj->parts[i].flags |= 4;
                SPHERE_CENTER(i);
            }
            if (testRenderObjectPlanes(center, obj->parts[i].sphere[obj->parts[i].flags & 3][3]) == 0) {
                obj->parts[i].flags &= ~4;
            }
        }
    }

    if (group == -1 || group == 0) {
        float *normal;
        CullPlane *plane;

        i = 0;
        normal = cullPlane.normal;
        plane = &cullPlane;
        for (;; i++) {
            float corner[3];

            if (!(i < obj->partCount)) break;

            if (obj->parts[i].flags & 4) {
                u32 lod = obj->parts[i].flags & 3;
                register int n __asm__("$4");

                __asm__("" : : : "$4");
                n = 0;
                CORNER(i, 0, 1, 2);
                if (!BEHIND(corner)) goto done;
                n = 1;
                CORNER(i, 3, 1, 2);
                if (!BEHIND(corner)) goto done;
                n = 2;
                CORNER(i, 0, 4, 2);
                if (!BEHIND(corner)) goto done;
                n = 3;
                CORNER(i, 3, 4, 2);
                if (!BEHIND(corner)) goto done;
                n = 4;
                CORNER(i, 0, 1, 5);
                if (!BEHIND(corner)) goto done;
                n = 5;
                CORNER(i, 3, 1, 5);
                if (!BEHIND(corner)) goto done;
                n = 6;
                CORNER(i, 0, 4, 5);
                if (!BEHIND(corner)) goto done;
                n = 7;
                CORNER(i, 3, 4, 5);
                if (BEHIND(corner)) goto clear;
            done:
                if (n == 8) {
                clear:
                    obj->parts[i].flags &= ~4;
                }
            }
        }
    }

    {
        u32 slot = currentPlayer + slotOffset;

        for (i = 0;; i++) {
            u32 lod;
            PartEntry *entries;
            u32 j;

            if (!(i < obj->partCount)) break;
            if (group != -1 && obj->parts[i].group != group) {
                continue;
            }
            if (obj->parts[i].flags & 4) {
                drawn = 1;
                lod = obj->parts[i].flags & 3;
                entries = obj->parts[i].entries[lod];
                for (j = 0;; j++, entries++) {
                    register DisplayCommand *cmd __asm__("v1");

                    if (!(j < obj->parts[i].entryCount[lod])) break;
                    if (resourceRecords[entries->record].lists[listIndex] == 0) {
                        cmd = &obj->list[entries->linkList[currentPlayer + slotOffset]];
                        cmd->w0 = 0xDF000000;
                        cmd->w1 = 0;
                    } else {
                        cmd = &obj->list[entries->linkList[currentPlayer + slotOffset]];
                        cmd->w0 = 0xDE010000;
                        cmd->w1 = (u32)resourceRecords[entries->record].lists[listIndex];
                    }
                    {
                        register ResourceRecord *record __asm__("v1") = &resourceRecords[entries->record];
                        DisplayCommand *list = obj->list;
                        __asm__("" : : "r"(record), "r"(list));
                        record->lists[listIndex] = &list[entries->nextList[currentPlayer + slotOffset]];
                        __asm__("" : : "r"(j));
                    }
                }
            }
        }
    }
    return drawn;
}
