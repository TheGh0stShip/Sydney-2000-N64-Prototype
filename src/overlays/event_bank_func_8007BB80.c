/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007BB80\n.ent func_8007BB80\n"
    "func_8007BB80:\n"
    "sb $17,3228($16)\n"
    "addiu $4,$19,11800\n"
    "lui $5,0x8008\n"
    "addiu $5,$5,-30900\n"
    "li $6,1\n"
    ".end func_8007BB80\n.set at\n.set reorder\n");
