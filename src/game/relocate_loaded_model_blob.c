/* func_80008864 (VRAM 0x80008864, size 0x6D8): matches with SN GCC 2.8
 * -O2 -G0 -mcpu=vr4300 -mips3 -mhard-float -meb.
 * Relocates a loaded model blob (0x54-byte header followed by a header
 * table, groups, parts, batches, strips), copies the vertex area into a
 * heap block, initialises each group, optionally clones the model into an
 * existing type-0x5A runtime record of kind 0x3A, then appends the
 * registered model (or clone) to the indexed record table terminated by
 * 0xFFFF and returns it. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    u32 count;
    void *data;
    void *weights;
    void *normals;
    void *extra;
    u8 padding14[0x0C];
} MeshPart; /* 0x20 */

typedef struct {
    u32 unknown00;
    u16 count;
    u16 padding06;
    u16 *indices;
} Strip; /* 0x0C */

typedef struct {
    u32 vertexCount;
    u32 stripCount;
    void *vertices;
    Strip *strips;
    u32 unknown10;
} Batch; /* 0x14 */

typedef struct {
    u32 partCount;
    MeshPart *parts;
    u32 batchCount;
    Batch *batches;
    void *flags;
    u32 unknown14;
} Group; /* 0x18 */

typedef struct {
    s16 kind;
    u16 padding02;
    void *entries;
} ModelHeader;

typedef struct {
    u16 groupCount;
    u16 padding02;
    u8 *data;
    u8 *copy;
    u32 unknown0C;
    u32 unknown10;
    u16 paragraphs;
    u16 state;
    u32 unknown18;
    ModelHeader *header;
    Group *groups;
    u8 padding24[0x20];
    u32 groupState[4];
} Model; /* 0x54 */

typedef struct {
    u32 type;
    Model *object;
    u32 active;
    void *objectAddress;
    void *auxiliaryAddress;
} RuntimeRecord;

typedef struct {
    u32 key;
    u16 resourceIds[64];
} IndexedRecord;

/* Target-only o32 layouts: file offsets and pointer slots are 32-bit. */
typedef char check_model_size[sizeof(Model) == 0x54 ? 1 : -1];
typedef char check_group_size[sizeof(Group) == 0x18 ? 1 : -1];
typedef char check_part_size[sizeof(MeshPart) == 0x20 ? 1 : -1];
typedef char check_batch_size[sizeof(Batch) == 0x14 ? 1 : -1];
typedef char check_strip_size[sizeof(Strip) == 0x0C ? 1 : -1];
typedef char check_model_header_size[sizeof(ModelHeader) == 8 ? 1 : -1];
typedef char check_runtime_record_size[sizeof(RuntimeRecord) == 0x14 ? 1 : -1];
typedef char check_indexed_record_size[sizeof(IndexedRecord) == 0x84 ? 1 : -1];
typedef char check_pointer_width[sizeof(void *) == 4 ? 1 : -1];

extern void *modelHeap __asm__("D_800456B0");
extern u32 forceShared __asm__("D_800456B4");
extern u32 indexedResourceCount __asm__("D_800477C0");
extern u32 indexedRecordCount __asm__("D_800479C8");
extern IndexedRecord indexedRecords[] __asm__("D_800456C0");
extern u32 runtimeRecordCount __asm__("D_8005AC7C");
extern RuntimeRecord runtimeRecords[] __asm__("D_8005ACD0");
extern char dataTag[] __asm__("D_800005A8");
extern char modelTag[] __asm__("D_800005B0");

extern int func_800AA804(void *heap, void *output, u32 size, char *tag);
extern void func_800AA658(void *heap, void *handle);
extern void func_8002F684(void *destination, void *source, u32 size);
extern void func_80008F3C(Model *model, u32 group, u32 zero, u32 parameter);

u32 func_80008864(Model *model, u32 mode, u32 parameter)
{
    u8 *cursor;
    u32 i;
    u32 j;
    u32 k;
    u32 size;
    Model *clone;
    u32 key;
    u32 part;

    indexedResourceCount = 0;
    if (forceShared != 0) {
        mode = 1;
    }

    cursor = (u8 *)model;
    cursor += 0x54;
    model->header = (ModelHeader *)cursor;
    cursor += 8;
    model->header->entries = cursor;
    cursor += model->header->kind * 16;
    model->groups = (Group *)cursor;
    cursor += model->groupCount * sizeof(Group);

    for (i = 0; i < model->groupCount; i++) {
        model->groups[i].parts = (MeshPart *)cursor;
        cursor += model->groups[i].partCount * sizeof(MeshPart);
        for (part = 0; part < model->groups[i].partCount; part++) {
            model->groups[i].parts[part].data = cursor;
            cursor += (model->groups[i].parts[part].count + 3) & ~3;
            model->groups[i].parts[part].weights = cursor;
            cursor += model->groups[i].parts[part].count * 12;
            model->groups[i].parts[part].normals = cursor;
            cursor += model->groups[i].parts[part].count * 4;
            model->groups[i].parts[part].extra = cursor;
            cursor += model->groups[i].parts[part].count * 12;
        }
        model->groups[i].batches = (Batch *)cursor;
        cursor += model->groups[i].batchCount * sizeof(Batch);
        for (j = 0; j < model->groups[i].batchCount; j++) {
            model->groups[i].batches[j].strips = (Strip *)cursor;
            cursor += model->groups[i].batches[j].stripCount * sizeof(Strip);
            for (k = 0; k < model->groups[i].batches[j].stripCount; k++) {
                model->groups[i].batches[j].strips[k].indices = (u16 *)cursor;
                cursor += model->groups[i].batches[j].strips[k].count * 2;
                if (model->groups[i].batches[j].strips[k].count & 1) {
                    cursor += 2;
                }
            }
        }
        model->groups[i].flags = cursor;
        cursor += ((model->groups[i].batchCount + 1) & ~1) * 2;
    }

    cursor = (u8 *)(((u32)cursor + 7) & ~7);
    model->data = cursor;
    model->copy = 0;
    model->unknown0C = 0;
    model->unknown10 = 0;
    for (i = 0; i < model->groupCount; i++) {
        for (j = 0; j < model->groups[i].batchCount; j++) {
            model->groups[i].batches[j].vertices = cursor;
            cursor += model->groups[i].batches[j].vertexCount * 16;
        }
    }

    model->unknown18 = 0;
    size = cursor - model->data;
    model->paragraphs = (size + 15) >> 4;
    func_800AA804(modelHeap, &model->copy, size, dataTag);
    if (model->copy != 0) {
        goto copied;
    }
    model->state = 0;
    model->copy = model->data;
    goto relocated;
failed:
    func_800AA658(modelHeap, &clone);
    key = (u32)model;
    indexedRecords[indexedRecordCount].key = key;
    indexedRecords[indexedRecordCount].resourceIds[indexedResourceCount] =
        0xFFFF;
    indexedRecordCount++;
    return key;
copied:
    model->state = 2;
    func_8002F684(model->copy, model->data, cursor - model->data);
relocated:

    for (i = 0; i < model->groupCount; i++) {
        model->groupState[i] = 0;
        func_80008F3C(model, i, 0, parameter);
    }

    if (model->header->kind == 0x3A && mode == 1) {
        for (i = 0; i < runtimeRecordCount; i++) {
            Model *other = runtimeRecords[i].object;
            if (other != 0 && runtimeRecords[i].type == 0x5A &&
                other->header->kind == 0x3A) {
                clone = 0;
                func_800AA804(modelHeap, &clone, sizeof(Model), modelTag);
                if (clone != 0) {
                    *clone = *other;
                    clone->data = 0;
                    func_800AA804(modelHeap, &clone->data, size, dataTag);
                    if (model->copy == 0) {
                        goto failed;
                    }
                    func_8002F684(clone->data, model->data, size);
                    clone->copy = model->copy;
                    clone->state = 3;
                    for (j = 0; j < model->groupCount; j++) {
                        clone->groupState[j] = model->groupState[j];
                    }
                    func_800AA658(modelHeap, &model);
                    key = (u32)clone;
                    indexedRecords[indexedRecordCount]
                        .resourceIds[indexedResourceCount] = 0xFFFF;
                    indexedRecords[indexedRecordCount].key = key;
                    indexedRecordCount++;
                    return key;
                }
            }
        }
    }

    key = (u32)model;
    indexedRecords[indexedRecordCount].resourceIds[indexedResourceCount] =
        0xFFFF;
    indexedRecords[indexedRecordCount].key = key;
    indexedRecordCount++;
    return key;
}
