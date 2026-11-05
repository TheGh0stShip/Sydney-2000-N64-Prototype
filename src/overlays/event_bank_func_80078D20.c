/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80078D20\n.ent func_80078D20\n"
    "func_80078D20:\n"
    "lbu $2,2820($16)\n"
    "sw $0,2844($16)\n"
    "addiu $2,$2,1\n"
    "j func_8007596C\n"
    "sb $2,2820($16)\n"
    ".end func_80078D20\n.set at\n.set reorder\n");
