#ifndef LEAF_NAME
#define LEAF_NAME sendEventMessage
#endif
#ifndef POP_THREAD_NAME
#define POP_THREAD_NAME popThread
#endif
#ifndef ENQUEUE_THREAD_NAME
#define ENQUEUE_THREAD_NAME enqueueThread
#endif

#define STRINGIFY_INNER(value) #value
#define STRINGIFY(value) STRINGIFY_INNER(value)

asm(
    ".text\n"
    ".align 2\n"
    ".globl " STRINGIFY(LEAF_NAME) "\n"
    STRINGIFY(LEAF_NAME) ":\n"
    ".set noreorder\n"
    "move $18,$31\n"
    "lui $10,0x8007\n"
    "addiu $10,$10,-3552\n"
    "addu $10,$10,$4\n"
    "lw $9,0($10)\n"
    "beqz $9,2f\n"
    "nop\n"
    "lw $11,8($9)\n"
    "lw $12,16($9)\n"
    "slt $1,$11,$12\n"
    "beqz $1,2f\n"
    "nop\n"
    "lw $13,12($9)\n"
    "addu $13,$13,$11\n"
    ".word 0x01ac001a\n"
    "bnez $12,1f\n"
    "nop\n"
    ".word 0x0007000d\n"
    "1:\n"
    "li $1,-1\n"
    "bne $12,$1,3f\n"
    "lui $1,0x8000\n"
    "bne $13,$1,3f\n"
    "nop\n"
    ".word 0x0006000d\n"
    "3:\n"
    "mfhi $13\n"
    "lw $12,20($9)\n"
    "li $1,4\n"
    "mult $13,$1\n"
    "mflo $13\n"
    "addu $12,$12,$13\n"
    "lw $13,4($10)\n"
    "sw $13,0($12)\n"
    "addiu $10,$11,1\n"
    "sw $10,8($9)\n"
    "lw $10,0($9)\n"
    "lw $11,0($10)\n"
    "beqz $11,2f\n"
    "nop\n"
    "jal " STRINGIFY(POP_THREAD_NAME) "\n"
    "move $4,$9\n"
    "move $10,$2\n"
    "move $5,$10\n"
    "lui $4,0x8006\n"
    "jal " STRINGIFY(ENQUEUE_THREAD_NAME) "\n"
    "addiu $4,$4,28840\n"
    "2:\n"
    "jr $18\n"
    "nop\n"
    ".set reorder\n");
