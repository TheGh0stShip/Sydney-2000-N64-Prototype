typedef struct {
    char pad0[13];
    signed char parent;
    char pad14[2];
} BoneLink;

typedef struct {
    unsigned short count;
    char pad2[2];
    BoneLink *links;
} Skeleton;

typedef struct {
    char pad0[28];
    Skeleton *skeleton;
} Model;

typedef struct {
    char pad0[196];
    Model *model;
    char pad200[24];
    unsigned int mask;
} Rig;

void func_800B9AD0(Rig *self)
{
    Model *model = self->model;
    unsigned short count = model->skeleton->count;
    int i;
    int bone;
    unsigned int bit;

    if (model == 0) {
        return;
    }
    for (i = 31; i >= 0; i--) {
        bit = 1 << i;
        if ((bit & self->mask) && i < count) {
            bone = i;
            self->mask |= bit;
            while (bone != 0) {
                bone = self->model->skeleton->links[bone].parent;
                self->mask |= 1 << bone;
            }
        }
    }
}
