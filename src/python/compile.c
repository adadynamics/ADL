#include <unistd.h>

int main()
{
    char *const argv[] = {"make",NULL};

    execvp(argv[0],argv);
}