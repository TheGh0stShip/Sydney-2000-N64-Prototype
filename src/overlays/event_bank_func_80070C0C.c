/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80070C0C\n.ent func_80070C0C\n"
    "func_80070C0C:\n"
    "jal func_800AA804\n"
    "addiu $7,$7,2168\n"
    "lw $5,184($21)\n"
    "jal func_800AAA58\n"
    "li $4,5432\n"
    "jal func_8007F23C\n"
    "move $4,$2\n"
    "li $5,3\n"
    ".end func_80070C0C\n.set at\n.set reorder\n");
