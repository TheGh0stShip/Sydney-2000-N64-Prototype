extern char D_80077804[];
extern char D_8007782C[];
extern void func_800D33A0(char *object, char *name, int a, int b);
extern void func_80077070(char *self, int a, int b, int c);
extern void func_800D29E0(char *object);

void func_800B1C08(char *self)
{
    *(int *)(self + 23432) += 256;
    if (*(unsigned char *)(self + 23426) != 0) {
        *(int *)(self + 23428) -= 256;
        if (*(int *)(self + 23428) <= 0) {
            *(int *)(self + 23428) = 0xB400;
            *(unsigned char *)(self + 23425) = 1;
            *(int *)(self + 21512) = 1;
            *(int *)(self + 21820) = 1;
            *(int *)(self + 22940) = 1;
            *(unsigned char *)(self + 23426) = 0;
            if (*(unsigned char *)(self + 23438) == 2) {
                func_800D33A0(self + 12020, D_80077804, 1, -1);
                func_80077070(self, 26, 0, 0);
            } else {
                func_800D33A0(self + 12020, D_8007782C, 1, -1);
            }
        }
    }
    if (*(unsigned char *)(self + 23425) != 0) {
        *(int *)(self + 23428) -= 256;
        if (*(int *)(self + 23428) <= 0) {
            *(int *)(self + 23428) = 0;
            *(unsigned char *)(self + 23425) = 0;
            *(int *)(self + 21512) = 0;
            *(int *)(self + 21820) = 0;
            *(int *)(self + 22940) = 0;
            func_800D29E0(self + 12020);
        }
    }
    if (*(unsigned char *)(self + 23438) == 0) {
        if (*(unsigned char *)(self + 23423) == 2) {
            *(int *)(self + 23428) = 30720;
        } else {
            *(int *)(self + 23428) = 15360;
        }
        *(int *)(self + 23412) = 6;
    }
}
