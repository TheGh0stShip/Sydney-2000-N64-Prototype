/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071BCC\n.ent func_80071BCC\n"
    "func_80071BCC:\n"
    "sll $16,$16,0x3\n"
    "addu $16,$16,$2\n"
    "sll $16,$16,0x2\n"
    "addu $16,$16,$2\n"
    "sll $16,$16,0x2\n"
    "addiu $16,$16,1724\n"
    ".end func_80071BCC\n.set at\n.set reorder\n");
