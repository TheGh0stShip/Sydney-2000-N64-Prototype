#include "PRinternal/macros.h"
#include "PR/os_internal.h"
#include "PRinternal/controller.h"

s32 __osCheckId(OSPfs* pfs) {
    u8 temp[BLOCKSIZE];
    s32 ret;

    if (pfs->activebank != 0) {
        ret = __osPfsSelectBank(pfs, 0);

        if (ret == PFS_ERR_NEW_PACK) {
            ret = __osPfsSelectBank(pfs, 0);
        }

        if (ret != 0) {
            return ret;
        }
    }

    ret = __osContRamRead(pfs->queue, pfs->channel, PFS_ID_0AREA, temp);

    if (ret != 0) {
        if (ret != PFS_ERR_NEW_PACK) {
            return ret;
        }
        ERRCK(__osContRamRead(pfs->queue, pfs->channel, PFS_ID_0AREA, temp));
    }

    if (bcmp(pfs->id, temp, BLOCKSIZE) != 0) {
        return PFS_ERR_NEW_PACK;
    }

    return 0;
}
