/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071BBC\n.ent func_80071BBC\n"
    "func_80071BBC:\n"
    ".word 0x1040001D\n"
    "andi $2,$23,0xff\n"
    "sll $16,$2,0x1\n"
    "addu $16,$16,$2\n"
    ".end func_80071BBC\n.set at\n.set reorder\n");
