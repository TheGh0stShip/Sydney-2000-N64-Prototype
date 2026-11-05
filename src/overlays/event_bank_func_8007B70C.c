/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007B70C\n.ent func_8007B70C\n"
    "func_8007B70C:\n"
    "addu $16,$16,$20\n"
    "lw $2,180($16)\n"
    "addiu $18,$18,1\n"
    "sb $0,256($16)\n"
    "lh $4,72($2)\n"
    "lw $2,76($2)\n"
    "jalr $2\n"
    ".end func_8007B70C\n.set at\n.set reorder\n");
