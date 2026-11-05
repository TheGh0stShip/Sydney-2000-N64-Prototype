/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800AEC0C\n.ent func_800AEC0C\n"
    "func_800AEC0C:\n"
    "addiu $29,$29,-24\n"
    "lui $4,0x8007\n"
    "addiu $4,$4,31872\n"
    "sw $31,16($29)\n"
    "jal func_800AF064\n"
    "li $5,2\n"
    "lui $4,0x8007\n"
    "addiu $4,$4,31280\n"
    "jal func_800AF064\n"
    ".end func_800AEC0C\n.set at\n.set reorder\n");
