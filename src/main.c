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

#define BLOCK_WIDTH 25
#define BLOCK_HEIGHT 25

static	mlx_image_t* image;
double	obstacle_startX;
double	obstacle_endX;
double	obstacle_startY;
double	obstacle_endY;
double	diff_x;
double	diff_y;
double	pi = 3.14159265359;
double	angle;

// -----------------------------------------------------------------------------

// #define row 5
// #define column 5
// int worldMap[row][column]=
// {
// 	{0, 0, 0, 0, 0},
// 	{0, 0, 0, 0, 0},
// 	{0, 0, 0, 0, 0},
// 	{0, 0, 0, 0, 0},
// 	{0, 0, 0, 0, 0}
// };

// #define row 24
// #define column 24
// int worldMap[column][row]=
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
	int32_t	y;
	int32_t	x;

	y = startY;
	while (y < endY)
    {
		x = startX;
       while(x < endX)
        {
            mlx_put_pixel(image, x, y, color);
			x++;
        }
		y++;
	}
}

// #define column 3
// #define row 3
// int worldMap[column][row]=
// {
// 	{1, 1, 1},
// 	{1, 0, 1},
// 	{1, 1, 1}
// };

// #define column 4
// #define row 4
// int worldMap[column][row]=
// {
// 	{1, 1, 1, 1},
// 	{1, 0, 0, 1},
// 	{1, 0, 0, 1},
// 	{1, 1, 1, 1}
// };

#define column 5
#define row 5
int worldMap[column][row]=
{
	{1, 1, 1, 1, 1},
	{1, 0, 0, 0, 1},
	{1, 0, 1, 0, 1},
	{1, 0, 0, 0, 1},
	{1, 1, 1, 1, 1}
};

// #define column 6
// #define row 6
// int worldMap[column][row]=
// {
// 	{1, 1, 1, 1, 1, 1},
// 	{1, 1, 0, 0, 1, 1},
// 	{1, 0, 0, 0, 0, 1},
// 	{1, 0, 1, 0, 0, 1},
// 	{1, 0, 1, 0, 0, 1},
// 	{1, 1, 1, 1, 1, 1}
// };

void	draw_floor_and_ceiling(t_cubed *cubed)
{
	uint32_t colorBrown = ft_pixel(139, 69, 19, 0xFF);
	uint32_t colorPurple = ft_pixel(160, 32, 240, 0xFF);

	draw_color_stripe(0, cubed->screen_width - 1, 0, cubed->screen_height / 2 - 1, colorPurple);
	draw_color_stripe(0, cubed->screen_width - 1, cubed->screen_height / 2 - 1, cubed->screen_height - 1, colorBrown);
}

void mini_map(void *param)
{
	uint32_t colorBlack = ft_pixel(0, 0, 0, 0xFF);
	uint32_t colorWhite = ft_pixel(255, 255, 255, 0xFF);
	t_cubed	*cubed = param;

	// uint32_t colorBrown = ft_pixel(139, 69, 19, 0xFF);
	// uint32_t colorPurple = ft_pixel(160, 32, 240, 0xFF);

	// draw_color_stripe(0, cubed->screen_width - 1, 0, cubed->screen_height / 2 - 1, colorPurple);
	// draw_color_stripe(0, cubed->screen_width - 1, cubed->screen_height / 2 - 1, cubed->screen_height - 1, colorBrown);

	int	y = 0;
	int	stepY = cubed->mapHeight / column;
	int stepX = cubed->mapWidth / row;
	int	startY = cubed->screen_height - cubed->mapHeight;
	int	endY = startY + stepY;

	while (y < (int)column)
	{
		int	startX = 0;
		int endX = stepX;
		int x = 0;
		while (x < (int)row)
		{
			if (worldMap[y][x] == 0)
			{
				draw_color_stripe(startX, endX, startY, endY, colorBlack);
			}
			else if (worldMap[y][x] == 1)
			{
				draw_color_stripe(startX+1, endX-1, startY+1, endY-1, colorWhite);
			}
			startX = endX;
			endX += stepX;
			x++;
		}
		startY = endY;
		endY += stepY;
		y++;
	}
}

void	setXYdir(t_cubed *cubed, double x, double y, int line)
{
	double	pa = cubed->pa + cubed->fov;
	double	xVision = x + cos(pa) * line;
	double	yVision = y + sin(pa) * line;

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

void	draw_visor(int x, int y, t_cubed *cubed)
{
	uint32_t	colorYellow = ft_pixel(255, 165, 0, 0xFF);
	double		pa;
	int	line;
	
	pa = cubed->pa;
	line = 15;
	setXYdir(cubed, x, y, line);
	while (line > 0)
	{
		mlx_put_pixel(image, x + cos(pa) * line, y + sin(pa) * line, colorYellow);
		line--;
	}
}

void	drawPoint(t_cubed *cubed, double posX, double posY, uint32_t color, int thickness)
{
	int	y = 0;

	while (y < cubed->mapHeight && posY > 0 && posY < cubed->mapHeight)
	{
		int x = 0;
		while (x < cubed->mapWidth && posX > 0 && posX < cubed->mapWidth)
		{
			if ((x > posX - thickness && x < posX + thickness)
						&& (y > posY - thickness && y < posY + thickness)
						&& (x != posX && y != posY))
					mlx_put_pixel(image, x, y + cubed->mini_map_start_y, color);
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
	while (y < column)
	{
		x = 0;
		while (x < row)
		{
			if (worldMap[y][x] == 1)
			{
				if ((x_target >= x * cubed->widthBlock && x_target <= (x + 1) * cubed->widthBlock + 1) &&
						(y_target >= y * cubed->heightBlock && y_target <= (y + 1) * cubed->heightBlock + 1))
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
	double	pa = cubed->pa + cubed->fov;

	if (cubed->dirX == 1)
		*Ax = cubed->posX;
	else if (cubed->dirX == -1)
		*Ax = cubed->mapWidth - cubed->posX;
	if (cubed->dirY == 1)
		*Ay = cubed->posY;
	else if (cubed->dirY == -1)
		*Ay = cubed->mapHeight - cubed->posY;			

	while (*Ax >= 0 && pa != 0.5 * pi && pa != 1.5 * pi)
		*Ax -= cubed->widthBlock;
	if (cubed->dirX == 1)
		*Ax *= -1;
	
	while (*Ay >= 0 && pa != 0 && pa != pi)
		*Ay -= cubed->heightBlock;
	if (cubed->dirY == 1)
		*Ay *= -1;
}

bool	x_ray_is_shortest(t_cubed *cubed, double Ax, double Ay)
{
	double	pa = cubed->pa + cubed->fov;

	cubed->x_ray_length = sqrt(Ax * Ax + (Ax * sin(pa) / cos(pa)) * (Ax * sin(pa) / cos(pa)));
	cubed->y_ray_length = sqrt((Ay * cos(pa) / sin(pa)) * (Ay * cos(pa) / sin(pa)) + Ay * Ay);

	if (cubed->x_ray_length < cubed->y_ray_length)
		return (true);
	return (false);
}

void	draw_vertical(int x, int drawStart, int endStart, uint32_t color)
{
	// (void)cubed;
	// uint32_t	colorYellow = ft_pixel(255, 165, 0, 0xFF);

	int y = drawStart;

	printf("y(drawStart): %i, endStart: %i\n", y, endStart);
	while (y < endStart)
	{
		printf("test draw vertical in while loop\n");
		mlx_put_pixel(image, x, y, color);
		y++;
	}
}


// sideDistX = Ax (when first calculated)
// sideDistY = Ay (when first calculated)
// deltaDistX = blockWidth
// deltaDistY = blockHeight
void	draw_one_wall(t_cubed *cubed, double Ax, double Ay, int x)
{
	double	perpWallDist;
	double	h = cubed->screen_height;
	

	perpWallDist = 0;
	//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
	if (cubed->side == 0)
		perpWallDist = (Ax - cubed->widthBlock);
	else
	    perpWallDist = (Ay - cubed->heightBlock);

	//Calculate height of line to draw on screen
	int lineHeight = (int)(h / perpWallDist);

	//calculate lowest and highest pixel to fill in current stripe
	int drawStart = -lineHeight / 2 + h / 2;
	int drawEnd = lineHeight / 2 + h / 2;

	if (drawStart < 0)
		drawStart = 0;
	if(drawEnd >= h)
		drawEnd = (int)h - 1;

	//choose wall color
	uint32_t	colorOrange = ft_pixel(255, 140, 0, 0xFF);
	uint32_t	colorYellow = ft_pixel(255, 165, 0, 0xFF);
	uint32_t	color = 0;
	// ColorRGB color;
	// switch(worldMap[mapX][mapY])
	// {
	// case 1:  color = RGB_Red;  break; //red
	// case 2:  color = RGB_Green;  break; //green
	// case 3:  color = RGB_Blue;   break; //blue
	// case 4:  color = RGB_White;  break; //white
	// default: color = RGB_Yellow; break; //yellow
	// }

	//give x and y sides different brightness
	if (cubed->side == 1) 
		color = colorOrange;
	else
		color = colorYellow;

	//draw the pixels of the stripe as a vertical line
	draw_vertical(x, drawStart, (int)drawEnd, color);		
}

void	draw_walls(void *param)
{
	size_t	i;
	size_t	end;
	// size_t	index;
	t_cubed *cubed = param;

	i = 0;

	end = cubed->intersections_index;
	while (i < end)
	{
		// printf("i: %zu\n", i);
		// double	x = cubed->intersections[cubed->intersections_index -1].x;
		// double	y = cubed->intersections[cubed->intersections_index -1].y;
		// printf("on index %zu the coordinates are: (x: %f, y: %f)\n", cubed->intersections_index - 1, x, y);
		double	x = cubed->intersections[i].x;
		double	y = cubed->intersections[i].y;
		printf("on index %zu the coordinates are: (x: %f, y: %f)\n",i, x, y);

		draw_one_wall(cubed, cubed->Ax, cubed->Ay, i);
		i++;
	}
}

// maybe not nessecary hot check shortest hit with ray in is_hit

// INTERSECTIONS
// 1) in this function our program will spot a hit with the x-ray or y-ray (with a wall)
// 2) instead of immediately using the x- and y-coordinate in the drawPoint (for drawing 
// the orange dot in the minimap) and in the draw_wall (for drawing the wall), we want to
// save every x- and y-coordinate in a array of coordinates. I have already created a struct
// s_intersections and added this struct with pointer to s_cubed so it will function as an
// array.
// 3) in initialize_cubed I have already initialized cubed->intersections to intersections_array[1024],
// 1024 will be enough, because it is bigger then the screen width (512). And it only draws vertical lines.
// Maybe intersections_array[cubed->screen_width + 1] will also work but that is an optimization and
// not important now.
// 4) So we want to save every time we have a hit it's coordinates to the array cubed->intersections and increase
// the intersections_index variable to keep track.
// 5) when we are able to access the array of coordinates in another mlx_loop_hook we can try to draw every vertical 
// line for the coordinates in there.
// 6) if that works we must make sure that every time the hooks (A, D, W, S and the arrows left / right) are used
// cubed->intersections and cubed->intersections_index are both updated.
t_hit	is_hit(t_cubed *cubed, double Ax, double Ay, bool x_ray_is_shortest)
{
	uint32_t	colorOrange = ft_pixel(255, 140, 0, 0xFF);
	double		pa = cubed->pa + cubed->fov;
	double		x;
	double		y;
	size_t		i;

	x = 0;
	y = 0;
	i = cubed->intersections_index;
	if (i >= 100)
		return (done);
	if (x_ray_is_shortest) // if true the x-ray has a hit, that means a wall is hit horizontally
	{
		x = cubed->posX + Ax;						// x-coordinate of hit
		y = cubed->posY + Ax * sin(pa) / cos(pa);	// y-coordinate of hit
		if (checkRay(cubed, x, y)) // change name
		{
			cubed->intersections[i].x = x;
			cubed->intersections[i].y = y;
			// printf("x-ray --> on index %zu the coordinates are: (x: %f, y: %f)\n", i, x, y);
			cubed->intersections_index++;
			drawPoint(cubed, x, y, colorOrange, 4); // we want to move these to another function to draw everything at once
			// draw_wall(cubed, Ax, Ay, x);			// we want to move these to another function to draw everything at once
			cubed->side = false;
			return (x_ray_hit);
		}
	} // i < cubed->screen_width
	else // the y-ray has a hit, that means a wall is hit vertically
	{
		x = cubed->posX + Ay * cos(pa) / sin(pa);	// x-coordinate of hit
		y = cubed->posY + Ay;						// y-coordinate of hit
		if (checkRay(cubed, x, y))
		{
			cubed->intersections[i].x = x;
			cubed->intersections[i].y = y;
			// printf("y-ray --> on index %zu the coordinates are: (x: %f, y: %f)\n", i, x, y);
			cubed->intersections_index++;
			drawPoint(cubed, x, y, colorOrange, 4);	// we want to move these to another function to draw everything at once
			// draw_wall(cubed, Ax, Ay, x);			// we want to move these to another function to draw everything at once
			cubed->side = true;
			return (y_ray_hit);
		}
	}
	return (no_hit);
}

void	ray_loop(t_cubed *cubed, double Ax, double Ay, bool *hit)
{
	// uint32_t	colorGreen = ft_pixel(60, 179, 113, 0xFF);
	// uint32_t	colorPurple = ft_pixel(160, 32, 240, 0xFF);
	// double		pa = cubed->pa + cubed->fov;	
	bool		xRay_is_shortest_bool;
	t_hit		is_hit_result;

	xRay_is_shortest_bool = false;
	is_hit_result = no_hit;
	while (!(*hit))
	{
		xRay_is_shortest_bool = x_ray_is_shortest(cubed, Ax, Ay);
		is_hit_result = is_hit(cubed, Ax, Ay, xRay_is_shortest_bool);
		if (!xRay_is_shortest_bool && is_hit_result == y_ray_hit)
		{
			// printf("The y ray has a hit on coordinates x(%f) and y(%f)\n", cubed->posX + Ay * cos(pa) / sin(pa), cubed->posY + Ay);
			*hit = true;
			// printf("ray_loop --> on index %zu the coordinates are: (x: %f, y: %f)\n", cubed->intersections_index, cubed->intersections[cubed->intersections_index].x, cubed->intersections[cubed->intersections_index].y);
			return ;
		}
		else if (is_hit_result == x_ray_hit)
		{
			// printf("The x ray has a hit on coordinates x(%f) and y(%f)\n", cubed->posX + Ax, cubed->posY + Ax * sin(pa) / cos(pa));
			*hit = true;
			// printf("ray_loop --> on index %zu the coordinates are: (x: %f, y: %f)\n", cubed->intersections_index, cubed->intersections[cubed->intersections_index].x, cubed->intersections[cubed->intersections_index].y);
			return ;
		}
		if (cubed->intersections_index >= 100)
			return ;
		// drawPoint(cubed, cubed->posX, cubed->posY + Ay, colorGreen, 3);
		// drawPoint(cubed, cubed->posX + Ax, cubed->posY, colorGreen, 3);
		if (xRay_is_shortest_bool)
		{
			// drawPoint(cubed, cubed->posX + Ax, cubed->posY + Ax * sin(pa) / cos(pa), colorPurple, 2);	
			if (cubed->dirX == 1)
				Ax += cubed->widthBlock;
			else
				Ax -= cubed->widthBlock;
		}
		else
		{
			// drawPoint(cubed, cubed->posX + Ay * cos(pa) / sin(pa), cubed->posY + Ay, colorPurple, 2);
			if (cubed->dirY == 1)
				Ay += cubed->heightBlock;
			else
				Ay -= cubed->heightBlock;
		}
	}
	// printf("ray_loop --> on index %zu the coordinates are: (x: %f, y: %f)\n", cubed->intersections_index, cubed->intersections[cubed->intersections_index].x, cubed->intersections[cubed->intersections_index].y);
}

// Start direction with there corresponding pa
// NO --> cubed->pa = pi * 3 / 2
// SO --> cubed->pa = pi / 2
// WE --> cubed->pa = pi
// EA --> cubed->pa = 0

// FOV
// 30 degrees to the left --> pa -= pi / 6
// 30 degrees to the right --> pa += pi / 6

void	raycasting(void *param)
{
	bool	hit = false;
	t_cubed	*cubed = param;

	getAxAy(cubed, &cubed->Ax, &cubed->Ay);
	ray_loop(cubed, cubed->Ax, cubed->Ay, &hit);

	// INTERSECTIONS
	// we have to be able to read out cubed->intersections right here
	double	x = cubed->intersections[cubed->intersections_index -1].x;
	double	y = cubed->intersections[cubed->intersections_index -1].y;
	printf("on index %zu the coordinates are: (x: %f, y: %f)\n", cubed->intersections_index - 1, x, y);

	if (cubed->fov >= pi / 6)
		cubed->fov = pi / -6;
	else
		cubed->fov += cubed->step_size_fov;

	// printf("cubed->fov = pi / -6: %f\n", cubed->fov = pi / -6);
	// printf("cubed->fov: %f\n", cubed->fov);

	// $$$
	// if (cubed->intersections_index >= 100 && !cubed->plus30)
	// {
	// 	draw_walls(cubed);
	// 	cubed->plus30 = true;
	// }
}	

void	player(void *param)
{
	uint32_t colorYellow = ft_pixel(255, 165, 0, 0xFF);
	t_cubed	*cubed = param;
	double	player_size;
	double	visor_thickness;

	player_size = 4;
	visor_thickness = 1.5;
	int	y = 0;
	while (y < cubed->mapHeight && cubed->posY > 0 && cubed->posY < cubed->mapHeight)
	{
		int x = 0;
		while (x < cubed->mapWidth && cubed->posX > 0 && cubed->posX < cubed->mapWidth)
		{
			if ((x > cubed->posX - player_size && x < cubed->posX + player_size)
					&& (y > cubed->posY - player_size && y < cubed->posY + player_size))
			{
				mlx_put_pixel(image, x, y + cubed->mini_map_start_y, colorYellow);
				if ((x > cubed->posX - visor_thickness && x < cubed->posX + visor_thickness)
					&& (y > cubed->posY - visor_thickness && y < cubed->posY + visor_thickness))
					draw_visor(x, y + cubed->mini_map_start_y, cubed);
			}
			x++;
		}
		y++;
	}
}

void draw_screen(void* param)
{
	// t_cubed	*cubed;

	// cubed = param;
	draw_floor_and_ceiling(param);
	mini_map(param);
	player(param);
	raycasting(param);
	// draw_walls(cubed);
}

void ft_hook(void* param)
{
	t_cubed	*cubed;

	cubed = param;

	if (mlx_is_key_down(cubed->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cubed->mlx);
	if (mlx_is_key_down(cubed->mlx, MLX_KEY_W)) // move forward (zoom isn)
	{
		if (cubed->posX < cubed->mapWidth - cubed->pdx && cubed->posY < cubed->mapHeight - cubed->pdy) 
		{
			cubed->posX += cubed->pdx;
			cubed->posY += cubed->pdy;

		}
		cubed->fov = pi / -6;
		cubed->intersections_index = 0;
	}
	if (mlx_is_key_down(cubed->mlx, MLX_KEY_S)) // move backward (zoom out)
	{
		if (cubed->posX >= 0 + cubed->pdx && cubed->posY >= 0 + cubed->pdy)
		{
			cubed->posX -= cubed->pdx;
			cubed->posY	-= cubed->pdy;
		}
		cubed->fov = pi / -6;
		cubed->intersections_index = 0;
	}
	// if (mlx_is_key_down(cubed->mlx, MLX_KEY_A)) // move to the left (change position in map)
	// {
	// }
	// if (mlx_is_key_down(cubed->mlx, MLX_KEY_D)) // move to the right (change position in map)
	// {
	// }
	if (mlx_is_key_down(cubed->mlx, MLX_KEY_LEFT)) // change screen to the left
	{
		cubed->pa -= 0.05;
		if (cubed->pa < 0)
			cubed->pa += 2 * pi;
		cubed->pdx = cos(cubed->pa)	* 2;
		cubed->pdy = sin(cubed->pa) * 2;
		cubed->fov = pi / -6;
		cubed->intersections_index = 0;
	}
	if (mlx_is_key_down(cubed->mlx, MLX_KEY_RIGHT)) // change screen to the right
	{
		cubed->pa += 0.05;
		if (cubed->pa > 2 * pi)
			cubed->pa -= 2 * pi;
		cubed->pdx = cos(cubed->pa)	* 2;
		cubed->pdy = sin(cubed->pa) * 2;
		cubed->fov = pi / -6;
		cubed->intersections_index = 0;
	}
}

bool	initialize_cubed(t_cubed *cubed)
{
	t_intersections	intersections_array[1024];

	cubed->posX = 33;
	cubed->posY = 33;
	cubed->dirX = -1.0;
	cubed->dirY = -1.0;
	cubed->screen_width = 800;
	cubed->screen_height = 800;
	cubed->mapWidth = 150;
	cubed->mapHeight = 150;
	cubed->mini_map_start_y = cubed->screen_height - cubed->mapHeight;
	cubed->pa = pi / 6;
	cubed->fov = pi / -6;
	cubed->pdx = 0;
	cubed->pdy = 0;
	cubed->widthBlock = cubed->mapWidth / (double)row;
	cubed->heightBlock = cubed->mapHeight / (double)column;
	cubed->plus30 = false;
	cubed->x_ray_length = 0;
	cubed->y_ray_length = 0;
	cubed->side = false;
	cubed->Ax = 0; // length_till_x_axis
	cubed->Ay = 0; // length_till_y_axis
	cubed->intersections = intersections_array;
	cubed->intersections_index = 0;
	cubed->step_size_fov = 0.01;
	return (true);
}

int32_t main(void)
{
	t_cubed	cubed;
	
	if (!initialize_cubed(&cubed))
		return (1);

	if (!(cubed.mlx = mlx_init(cubed.screen_width, cubed.screen_height, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	
	if (!(image = mlx_new_image(cubed.mlx, cubed.screen_width, cubed.screen_height)))
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

	mlx_loop_hook(cubed.mlx, draw_screen, &cubed);
	// mlx_loop_hook(cubed.mlx, mini_map, &cubed);
	// mlx_loop_hook(cubed.mlx, player, &cubed);
	// mlx_loop_hook(cubed.mlx, raycasting, &cubed);
	// mlx_loop_hook(cubed.mlx, draw_walls, &cubed);

	// INTERSECTIONS
	// I also think we have to be able to read out cubed->intersections here

	mlx_loop_hook(cubed.mlx, ft_hook, &cubed);

	mlx_loop(cubed.mlx);
	mlx_terminate(cubed.mlx);
	return (EXIT_SUCCESS);
}
