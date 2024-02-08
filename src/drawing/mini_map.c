#include "../../include/cubed.h"

static int worldMap[column][row]=
{
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 0, 0, 0, 1},
	{1, 0, 0, 1, 1, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1}
};

// static int worldMap[column][row]=
// {
// 	{1, 1, 1, 1, 1, 1, 1, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 1, 1, 0, 1},
// 	{1, 0, 0, 0, 0, 1, 0, 1},
// 	{1, 0, 0, 0, 0, 1, 0, 1},
// 	{1, 0, 1, 1, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 1, 1, 1, 1, 1, 1, 1}
// };

// static int worldMap[column][row]=
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

static void	draw_visor(int x, int y, t_cubed *cubed)
{
	uint32_t	colorPurple = ft_pixel(106, 90, 205, 0xFF);
	double		pa;
	int	line;
	
	pa = cubed->pa;
	line = 15;
	while (line > 0)
	{
		mlx_put_pixel(cubed->image, x + cos(pa) * line, y + sin(pa) * line, colorPurple);
		line--;
	}
}

static void	player(t_cubed *cubed)
{
	uint32_t colorGreen = ft_pixel(60, 179, 113, 0xFF);
	double	player_size;
	double	visor_thickness;
	double	player_posX;
	double	player_posY;

	// player_posX = cubed->posX * cubed->multiplier_mini_map_x;
	// player_posY = cubed->posY * cubed->multiplier_mini_map_y;
	// player_posX = cubed->posX / column * cubed->mini_map_width;
	// player_posY = cubed->posY / row * cubed->mini_map_height;
	player_posX = cubed->posX * cubed->grid_width;
	player_posY = cubed->posY * cubed->grid_height;

	// printf("pos (%f, %f)\n", cubed->posX, cubed->posY);
	// printf("player_pos (%f, %f)\n", player_posX, player_posY);

	player_size = 4;
	visor_thickness = 1.5;
	int	y = 0;
	while (y < cubed->mini_map_height && player_posY > 0 && player_posY < cubed->mini_map_height)
	{
		int x = 0;
		while (x < cubed->mini_map_width && player_posX > 0 && player_posX < cubed->mini_map_width)
		{
			if ((x > player_posX - player_size && x < player_posX + player_size)
					&& (y > player_posY - player_size && y < player_posY + player_size))
			{
				mlx_put_pixel(cubed->image, x, y + cubed->mini_map_start_y, colorGreen);
				if ((x > player_posX - visor_thickness && x < player_posX + visor_thickness)
					&& (y > player_posY - visor_thickness && y < player_posY + visor_thickness))
					draw_visor(x, y + cubed->mini_map_start_y, cubed);
			}
			x++;
		}
		y++;
	}
}

static void	draw_black_background(t_cubed *cubed)
{
	uint32_t	colorBlack;
	uint32_t	colorBlue;
	size_t		x;
	size_t		y;
	
	colorBlack = ft_pixel(0, 0, 0, 0xFF);
	colorBlue = ft_pixel(52, 126, 133, 0xFF);

	y = cubed->screen_height - cubed->mini_map_height;
	while (y < cubed->screen_height)
	{
		x = 0;
		while (x < cubed->mini_map_width)
		{
			if (y == cubed->screen_height - cubed->mini_map_height || 
					y == cubed->screen_height -1 || x == 0 ||
					x == cubed->mini_map_width -1)
				mlx_put_pixel(cubed->image, x, y, colorBlue);
			else
				mlx_put_pixel(cubed->image, x, y, colorBlack);
			x++;
		}
		y++;
	}
}

// TO DO: does not work perfectly on all maps
void	mini_map(t_cubed *cubed)
{
	// uint32_t colorBlack = ft_pixel(0, 0, 0, 0xFF);
	uint32_t colorLightGrey = ft_pixel(218, 223, 225, 0xFF);
	int	y;
	int	border;

	border = 1;
	y = 0;

	double	stepY = cubed->grid_width;
	double	stepX = cubed->grid_height;
	double	startY = cubed->screen_height - cubed->mini_map_height;
	double	endY = startY + stepY;
	int		scope = 3;
	int		tempPosY = (int)cubed->posY - scope;
	

	printf("pos (%f, %f)\n", cubed->posX, cubed->posY);

	draw_black_background(cubed);
	while (y < (int)column && y >= (int)cubed->posY - scope && y <= (int)cubed->posY + scope)
	{
		printf("%d < %d < %d ||\t", (int)cubed->posY - scope, y, (int)cubed->posY + scope);
		int	startX = 0;
		int endX = stepX;
		int x = 0;
		while (x < (int)row && x >= (int)cubed->posX - scope && x <= (int)cubed->posX + scope)
		{
			if (worldMap[y][x] == 1)
			{
				draw_color_stripe((int) startX + border, (int) endX - border, (int) startY + border, 
					(int) endY - border, colorLightGrey, cubed);
			}
			startX = endX;
			endX += stepX;
			x++;
		}
		startY = endY;
		endY += stepY;
		y++;
	}
	player(cubed);
}