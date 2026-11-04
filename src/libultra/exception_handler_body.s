.set noreorder
.set noat
.text
.globl func_8003227C
.ent func_8003227C
func_8003227C:
.set handle_cop_unusable, func_8003227C + 0x60C
    sw $zero, 0x18($k0)
    mfc0 $t0, $13
savecontext:
    move $t0, $k0
    lui $k0, 0x8006
    lw $k0, 0x70B0($k0)
    ld $t1, 0x20($t0)
    sd $t1, 0x20($k0)
    ld $t1, 0x118($t0)
    sd $t1, 0x118($k0)
    ld $t1, 0x58($t0)
    sd $t1, 0x58($k0)
    ld $t1, 0x60($t0)
    sd $t1, 0x60($k0)
    ld $t1, 0x68($t0)
    sd $t1, 0x68($k0)
    sd $v0, 0x28($k0)
    sd $v1, 0x30($k0)
    sd $a0, 0x38($k0)
    sd $a1, 0x40($k0)
    sd $a2, 0x48($k0)
    sd $a3, 0x50($k0)
    sd $t3, 0x70($k0)
    sd $t4, 0x78($k0)
    sd $t5, 0x80($k0)
    sd $t6, 0x88($k0)
    sd $t7, 0x90($k0)
    sd $s0, 0x98($k0)
    sd $s1, 0xA0($k0)
    sd $s2, 0xA8($k0)
    sd $s3, 0xB0($k0)
    sd $s4, 0xB8($k0)
    sd $s5, 0xC0($k0)
    sd $s6, 0xC8($k0)
    sd $s7, 0xD0($k0)
    sd $t8, 0xD8($k0)
    sd $t9, 0xE0($k0)
    sd $gp, 0xE8($k0)
    sd $sp, 0xF0($k0)
    sd $fp, 0xF8($k0)
    sd $ra, 0x100($k0)
    mflo $t0
    sd $t0, 0x108($k0)
    mfhi $t0
    sd $t0, 0x110($k0)
    lw $k1, 0x118($k0)
    andi $t1, $k1, 0xFF00
    beqz $t1, savercp
     nop
    lui $t0, 0x8007
    addiu $t0, $t0, -0x7BB0
    lw $t0, 0($t0)
    li $at, -1
    xor $t2, $t0, $at
    andi $t2, $t2, 0xFF00
    or $t4, $t1, $t2
    lui $at, 0xFFFF
    ori $at, $at, 0x00FF
    and $t3, $k1, $at
    or $t3, $t3, $t4
    sw $t3, 0x118($k0)
    andi $t0, $t0, 0xFF00
    and $t1, $t1, $t0
    lui $at, 0xFFFF
    ori $at, $at, 0x00FF
    and $k1, $k1, $at
    or $k1, $k1, $t1
savercp:
    lui $t1, 0xA430
    lw $t1, 0x000C($t1)
    beqz $t1, endrcp
     nop
    lui $t0, 0x8007
    addiu $t0, $t0, -0x7BB0
    lw $t0, 0($t0)
    srl $t0, $t0, 16
    li $at, -1
    xor $t0, $t0, $at
    andi $t0, $t0, 0x3F
    lw $t4, 0x128($k0)
    and $t0, $t0, $t4
    or $t1, $t1, $t0
endrcp:
    sw $t1, 0x128($k0)
    mfc0 $t0, $14
    sw $t0, 0x11C($k0)
    lw $t0, 0x18($k0)
    beqz $t0, fp_done
     nop
    cfc1 $t0, $31
    nop
    sw $t0, 0x12C($k0)
    sdc1 $f0, 0x130($k0)
    sdc1 $f2, 0x138($k0)
    sdc1 $f4, 0x140($k0)
    sdc1 $f6, 0x148($k0)
    sdc1 $f8, 0x150($k0)
    sdc1 $f10, 0x158($k0)
    sdc1 $f12, 0x160($k0)
    sdc1 $f14, 0x168($k0)
    sdc1 $f16, 0x170($k0)
    sdc1 $f18, 0x178($k0)
    sdc1 $f20, 0x180($k0)
    sdc1 $f22, 0x188($k0)
    sdc1 $f24, 0x190($k0)
    sdc1 $f26, 0x198($k0)
    sdc1 $f28, 0x1A0($k0)
    sdc1 $f30, 0x1A8($k0)
fp_done:
    mfc0 $t0, $13
    sw $t0, 0x120($k0)
    li $t1, 2
    sh $t1, 0x10($k0)
    andi $t1, $t0, 0x7C
    li $t2, 0x24
    beq $t1, $t2, handle_break
     nop
    li $t2, 0x2C
    beq $t1, $t2, handle_cop_unusable
     nop
    li $t2, 0
    bne $t1, $t2, panic
     nop
    and $s0, $k1, $t0
next_interrupt:
    andi $t1, $s0, 0xFF00
    srl $t2, $t1, 12
    bnez $t2, interrupt_index_ready
     nop
    srl $t2, $t1, 8
    addi $t2, $t2, 16
interrupt_index_ready:
    lui $at, 0x8000
    addu $at, $at, $t2
    lbu $t2, 0x2090($at)
    lui $at, 0x8000
    addu $at, $at, $t2
    lw $t2, 0x20B0($at)
    jr $t2
     nop
IP6_Hdlr:
    li $at, -0x2001
    b next_interrupt
     and $s0, $s0, $at
IP7_Hdlr:
    li $at, -0x4001
    b next_interrupt
     and $s0, $s0, $at
counter:
    mfc0 $t1, $11
    mtc0 $t1, $11
    li $a0, 0x18
    jal func_800327CC
     nop
    lui $at, 0xFFFF
    ori $at, $at, 0x7FFF
    b next_interrupt
     and $s0, $s0, $at
cart:
    li $at, -0x801
    and $s0, $s0, $at
    lui $t1, 0x8006
    addiu $t1, $t1, 0x7040
    addi $t1, $t1, 8
    lw $t2, 0($t1)
    beqz $t2, cart_message
     nop
    jalr $t2
     lw $sp, 4($t1)
    beqz $v0, cart_message
     nop
    b redispatch
     nop
cart_message:
    jal func_800327CC
     li $a0, 0x10
    b next_interrupt
     nop
rcp:
    lui $s1, 0xA430
    lw $s1, 8($s1)
    lui $t0, 0x8007
    addiu $t0, $t0, -0x7BB0
    lw $t0, 0($t0)
    srl $t0, $t0, 16
    and $s1, $s1, $t0
    andi $t1, $s1, 1
    beqz $t1, video_interrupt
     nop
    andi $s1, $s1, 0x3E
    lui $t4, 0xA404
    lw $t4, 0x10($t4)
    ori $t1, $zero, 0x8008
    lui $at, 0xA404
    sw $t1, 0x10($at)
    andi $t4, $t4, 0x300
    beqz $t4, sp_break
     nop
    jal func_800327CC
     li $a0, 0x20
    beqz $s1, no_more_rcp
     nop
    b video_interrupt
     nop
sp_break:
    jal func_800327CC
     li $a0, 0x58
    beqz $s1, no_more_rcp
     nop
video_interrupt:
    andi $t1, $s1, 8
    beqz $t1, audio_interrupt
     nop
    andi $s1, $s1, 0x37
    lui $at, 0xA440
    sw $zero, 0x10($at)
    jal func_800327CC
     li $a0, 0x38
    beqz $s1, no_more_rcp
     nop
audio_interrupt:
    andi $t1, $s1, 4
    beqz $t1, serial_interrupt
     nop
    andi $s1, $s1, 0x3B
    li $t1, 1
    lui $at, 0xA450
    sw $t1, 0x0C($at)
    jal func_800327CC
     li $a0, 0x30
    beqz $s1, no_more_rcp
     nop
serial_interrupt:
    andi $t1, $s1, 2
    beqz $t1, parallel_interrupt
     nop
    andi $s1, $s1, 0x3D
    lui $at, 0xA480
    sw $zero, 0x18($at)
    jal func_800327CC
     li $a0, 0x28
    beqz $s1, no_more_rcp
     nop
parallel_interrupt:
    andi $t1, $s1, 0x10
    beqz $t1, display_interrupt
     nop
    andi $s1, $s1, 0x2F
    li $t1, 2
    lui $at, 0xA460
    sw $t1, 0x10($at)
    lui $t1, 0x8006
    addiu $t1, $t1, 0x7068
    lw $t2, 0($t1)
    beqz $t2, parallel_message
     nop
    lw $sp, 4($t1)
    jalr $t2
     move $a0, $v0
    bnez $v0, parallel_done
     nop
parallel_message:
    jal func_800327CC
     li $a0, 0x40
parallel_done:
    beqz $s1, no_more_rcp
     nop
display_interrupt:
    andi $t1, $s1, 0x20
    beqz $t1, no_more_rcp
     nop
    andi $s1, $s1, 0x1F
    li $t1, 0x800
    lui $at, 0xA430
    sw $t1, 0($at)
    jal func_800327CC
     li $a0, 0x48
no_more_rcp:
    li $at, -0x401
    b next_interrupt
     and $s0, $s0, $at
prenmi:
    lw $k1, 0x118($k0)
    li $at, -0x1001
    and $k1, $k1, $at
    sw $k1, 0x118($k0)
    lui $t1, 0x8007
    addiu $t1, $t1, -0x7BB4
    lw $t2, 0($t1)
    beqz $t2, first_nmi
     nop
    li $at, -0x1001
    b redispatch
     and $s0, $s0, $at
first_nmi:
    li $t2, 1
    sw $t2, 0($t1)
    jal func_800327CC
     li $a0, 0x70
    li $at, -0x1001
    and $s0, $s0, $at
    lui $t2, 0x8006
    lw $t2, 0x70A8($t2)
    lw $k1, 0x118($t2)
    li $at, -0x1001
    and $k1, $k1, $at
    b redispatch
     sw $k1, 0x118($t2)
sw2:
    li $at, -0x201
    and $t0, $t0, $at
    mtc0 $t0, $13
    li $a0, 8
    jal func_800327CC
     nop
    li $at, -0x201
    b next_interrupt
     and $s0, $s0, $at
sw1:
    li $at, -0x101
    and $t0, $t0, $at
    mtc0 $t0, $13
    li $a0, 0
    jal func_800327CC
     nop
    li $at, -0x101
    b next_interrupt
     and $s0, $s0, $at
handle_break:
    li $t1, 1
    sh $t1, 0x12($k0)
    jal func_800327CC
     li $a0, 0x50
    b redispatch
     nop
redispatch:
    lw $t1, 0x04($k0)
    lui $t2, 0x8006
    lw $t2, 0x70A8($t2)
    lw $t3, 0x04($t2)
    slt $at, $t1, $t3
    beqz $at, enqueue_running
     nop
    move $a1, $k0
    lui $a0, 0x8006
    jal func_800329C4
     addiu $a0, $a0, 0x70A8
    j func_80032A1C
     nop
enqueue_running:
    lui $t1, 0x8006
    addiu $t1, $t1, 0x70A8
    lw $t2, 0($t1)
    sw $t2, 0x00($k0)
    j func_80032A1C
     sw $k0, 0($t1)
panic:
    lui $at, 0x8006
    sw $k0, 0x70B4($at)
    li $t1, 1
    sh $t1, 0x10($k0)
    li $t1, 2
    sh $t1, 0x12($k0)
    mfc0 $t2, $8
    sw $t2, 0x124($k0)
    jal func_800327CC
     li $a0, 0x60
    j func_80032A1C
     nop
.end func_8003227C
