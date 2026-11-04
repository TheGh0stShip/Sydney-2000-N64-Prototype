.set noreorder
.set noat
.text
.set os_exception_entry, func_80029398 - 0x234
.set vector_stub_a, func_80029398 - 0x234
.set vector_stub_b, func_80029398 - 0x1fc
.set host_hook, func_80029398 - 0x644
.set stub_main, func_80029398 + 0x58c
.globl func_80029398
.ent func_80029398
func_80029398:
    mfc0 $at, $13
    lw $v0, 0x338($k0)
    srl $at, $at, 2
    andi $at, $at, 0x1F
    beqz $at, check_interrupt
     srlv $v0, $v0, $at
    andi $v0, $v0, 1
    bnez $v0, check_break
     nop
pass_to_os:
    ld $at, 0x328($k0)
    ld $v0, 0x330($k0)
    bgez $zero, os_exception_entry
     nop
check_interrupt:
    mfc0 $at, $13
    nop
    andi $at, $at, 0x0800
    beqz $at, pass_to_os
     nop
    wait_pi_hello: lui $at, 0xA460; ori $at, $at, 0x0010; lw $at, 0($at); nop; andi $at, $at, 3; bnez $at, wait_pi_hello; nop
    lui $at, 0xB200
    lw $at, -0x28($at)
    nop
    andi $at, $at, 0xFFFF
    addi $at, $at, -0x0202
    bnez $at, check_request
     nop
handshake:
    wait_pi_send: lui $at, 0xA460; ori $at, $at, 0x0010; lw $at, 0($at); nop; andi $at, $at, 3; bnez $at, wait_pi_send; nop
    lui $at, 0x0303
    ori $at, $at, 0x0303
    lui $v0, 0xB200
    sw $at, -0x28($v0)
    wait_pi_echo: lui $at, 0xA460; ori $at, $at, 0x0010; lw $at, 0($at); nop; andi $at, $at, 3; bnez $at, wait_pi_echo; nop
    lui $v0, 0xB200
    lw $at, -0x28($v0)
    lui $v0, 0x0303
    ori $v0, $v0, 0x0303
    sub $at, $at, $v0
    bnez $at, handshake_done
     nop
    lui $at, 1
    ori $at, $at, 1
1: bnez $at, 1b
     addi $at, $at, -1
    beqz $at, wait_pi_echo
     nop
handshake_done:
    wait_pi_clear: lui $at, 0xA460; ori $at, $at, 0x0010; lw $at, 0($at); nop; andi $at, $at, 3; bnez $at, wait_pi_clear; nop
    lui $v0, 0xB200
    sw $zero, -0x28($v0)
    mfc0 $at, $13
    nop
    ori $at, $at, 0x0100
    j pass_to_os
     mtc0 $at, $13
check_request:
    wait_pi_req: lui $at, 0xA460; ori $at, $at, 0x0010; lw $at, 0($at); nop; andi $at, $at, 3; bnez $at, wait_pi_req; nop
    lui $at, 0xB200
    lw $at, -0x10($at)
    nop
    andi $at, $at, 0xFFFF
    beqz $at, pass_to_os
     nop
    bgez $zero, enter_stub_active
     nop
check_break:
    addiu $v0, $zero, 9
    bne $at, $v0, enter_stub
     nop
    mfc0 $v0, $14
    nop
    lw $v0, 0($v0)
    nop
    srl $v0, $v0, 6
    addiu $at, $v0, -0x400
    bgez $at, break_service
     nop
enter_stub_break:
    addiu $at, $zero, 9
enter_stub:
    sb $at, 0x320($k0)
    sb $zero, 0x322($k0)
enter_stub_active:
    addiu $at, $zero, 1
    sw $at, 0x33C($k0)
    ld $at, 0x328($k0)
    ld $v0, 0x330($k0)
    sd $ra, ((31) * 8)($k0)
    jal stub_main
     nop
    lui $sp, 0x8007
    addiu $sp, $sp, -0x23F8
    jal func_80028EB8
     nop
    jal func_80029274
     nop
    jal func_80029290
     nop
restore_context:
    lui $k0, 0x8007
    addiu $k0, $k0, -0x2F80
    addiu $at, $zero, 1
    sb $at, 0x320($k0)
    ld $t0, 0x108($k0)
    nop
    mthi $t0
    ld $t0, 0x100($k0)
    nop
    mtlo $t0
    ld $t0, 0x178($k0)
    nop
    mtc0 $t0, $12
    ld $t0, 0x110($k0)
    nop
    mtc0 $t0, $14
    ld $t0, 0x1A8($k0)
    nop
    mtc0 $t0, $18
    ld $t0, 0x1B0($k0)
    nop
    mtc0 $t0, $19
    ld $t0, ((26) * 8)($k0)
    nop
    mtc0 $t0, $30
    ld $t0, 0x178($k0)
    lui $t1, 0x2000
    and $t1, $t1, $t0
    beqz $t1, restore_gprs
     nop
    lw $t0, 0x318($k0)
    nop
    ctc1 $t0, $0
    mfc0 $v1, $13
    addiu $v0, $zero, 0x3C
    andi $at, $v1, 0x7C
    bne $at, $v0, 1f
     nop
    lw $t0, 0x31C($k0)
    lui $t1, 0xFFFE
    ori $t1, $t1, 0xF83
    and $t0, $t0, $t1
    ctc1 $t0, $31
    lw $t0, 0x340($k0)
    beqz $t0, 1f
     nop
    bltz $v1, 1f
     nop
    mfc0 $at, $14
    nop
    addiu $at, $at, 4
    mtc0 $at, $14
1:
    ldc1 $f0, (0x218 + (0) * 8)($k0)
    ldc1 $f2, (0x218 + (2) * 8)($k0)
    ldc1 $f4, (0x218 + (4) * 8)($k0)
    ldc1 $f6, (0x218 + (6) * 8)($k0)
    ldc1 $f8, (0x218 + (8) * 8)($k0)
    ldc1 $f10, (0x218 + (10) * 8)($k0)
    ldc1 $f12, (0x218 + (12) * 8)($k0)
    ldc1 $f14, (0x218 + (14) * 8)($k0)
    ldc1 $f16, (0x218 + (16) * 8)($k0)
    ldc1 $f18, (0x218 + (18) * 8)($k0)
    ldc1 $f20, (0x218 + (20) * 8)($k0)
    ldc1 $f22, (0x218 + (22) * 8)($k0)
    ldc1 $f24, (0x218 + (24) * 8)($k0)
    ldc1 $f26, (0x218 + (26) * 8)($k0)
    ldc1 $f28, (0x218 + (28) * 8)($k0)
    ldc1 $f30, (0x218 + (30) * 8)($k0)
    ld $t0, 0x178($k0)
    lui $t1, 0x0400
    and $t1, $t1, $t0
    beqz $t1, restore_gprs
     nop
    ldc1 $f1, (0x218 + (1) * 8)($k0)
    ldc1 $f3, (0x218 + (3) * 8)($k0)
    ldc1 $f5, (0x218 + (5) * 8)($k0)
    ldc1 $f7, (0x218 + (7) * 8)($k0)
    ldc1 $f9, (0x218 + (9) * 8)($k0)
    ldc1 $f11, (0x218 + (11) * 8)($k0)
    ldc1 $f13, (0x218 + (13) * 8)($k0)
    ldc1 $f15, (0x218 + (15) * 8)($k0)
    ldc1 $f17, (0x218 + (17) * 8)($k0)
    ldc1 $f19, (0x218 + (19) * 8)($k0)
    ldc1 $f21, (0x218 + (21) * 8)($k0)
    ldc1 $f23, (0x218 + (23) * 8)($k0)
    ldc1 $f25, (0x218 + (25) * 8)($k0)
    ldc1 $f27, (0x218 + (27) * 8)($k0)
    ldc1 $f29, (0x218 + (29) * 8)($k0)
    ldc1 $f31, (0x218 + (31) * 8)($k0)
restore_gprs:
    ld $1, ((1) * 8)($k0)
    ld $2, ((2) * 8)($k0)
    ld $3, ((3) * 8)($k0)
    ld $4, ((4) * 8)($k0)
    ld $5, ((5) * 8)($k0)
    ld $6, ((6) * 8)($k0)
    ld $7, ((7) * 8)($k0)
    ld $8, ((8) * 8)($k0)
    ld $9, ((9) * 8)($k0)
    ld $10, ((10) * 8)($k0)
    ld $11, ((11) * 8)($k0)
    ld $12, ((12) * 8)($k0)
    ld $13, ((13) * 8)($k0)
    ld $14, ((14) * 8)($k0)
    ld $15, ((15) * 8)($k0)
    ld $16, ((16) * 8)($k0)
    ld $17, ((17) * 8)($k0)
    ld $18, ((18) * 8)($k0)
    ld $19, ((19) * 8)($k0)
    ld $20, ((20) * 8)($k0)
    ld $21, ((21) * 8)($k0)
    ld $22, ((22) * 8)($k0)
    ld $23, ((23) * 8)($k0)
    ld $24, ((24) * 8)($k0)
    ld $25, ((25) * 8)($k0)
    ld $27, ((27) * 8)($k0)
    ld $28, ((28) * 8)($k0)
    ld $29, ((29) * 8)($k0)
    ld $30, ((30) * 8)($k0)
    ld $31, ((31) * 8)($k0)
    sw $zero, 0x33C($k0)
    mfc0 $k0, $30
    eret
break_service:
    addiu $at, $v0, -(0x400 + 10)
    bgez $at, enter_stub_break
     nop
    lui $at, %hi(break_service_table)
    addiu $at, $at, %lo(break_service_table)
    addiu $v0, $v0, -0x400
    sll $v0, $v0, 2
    addu $v0, $v0, $at
    lw $v0, 0($v0)
    nop
    jr $v0
     nop
break_service_table:
    .word svc_host_poll
    .word svc_fault_a
    .word svc_fault_b
    .word enter_stub_break
    .word svc_break
    .word svc_install_vectors
    .word svc_set_exc_mask
    .word svc_skip
    .word svc_host_hook
    .word svc_set_fpe_skip
svc_host_poll:
    lw $at, 0x33C($k0)
    nop
    bnez $at, skip_restore_v0
     nop
    addiu $at, $zero, 100
1: bnez $at, 1b
     addi $at, $at, -1
    lui $at, 0xA460
    ori $at, $at, 0x0010
2: lw $v0, 0($at)
    nop
    andi $v0, $v0, 3
    bnez $v0, 2b
     nop
    lui $at, 0xB200
    lw $at, -0x10($at)
    nop
    beqz $at, skip_restore_v0
     nop
    bgez $zero, enter_stub_active
     nop
svc_fault_a:
    addiu $at, $zero, -1
    j enter_stub
     nop
svc_fault_b:
    addiu $at, $zero, -1
    j enter_stub
     nop
svc_break:
    j enter_stub_break
     nop
svc_install_vectors:
    sd $v1, ((3) * 8)($k0)
    sd $a0, ((4) * 8)($k0)
    sd $ra, ((31) * 8)($k0)
    bal install_vectors
     nop
    ld $ra, ((31) * 8)($k0)
    ld $a0, ((4) * 8)($k0)
    bgez $zero, skip_restore_v0
     ld $v1, ((3) * 8)($k0)
install_vectors:
    lui $v1, 0x8000
    ori $v1, $v1, 0x0180
    lui $v0, %hi(vector_stub_a)
    addiu $v0, $v0, %lo(vector_stub_a)
    addi $a0, $v0, 0x14
1: lw $at, 0($v0)
    addi $v0, $v0, 4
    sw $at, 0($v1)
    addi $v1, $v1, 4
    bne $v0, $a0, 1b
     nop
    lui $v1, 0x8000
    lui $v0, %hi(vector_stub_b)
    addiu $v0, $v0, %lo(vector_stub_b)
    addi $a0, $v0, 0x14
2: lw $at, 0($v0)
    addi $v0, $v0, 4
    sw $at, 0($v1)
    addi $v1, $v1, 4
    bne $v0, $a0, 2b
     nop
    jal func_80029274
     nop
    jal func_80029290
     nop
    jr $ra
     nop
svc_set_exc_mask:
    sw $a0, 0x338($k0)
    j skip_restore_v0
     nop
svc_skip:
    mfc0 $at, $14
    nop
    addiu $at, $at, 4
    mtc0 $at, $14
    addiu $at, $zero, 9
    j enter_stub
     nop
svc_host_hook:
    lui $v0, %hi(host_hook)
    addiu $v0, $v0, %lo(host_hook)
    j skip_break
     nop
svc_set_fpe_skip:
    sw $a0, 0x340($k0)
    j skip_restore_v0
     nop
skip_restore_v0:
    ld $v0, 0x330($k0)
skip_break:
    mfc0 $at, $14
    nop
    addiu $at, $at, 4
    mtc0 $at, $14
    ld $at, 0x328($k0)
    mfc0 $k0, $30
    eret
.end func_80029398
