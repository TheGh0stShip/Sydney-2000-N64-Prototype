/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007B74C\n.ent func_8007B74C\n"
    "func_8007B74C:\n"
    "lw $2,28($2)\n"
    "jalr $2\n"
    "addu $4,$17,$4\n"
    "j func_80072464\n"
    "andi $3,$18,0xff\n"
    ".end func_8007B74C\n.set at\n.set reorder\n");
