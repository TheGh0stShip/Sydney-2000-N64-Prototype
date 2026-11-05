/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800D2760\n.ent func_800D2760\n"
    "func_800D2760:\n"
    "move $6,$0\n"
    "lw $2,3856($18)\n"
    "move $7,$6\n"
    "sw $0,18216($18)\n"
    "sw $2,3852($18)\n"
    "sw $0,16($29)\n"
    "jal func_80082A84\n"
    "sw $0,20($29)\n"
    "li $2,4\n"
    "sw $2,17124($18)\n"
    "li $2,1\n"
    "j func_80071114\n"
    "sw $2,10836($18)\n"
    ".end func_800D2760\n.set at\n.set reorder\n");
