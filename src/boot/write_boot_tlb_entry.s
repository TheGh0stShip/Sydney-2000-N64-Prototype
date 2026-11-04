.set noat
.set noreorder

.globl func_800032F0
.ent func_800032F0
func_800032F0:
    mfc0  $t3, $5
    mtc0  $s4, $0
    bltz  $s4, .Lindexed
     mtc0 $t8, $1
    jr    $ra
     mtc0 $s3, $2
.Lindexed:
    jr    $ra
     mtc0 $s3, $3
.end func_800032F0
