/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076824\n.ent func_80076824\n"
    "func_80076824:\n"
    "sw $17,20($29)\n"
    "sw $16,16($29)\n"
    "sw $0,10024($2)\n"
    "jal func_800BC274\n"
    "lui $17,0x800f\n"
    "addiu $16,$17,9952\n"
    ".end func_80076824\n.set at\n.set reorder\n");
