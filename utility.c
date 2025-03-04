#include <stdio.h>
#include <string.h>
#include "utility.h"



int remove_newline(char *input) {
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    return 0;
}

void clear_buffer(){
    int c;
    while((c = getchar()) != '\n' );
}

