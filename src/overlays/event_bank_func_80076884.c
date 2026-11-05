/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076884\n.ent func_80076884\n"
    "func_80076884:\n"
    "addu $2,$2,$3\n"
    "sll $2,$2,0x2\n"
    "subu $2,$2,$3\n"
    "sll $2,$2,0x3\n"
    "addu $2,$2,$3\n"
    "sll $17,$2,0x4\n"
    "addu $2,$17,$19\n"
    "lw $2,2320($2)\n"
    ".word 0x10400010\n"
    "addiu $16,$17,1584\n"
    ".end func_80076884\n.set at\n.set reorder\n");
