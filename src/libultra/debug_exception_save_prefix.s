.set noat
.set noreorder

.globl func_80029388
.ent func_80029388
func_80029388:
    lui   $k0, %hi(D_8006D080)
    addiu $k0, $k0, %lo(D_8006D080)
    sd    $at, 0x328($k0)
    sd    $v0, 0x330($k0)
.end func_80029388
