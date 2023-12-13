#include "../include/cubed.h"

int main(int argc, char **argv)
{
    t_cubed     cubed;
    t_mlx       mlx;
    t_screen    screen;

    input_error_handling(argc, argv);
    input_initialization(&cubed, &mlx, &screen, argv[1]);
    input_parsing(&cubed, argv[1]);
    // printf("%i\n", )
    return (0);
}