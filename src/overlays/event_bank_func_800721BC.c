/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800721BC\n.ent func_800721BC\n"
    "func_800721BC:\n"
    "lw $2,12($2)\n"
    "jalr $2\n"
    "addu $4,$3,$4\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,10072\n"
    "jal func_800AA658\n"
    ".end func_800721BC\n.set at\n.set reorder\n");
