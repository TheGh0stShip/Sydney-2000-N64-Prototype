/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076D4C\n.ent func_80076D4C\n"
    "func_80076D4C:\n"
    "jal func_8001D5D8\n"
    "sra $6,$8,0xf\n"
    "move $4,$18\n"
    "li $5,56\n"
    "li $6,17\n"
    "move $7,$0\n"
    "lui $2,0x1\n"
    "addu $2,$18,$2\n"
    ".end func_80076D4C\n.set at\n.set reorder\n");
