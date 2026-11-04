.set noat
.set noreorder

.globl func_80003370
.ent func_80003370
func_80003370:
    lw    $t3, 0xfd0($zero)
    sw    $k0, 0xbf8($zero)
    sw    $t3, 0xbfc($zero)
    addi  $t4, $zero, 0x5000
    lw    $t8, 0xff8($zero)
    addi  $s4, $zero, -0x8000
    addi  $s3, $zero, 0xbff
    j     func_80001FD8
     addi $ra, $zero, 0x1088
.end func_80003370
