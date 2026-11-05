/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800EF964\n.ent func_800EF964\n"
    "func_800EF964:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "lw $2,180($4)\n"
    "lh $3,72($2)\n"
    "lw $2,76($2)\n"
    "jalr $2\n"
    "addu $4,$4,$3\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800EF964\n.set at\n.set reorder\n");
