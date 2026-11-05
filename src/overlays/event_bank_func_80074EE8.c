/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074EE8\n.ent func_80074EE8\n"
    "func_80074EE8:\n"
    "lui $4,0x1\n"
    "jal func_800833B8\n"
    "addiu $4,$18,28608\n"
    "lui $4,0x1\n"
    "ori $4,$4,0x3c8\n"
    "addu $4,$18,$4\n"
    "li $2,0x9600\n"
    "jal func_800D29E0\n"
    ".end func_80074EE8\n.set at\n.set reorder\n");
