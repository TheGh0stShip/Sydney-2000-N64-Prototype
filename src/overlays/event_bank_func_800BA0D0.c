/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800BA0D0\n.ent func_800BA0D0\n"
    "func_800BA0D0:\n"
    "addiu $29,$29,-112\n"
    "sdc1 $f28,104($29)\n"
    "lui $1,0x8007\n"
    "lwc1 $f28,3956($1)\n"
    "sdc1 $f26,96($29)\n"
    "lui $1,0x8007\n"
    "lwc1 $f26,3960($1)\n"
    ".end func_800BA0D0\n.set at\n.set reorder\n");
