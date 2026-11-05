/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007289C\n.ent func_8007289C\n"
    "func_8007289C:\n"
    "addiu $20,$29,40\n"
    "li $23,1\n"
    "lui $22,0x800f\n"
    "li $30,5\n"
    "andi $16,$18,0xff\n"
    "sltiu $2,$16,3\n"
    ".word 0x104001E0\n"
    "sll $2,$16,0x1\n"
    ".end func_8007289C\n.set at\n.set reorder\n");
