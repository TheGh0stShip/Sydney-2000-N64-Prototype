struct Vertex {
    char pad[28];
    float y;
    char pad2[4];
};

struct Part {
    void *model;
    char pad[208];
};

struct Lift {
    char pad[384];
    struct Part parts[2];
};

extern void func_80017C4C(void *model, int index, struct Vertex **verts);
extern void func_80017C3C(void *model);

void func_800C9230(struct Lift *self)
{
    unsigned char i;

    for (i = 0;; i++) {
        unsigned char j;

        if (i >= 2) {
            break;
        }
        if (self->parts[i].model != 0) {
            struct Vertex *verts = 0;
            float offsets[2] = { 0.001f, -0.001f };

            func_80017C4C(self->parts[i].model, 0, &verts);
            for (j = 0; j < 4; j++) {
                verts[j].y += offsets[i];
            }
            func_80017C3C(self->parts[i].model);
        }
    }
}
