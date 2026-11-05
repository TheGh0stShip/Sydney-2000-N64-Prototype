/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A3028\n.ent func_800A3028\n"
    "func_800A3028:\n"
    "beqz $5,L_800A304C\n"
    "move $3,$0\n"
    "L_800A3030:\n"
    "lw $2,12($4)\n"
    "beql $2,$5,L_800A303C\n"
    "sw $0,12($4)\n"
    "L_800A303C:\n"
    "addiu $3,$3,1\n"
    "slti $2,$3,4\n"
    "bnez $2,L_800A3030\n"
    "addiu $4,$4,4\n"
    "L_800A304C:\n"
    "jr $31\n"
    "nop\n"
    ".end func_800A3028\n.set at\n.set reorder\n");
