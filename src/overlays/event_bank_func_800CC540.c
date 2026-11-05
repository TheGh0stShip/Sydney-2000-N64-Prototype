/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800CC540\n.ent func_800CC540\n"
    "func_800CC540:\n"
    "addu $2,$2,$4\n"
    "j func_8007167C\n"
    "sw $2,17380($19)\n"
    ".end func_800CC540\n.set at\n.set reorder\n");
