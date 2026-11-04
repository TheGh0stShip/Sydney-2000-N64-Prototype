.set noat
.set noreorder

.globl func_80029150
.ent func_80029150
func_80029150:
    mtc0  $k0, $30
    lui   $k0, %hi(func_80029388)
    addiu $k0, $k0, %lo(func_80029388)
    jr    $k0
     nop
    nop
    nop
    nop
    nop
    nop
.end func_80029150
