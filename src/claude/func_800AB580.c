/* func_800AB580: depth-first scene walk; position = parent->position + offset when inherit is set. Matches SN -O2 (the loop nesting matters: loop-depth ref weighting decides the f0/f2 choice for the y add). */
typedef struct Vec3f { float x, y, z; } Vec3f;
typedef struct SceneNode SceneNode;
struct SceneNode {
    int type;
    SceneNode *parent;
    SceneNode *firstChild;
    SceneNode *next;
    char unused10[0x44];
    Vec3f position;
    char unused60[0x40];
    Vec3f offset;
    char unusedAC[4];
    signed char inherit;
};

extern SceneNode *sceneRoot;

void func_800AB580(void) {
    SceneNode *root = sceneRoot;
    SceneNode *node;
    int depth;

    if (!root) return;
    depth = 1;
    node = root;
    for (;;) {
        if (!depth) return;
        if (node->parent && node->inherit) {
            Vec3f *base = &node->parent->position;
            Vec3f *offset = &node->offset;
            Vec3f *position = &node->position;

            position->x = base->x + offset->x;
            position->y = base->y + offset->y;
            position->z = base->z + offset->z;
        }
        if (node->firstChild) {
            node = node->firstChild;
            depth++;
        } else {
            for (;;) {
                if (!depth || node->next) break;
                node = node->parent;
                depth--;
            }
            if (node) node = node->next;
        }
    }
}
