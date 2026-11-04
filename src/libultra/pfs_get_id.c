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

s32 __osGetId(OSPfs* pfs) {
    u16 sum;
    u16 isum;
    u8 temp[BLOCKSIZE];
    __OSPackId newid;
    s32 ret;
    __OSPackId* id;

    SET_ACTIVEBANK_TO_ZERO();
    ERRCK(__osContRamRead(pfs->queue, pfs->channel, PFS_ID_0AREA, temp));
    __osIdCheckSumInline((u16*)temp, &sum, &isum);
    id = (__OSPackId*)temp;

    if (id->checksum != sum || id->inverted_checksum != isum) {
        ret = __osCheckPackId(pfs, id);

        if (ret == PFS_ERR_ID_FATAL) {
            ERRCK(__osRepairPackId(pfs, id, &newid));
            id = &newid;
        } else if (ret != 0) {
            return ret;
        }
    }

    if ((id->deviceid & 1) == 0) {
        ERRCK(__osRepairPackId(pfs, id, &newid));
        id = &newid;

        if ((id->deviceid & 1) == 0) {
            return PFS_ERR_DEVICE;
        }
    }

    bcopy(id, pfs->id, BLOCKSIZE);
    pfs->version = id->version;
    pfs->banks = id->banks;
    pfs->inode_start_page = 1 + DEF_DIR_PAGES + (2 * pfs->banks);
    pfs->dir_size = 16;
    pfs->inode_table = PFS_ONE_PAGE;
    pfs->minode_table = (1 + pfs->banks) * PFS_ONE_PAGE;
    pfs->dir_table = pfs->minode_table + pfs->banks * PFS_ONE_PAGE;
    ERRCK(__osContRamRead(pfs->queue, pfs->channel, PFS_LABEL_AREA, pfs->label));
    return 0;
}
