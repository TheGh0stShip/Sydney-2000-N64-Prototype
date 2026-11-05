/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007704C\n.ent func_8007704C\n"
    "func_8007704C:\n"
    "sltu $2,$2,$3\n"
    ".word 0x14400054\n"
    "move $2,$3\n"
    "addiu $2,$2,-1\n"
    "sll $2,$2,0x2\n"
    "sll $3,$7,0x1\n"
    ".end func_8007704C\n.set at\n.set reorder\n");
