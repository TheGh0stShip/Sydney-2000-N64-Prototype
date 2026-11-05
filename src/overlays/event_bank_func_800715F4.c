/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800715F4\n.ent func_800715F4\n"
    "func_800715F4:\n"
    "lui $1,0x8007\n"
    "lwc1 $f0,3172($1)\n"
    "addu $16,$21,$16\n"
    ".end func_800715F4\n.set at\n.set reorder\n");
