typedef struct { unsigned char ids[4]; float vals[4]; } Group;

extern char *D_800FC270;

float func_800E3E60(void *self, unsigned int table, int id, unsigned int *outIndex)
{
    Group *groups = 0;
    unsigned int count = 0;
    unsigned int i;

    switch (table) {
    case 0:
    case 1:
    case 7:
    case 9:
    case 10:
        break;
    case 2:
        count = 32;
        groups = (Group *)(D_800FC270 + 1552);
        break;
    case 3:
        count = 32;
        groups = (Group *)(D_800FC270 + 1712);
        break;
    case 4:
        count = 32;
        groups = (Group *)(D_800FC270 + 1872);
        break;
    case 5:
        count = 32;
        groups = (Group *)(D_800FC270 + 2032);
        break;
    case 6:
        count = 30;
        groups = (Group *)(D_800FC270 + 2192);
        break;
    case 8:
        count = 18;
        groups = (Group *)(D_800FC270 + 2364);
        break;
    }
    if (groups != 0 && count != 0) {
        i = 0;
        do {
                        if (groups[i / 4].ids[i % 4] == id) {
                if (outIndex != 0) {
                    *outIndex = i;
                }
                return groups[i / 4].vals[i % 4];
            }
            i++;
        } while (i < count);
    }
    *outIndex = 0;
    return -1.0f;
}
