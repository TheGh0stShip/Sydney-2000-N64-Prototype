/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075FF4\n.ent func_80075FF4\n"
    "func_80075FF4:\n"
    "move $4,$17\n"
    "li $5,3\n"
    "addu $6,$20,$6\n"
    "mtc1 $0,$f20\n"
    "lui $1,0x8007\n"
    "lwc1 $f0,3084($1)\n"
    "mfc1 $7,$f20\n"
    ".end func_80075FF4\n.set at\n.set reorder\n");
