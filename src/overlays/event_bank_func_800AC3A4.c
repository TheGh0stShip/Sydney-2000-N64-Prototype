/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800AC3A4\n.ent func_800AC3A4\n"
    "func_800AC3A4:\n"
    "li $5,0x8120\n"
    "addu $5,$20,$5\n"
    "li $6,7200\n"
    "lui $7,0x8007\n"
    "jal func_800AA804\n"
    "addiu $7,$7,4848\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,9952\n"
    "li $6,21\n"
    "li $16,0x8000\n"
    "addu $16,$20,$16\n"
    "li $2,0x8124\n"
    ".end func_800AC3A4\n.set at\n.set reorder\n");
