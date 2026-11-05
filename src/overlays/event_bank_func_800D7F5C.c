/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800D7F5C\n.ent func_800D7F5C\n"
    "func_800D7F5C:\n"
    "lui $2,0x1\n"
    "j func_800733FC\n"
    "ori $2,$2,0x2c00\n"
    ".end func_800D7F5C\n.set at\n.set reorder\n");
