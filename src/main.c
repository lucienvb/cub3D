// #include "cubed.h"

// int main(int argc, char **argv)
// {
// 	(void)argc;
// 	(void)argv;
//     // t_cubed     cubed;
//     // t_mlx       mlx;
//     // t_screen    screen;

//     // error_handling(argc, argv);
//     // input_initialization(&cubed, &mlx, &screen, argv[1]);
//     // input_parsing(&cubed, argv[1]);
//     // printf("%i\n", )

// 	printf("Raycasting !");
//     return (0);
// }

// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/libft/libft.h"
#include "../lib/libft/ft_printf/ft_printf.h"

#define WIDTH 1024
#define HEIGHT 1024

static mlx_image_t* image;
// static mlx_image_t* obstacle;

// -----------------------------------------------------------------------------

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void drawColorStripe(int32_t startY, int32_t endY, uint32_t color)
{
    for (int32_t i = 0; i < (int32_t)image->width; ++i)
    {
        for (int32_t y = startY; y <= endY; ++y)
        {
            mlx_put_pixel(image, i, y, color);
        }
    }
}

// void ft_obstacle(void* param)
// {
//     (void)param;

//     uint32_t color = ft_pixel(220, 20, 60, 0xFF);

//     drawColorStripe(0, 128, color);
// }

void ft_randomize(void* param)
{
    (void)param;

    uint32_t upperColor = ft_pixel(47, 79, 79, 0xFF);
    uint32_t lowerColor = ft_pixel(112, 128, 144, 0xFF);

    drawColorStripe(0, image->height / 2 - 1, upperColor);
    drawColorStripe(image->height / 2, image->height - 1, lowerColor);
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

// -----------------------------------------------------------------------------

int32_t main(void)
{
	mlx_t* mlx;

	ft_printf("jaa man\n");
	
	// Gotta error check this stuff
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	// if (!(obstacle = mlx_new_image(mlx, WIDTH, HEIGHT)))
	// {
	// 	mlx_close_window(mlx);
	// 	puts(mlx_strerror(mlx_errno));
	// 	return(EXIT_FAILURE);
	// }
	// if (mlx_image_to_window(mlx, obstacle, 0, 0) == -1)
	// {
	// 	mlx_close_window(mlx);
	// 	puts(mlx_strerror(mlx_errno));
	// 	return(EXIT_FAILURE);
	// }

	

	mlx_loop_hook(mlx, ft_randomize, mlx);
	// mlx_look_hook(mlx, ft_obstacle, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
