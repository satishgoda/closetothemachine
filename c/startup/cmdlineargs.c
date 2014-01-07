#include <stdio.h>

int main(int argc, char *argv[])
{
   printf("argc=%d program name=[\"%s\"]\n", argc, argv[0]);

    printf("%d \n", argc == ((argv + argc) - argv) );
    
    if (argc < 2) {
        printf("No command-line arguments specified\n");
    } 
    else {
        printf("Command-line arguments are \n");
        
        char **args = argv + 1;
        
        while(args < (argv+argc)) {
            printf("    %lu %s\n", (args - argv), *args);
            args++;
        }
    }
    
    return 0;
}
