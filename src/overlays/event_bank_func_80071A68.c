/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071A68\n.ent func_80071A68\n"
    "func_80071A68:\n"
    "sll $2,$5,0x2\n"
    "addu $2,$2,$5\n"
    "sll $3,$2,0x4\n"
    "subu $3,$3,$2\n"
    "sll $3,$3,0x5\n"
    ".end func_80071A68\n.set at\n.set reorder\n");
