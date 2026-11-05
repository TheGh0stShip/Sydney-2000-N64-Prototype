/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800AF06C\n.ent func_800AF06C\n"
    "func_800AF06C:\n"
    "addiu $29,$29,-24\n"
    "li $2,0x8000\n"
    "addu $4,$4,$2\n"
    "sw $31,16($29)\n"
    "lbu $2,286($4)\n"
    "sltiu $2,$2,2\n"
    ".word 0x1040000A\n"
    ".end func_800AF06C\n.set at\n.set reorder\n");
