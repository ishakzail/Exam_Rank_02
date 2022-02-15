#include <unistd.h>

int check(char *s, char c, int pos)
{
    int i;

    i = -1;
    while(++i < pos)
        if (s[i] == c)
            return (0);
    return (1);
}

int main(int ac, char **av)
{
    int i;
    int j;

	if (ac == 3)
	{
        i = -1;
        while (av[1][++i])
            if (check(av[1], av[1][i], i))
                write(1, &av[1][i], 1);
        j = -1;
        while (av[2][++j])
            if (check(av[1], av[2][j], i) && check(av[2], av[2][j], j))
                write(1, &av[2][j], 1);
	}
	write(1, "\n", 1);
}