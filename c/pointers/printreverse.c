#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    for(char **arg = argv + argc - 1; arg > argv; --arg) {
        for(char *sptr = *arg + strlen(*arg) - 1; sptr >= *arg; --sptr ) {
            printf("%c", *sptr);
        }
        printf("\n");
    }
  
    printf("\n");
   
    return EXIT_SUCCESS;
}
