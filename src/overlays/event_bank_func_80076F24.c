/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076F24\n.ent func_80076F24\n"
    "func_80076F24:\n"
    "ori $7,$7,0xffff\n"
    "sll $3,$4,0x2\n"
    "addu $3,$3,$4\n"
    ".end func_80076F24\n.set at\n.set reorder\n");
