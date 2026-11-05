/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075F38\n.ent func_80075F38\n"
    "func_80075F38:\n"
    "addiu $5,$16,356\n"
    "li $6,15840\n"
    "lui $7,0x8007\n"
    "jal func_800AA804\n"
    "addiu $7,$7,2008\n"
    ".end func_80075F38\n.set at\n.set reorder\n");
