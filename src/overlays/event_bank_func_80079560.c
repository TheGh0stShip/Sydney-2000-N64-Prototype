/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80079560\n.ent func_80079560\n"
    "func_80079560:\n"
    "lui $3,0x1\n"
    "addu $4,$4,$3\n"
    "mflo $9\n"
    "srl $2,$9,0x10\n"
    "addiu $2,$2,60\n"
    "andi $2,$2,0x7e\n"
    "sll $2,$2,0x8\n"
    "jr $31\n"
    "sw $2,2836($4)\n"
    ".end func_80079560\n.set at\n.set reorder\n");
