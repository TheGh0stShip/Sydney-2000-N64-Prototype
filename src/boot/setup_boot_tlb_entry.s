.set noat
.set noreorder

.globl func_800032BC
.ent func_800032BC
func_800032BC:
    addi  $t4, $zero, 0x1000
    addi  $t3, $zero, 0x2e0
    lw    $t8, 0($t3)
    lhu   $s3, 4($t3)
    jal   func_80001FD8
     lhu  $s4, 6($t3)
    ori   $ra, $t4, 0
    mfc0  $t3, $6
.Lwait_wired:
    bnez  $t3, .Lwait_wired
     mfc0 $t3, $6
    jr    $ra
     mfc0 $t3, $5
.end func_800032BC
