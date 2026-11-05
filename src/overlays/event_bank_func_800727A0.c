/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800727A0\n.ent func_800727A0\n"
    "func_800727A0:\n"
    "sll $4,$4,0x2\n"
    "addu $4,$4,$2\n"
    "sll $4,$4,0x2\n"
    "addiu $4,$4,1724\n"
    "addu $4,$19,$4\n"
    "addiu $5,$29,24\n"
    "addiu $6,$29,56\n"
    "jal func_800B9964\n"
    "addiu $7,$29,40\n"
    "j func_80072AD0\n"
    "addiu $18,$18,1\n"
    ".end func_800727A0\n.set at\n.set reorder\n");
