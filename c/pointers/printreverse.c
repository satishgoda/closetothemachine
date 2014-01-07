#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char **arg = argv + argc - 1;
   
    while( arg > argv ) {
        char *sptr = *arg + strlen(*arg) - 1;

        while( sptr >= *arg ) {
            printf("%c", *sptr);
            --sptr;
        }

        printf("\n");
        --arg;
    }
   
    printf("\n");
   
    return EXIT_SUCCESS;
}
