/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071580\n.ent func_80071580\n"
    "func_80071580:\n"
    "subu $16,$16,$20\n"
    "sll $16,$16,0x2\n"
    "addu $2,$16,$21\n"
    "addiu $2,$2,4792\n"
    ".end func_80071580\n.set at\n.set reorder\n");
