/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800ADC38\n.ent func_800ADC38\n"
    "func_800ADC38:\n"
    "lw $3,11704($18)\n"
    "andi $5,$4,0xff\n"
    "sb $6,424($3)\n"
    "lw $2,11704($18)\n"
    "sll $6,$6,0x18\n"
    "sb $4,425($2)\n"
    "lw $4,11704($18)\n"
    ".end func_800ADC38\n.set at\n.set reorder\n");
