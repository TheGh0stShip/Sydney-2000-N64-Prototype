/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800C013C\n.ent func_800C013C\n"
    "func_800C013C:\n"
    "addiu $29,$29,-24\n"
    "sw $31,16($29)\n"
    "sb $0,209($4)\n"
    "sb $0,208($4)\n"
    "sb $0,207($4)\n"
    "lui $4,0x800f\n"
    "jal func_8001DFF4\n"
    "addiu $4,$4,7044\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800C013C\n.set at\n.set reorder\n");
