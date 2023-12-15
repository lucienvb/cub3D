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
#include <math.h>
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
double	diff_x;
double	diff_y;
const double pi = 3.14159265359;
double	angle;

// -----------------------------------------------------------------------------

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}


// void draw_color_stripe(int32_t startX, int32_t endX, int32_t startY, int32_t endY, uint32_t color)
// {
//     // Calculate rotation center
// 	double rotationAngle = pi / 4.0;

//     double centerX = (startX + endX) / 2.0;
//     double centerY = (startY + endY) / 2.0;

//     for (int32_t i = startX; i < endX; ++i)
//     {
//         for (int32_t y = startY; y <= endY; ++y)
//         {
//             // Apply rotation transformation
//             double rotatedX = centerX + (i - centerX) * cos(rotationAngle) - (y - centerY) * sin(rotationAngle);
//             double rotatedY = centerY + (i - centerX) * sin(rotationAngle) + (y - centerY) * cos(rotationAngle);

//             // Round the rotated coordinates to the nearest integer
//             int32_t pixelX = (int32_t)round(rotatedX);
//             int32_t pixelY = (int32_t)round(rotatedY);

//             mlx_put_pixel(image, pixelX, pixelY, color);
//         }
//     }
// }

void draw_color_stripe(int32_t startX, int32_t endX, int32_t startY, int32_t endY, uint32_t color)
{
	// double	current_diff_x = endX - startX;
	// double	e = current_diff_x = 2;

    for (int32_t i = startX; i < endX; ++i)
    {
        for (int32_t y = startY; y <= endY; ++y)
        {
			// printf("newX: %f\n", i + (e - cos(angle) * e));
			// printf("newY: %f\n", y - (sin(angle) * e));
			// printf("i: %d\n", i);
			// printf("y: %d\n", y);
            mlx_put_pixel(image, i, y, color);
            // mlx_put_pixel(image, round(i + (e - cos(angle) * e)), round(y - (sin(angle) * e)), color);
        }
    }
}

void start_screen(void* param)
{
    (void)param;

    uint32_t sealing_color = ft_pixel(47, 79, 79, 0xFF);
    uint32_t floor_color = ft_pixel(112, 128, 144, 0xFF);
	uint32_t obstacle_color = ft_pixel(220, 20, 60, 0xFF);

    draw_color_stripe(0, image->width, 0, image->height / 2 - 1, sealing_color);
    draw_color_stripe(0, image->width, image->height / 2, image->height - 1, floor_color);
    draw_color_stripe(obstacle_startX, obstacle_endX, obstacle_startY, obstacle_endY, obstacle_color);
}

bool	max_obstacle_check(void)
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
		if (!max_obstacle_check())
			return ;
		obstacle_startX -= 5;
		obstacle_endX += 5;
		obstacle_startY -= 5;
		if (obstacle_endY - obstacle_startY >= diff_y)
			obstacle_endY += 5;

	}
	if (mlx_is_key_down(mlx, MLX_KEY_S)) // move backward (zoom out)
	{
		obstacle_startX += 5;
		obstacle_endX -= 5;
		if (obstacle_endY > image->height / 2)
			obstacle_endY -= 5;
		obstacle_startY += 5;
	}

	if (mlx_is_key_down(mlx, MLX_KEY_A)) // move to the left (change position in map)
	{
		obstacle_startX += 5;
		obstacle_endX += 5;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_D)) // move to the right (change position in map)
	{
		obstacle_startX -= 5;
		obstacle_endX -= 5;
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
	
	double a = sin(1) * 5;
	double b = cos(1) * 5;
	
	printf("a: %f\n", a);
	printf("b: %f\n", b);

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
	angle = 2;
	obstacle_startX = image->width * 0.25;
	obstacle_endX = image->width * 0.75;
	diff_x = obstacle_endX - obstacle_startX;
	obstacle_startY = image->height * 0.25;
	obstacle_endY = image->height * 0.5 - 1;
	diff_y = obstacle_endY - obstacle_startY;

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
