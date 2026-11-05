/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076DC8\n.ent func_80076DC8\n"
    "func_80076DC8:\n"
    "sw $19,36($29)\n"
    "sw $17,28($29)\n"
    "sb $2,426($16)\n"
    "addiu $2,$18,1576\n"
    "sw $2,644($16)\n"
    "lui $2,0x800f\n"
    "addiu $2,$2,10872\n"
    "addiu $17,$18,1584\n"
    "sw $2,648($16)\n"
    "lbu $2,425($17)\n"
    ".end func_80076DC8\n.set at\n.set reorder\n");
