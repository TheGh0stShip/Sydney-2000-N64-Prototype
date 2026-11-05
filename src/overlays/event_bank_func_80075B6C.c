/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075B6C\n.ent func_80075B6C\n"
    "func_80075B6C:\n"
    "jalr $2\n"
    "addu $4,$16,$4\n"
    "lbu $3,1556($20)\n"
    ".end func_80075B6C\n.set at\n.set reorder\n");
