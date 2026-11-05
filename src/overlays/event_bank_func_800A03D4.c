/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A03D4\n.ent func_800A03D4\n"
    "func_800A03D4:\n"
    "li $2,-1\n"
    ".word 0x50620038\n"
    "li $16,251\n"
    "lb $3,8($16)\n"
    "bnez $3,L_800A03F4\n"
    "li $2,1\n"
    "j func_800746F8\n"
    "li $16,258\n"
    "L_800A03F4:\n"
    ".word 0x14620003\n"
    ".end func_800A03D4\n.set at\n.set reorder\n");
