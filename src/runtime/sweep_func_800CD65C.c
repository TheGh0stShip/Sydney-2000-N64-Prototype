extern void func_80014480(void *p);

typedef struct {
    unsigned char data[196];
    int active;
    unsigned char rest[12];
} Part;

typedef struct {
    Part a;
    Part b;
    unsigned char pad[60];
    Part extra[2];
} Group;

void func_800CD65C(Group *group)
{
    unsigned int i;

    func_80014480(&group->a);
    func_80014480(&group->b);
    for (i = 0; i < 2; i++) {
        if (group->extra[i].active != 0) {
            func_80014480(&group->extra[i]);
        }
    }
}
