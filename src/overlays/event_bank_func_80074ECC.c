/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074ECC\n.ent func_80074ECC\n"
    "func_80074ECC:\n"
    "jal func_800833B8\n"
    "addiu $4,$18,1584\n"
    "lui $2,0x1\n"
    "addu $16,$18,$2\n"
    "lbu $2,2841($16)\n"
    "sltiu $2,$2,2\n"
    ".word 0x14400004\n"
    ".end func_80074ECC\n.set at\n.set reorder\n");
