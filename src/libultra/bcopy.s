.text
.globl bcopy ; .align 2 ; ; .ent bcopy,0 ; bcopy: ; .frame $29,0,$31
    move $7, $5
    beqz $6, ret
    beq $4, $5, ret
    blt $5, $4, goforwards
    add $2, $4, $6
    bge $5, $2, goforwards
    b gobackwards
goforwards:
    blt $6, 16, forwards_bytecopy
    andi $2, $4, 0x3
    andi $3, $5, 0x3
    beq $2, $3, forwalignable
forwards_bytecopy:
    beqz $6, ret
    addu $3, $4, $6
99:
    lb $2, 0($4)
    addiu $4, $4, 1
    sb $2, 0($5)
    addiu $5, $5, 1
    bne $4, $3, 99b
ret:
    move $2, $7
    jr $31
forwalignable:
    beqz $2, forwards
    beq $2, 1, forw_copy3
    beq $2, 2, forw_copy2
    lb $2, 0($4)
    addiu $4, $4, 1
    sb $2, 0($5)
    addiu $5, $5, 1
    addiu $6, $6, -1
    b forwards
forw_copy2:
    lh $2, 0($4)
    addiu $4, $4, 2
    sh $2, 0($5)
    addiu $5, $5, 2
    addiu $6, $6, -2
    b forwards
forw_copy3:
    lb $2, 0($4)
    lh $3, 1($4)
    addiu $4, $4, 3
    sb $2, 0($5)
    sh $3, 1($5)
    addiu $5, $5, 3
    addiu $6, $6, -3
forwards:
forwards_32:
    blt $6, 32, forwards_16
    lw $2, 0($4)
    lw $3, 4($4)
    lw $8, 8($4)
    lw $9, 12($4)
    lw $10, 16($4)
    lw $11, 20($4)
    lw $12, 24($4)
    lw $13, 28($4)
    addiu $4, $4, 32
    sw $2, 0($5)
    sw $3, 4($5)
    sw $8, 8($5)
    sw $9, 12($5)
    sw $10, 16($5)
    sw $11, 20($5)
    sw $12, 24($5)
    sw $13, 28($5)
    addiu $5, $5, 32
    addiu $6, $6, -32
    b forwards_32
forwards_16:
    blt $6, 16, forwards_4
    lw $2, 0($4)
    lw $3, 4($4)
    lw $8, 8($4)
    lw $9, 12($4)
    addiu $4, $4, 16
    sw $2, 0($5)
    sw $3, 4($5)
    sw $8, 8($5)
    sw $9, 12($5)
    addiu $5, $5, 16
    addiu $6, $6, -16
    b forwards_16
forwards_4:
    blt $6, 4, forwards_bytecopy
    lw $2, 0($4)
    addiu $4, $4, 4
    sw $2, 0($5)
    addiu $5, $5, 4
    addiu $6, $6, -4
    b forwards_4
gobackwards:
    add $4, $4, $6
    add $5, $5, $6
    blt $6, 16, backwards_bytecopy
    andi $2, $4, 0x3
    andi $3, $5, 0x3
    beq $2, $3, backalignable
backwards_bytecopy:
    beqz $6, ret
    addiu $4, $4, -1
    addiu $5, $5, -1
    subu $3, $4, $6
99:
    lb $2, 0($4)
    addiu $4, $4, -1
    sb $2, 0($5)
    addiu $5, $5, -1
    bne $4, $3, 99b
    move $2, $7
    jr $31
backalignable:
    beqz $2, backwards
    beq $2, 3, back_copy3
    beq $2, 2, back_copy2
    lb $2, -1($4)
    addiu $4, $4, -1
    sb $2, -1($5)
    addiu $5, $5, -1
    addiu $6, $6, -1
    b backwards
back_copy2:
    lh $2, -2($4)
    addiu $4, $4, -2
    sh $2, -2($5)
    addiu $5, $5, -2
    addiu $6, $6, -2
    b backwards
back_copy3:
    lb $2, -1($4)
    lh $3, -3($4)
    addiu $4, $4, -3
    sb $2, -1($5)
    sh $3, -3($5)
    addiu $5, $5, -3
    addiu $6, $6, -3
backwards:
backwards_32:
    blt $6, 32, backwards_16
    lw $2, -4($4)
    lw $3, -8($4)
    lw $8, -12($4)
    lw $9, -16($4)
    lw $10, -20($4)
    lw $11, -24($4)
    lw $12, -28($4)
    lw $13, -32($4)
    addiu $4, $4, -32
    sw $2, -4($5)
    sw $3, -8($5)
    sw $8, -12($5)
    sw $9, -16($5)
    sw $10, -20($5)
    sw $11, -24($5)
    sw $12, -28($5)
    sw $13, -32($5)
    addiu $5, $5, -32
    addiu $6, $6, -32
    b backwards_32
backwards_16:
    blt $6, 16, backwards_4
    lw $2, -4($4)
    lw $3, -8($4)
    lw $8, -12($4)
    lw $9, -16($4)
    addiu $4, $4, -16
    sw $2, -4($5)
    sw $3, -8($5)
    sw $8, -12($5)
    sw $9, -16($5)
    addiu $5, $5, -16
    addiu $6, $6, -16
    b backwards_16
backwards_4:
    blt $6, 4, backwards_bytecopy
    lw $2, -4($4)
    addiu $4, $4, -4
    sw $2, -4($5)
    addiu $5, $5, -4
    addiu $6, $6, -4
    b backwards_4
.end bcopy
