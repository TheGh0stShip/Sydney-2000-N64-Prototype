/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800718B4\n.ent func_800718B4\n"
    "func_800718B4:\n"
    "addiu $8,$8,15400\n"
    "addu $3,$3,$8\n"
    "lwc1 $f2,2096($16)\n"
    "lwc1 $f0,0($3)\n"
    "add.s $f2,$f2,$f0\n"
    "swc1 $f2,2096($16)\n"
    ".end func_800718B4\n.set at\n.set reorder\n");
