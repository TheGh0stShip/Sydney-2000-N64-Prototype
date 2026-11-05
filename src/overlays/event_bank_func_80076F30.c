/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076F30\n.ent func_80076F30\n"
    "func_80076F30:\n"
    "sll $2,$3,0x4\n"
    "subu $2,$2,$3\n"
    "sll $2,$2,0x5\n"
    ".end func_80076F30\n.set at\n.set reorder\n");
