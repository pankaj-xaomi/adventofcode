#include <stdio.h>
#include <stdlib.h>

int g_basement_entered = 0;
int whichfloor(const char *input)
{
    char c;
    int floor = 0;
    int index = 0;
    int basement_entered = 0;

    while (c = *(input + index))
    {
        index++;
        if (c == '(')
        {
            floor++;
        }
        else if (c == ')')
        {
            floor--;
        }
        else
        {
            printf ("Invalid input. '%c'. Aborting.\n", c);
            exit(1);
        }
        if ((floor == -1) && (g_basement_entered == 0))
        {
            g_basement_entered = index;
        }
    }

    return floor;
}

int main(int argc, char **argv)
{
    int floor_number = 0;

    if (argc != 2)
    {
        printf ("Usage: %s <input-string>\n", argv[0]);
        return 1;
    }

    floor_number = whichfloor(argv[1]);

    printf ("Floor: %d\n", floor_number);
    printf ("Basement entered: %d\n", g_basement_entered);
}
