.set noat
.set noreorder

.globl func_80003334
.ent func_80003334
func_80003334:
    add   $k0, $k0, $k1
    lw    $t8, 0x9c4($k1)
    sw    $k0, 0xff0($zero)
    sw    $t8, 0xfd0($zero)
    addiu $s4, $zero, 0x1080
    jal   func_80001FD8
     addi $s3, $zero, 0xf47
    lw    $t8, 0xd8($zero)
    addiu $s4, $zero, 0x180
    andi  $s3, $t9, 0xfff
    add   $t8, $t8, $s4
    jal   func_80001FD8
     sub  $s3, $s3, $s4
    j     func_80001FC8
     addi $ra, $zero, 0x1084
.end func_80003334
