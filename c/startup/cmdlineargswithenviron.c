#include <stdio.h>  // printf
#include <stdlib.h> // EXIT_SUCCESS
#include <stddef.h> // ptrdiff_t


int argcorig = 0;
char **argvorig = NULL;
char **envorig = NULL;
char **arg = NULL;
char **env = NULL;


typedef void (*exitcallback) ();


void numargs()
{
    ptrdiff_t numargs = arg - argvorig;

    if( ((arg - argvorig) == argcorig) || 0 ) {
        printf("# of command-line arguments %lu\n", numargs);
    }
}

void numenvirons()
{
    printf("# of environment variables %lu \n", env - envorig);
}


int main(int argc, char *argv[], char *environ[])
{
    exitcallback numargsatexit = &numargs;
    exitcallback numenvironsatexit = &numenvirons;
   
    atexit(numenvironsatexit);
    atexit(numargsatexit);
   
    argcorig = argc;
   
    arg = argv;
    argvorig = argv;
   
    while (*arg != NULL) { ++arg; }
   
    env = environ;
    envorig = environ;
   
    while (*env != NULL) { ++env; }
   
    return EXIT_SUCCESS;
}
