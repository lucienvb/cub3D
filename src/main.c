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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/libft/libft.h"
#include "../lib/libft/ft_printf/ft_printf.h"
#include "../include/cubed.h"

#define WIDTH 512
#define HEIGHT 512
// #define mapWidth 24
// #define mapHeight 24

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

#define mapWidth 5
#define mapHeight 5
int worldMap[mapWidth][mapHeight]=
{
	{1, 1, 1, 1, 1},
	{1, 0, 0, 0, 1},
	{1, 0, 0, 0, 1},
	{1, 0, 0, 0, 1},
	{1, 1, 1, 1, 1}
};

// #define mapWidth 5
// #define mapHeight 5
// int worldMap[mapWidth][mapHeight]=
// {
// 	{0, 0, 0, 0, 0},
// 	{0, 0, 0, 0, 0},
// 	{0, 0, 0, 0, 0},
// 	{0, 0, 0, 0, 0},
// 	{0, 0, 0, 0, 0}
// };

// #define mapWidth 24
// #define mapHeight 24
// int worldMap[mapWidth][mapHeight]=
// {
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
// };

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void draw_color_stripe(int32_t startX, int32_t endX, int32_t startY, int32_t endY, uint32_t color)
{
    for (int32_t x = startX; x < endX; ++x)
    {
        for (int32_t y = startY; y <= endY; ++y)
        {
            mlx_put_pixel(image, x, y, color);
        }
    }
}

void	raycasting(t_cubed *cubed)
{
	int	w = WIDTH;
	// int	h = HEIGHT; NOT USED

	uint32_t color3 = ft_pixel(255, 0, 0, 0xFF); // red
	(void)color3;

	for(int x = 0; x < w; x++)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
		double rayDirX = cubed->dirX + cubed->planeX * cameraX;
		double rayDirY = cubed->dirY + cubed->planeY * cameraX;
		if (rayDirY >= 0)
			mlx_put_pixel(image, WIDTH / 2, rayDirY * HEIGHT, color3);

		// printf("cameraX: %f\n", cameraX);
		// printf("rayDirX: %f\n", rayDirX);
		// printf("rayDirY: %f\n", rayDirY * HEIGHT);

		// which box of the map we're in
		int mapX = (int)cubed->posX;
		int mapY = (int)cubed->posY;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		double deltaDistX = ((int)rayDirX == 0) ? 1e30 : abs(1 / (int)rayDirX);
		double deltaDistY = ((int)rayDirY == 0) ? 1e30 : abs(1 / (int)rayDirY);

		// double perpWallDist; NOT USED

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (cubed->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - cubed->posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (cubed->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - cubed->posY) * deltaDistY;
		}
		//perform DDA
		while(hit == 0)
		{
		//jump to next map square, either in x-direction, or in y-direction
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				// printf("sideDistX: %f\n", sideDistX);
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			// if(worldMap[mapX][mapY] > 0) hit = 1;
			if(worldMap[mapX][mapY] == 1) 
			{
				printf("mapX: %d\n", mapX);
				printf("mapY: %d\n", mapY);
				// printf("hit is now 1\n");
				hit = 1;
			}
		}
		(void)side;
		// mlx_put_pixel(image, mapX, mapY, color3);
		printf("hit is %d\n", hit);
		// printf("side is %d\n", side);
		// if (hit)
		// 	return ;
	}
}

void start_screen(void* param)
{
	// t_cubed	*cubed;
	(void)param;

	// cubed = param;

    // uint32_t color0 = ft_pixel(47, 79, 79, 0xFF);
    // uint32_t color1 = ft_pixel(112, 128, 144, 0xFF);
	// uint32_t color2 = ft_pixel(220, 20, 60, 0xFF);
	// uint32_t color3 = ft_pixel(255, 0, 0, 0xFF); // red
	// uint32_t color4 = ft_pixel(60, 179, 113, 0xFF);
	// uint32_t color5 = ft_pixel(0, 0, 255, 0xFF);
	uint32_t colorBlack = ft_pixel(0, 0, 0, 0xFF);
	uint32_t colorWhite = ft_pixel(255, 255, 255, 0xFF);


	int	y = 0;
	int	stepY = HEIGHT / mapHeight;
	int	startY = 0;
	int	endY = stepY;

	while (y < mapHeight)
	{
		int	startX = 0;
		int stepX = WIDTH / mapWidth;
		int endX = stepX;
		int x = 0;
		while (x < mapWidth)
		{
			// printf("x: %d\n", x);
			// if (x == round(cubed->posX) && y == round(cubed->posY)) // doesn't work yet
			// {
			// 	draw_color_stripe(startX + 25, endX - 25, startY + 25, endY - 25, colorBlack);
			// }
			if (worldMap[x][y] == 0)
				draw_color_stripe(startX, endX, startY, endY, colorBlack);
			else if (worldMap[x][y] == 1)
				draw_color_stripe(startX+1, endX-1, startY+1, endY-1, colorWhite);
			// else if (worldMap[x][y] == 2)
			// draw_color_stripe(startX, endX, startY, endY, color2);
			// else if (worldMap[x][y] == 3)
			// 	draw_color_stripe(startX, endX, startY, endY, color3);
			// else if (worldMap[x][y] == 4)
			// 	draw_color_stripe(startX, endX, startY, endY, color4);
			// else if (worldMap[x][y] == 5)
			// 	draw_color_stripe(startX, endX, startY, endY, color5);
			


			startX = endX;
			endX += stepX;
			x++;
		}
		startY = endY;
		endY += stepY;
		y++;
	}
	// raycasting(cubed);
    // draw_color_stripe(0, image->width, 0, image->height / 2 - 1, sealing_color);
    // draw_color_stripe(0, image->width, image->height / 2, image->height - 1, floor_color);
    // draw_color_stripe(obstacle_startX, obstacle_endX, obstacle_startY, obstacle_endY, obstacle_color);
}

bool	max_obstacle_check(void)
{
	if (obstacle_startX == 0 || obstacle_endX == WIDTH - 1 ||
		obstacle_startY == 0 || obstacle_endY == HEIGHT - 1)
		return (false);
	return (true);
}

void	draw_vertical(int x, int y, t_cubed *cubed)
{
	uint32_t colorYellow = ft_pixel(255, 165, 0, 0xFF);

	// printf("pa: %f\n", cubed->pa);
	int	line = 20;

	while (line > 0)
	{
		mlx_put_pixel(image, x + cos(cubed->pa) * line, y + sin(cubed->pa) * line, colorYellow);
		line--;
	}
}

void	drawRays3D(void *param)
{
	t_cubed *cubed;
	int		r, mx, my, mp, dof;
	float	rx, ry, ra, xo, yo;

	cubed = param;
	int	mapX = cubed->posX;
	int	mapY = cubed->posY;
	ra = cubed->pa;
	for (r = 0; r < 1; r++)
	{
		dof = 0;
		double	aTan = -1/tan(ra);
		if (ra > pi)
		{
			ry = (((int)cubed->posY >> 6) << 6) - 0.0001;
			rx = (cubed->posY - ry) * aTan + cubed->posX;
			yo = -64;
			xo = -yo * aTan;
		}
		if (ra < pi)
		{
			ry = (((int)cubed->posY >> 6) << 6) + 64;
			rx = (cubed->posY - ry) * aTan + cubed->posX;
			yo = 64;
			xo = -yo * aTan;
		}
		if (ra == 0 || ra == pi)
		{
			rx = cubed->posX;
			ry = cubed->posY;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(rx) >> 6;
			my = (int)(ry) >> 6;
			mp = my * mapX + mx;
			// if (mp < mapX * mapY && map[mp] == 1)
			if (mp < mapX * mapY && worldMap[mapX][mapY] == 1)
				dof = 8;
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		printf("cubed->posX: %f\n", cubed->posX);
		printf("cubed->posY: %f\n", cubed->posY);
		printf("rx: %f\n", rx);
		printf("ry: %f\n", ry);
	}

}

void	player(void *param)
{
	t_cubed *cubed;

	cubed = param;
	uint32_t colorYellow = ft_pixel(255, 165, 0, 0xFF);

	int	y = 0;
	while (y < HEIGHT)
	{
		int x = 0;
		while (x < WIDTH)
		{
			if ((x > cubed->posX - 6 && x < cubed->posX + 6)
					&& (y > cubed->posY - 6 && y < cubed->posY + 6))
			{
				mlx_put_pixel(image, x, y, colorYellow);
				if ((x > cubed->posX - 2 && x < cubed->posX + 2)
					&& (y > cubed->posY - 2 && y < cubed->posY + 2))
					draw_vertical(x, y, cubed);
			}
			x++;
		}
		y++;
	}
}

void ft_hook(void* param)
{
	t_cubed	*cubed;

	cubed = param;

	if (mlx_is_key_down(cubed->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cubed->mlx);
	if (mlx_is_key_down(cubed->mlx, MLX_KEY_W)) // move forward (zoom isn)
	{
		// if (cubed->posY >= 5)
			// cubed->posY -= 5;
		cubed->posX += cubed->pdx;
		cubed->posY += cubed->pdy;
		
		// if (!max_obstacle_check())
		// 	return ;
		// obstacle_startX -= 5;
		// obstacle_endX += 5;
		// obstacle_startY -= 5;
		// if (obstacle_endY - obstacle_startY >= diff_y)
		// 	obstacle_endY += 5;

	}
	if (mlx_is_key_down(cubed->mlx, MLX_KEY_S)) // move backward (zoom out)
	{
		// if (cubed->posY <= HEIGHT - 5)
		// 	cubed->posY += 5;
		cubed->posX -= cubed->pdx;
		cubed->posY	-= cubed->pdy;

		// obstacle_startX += 5;
		// obstacle_endX -= 5;
		// if (obstacle_endY > image->height / 2)
		// 	obstacle_endY -= 5;
		// obstacle_startY += 5;
	}

	// if (mlx_is_key_down(cubed->mlx, MLX_KEY_A)) // move to the left (change position in map)
	// {
	// 	// if (cubed->posX >= 0)
	// 	// 	cubed->posX -= 5;

	// 	cubed->posX -= cubed->pdx;
	// 	cubed->posY -= cubed->pdy;

	// 	// obstacle_startX += 5;
	// 	// obstacle_endX += 5;
	// }
	// if (mlx_is_key_down(cubed->mlx, MLX_KEY_D)) // move to the right (change position in map)
	// {
	// 	// if (cubed->posX <= WIDTH - 5)
	// 	// 	cubed->posX += 5;
	// 	cubed->posX += cubed->pdx;
	// 	cubed->posY += cubed->pdy;

	// 	// obstacle_startX -= 5;
	// 	// obstacle_endX -= 5;
	// }
	if (mlx_is_key_down(cubed->mlx, MLX_KEY_LEFT)) // change screen to the left
		// image->instances[0].x -= 5;
	{
		cubed->pa -= 0.05;
		if (cubed->pa < 0)
			cubed->pa += 2 * pi;
		cubed->pdx = cos(cubed->pa)	* 2;
		cubed->pdy = sin(cubed->pa) * 2;
	}
	if (mlx_is_key_down(cubed->mlx, MLX_KEY_RIGHT)) // change screen to the right
		// image->instances[0].x += 5;
	{
		cubed->pa += 0.05;
		if (cubed->pa > 2 * pi)
			cubed->pa -= 2 * pi;
		cubed->pdx = cos(cubed->pa)	* 2;
		cubed->pdy = sin(cubed->pa) * 2;
	}
}

bool	initialize_cubed(t_cubed *cubed)
{
	cubed->posX = 256;
	cubed->posY = 256;
	cubed->dirX = -1.0;
	cubed->dirY = 0.0;
	cubed->planeX = 0.0;
	cubed->planeY = 0.66;
	cubed->time = 0;
	cubed->oldTime = 0;
	cubed->pa = 0;
	cubed->px = 0;
	cubed->py = 0;
	cubed->pdx = 0;
	cubed->pdy = 0;
	return (true);
}

int32_t main(void)
{
	t_cubed	cubed;
	
	if (!initialize_cubed(&cubed))
		return (1);
	if (!(cubed.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(cubed.mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(cubed.mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	// angle = 2;
	// obstacle_startX = image->width * 0.25;
	// obstacle_endX = image->width * 0.75;
	// diff_x = obstacle_endX - obstacle_startX;
	// obstacle_startY = image->height * 0.25;
	// obstacle_endY = image->height * 0.5 - 1;
	// diff_y = obstacle_endY - obstacle_startY;

	if (mlx_image_to_window(cubed.mlx, image, 0, 0) == -1)
	{
		mlx_close_window(cubed.mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}

	mlx_loop_hook(cubed.mlx, start_screen, &cubed);
	mlx_loop_hook(cubed.mlx, player, &cubed);
	mlx_loop_hook(cubed.mlx, drawRays3D, &cubed);
	mlx_loop_hook(cubed.mlx, ft_hook, &cubed);

	mlx_loop(cubed.mlx);
	mlx_terminate(cubed.mlx);
	return (EXIT_SUCCESS);
}

// -----------------------------------------------------------------------------


// &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

/*
Copyright (c) 2004-2021, Lode Vandevenne

All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

// #include <math.h>
// #include <string.h>
// #include "../include/cubed.h"
// // #include <vector.h>
// // #include <iostream>

// /*
// g++ *.cpp -lSDL -O3 -W -Wall -ansi -pedantic
// g++ *.cpp -lSDL
// */

// //place the example code below here:

// #define screenWidth 640
// #define screenHeight 480
// #define mapWidth 24
// #define mapHeight 24

// static mlx_image_t* image;

// int worldMap[mapWidth][mapHeight]=
// {
// 	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
// 	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
// 	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
// };

// int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

// void draw_color_stripe(int32_t x, int32_t y1, int32_t y2, uint32_t color)
// {
// 	int	w = (int)screenWidth;
// 	int	h = (int)screenHeight;

// 	if(y2 < y1) {y1 += y2; y2 = y1 - y2; y1 -= y2;} //swap y1 and y2
// 	if(y2 < 0 || y1 >= h  || x < 0 || x >= w) return ; //no single point of the line is on screen
// 	if(y1 < 0) y1 = 0; //clip
// 	if(y2 >= w) y2 = h - 1; //clip

//     for (int32_t y = y1; y < y2; ++y)
//     {
// 		mlx_put_pixel(image, x, y, color);
//     }
// }

// void	screen(void *param)
// {
// 	t_cubed	*cubed;

// 	cubed = param;
// 	int	w = (int)screenWidth;
// 	int	h = (int)screenHeight;
	

// 	for(int x = 0; x < w; x++)
// 	{
// 		//calculate ray position and direction
// 		double cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
// 		double rayDirX = cubed->dirX + cubed->planeX * cameraX;
// 		double rayDirY = cubed->dirY + cubed->planeY * cameraX;
// 		//which box of the map we're in
// 		int mapX = (int)cubed->posX;
// 		int mapY = (int)cubed->posY;

// 		//length of ray from current position to next x or y-side
// 		double sideDistX;
// 		double sideDistY;

// 		//length of ray from one x or y-side to next x or y-side
// 		//these are derived as:
// 		//deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX))
// 		//deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY))
// 		//which can be simplified to abs(|rayDir| / rayDirX) and abs(|rayDir| / rayDirY)
// 		//where |rayDir| is the length of the vector (rayDirX, rayDirY). Its length,
// 		//unlike (dirX, dirY) is not 1, however this does not matter, only the
// 		//ratio between deltaDistX and deltaDistY matters, due to the way the DDA
// 		//stepping further below works. So the values can be computed as below.
// 		// Division through zero is prevented, even though technically that's not
// 		// needed in C++ with IEEE 754 floating point values.
// 		double deltaDistX = ((int)rayDirX == 0) ? 1e30 : abs(1 / (int)rayDirX);
// 		double deltaDistY = ((int)rayDirY == 0) ? 1e30 : abs(1 / (int)rayDirY);

// 		double perpWallDist;

// 		//what direction to step in x or y-direction (either +1 or -1)
// 		int stepX;
// 		int stepY;

// 		int hit = 0; //was there a wall hit?
// 		int side; //was a NS or a EW wall hit?
// 		//calculate step and initial sideDist
// 		if(rayDirX < 0)
// 		{
// 			stepX = -1;
// 			sideDistX = (cubed->posX - mapX) * deltaDistX;
// 		}
// 		else
// 		{
// 			stepX = 1;
// 			sideDistX = (mapX + 1.0 - cubed->posX) * deltaDistX;
// 		}
// 		if(rayDirY < 0)
// 		{
// 			stepY = -1;
// 			sideDistY = (cubed->posY - mapY) * deltaDistY;
// 		}
// 		else
// 		{
// 			stepY = 1;
// 			sideDistY = (mapY + 1.0 - cubed->posY) * deltaDistY;
// 		}
// 		//perform DDA
// 		while(hit == 0)
// 		{
// 		//jump to next map square, either in x-direction, or in y-direction
// 			if(sideDistX < sideDistY)
// 			{
// 				sideDistX += deltaDistX;
// 				mapX += stepX;
// 				side = 0;
// 			}
// 			else
// 			{
// 				sideDistY += deltaDistY;
// 				mapY += stepY;
// 				side = 1;
// 			}
// 			//Check if ray has hit a wall
// 			if(worldMap[mapX][mapY] > 0) hit = 1;
// 		}
// 		//Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
// 		//hit to the camera plane. Euclidean to center camera point would give fisheye effect!
// 		//This can be computed as (mapX - posX + (1 - stepX) / 2) / rayDirX for side == 0, or same formula with Y
// 		//for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
// 		//because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
// 		//steps, but we subtract deltaDist once because one step more into the wall was taken above.
// 		if(side == 0) perpWallDist = (sideDistX - deltaDistX);
// 		else          perpWallDist = (sideDistY - deltaDistY);

// 		//Calculate height of line to draw on screen
// 		int lineHeight = (int)(h / perpWallDist);

// 		//calculate lowest and highest pixel to fill in current stripe
// 		int drawStart = -lineHeight / 2 + h / 2;
// 		if(drawStart < 0) drawStart = 0;
// 		int drawEnd = lineHeight / 2 + h / 2;
// 		if(drawEnd >= h) drawEnd = h - 1;

// 		//choose wall color
// 		// ColorRGB color;
// 		// switch(worldMap[mapX][mapY])
// 		// {
// 		// 	case 1:  color = RGB_Red;    break; //red
// 		// 	case 2:  color = RGB_Green;  break; //green
// 		// 	case 3:  color = RGB_Blue;   break; //blue
// 		// 	case 4:  color = RGB_White;  break; //white
// 		// 	default: color = RGB_Yellow; break; //yellow
// 		// }
// 		uint32_t color;
// 		switch (worldMap[mapX][mapY])
// 		{
// 			case 1: color = ft_pixel(255, 0, 0, 0xFF); break;
// 			case 2: color = ft_pixel(60, 179, 113, 0xFF); break;
// 			case 3: color = ft_pixel(0, 0, 255, 0xFF); break;
// 			case 4: color = ft_pixel(255, 165, 0, 0xFF); break;
// 			default: color = ft_pixel(0, 0, 0, 0xFF); break;
// 		}

// 		//give x and y sides different brightness
// 		if(side == 1) {color = color / 2;}

// 		//draw the pixels of the stripe as a vertical line
// 		draw_color_stripe(x, drawStart, drawEnd, color);
// 		// verLine(x, drawStart, drawEnd, color); // replace for mlx_put_pixel
// 	}
// }

// void	hooks(void *param)
// {
// 	t_cubed	*cubed = param;
// 	//timing for input and FPS counter
// 	cubed->oldTime = cubed->time;
// 	// cubed->time = getTicks();
// 	cubed->time = mlx_get_time(); // DON'T KNOW IF THIS IS GOING TO WORK
// 	double frameTime = (cubed->time - cubed->oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
// 	printf("FPS counter: %f\n", 1.0 / frameTime); //FPS counter
// 	// redraw(); // DON'T KNOW IF THIS IS GOING TO WORK
// 	// cls(); // DON'T KNOW IF THIS IS GOING TO WORK

// 	//speed modifiers
// 	double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
// 	double rotSpeed = frameTime * 3.0; //the constant value is in radians/second
// 	// readKeys(); // DON'T KNOW IF THIS IS GOING TO WORK
// 	//move forward if no wall in front of you
// 	if(mlx_is_key_down(cubed->mlx, MLX_KEY_W))
// 	{
// 		if(worldMap[(int)(cubed->posX + cubed->dirX * moveSpeed)][(int)(cubed->posY)] == false) cubed->posX += cubed->dirX * moveSpeed;
// 		if(worldMap[(int)(cubed->posX)][(int)(cubed->posY + cubed->dirY * moveSpeed)] == false) cubed->posY += cubed->dirY * moveSpeed;
// 	}
// 	//move backwards if no wall behind you
// 	if(mlx_is_key_down(cubed->mlx, MLX_KEY_S))
// 	{
// 		if(worldMap[(int)(cubed->posX - cubed->dirX * moveSpeed)][(int)(cubed->posY)] == false) cubed->posX -= cubed->dirX * moveSpeed;
// 		if(worldMap[(int)(cubed->posX)][(int)(cubed->posY - cubed->dirY * moveSpeed)] == false) cubed->posY -= cubed->dirY * moveSpeed;
// 	}
// 	//rotate to the right
// 	if(mlx_is_key_down(cubed->mlx, MLX_KEY_RIGHT))
// 	{
// 		//both camera direction and camera plane must be rotated
// 		double oldDirX = cubed->dirX;
// 		cubed->dirX = cubed->dirX * cos(-rotSpeed) - cubed->dirY * sin(-rotSpeed);
// 		cubed->dirY = oldDirX * sin(-rotSpeed) + cubed->dirY * cos(-rotSpeed);
// 		double oldPlaneX = cubed->planeX;
// 		cubed->planeX = cubed->planeX * cos(-rotSpeed) - cubed->planeY * sin(-rotSpeed);
// 		cubed->planeY = oldPlaneX * sin(-rotSpeed) + cubed->planeY * cos(-rotSpeed);
// 	}
// 	//rotate to the left
// 	if(mlx_is_key_down(cubed->mlx, MLX_KEY_LEFT))
// 	{
// 		//both camera direction and camera plane must be rotated
// 		double oldDirX = cubed->dirX;
// 		cubed->dirX = cubed->dirX * cos(rotSpeed) - cubed->dirY * sin(rotSpeed);
// 		cubed->dirY = oldDirX * sin(rotSpeed) + cubed->dirY * cos(rotSpeed);
// 		double oldPlaneX = cubed->planeX;
// 		cubed->planeX = cubed->planeX * cos(rotSpeed) - cubed->planeY * sin(rotSpeed);
// 		cubed->planeY = oldPlaneX * sin(rotSpeed) + cubed->planeY * cos(rotSpeed);
// 	}
// 	if (mlx_is_key_down(cubed->mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(cubed->mlx);
// }

// void	initialize_cubed(t_cubed *cubed)
// {
// 	cubed->posX = 22;
// 	cubed->posY = 12;  //x and y start position
// 	cubed->dirX = -1;
// 	cubed->dirY = 0; //initial direction vector
// 	cubed->planeX = 0;
// 	cubed->planeY = 0.66; //the 2d raycaster version of camera plane

// 	cubed->time = 0; //time of current frame
// 	cubed->oldTime = 0; //time of previous frame
// }

// int	mlx(t_cubed *cubed)
// {
// 	// screen(screenWidth, screenHeight, 0, "Raycaster");
// 	if (!(cubed->mlx = mlx_init(screenWidth, screenHeight, "MLX42", true)))
// 	{
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (!(image = mlx_new_image(cubed->mlx, screenWidth, screenHeight)))
// 	{
// 		mlx_close_window(cubed->mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (mlx_image_to_window(cubed->mlx, image, 0, 0) == -1)
// 	{
// 		mlx_close_window(cubed->mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}

// 	mlx_loop_hook(cubed->mlx, screen, cubed);
// 	mlx_loop_hook(cubed->mlx, hooks, cubed);

// 	mlx_loop(cubed->mlx);
// 	mlx_terminate(cubed->mlx);
// 	return (EXIT_SUCCESS);
// }

// int main(int argc, char *argv[])
// {
// 	(void)argc;
// 	(void)argv;
// 	t_cubed	cubed;

// 	initialize_cubed(&cubed);

// 	mlx(&cubed);
	
// 	return (EXIT_SUCCESS);
	
// }
