/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800723A8\n.ent func_800723A8\n"
    "func_800723A8:\n"
    "sw $18,72($29)\n"
    "sw $17,68($29)\n"
    "sw $16,64($29)\n"
    "sdc1 $f22,112($29)\n"
    "sdc1 $f20,104($29)\n"
    "lbu $2,4456($19)\n"
    ".word 0x10400004\n"
    "lui $3,0x17\n"
    "ori $3,$3,0x7000\n"
    ".end func_800723A8\n.set at\n.set reorder\n");
