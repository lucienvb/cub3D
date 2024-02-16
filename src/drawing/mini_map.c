#include "../../include/cubed.h"

// static int worldMap[column][row]=
// {
// 	{1, 1, 1, 1, 1, 1, 1, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 1, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 1, 0, 1},
// 	{1, 0, 0, 0, 0, 1, 0, 1},
// 	{1, 0, 1, 0, 0, 0, 0, 1},
// 	{1, 0, 1, 1, 0, 0, 0, 1},
// 	{1, 0, 0, 1, 1, 0, 0, 1},
// 	{1, 0, 0, 0, 1, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 1, 1, 1, 1, 1, 1, 1}
// };

// static int worldMap[column][row]=
// {
// 	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
// };

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

static int worldMap[column][row]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

static void	draw_visor(int x, int y, t_cubed *cubed)
{
	uint32_t	colorPurple = ft_pixel(106, 90, 205, 0xFF);
	double		pa;
	int	line;
	
	pa = cubed->pa;
	line = 15;
	while (line > 0)
	{
		mlx_put_pixel(cubed->image_game, x + cos(pa) * line, y + sin(pa) * line, colorPurple);
		line--;
	}
}

void	clean_screen(t_cubed *cubed)
{
	double		mini_map_surface;
	uint32_t	colorTransparent;
	size_t		x;
	size_t		y;

	colorTransparent = ft_pixel(0, 0, 0, 0);
	mini_map_surface = cubed->mini_map_size * cubed->grid_width;
	y = 0;
	while (y < cubed->screen_height)
	{
		x = 0;
		while (x < cubed->screen_width)
		{
			if (x < mini_map_surface && y < mini_map_surface)
				mlx_put_pixel(cubed->image_game, x, y, colorTransparent);
			else if (x < cubed->screen_width - 1 && y < cubed->screen_height / 2 - 1)
				mlx_put_pixel(cubed->image_game, x, y, ft_pixel(255, 243, 231, 0xFF));
			else
				mlx_put_pixel(cubed->image_game, x, y, ft_pixel(255, 0, 0, 0xFF));
			x++;
		}
		y++;
	}
}

void	draw_player_mini_map(t_cubed *cubed)
{
	size_t	x;
	size_t	y;
	double	player_size = 4;
	uint32_t colorGreen;
	
	colorGreen = ft_pixel(60, 179, 113, 0xFF);

	y = cubed->mini_map_middle - player_size;
	while (y < cubed->mini_map_middle + player_size)
	{
		x = cubed->mini_map_middle - player_size;
		while (x < cubed->mini_map_middle + player_size)
		{
			mlx_put_pixel(cubed->image_game, x, y, colorGreen);
			double	visor_thickness = 1.5;
			if ((x > cubed->mini_map_middle - visor_thickness && x < cubed->mini_map_middle + visor_thickness) &&
					(y > cubed->mini_map_middle - visor_thickness && y < cubed->mini_map_middle + visor_thickness))
					draw_visor(x, y, cubed);
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

	y = 0;
	while (y < cubed->mini_map_height)
	{
		x = 0;
		while (x < cubed->mini_map_width)
		{
			if (x == 0 || x == cubed->mini_map_width -1 || 
				y == 0 || y == cubed->mini_map_height -1)
				mlx_put_pixel(cubed->image, x, y, colorBlue);
			else
				mlx_put_pixel(cubed->image, x, y, colorBlack);
			x++;
		}
		y++;
	}
}

void	mini_map(t_cubed *cubed)
{
	uint32_t colorLightGrey = ft_pixel(218, 223, 225, 0xFF);
	int	y;
	int	border;
	double	stepX;
	double	stepY;
	double	startY;
	double	endY;

	border = 1;
	y = 0;
	stepY = cubed->grid_width;
	stepX = cubed->grid_height;
	startY = 0;
	endY = startY + stepY;
	draw_black_background(cubed);
	while (y < (int)column)
	{
		int	startX = 0;
		int endX = stepX;
		int x = 0;
		while (x < (int)row)
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
}