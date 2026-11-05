/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80082950\n.ent func_80082950\n"
    "func_80082950:\n"
    "li $2,8\n"
    "sb $0,21621($18)\n"
    "j func_80071928\n"
    "sb $2,1551($18)\n"
    ".end func_80082950\n.set at\n.set reorder\n");
