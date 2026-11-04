.set noat
.set noreorder

.globl func_800292C4
.ent func_800292C4
func_800292C4:
    addi  $sp, $sp, -0x20
    sw    $a0, 0x00($sp)
    sw    $a1, 0x04($sp)
    sw    $a2, 0x08($sp)
    sw    $a3, 0x0c($sp)
    mfc0  $v0, $10
    mfc0  $a0, $0
    sw    $a0, 0x10($sp)
    mfc0  $a0, $5
    sw    $a0, 0x14($sp)
    mfc0  $a0, $2
    sw    $a0, 0x18($sp)
    mfc0  $a0, $3
    sw    $a0, 0x1c($sp)
    addi  $a0, $zero, 31
    lui   $a1, %hi(D_8006D5B4)
    addiu $a1, $a1, %lo(D_8006D5B4)
1:
    mtc0  $a0, $0
    addi  $a0, $a0, -1
    tlbr
    nop
    nop
    nop
    nop
    mfc0  $a2, $5
    mfc0  $a3, $10
    sw    $a2, 0x00($a1)
    sw    $a3, 0x04($a1)
    mfc0  $a2, $2
    mfc0  $a3, $3
    sw    $a2, 0x08($a1)
    sw    $a3, 0x0c($a1)
    bgez  $a0, 1b
     addi $a1, $a1, -0x10
    mtc0  $v0, $10
    lw    $a0, 0x10($sp)
    mtc0  $a0, $0
    lw    $a0, 0x14($sp)
    mtc0  $a0, $5
    lw    $a0, 0x18($sp)
    mtc0  $a0, $2
    lw    $a0, 0x1c($sp)
    mtc0  $a0, $3
    lw    $a0, 0x00($sp)
    lw    $a1, 0x04($sp)
    lw    $a2, 0x08($sp)
    lw    $a3, 0x0c($sp)
    jr    $ra
     addi $sp, $sp, 0x20
.end func_800292C4
