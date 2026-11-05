/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075E10\n.ent func_80075E10\n"
    "func_80075E10:\n"
    "addiu $5,$16,8\n"
    "sh $0,16($16)\n"
    "sh $0,18($16)\n"
    ".end func_80075E10\n.set at\n.set reorder\n");
