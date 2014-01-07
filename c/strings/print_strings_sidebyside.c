/*
 * H B H F B
 * e e e e o
 * l a l l i
 * l u p i s
 * o t   c t
 *   i   i e
 *   f   t r
 *   u   y o
 *   l     u
 *         s
 *   W
 *   o
 *   r
 *   l
 *   d
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char notdone;
    char* current;
    char c;
} Line;

char line_allnotdone(Line* lines)
{
    char notdone = 0;
    Line *line = lines;

    while(line->current != NULL) {
        notdone = notdone || line->notdone;
        line++;
    }

    return notdone;
}

void line_status(Line* line)
{
    if (line->notdone == 0) return;

    if (*line->current != '\0') {
        line->c = *line->current++;
    } else {
        line->c = ' ';
        line->notdone = 0;
    }
}

void line_advanceall(Line* lines)
{
    Line *line = lines;
    while(line->current != NULL) {
        line_status(line);
        line++;
    }
}

int main(int argc, char* argv[])
{
    char *strings[] = {
        "Hello",
        "Beautiful World",
        "Help",
        "Felicity",
        "Boisterous",
        ""
    };

    long unsigned int count = sizeof(strings)/sizeof(char*);
    printf("%lu \n", count);

    Line *lines = calloc(count, sizeof(Line));

    char **str = strings;
    Line *line = lines;

    while (!(strcmp(*str, "") == 0)) {
        line->notdone = 1;
        line->current = *str;
        line->c = ' ';
        str++;
        line++;
    }

    line->notdone = 1;
    line->current = NULL;
    line->c = ' ';

    while (line_allnotdone(lines))
    {
        line_advanceall(lines);

        Line *print = lines;

        while (print->current != NULL) {
            printf("%c ", print->c);
            print++;
        }
        printf("\n");
    }

    free(lines);
    lines = NULL;
}
