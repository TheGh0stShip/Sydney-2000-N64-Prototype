extern void func_8001457C(void *p);

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

void func_800CD6D4(Group *group)
{
    unsigned int i;

    func_8001457C(&group->a);
    func_8001457C(&group->b);
    for (i = 0; i < 2; i++) {
        if (group->extra[i].active != 0) {
            func_8001457C(&group->extra[i]);
        }
    }
}
