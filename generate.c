#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    FILE* f = fopen ("src", "w");
    for (int i=0; i<50; i++)
    {
        fprintf (f, " %c%d/%c%d\n", rand()%2?' ':'-', rand()%101, rand()%2?' ':'-', rand()%101);
    }
    fclose (f);
}
