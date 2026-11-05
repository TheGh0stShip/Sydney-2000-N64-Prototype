/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071D2C\n.ent func_80071D2C\n"
    "func_80071D2C:\n"
    "sw $2,1284($21)\n"
    "sw $3,1496($21)\n"
    "sw $4,1708($21)\n"
    "andi $2,$23,0xff\n"
    "sll $16,$2,0x1\n"
    "addu $16,$16,$2\n"
    "sll $16,$16,0x2\n"
    "addu $16,$16,$2\n"
    "sll $16,$16,0x2\n"
    ".end func_80071D2C\n.set at\n.set reorder\n");
