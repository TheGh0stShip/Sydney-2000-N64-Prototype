/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800D0C20\n.ent func_800D0C20\n"
    "func_800D0C20:\n"
    "sw $17,17124($19)\n"
    "sw $2,3852($19)\n"
    "swc1 $f0,18292($19)\n"
    "sw $0,16($29)\n"
    "jal func_800B9FA4\n"
    "sw $16,20($29)\n"
    "sb $16,18310($19)\n"
    "j func_800710F4\n"
    "sb $17,18312($19)\n"
    ".end func_800D0C20\n.set at\n.set reorder\n");
