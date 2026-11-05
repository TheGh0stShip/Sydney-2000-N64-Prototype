/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800ED788\n.ent func_800ED788\n"
    "func_800ED788:\n"
    "mul.s $f0,$f0,$f2\n"
    "lwc1 $f2,860($18)\n"
    "sub.s $f2,$f2,$f0\n"
    "addiu $4,$18,20\n"
    "neg.s $f0,$f0\n"
    "mfc1 $5,$f0\n"
    "li $6,3\n"
    "jal func_800AD434\n"
    "swc1 $f2,860($18)\n"
    "j func_8007A018\n"
    "move $4,$18\n"
    ".end func_800ED788\n.set at\n.set reorder\n");
