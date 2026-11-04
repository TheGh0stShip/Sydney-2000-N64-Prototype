.set noat
.set noreorder

.equ __osRunQueue, 0x800670A8
.equ __osRunningThread, 0x800670B0
.equ __OSGlobalIntMask, 0x80068450
.equ __osRcpImTable, 0x80001B10

.globl func_80032A1C
.ent func_80032A1C
func_80032A1C:
    lui   $a0, 0x8006
    jal   __osPopThread
     addiu $a0, $a0, 0x70a8
    lui   $at, 0x8006
    sw    $v0, 0x70b0($at)
    addiu $t0, $zero, 4
    sh    $t0, 0x10($v0)
    addu  $k0, $v0, $zero
    lw    $k1, 0x118($k0)
    lui   $t0, 0x8007
    addiu $t0, $t0, -0x7bb0
    lw    $t0, 0($t0)
    andi  $t0, $t0, 0xff00
    andi  $t1, $k1, 0xff00
    and   $t1, $t1, $t0
    lui   $at, 0xffff
    ori   $at, $at, 0x00ff
    and   $k1, $k1, $at
    or    $k1, $k1, $t1
    mtc0  $k1, $12
    ld    $at, 0x020($k0)
    ld    $v0, 0x028($k0)
    ld    $v1, 0x030($k0)
    ld    $a0, 0x038($k0)
    ld    $a1, 0x040($k0)
    ld    $a2, 0x048($k0)
    ld    $a3, 0x050($k0)
    ld    $t0, 0x058($k0)
    ld    $t1, 0x060($k0)
    ld    $t2, 0x068($k0)
    ld    $t3, 0x070($k0)
    ld    $t4, 0x078($k0)
    ld    $t5, 0x080($k0)
    ld    $t6, 0x088($k0)
    ld    $t7, 0x090($k0)
    ld    $s0, 0x098($k0)
    ld    $s1, 0x0a0($k0)
    ld    $s2, 0x0a8($k0)
    ld    $s3, 0x0b0($k0)
    ld    $s4, 0x0b8($k0)
    ld    $s5, 0x0c0($k0)
    ld    $s6, 0x0c8($k0)
    ld    $s7, 0x0d0($k0)
    ld    $t8, 0x0d8($k0)
    ld    $t9, 0x0e0($k0)
    ld    $gp, 0x0e8($k0)
    ld    $sp, 0x0f0($k0)
    ld    $fp, 0x0f8($k0)
    ld    $ra, 0x100($k0)
    ld    $k1, 0x108($k0)
    mtlo  $k1
    ld    $k1, 0x110($k0)
    mthi  $k1
    lw    $k1, 0x11c($k0)
    mtc0  $k1, $14
    lw    $k1, 0x018($k0)
    beqz  $k1, 1f
     nop
    lw    $k1, 0x12c($k0)
    ctc1  $k1, $31
    ldc1  $f0, 0x130($k0)
    ldc1  $f2, 0x138($k0)
    ldc1  $f4, 0x140($k0)
    ldc1  $f6, 0x148($k0)
    ldc1  $f8, 0x150($k0)
    ldc1  $f10, 0x158($k0)
    ldc1  $f12, 0x160($k0)
    ldc1  $f14, 0x168($k0)
    ldc1  $f16, 0x170($k0)
    ldc1  $f18, 0x178($k0)
    ldc1  $f20, 0x180($k0)
    ldc1  $f22, 0x188($k0)
    ldc1  $f24, 0x190($k0)
    ldc1  $f26, 0x198($k0)
    ldc1  $f28, 0x1a0($k0)
    ldc1  $f30, 0x1a8($k0)
1:
    lw    $k1, 0x128($k0)
    lui   $k0, 0x8007
    addiu $k0, $k0, -0x7bb0
    lw    $k0, 0($k0)
    srl   $k0, $k0, 16
    and   $k1, $k1, $k0
    sll   $k1, $k1, 1
    lui   $k0, 0x8000
    addiu $k0, $k0, 0x1b10
    addu  $k1, $k1, $k0
    lhu   $k1, 0($k1)
    lui   $k0, 0xa430
    ori   $k0, $k0, 0x000c
    sw    $k1, 0($k0)
    nop
    nop
    nop
    nop
    eret
.end func_80032A1C
