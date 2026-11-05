/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80070C4C\n.ent func_80070C4C\n"
    "func_80070C4C:\n"
    "lw $2,20($2)\n"
    "jalr $2\n"
    "addu $4,$3,$4\n"
    "lui $1,0x8007\n"
    "lwc1 $f0,3064($1)\n"
    "lui $1,0x8007\n"
    "lwc1 $f2,3068($1)\n"
    "j func_800716F0\n"
    "swc1 $f0,5024($21)\n"
    ".end func_80070C4C\n.set at\n.set reorder\n");
