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
double	obstacle_startX;
double	obstacle_endX;
double	obstacle_startY;
double	obstacle_endY;

// -----------------------------------------------------------------------------

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void drawColorStripe(int32_t startX, int32_t endX, int32_t startY, int32_t endY, uint32_t color)
{
    for (int32_t i = startX; i < endX; ++i)
    {
        for (int32_t y = startY; y <= endY; ++y)
        {
            mlx_put_pixel(image, i, y, color);
        }
    }
}

void start_screen(void* param)
{
    (void)param;

    uint32_t sealing_color = ft_pixel(47, 79, 79, 0xFF);
    uint32_t floor_color = ft_pixel(112, 128, 144, 0xFF);
	uint32_t obstacle_color = ft_pixel(220, 20, 60, 0xFF);

    drawColorStripe(0, image->width, 0, image->height / 2 - 1, sealing_color);
    drawColorStripe(0, image->width, image->height / 2, image->height - 1, floor_color);
    drawColorStripe(obstacle_startX, obstacle_endX, obstacle_startY, obstacle_endY, obstacle_color);
}

bool	screen_check(void)
{
	if (obstacle_startX == 0 || obstacle_endX == WIDTH - 1 ||
		obstacle_startY == 0 || obstacle_endY == HEIGHT - 1)
		return (false);
	return (true);
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_W)) // move forward (zoom isn)
	{
		if (!screen_check())
			return ;
		obstacle_startX -= 5;
		obstacle_endX += 5;
		obstacle_startY -= 5;
		obstacle_endY += 5;

	}
	if (mlx_is_key_down(mlx, MLX_KEY_S)) // move backward (zoom out)
	{
		obstacle_startX += 5;
		obstacle_endX -= 5;
		obstacle_startY += 5;
		obstacle_endY -= 5;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_A)) // move to the left (change position in map)
	{
		obstacle_startX -= 5;
		obstacle_endX -= 5;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_D)) // move to the right (change position in map)
	{
		obstacle_startX += 5;
		obstacle_endX += 5;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT)) // change screen to the left
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT)) // change screen to the right
		image->instances[0].x += 5;
}

// -----------------------------------------------------------------------------

int32_t main(void)
{
	mlx_t* mlx;
	
	ft_printf("jaa man\n");
	
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

	obstacle_startX = image->width * 0.25;
	obstacle_endX = image->width * 0.75;
	obstacle_startY = image->height * 0.25;
	obstacle_endY = image->height * 0.5 - 1;

	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}

	mlx_loop_hook(mlx, start_screen, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
