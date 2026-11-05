/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007AAB0\n.ent func_8007AAB0\n"
    "func_8007AAB0:\n"
    "lw $2,28($2)\n"
    "jalr $2\n"
    "addu $4,$17,$4\n"
    "j func_800717C8\n"
    "andi $3,$18,0xff\n"
    ".end func_8007AAB0\n.set at\n.set reorder\n");
