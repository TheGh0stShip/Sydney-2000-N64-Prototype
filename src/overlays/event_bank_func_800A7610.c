/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A7610\n.ent func_800A7610\n"
    "func_800A7610:\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,15296\n"
    "li $5,541\n"
    "li $6,7680\n"
    "jal func_800C0110\n"
    "li $7,23040\n"
    "j func_80076660\n"
    "li $20,4\n"
    ".end func_800A7610\n.set at\n.set reorder\n");
