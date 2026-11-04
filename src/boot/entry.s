.set noat
.set noreorder

.globl func_80000400
.ent func_80000400
func_80000400:
    lui     $sp, 0x803f
    ori     $sp, $sp, 0xfff0
    lui     $t0, 0x8007
    addiu   $t0, $t0, -0x7b90
    lui     $t1, 0x8007
    addiu   $t1, $t1, 0x7d0
    beq     $t0, $t1, .Lentry_call
     nop
.Lentry_clear_bss:
    addiu   $t0, $t0, 4
    sltu    $at, $t0, $t1
    bnez    $at, .Lentry_clear_bss
     sw     $zero, -4($t0)
.Lentry_call:
    jal     func_800048B0
     nop
    # This assembler accepts only the first of the two architectural BREAK fields.
    .long   (1 << 16) | (2 << 6) | 0x0d
     nop
.end func_80000400
