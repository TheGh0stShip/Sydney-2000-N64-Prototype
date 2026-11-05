/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800766AC\n.ent func_800766AC\n"
    "func_800766AC:\n"
    "lui $4,0x800f\n"
    "jal func_800BC180\n"
    "addiu $4,$4,10968\n"
    "jal func_800735B0\n"
    "move $4,$19\n"
    "jal func_8000C944\n"
    "lui $18,0x800f\n"
    "lui $2,0x1\n"
    "ori $2,$2,0xca8\n"
    "addiu $18,$18,9952\n"
    "move $4,$18\n"
    "lui $17,0x800f\n"
    ".end func_800766AC\n.set at\n.set reorder\n");
