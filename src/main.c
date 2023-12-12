#include "../include/cubed.h"

int main(int argc, char **argv)
{
    t_cubed     cubed;
    t_mlx       mlx;
    t_screen    screen;

    error_handling(argc, argv);
    initialization(&cubed, &mlx, &screen, argv[1]);
    // printf("%i\n", )
    // initialization();
    return (0);
}