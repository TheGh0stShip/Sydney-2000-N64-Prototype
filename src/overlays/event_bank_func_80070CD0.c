/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80070CD0\n.ent func_80070CD0\n"
    "func_80070CD0:\n"
    "lh $4,16($2)\n"
    "lw $2,20($2)\n"
    "jalr $2\n"
    "addu $4,$3,$4\n"
    "lui $1,0x8007\n"
    "lwc1 $f0,3072($1)\n"
    "lui $1,0x8007\n"
    ".end func_80070CD0\n.set at\n.set reorder\n");
