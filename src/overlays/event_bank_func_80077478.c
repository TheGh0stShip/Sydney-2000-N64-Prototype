/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80077478\n.ent func_80077478\n"
    "func_80077478:\n"
    "addiu $29,$29,-24\n"
    "andi $5,$5,0xff\n"
    "sll $2,$5,0x1\n"
    "addu $2,$2,$5\n"
    ".end func_80077478\n.set at\n.set reorder\n");
