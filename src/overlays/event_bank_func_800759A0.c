/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800759A0\n.ent func_800759A0\n"
    "func_800759A0:\n"
    ".word 0x10620013\n"
    "slti $2,$3,2\n"
    "beqz $2,L_800759C0\n"
    "li $2,2\n"
    ".word 0x10600007\n"
    "lui $16,0x800f\n"
    "j func_800726A4\n"
    "addiu $16,$16,15296\n"
    "L_800759C0:\n"
    ".word 0x10620008\n"
    "lui $16,0x800f\n"
    ".end func_800759A0\n.set at\n.set reorder\n");
