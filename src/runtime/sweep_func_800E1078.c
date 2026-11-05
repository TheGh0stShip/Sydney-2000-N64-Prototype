typedef struct Sheet {
    char pad[18956];
    int *files[12];
    int *headers[12];
    int *bodies[12];
} Sheet;

extern char *const D_8008B9A8[12];
extern char D_800F2758[];
extern char D_8008B5C0[];
extern char D_8008B5D4[];
extern char D_8008B5E4[];
extern char D_8008BA20[];
extern int func_80005A3C(char *, int **, void *, int);
extern void func_800320B0(char *);
extern void func_800AA658(void *, int **);
extern int func_800AA804(void *, int **, int, char *);
extern void func_800B3870(void *, void *, int);
extern void func_800B3AFC(void *, int, int);

#define HEADER_SIZE 4
#define BODY_SIZE 128

void func_800E1078(Sheet *sheet)
{
    unsigned int i;
    int body;

    body = HEADER_SIZE + BODY_SIZE;
    for (i = 0; i < 12; i++) {
        sheet->files[i] = 0;
        if (func_80005A3C(D_8008B9A8[i], &sheet->files[i], D_800F2758, 1)) {
            if (*sheet->files[i] == 0x54535433) {
                sheet->headers[i] = sheet->files[i] + 1;
                sheet->bodies[i] = (int *)((char *)sheet->files[i] + body);
                continue;
            }
            func_800320B0(D_8008B5C0);
        } else {
            func_800320B0(D_8008B5D4);
        }
        if (sheet->files[i] != 0) {
            func_800AA658(D_800F2758, &sheet->files[i]);
            sheet->files[i] = 0;
        }
        if (func_800AA804(D_800F2758, &sheet->files[i], body + BODY_SIZE, D_8008B5E4)) {
            break;
        }
        sheet->headers[i] = sheet->files[i] + 1;
        sheet->bodies[i] = (int *)((char *)sheet->files[i] + body);
        func_800B3870(sheet->headers[i], D_8008BA20, BODY_SIZE);
        func_800B3AFC(sheet->bodies[i], 0, BODY_SIZE);
    }
}
