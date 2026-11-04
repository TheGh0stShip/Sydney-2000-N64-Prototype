#ifndef LEAF_NAME
#define LEAF_NAME rebuildFramebuffers
#endif

#ifndef RELEASE_NAME
#define RELEASE_NAME releaseHandle
#endif

#ifndef ALLOCATE_NAME
#define ALLOCATE_NAME allocateHandle
#endif

#ifndef FORMAT_NAME
#define FORMAT_NAME formatString
#endif

typedef unsigned int u32;

extern unsigned char page80000000[] __asm__("D_80000000");
extern unsigned char page80040000[] __asm__("D_80040000");
extern unsigned char page80060000[] __asm__("D_80060000");
extern unsigned char page800F0000[] __asm__("D_800F0000");

extern void RELEASE_NAME(void *context, void **handle);
extern void ALLOCATE_NAME(void *context, void **handle, u32 size, char *name);
extern void FORMAT_NAME(char *output, char *format, ...);

void LEAF_NAME(void)
{
    char name[256];
    {
        register unsigned char *resourcePage __asm__("$16") = page80040000;
        register void **depthAddress __asm__("$17") =
            (void **)(resourcePage - 0x6BA0);
        register unsigned char *contextPage __asm__("$8") = page800F0000;

        if (*depthAddress != 0) {
            RELEASE_NAME(contextPage + 0x2758, depthAddress);
            *depthAddress = 0;
        }
        ALLOCATE_NAME(contextPage + 0x2758, depthAddress,
                      *(u32 *)(page80060000 - 0x57DC) *
                          *(u32 *)(page80060000 - 0x57D8) * 2,
                      (char *)(page80000000 + 0x800));

        {
            register u32 index __asm__("$17");
            register void **frameAddress __asm__("$16") =
                (void **)(resourcePage - 0x6BAC);
            register unsigned char *releaseContext __asm__("$18") =
                contextPage;

            for (index = 0; index < 3; index++, frameAddress++) {
                if (*frameAddress != 0) {
                    RELEASE_NAME(releaseContext + 0x2758, frameAddress);
                    *frameAddress = 0;
                }
            }
        }
    }

    if (*(u32 *)(page80060000 + 0x61CC) != 0) {
        register u32 index __asm__("$17");
        register void **frameAddress __asm__("$16") =
            (void **)(page80040000 - 0x6BAC);
        register unsigned char *formatPage __asm__("$22") = page80000000;
        register unsigned char *contextPage __asm__("$21") = page800F0000;
        register unsigned char *widthPage __asm__("$20") = page80060000;
        register unsigned char *heightPage __asm__("$19") = page80060000;
        register unsigned char *countPage __asm__("$18") = page80060000;

        for (index = 0;
             index < *(u32 *)(countPage + 0x61CC);
             index++, frameAddress++) {
            FORMAT_NAME(name, (char *)(formatPage + 0x808), index);
            ALLOCATE_NAME(contextPage + 0x2758, frameAddress,
                          *(u32 *)(widthPage - 0x57DC) *
                              *(u32 *)(heightPage - 0x57D8) * 2,
                          name);
        }
    }
}
