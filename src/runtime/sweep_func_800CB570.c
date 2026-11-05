/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800CB570\n.ent func_800CB570\n"
    "func_800CB570:\n"
    "lui $1,0x8009\n"
    "lwc1 $f0,-26956($1)\n"
    "mtc1 $5,$f4\n"
    "sub.s $f0,$f0,$f4\n"
    "lui $1,0x8009\n"
    "lwc1 $f2,-26952($1)\n"
    "mul.s $f2,$f0,$f2\n"
    "mtc1 $0,$f0\n"
    ".end func_800CB570\n.set at\n.set reorder\n");
