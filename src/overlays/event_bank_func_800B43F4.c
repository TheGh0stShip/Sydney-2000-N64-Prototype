/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800B43F4\n.ent func_800B43F4\n"
    "func_800B43F4:\n"
    "swc1 $f12,80($29)\n"
    "swc1 $f16,92($29)\n"
    "mul.s $f8,$f8,$f2\n"
    "swc1 $f22,88($29)\n"
    "swc1 $f0,112($29)\n"
    "swc1 $f30,56($29)\n"
    "mov.s $f30,$f0\n"
    "sub.s $f0,$f30,$f26\n"
    "swc1 $f4,60($29)\n"
    ".end func_800B43F4\n.set at\n.set reorder\n");
