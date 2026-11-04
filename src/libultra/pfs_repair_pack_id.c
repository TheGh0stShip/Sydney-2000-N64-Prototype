#include "PRinternal/macros.h"
#include "PR/os_internal.h"
#include "PRinternal/controller.h"

static __inline__ s32 __osIdCheckSumInline(u16* ptr, u16* csum, u16* icsum) {
    u16 data = 0;
    u32 j;

    *csum = *icsum = 0;
    for (j = 0; j < ((sizeof(__OSPackId) - sizeof(u32)) / sizeof(u8)); j += 2) {
        data = *(u16*)((u32)ptr + j);
        *csum += data;
        *icsum += ~data;
    }
    return 0;
}

s32 __osRepairPackId(OSPfs* pfs, __OSPackId* badid, __OSPackId* newid) {
    s32 ret = 0;
    u8 temp[BLOCKSIZE];
    u8 comp[BLOCKSIZE];
    u8 mask = 0;
    int i;
    int j;
    u16 index[4];

    j = 0;
    newid->repaired = -1;
    newid->random = osGetCount();
    newid->serial_mid = badid->serial_mid;
    newid->serial_low = badid->serial_low;

    SET_ACTIVEBANK_TO_ZERO();
    do {
        ERRCK(SELECT_BANK(pfs, j));
        ERRCK(__osContRamRead(pfs->queue, pfs->channel, 0, temp));

        temp[0] = j | 0x80;
        for (i = 1; i < BLOCKSIZE; i++) {
            temp[i] = ~temp[i];
        }

        ERRCK(__osContRamWrite(pfs->queue, pfs->channel, 0, temp, FALSE));
        ERRCK(__osContRamRead(pfs->queue, pfs->channel, 0, comp));

        for (i = 0; i < BLOCKSIZE; i++) {
            if (comp[i] != temp[i]) {
                break;
            }
        }

        if (i != BLOCKSIZE) {
            break;
        }

        if (j > 0) {
            ERRCK(SELECT_BANK(pfs, 0));
            ERRCK(__osContRamRead(pfs->queue, pfs->channel, 0, temp));

            if (temp[0] != 0x80) {
                break;
            }
        }

        j++;
    } while (j < PFS_MAX_BANKS);

    SET_ACTIVEBANK_TO_ZERO();
    mask = (j > 0) ? 1 : 0;

    newid->deviceid = (badid->deviceid & (u16)~1) | mask;
    newid->banks = j;
    newid->version = badid->version;
    __osIdCheckSumInline((u16*)newid, &newid->checksum, &newid->inverted_checksum);
    index[0] = PFS_ID_0AREA;
    index[1] = PFS_ID_1AREA;
    index[2] = PFS_ID_2AREA;
    index[3] = PFS_ID_3AREA;

    for (i = 0; i < ARRLEN(index); i++) {
        ERRCK(__osContRamWrite(pfs->queue, pfs->channel, index[i], (u8*)newid, TRUE));
    }

    ERRCK(__osContRamRead(pfs->queue, pfs->channel, PFS_ID_0AREA, temp));

    for (i = 0; i < BLOCKSIZE; i++) {
        if (temp[i] != ((u8*)newid)[i]) {
            return PFS_ERR_DEVICE;
        }
    }
    return 0;
}
