#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define GROUP_SIZE 3
#define MAX_RUCKSACK 49

static char get_badge(char [GROUP_SIZE][MAX_RUCKSACK]);
static int get_priority(char);

int
main(int argc, char **argv)
{
    char b[GROUP_SIZE][MAX_RUCKSACK];
    int i = 0, t = 0;;

    while (gets(b[i++]) != NULL)
        if (i == GROUP_SIZE) {
            t += get_priority(get_badge(b));
            i = 0;
        }
    printf("%d\n", t);
}

static char
get_badge(char g[GROUP_SIZE][MAX_RUCKSACK])
{
    for (int i = 0; i < strlen(g[0]); ++i)
        if (strchr(g[1], g[0][i]) && strchr(g[2], g[0][i]))
            return g[0][i];
}

static int
get_priority(char c)
{
    return c - (islower(c) ? '`' : '@' - 26);
}
