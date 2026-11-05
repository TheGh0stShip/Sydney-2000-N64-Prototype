/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800793EC\n.ent func_800793EC\n"
    "func_800793EC:\n"
    "addiu $29,$29,-32\n"
    "lui $2,0x8010\n"
    "lui $6,0x1\n"
    "ori $6,$6,0x3c8\n"
    "lw $2,-15760($2)\n"
    "lui $1,0x8007\n"
    "lwc1 $f2,3476($1)\n"
    ".end func_800793EC\n.set at\n.set reorder\n");
