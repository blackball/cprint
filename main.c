#include "cprint.h"
#include <stdio.h>

int 
main(int argc, char *argv[]) {
        const int att = cprint_getatt();
        int i = 0;
        
        for (; i < 128; ++i) {
                cprint_setatt(i);
                cprint_print("%d hello world!\n", i);
        }

        // reset to the original color theme
        cprint_setatt(att);

        getchar();
        return 0;
}
