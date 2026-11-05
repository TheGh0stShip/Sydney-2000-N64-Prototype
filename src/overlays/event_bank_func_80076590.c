/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076590\n.ent func_80076590\n"
    "func_80076590:\n"
    "mflo $3\n"
    "sll $2,$3,0x1\n"
    "addu $2,$2,$3\n"
    "sll $2,$2,0x2\n"
    "lw $3,-15760($16)\n"
    ".end func_80076590\n.set at\n.set reorder\n");
