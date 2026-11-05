/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80070B58\n.ent func_80070B58\n"
    "func_80070B58:\n"
    "add.s $f0,$f0,$f2\n"
    "lui $1,0x8007\n"
    "lwc1 $f2,3000($1)\n"
    "addiu $2,$2,15280\n"
    "swc1 $f0,3348($21)\n"
    "lwc1 $f0,4($2)\n"
    ".end func_80070B58\n.set at\n.set reorder\n");
