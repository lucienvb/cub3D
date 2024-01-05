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
	{1, 1, 0, 1, 1},
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
//   {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
//   {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
//   {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
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

void	setXYdir(t_cubed *cubed, double x, double y, int line)
{
	double	xVision = x + cos(cubed->pa) * line;
	double	yVision = y + sin(cubed->pa) * line;

	if (x == xVision)
		cubed->dirX = 0;
	else if (x < xVision)
		cubed->dirX = 1.0;
	else
		cubed->dirX = -1.0;
	if (y == yVision)
		cubed->dirY = 0;
	else if (y < yVision)
		cubed->dirY = 1.0;
	else
		cubed->dirY = -1.0;
}

void	draw_vertical(int x, int y, t_cubed *cubed)
{
	uint32_t colorYellow = ft_pixel(255, 165, 0, 0xFF);

	// printf("pa: %f\n", cubed->pa);
	int	line = 20;
	setXYdir(cubed, x, y, line);

	while (line > 0)
	{
		mlx_put_pixel(image, x + cos(cubed->pa) * line, y + sin(cubed->pa) * line, colorYellow);
		line--;
	}
}

void	drawPoint(double posX, double posY, uint32_t color, int thickness)
{
	int	y = 0;

	while (y < HEIGHT && posY > 0 && posY < HEIGHT)
	{
		int x = 0;
		while (x < WIDTH && posX > 0 && posX < WIDTH)
		{
			if ((x > posX - thickness && x < posX + thickness)
						&& (y > posY - thickness && y < posY + thickness)
						&& (x != posX && y != posY))
					mlx_put_pixel(image, x, y, color);
			x++;
		}
		y++;
	}
}

bool	checkRay(t_cubed *cubed, double x_target, double y_target)
{
	int	x;
	int	y;

	y = 0;
	while (y < mapHeight)
	{
		x = 0;
		while (x < mapWidth)
		{
			if (worldMap[x][y] == 1)
			{
				if ((x_target >= x * cubed->widthBlock && x_target <= (x + 1) * cubed->widthBlock) &&
						(y_target >= y * cubed->heightBlock && y_target <= (y + 1) * cubed->heightBlock))
					return (true);
			}
			x++;
		} 
		y++;
	}
	return (false);
}

void	getAxAy(t_cubed *cubed, double *Ax, double *Ay)
{
	// double	tempAx = 0;
	// double	tempAy = 0;

	printf("Ax: %f\n", *Ax);
	printf("Ay: %f\n", *Ay);
	// tempAx = *Ax; 
	// tempAy = *Ay;
	// if (cubed->dirX == 1)
	// 	*Ax = cubed->tempPosX + tempAx;
	// else if (cubed->dirX == -1)
	// 	*Ax = WIDTH - cubed->tempPosX - tempAx;
	// if (cubed->dirY == 1)
	// 	*Ay = cubed->tempPosY + tempAy;
	// else if (cubed->dirY == -1)
	// 	*Ay = HEIGHT - cubed->tempPosY - tempAy;
	if (cubed->dirX == 1)
		*Ax = cubed->tempPosX;
	else if (cubed->dirX == -1)
		*Ax = WIDTH - cubed->tempPosX;
	if (cubed->dirY == 1)
		*Ay = cubed->tempPosY;
	else if (cubed->dirY == -1)
		*Ay = HEIGHT - cubed->tempPosY;			

	while (*Ax >= 0 && cubed->pa != 0.5 * pi && cubed->pa != 1.5 * pi)
		*Ax -= cubed->widthBlock;
	if (cubed->dirX == 1)
		*Ax *= -1;
	// printf("Ax: %f\n", *Ax);
	
	while (*Ay >= 0 && cubed->pa != 0 && cubed->pa != pi)
		*Ay -= cubed->heightBlock;
	if (cubed->dirY == 1)
		*Ay *= -1;
	// printf("Ay: %f\n", *Ay);
}

bool	x_ray_is_shortest(t_cubed *cubed, double Ax, double Ay)
{
	double xRayLength = sqrt(Ax * Ax + Ax * sin(cubed->pa) / cos(cubed->pa) * Ax * sin(cubed->pa) / cos(cubed->pa));
	double yRayLength = sqrt(Ay * cos(cubed->pa) / sin(cubed->pa) * Ay * cos(cubed->pa) / sin(cubed->pa) + Ay * Ay);

	if (xRayLength < yRayLength)
	{
		printf("xRay is shortest\n");
		return (true);
	}
	printf("yRay is shortest\n");
	return (false);
}

t_hit	is_hit(t_cubed *cubed, double Ax, double Ay)
{
	uint32_t	colorOrange = ft_pixel(255, 140, 0, 0xFF);

	if (x_ray_is_shortest(cubed, Ax, Ay) == true)
	{
		if (checkRay(cubed, cubed->tempPosX + Ax, cubed->tempPosY + Ax * sin(cubed->pa)))
		{
			drawPoint(cubed->tempPosX + Ax, cubed->tempPosY + Ax * sin(cubed->pa) / cos(cubed->pa), colorOrange, 4);	
			return (x_ray_hit);
		}
		else if (checkRay(cubed, cubed->tempPosX + Ay * cos(cubed->pa) / sin(cubed->pa), cubed->tempPosY + Ay))
		{
			drawPoint(cubed->tempPosX + Ay * cos(cubed->pa) / sin(cubed->pa), cubed->tempPosY + Ay, colorOrange, 4);
			return (y_ray_hit);
		}
	}
	else
	{
		if (checkRay(cubed, cubed->tempPosX + Ay * cos(cubed->pa) / sin(cubed->pa), cubed->tempPosY + Ay))
		{
			drawPoint(cubed->tempPosX + Ay * cos(cubed->pa) / sin(cubed->pa), cubed->tempPosY + Ay, colorOrange, 4);
			return (y_ray_hit);
		}
		else if (checkRay(cubed, cubed->tempPosX + Ax, cubed->tempPosY + Ax * sin(cubed->pa)))
		{
			drawPoint(cubed->tempPosX + Ax, cubed->tempPosY + Ax * sin(cubed->pa) / cos(cubed->pa), colorOrange, 4);	
			return (x_ray_hit);
		}
	}
	return (no_hit);
}

void	raycasting(void *param)
{
	t_cubed 	*cubed;
	uint32_t	colorGreen = ft_pixel(60, 179, 113, 0xFF);
	uint32_t	colorPurple = ft_pixel(160, 32, 240, 0xFF);

	cubed = param;
	double		Ax = 0;
	double		Ay = 0;
	
	printf("widthBlock: %f\n", cubed->widthBlock);
	printf("heightBlock: %f\n", cubed->heightBlock);
	printf("pa: %f\n", cubed->pa);
	printf("dirX: %f\n", cubed->dirX);
	printf("dirY: %f\n", cubed->dirY);

	// double	currentX = 0;
	// double	currentY = 0;
	// bool	hit = false;
	
	cubed->tempPosX = cubed->posX;
	cubed->tempPosY = cubed->posY;
	getAxAy(cubed, &Ax, &Ay);
	
	
	drawPoint(cubed->posX, cubed->posY + Ay, colorGreen, 3);
	drawPoint(cubed->posX + Ax, cubed->posY, colorGreen, 3);
	
	drawPoint(cubed->posX + Ax, cubed->posY + Ax * sin(cubed->pa) / cos(cubed->pa), colorPurple, 2);	
	drawPoint(cubed->posX + Ax + cubed->widthBlock, cubed->posY + (Ax + cubed->widthBlock) * sin(cubed->pa) / cos(cubed->pa), colorPurple, 2);	
	drawPoint(cubed->posX + Ay * cos(cubed->pa) / sin(cubed->pa), cubed->posY + Ay, colorPurple, 2);

	if (is_hit(cubed, Ax, Ay) == x_ray_hit)
	{
		printf("It's hit on coordinates x(%f) and y(%f)\n", cubed->posX + Ax, cubed->posY + Ax * sin(cubed->pa) / cos(cubed->pa));
		return ;
	}
	else if (is_hit(cubed, Ax + cubed->widthBlock, (Ax + cubed->widthBlock) * sin(cubed->pa) / cos(cubed->pa)) == x_ray_hit)
	{
		printf("It's hit on coordinates x(%f) and y(%f)\n", cubed->posX + Ax + cubed->widthBlock, cubed->posY + (Ax + cubed->widthBlock) * sin(cubed->pa) / cos(cubed->pa));
		return ;
	}
	else if (is_hit(cubed, Ax, Ay) == y_ray_hit)
	{
		printf("It's hit on coordinates x(%f) and y(%f)\n", cubed->posX + Ay * cos(cubed->pa) / sin(cubed->pa), cubed->posY + Ay);
		return ;
	}
	else 
		printf("no hit\n");

	printf("Ax in raycasting: %f\n", Ax);
	printf("Ay in raycasting: %f\n", Ay);
	if (x_ray_is_shortest(cubed, Ax, Ay))
	{
		// Ax += cubed->widthBlock;
		cubed->tempPosX += Ax;
		cubed->tempPosY += Ax * sin(cubed->pa) / cos(cubed->pa);
	}	
	else
	{
		cubed->tempPosX += Ay * cos(cubed->pa) / sin(cubed->pa);
		cubed->tempPosY += Ay;
		// Ay += cubed->heightBlock;
	}

	// second run

	// getAxAy(cubed, &Ax, &Ay);
		
	// drawPoint(cubed->tempPosX, cubed->tempPosY + Ay, colorGreen, 3);
	// drawPoint(cubed->tempPosX + Ax, cubed->tempPosY, colorGreen, 3);
	
	// drawPoint(cubed->tempPosX + Ax, cubed->tempPosY + Ax * sin(cubed->pa) / cos(cubed->pa), colorPurple, 2);	
	// drawPoint(cubed->tempPosX + Ay * cos(cubed->pa) / sin(cubed->pa), cubed->tempPosY + Ay, colorPurple, 2);

	// if (is_hit(cubed, Ax, Ay) == x_ray_hit)
	// {
	// 	printf("It's hit on coordinates x(%f) and y(%f)\n", cubed->posX + Ax, cubed->posY + Ax * sin(cubed->pa) / cos(cubed->pa));
	// 	return ;
	// }
	// else if (is_hit(cubed, Ax, Ay) == y_ray_hit)
	// {
	// 	printf("It's hit on coordinates x(%f) and y(%f)\n", cubed->posX + Ay * cos(cubed->pa) / sin(cubed->pa), cubed->posY + Ay);
	// 	return ;
	// }
	// else 
	// 	printf("no hit\n");

	// printf("Ax in raycasting: %f\n", Ax);
	// printf("Ay in raycasting: %f\n", Ay);

	// third run

	// if (x_ray_is_shortest(cubed, Ax, Ay))
	// {
	// 	cubed->tempPosX += Ax;
	// 	cubed->tempPosY += Ax * sin(cubed->pa) / cos(cubed->pa);
	// }	
	// else
	// {
	// 	cubed->tempPosX += Ay * cos(cubed->pa) / sin(cubed->pa);
	// 	cubed->tempPosY += Ay;
	// }

	// getAxAy(cubed, &Ax, &Ay);
		
	// drawPoint(cubed->tempPosX, cubed->tempPosY + Ay, colorGreen, 3);
	// drawPoint(cubed->tempPosX + Ax, cubed->tempPosY, colorGreen, 3);
	
	// drawPoint(cubed->tempPosX + Ax, cubed->tempPosY + Ax * sin(cubed->pa) / cos(cubed->pa), colorPurple, 2);	
	// drawPoint(cubed->tempPosX + Ay * cos(cubed->pa) / sin(cubed->pa), cubed->tempPosY + Ay, colorPurple, 2);

	// if (is_hit(cubed, Ax, Ay) == x_ray_hit)
	// {
	// 	printf("It's hit on coordinates x(%f) and y(%f)\n", cubed->posX + Ax, cubed->posY + Ax * sin(cubed->pa) / cos(cubed->pa));
	// 	return ;
	// }
	// else if (is_hit(cubed, Ax, Ay) == y_ray_hit)
	// {
	// 	printf("It's hit on coordinates x(%f) and y(%f)\n", cubed->posX + Ay * cos(cubed->pa) / sin(cubed->pa), cubed->posY + Ay);
	// 	return ;
	// }
	// else 
	// 	printf("no hit\n");

	// if (x_ray_is_shortest(cubed, Ax, Ay))
	// {
	// 	cubed->tempPosX += Ax;
	// 	cubed->tempPosY += Ax * sin(cubed->pa) / cos(cubed->pa);
	// }	
	// else
	// {
	// 	cubed->tempPosX += Ay * cos(cubed->pa) / sin(cubed->pa);
	// 	cubed->tempPosY += Ay;
	// }

	// getAxAy(cubed, &Ax, &Ay);
		
	// drawPoint(cubed->tempPosX, cubed->tempPosY + Ay, colorGreen, 3);
	// drawPoint(cubed->tempPosX + Ax, cubed->tempPosY, colorGreen, 3);
	
	// drawPoint(cubed->tempPosX + Ax, cubed->tempPosY + Ax * sin(cubed->pa) / cos(cubed->pa), colorPurple, 2);	
	// drawPoint(cubed->tempPosX + Ay * cos(cubed->pa) / sin(cubed->pa), cubed->tempPosY + Ay, colorPurple, 2);

	// if (is_hit(cubed, Ax, Ay) == x_ray_hit)
	// {
	// 	printf("It's hit on coordinates x(%f) and y(%f)\n", cubed->posX + Ax, cubed->posY + Ax * sin(cubed->pa) / cos(cubed->pa));
	// 	return ;
	// }
	// else if (is_hit(cubed, Ax, Ay) == y_ray_hit)
	// {
	// 	printf("It's hit on coordinates x(%f) and y(%f)\n", cubed->posX + Ay * cos(cubed->pa) / sin(cubed->pa), cubed->posY + Ay);
	// 	return ;
	// }
	// else 
	// 	printf("no hit\n");
	
}

void	player(void *param)
{
	t_cubed *cubed;

	cubed = param;
	uint32_t colorYellow = ft_pixel(255, 165, 0, 0xFF);

	int	y = 0;
	while (y < HEIGHT && cubed->posY > 0 && cubed->posY < HEIGHT)
	{
		int x = 0;
		while (x < WIDTH && cubed->posX > 0 && cubed->posX < WIDTH)
		{
			if ((x > cubed->posX - 6 && x < cubed->posX + 6)
					&& (y > cubed->posY - 6 && y < cubed->posY + 6))
			{
			// printf("posX: %f\n", cubed->posX);
			// printf("posY: %f\n", cubed->posY);
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
		if (cubed->posX < WIDTH - cubed->pdx && cubed->posY < HEIGHT - cubed->pdy) 
		{
			cubed->posX += cubed->pdx;
			cubed->posY += cubed->pdy;

		}
		
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
		if (cubed->posX >= 0 + cubed->pdx && cubed->posY >= 0 + cubed->pdy)
		{
			cubed->posX -= cubed->pdx;
			cubed->posY	-= cubed->pdy;
		}

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
	cubed->posX = 150;
	cubed->posY = 375;
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
	cubed->widthBlock = (double)WIDTH / (double)mapWidth;
	cubed->heightBlock = (double)HEIGHT / (double)mapHeight;
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

	if (mlx_image_to_window(cubed.mlx, image, 0, 0) == -1)
	{
		mlx_close_window(cubed.mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}

	mlx_loop_hook(cubed.mlx, start_screen, &cubed);

	// int hit = 0;
	// checkRay(&cubed, 102.3, 102.3, &hit);
	// printf("hit: %i\n", hit);

	mlx_loop_hook(cubed.mlx, player, &cubed);
	mlx_loop_hook(cubed.mlx, raycasting, &cubed);
	mlx_loop_hook(cubed.mlx, ft_hook, &cubed);

	mlx_loop(cubed.mlx);
	mlx_terminate(cubed.mlx);
	return (EXIT_SUCCESS);
}
