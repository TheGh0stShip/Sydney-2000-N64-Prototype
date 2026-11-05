/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074EA0\n.ent func_80074EA0\n"
    "func_80074EA0:\n"
    "sltiu $2,$2,2\n"
    "bnez $2,L_80074EBC\n"
    "li $2,3\n"
    "move $4,$18\n"
    "jal func_80074118\n"
    "li $5,1\n"
    "li $2,3\n"
    "L_80074EBC:\n"
    "j func_80071B68\n"
    "sw $0,1216($18)\n"
    ".end func_80074EA0\n.set at\n.set reorder\n");
