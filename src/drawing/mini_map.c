#include "../../include/cubed.h"
// #include "../../lib/MLX42/include/MLX42/MLX42.h"

// static void	draw_visor(int x, int y, t_cubed *cubed)
// {
// 	uint32_t	colorYellow = ft_pixel(255, 165, 0, 0xFF);
// 	double		pa;
// 	int	line;
	
// 	pa = cubed->pa;
// 	line = 15;
// 	while (line > 0)
// 	{
// 		mlx_put_pixel(image, x + cos(pa) * line, y + sin(pa) * line, colorYellow);
// 		line--;
// 	}
// }

// static void	player(void *param)
// {
// 	uint32_t colorYellow = ft_pixel(255, 165, 0, 0xFF);
// 	t_cubed	*cubed = param;
// 	double	player_size;
// 	double	visor_thickness;

// 	player_size = 4;
// 	visor_thickness = 1.5;
// 	int	y = 0;
// 	while (y < cubed->mapHeight && cubed->posY > 0 && cubed->posY < cubed->mapHeight)
// 	{
// 		int x = 0;
// 		while (x < cubed->mapWidth && cubed->posX > 0 && cubed->posX < cubed->mapWidth)
// 		{
// 			if ((x > cubed->posX - player_size && x < cubed->posX + player_size)
// 					&& (y > cubed->posY - player_size && y < cubed->posY + player_size))
// 			{
// 				mlx_put_pixel(image, x, y + cubed->mini_map_start_y, colorYellow);
// 				if ((x > cubed->posX - visor_thickness && x < cubed->posX + visor_thickness)
// 					&& (y > cubed->posY - visor_thickness && y < cubed->posY + visor_thickness))
// 					draw_visor(x, y + cubed->mini_map_start_y, cubed);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void mini_map(void *param)
// {
// 	uint32_t colorBlack = ft_pixel(0, 0, 0, 0xFF);
// 	uint32_t colorWhite = ft_pixel(255, 255, 255, 0xFF);
// 	t_cubed	*cubed = param;

// 	int	y = 0;
// 	int	stepY = cubed->mapHeight / column;
// 	int stepX = cubed->mapWidth / row;
// 	int	startY = cubed->screen_height - cubed->mapHeight;
// 	int	endY = startY + stepY;
// 	while (y < (int)column)
// 	{
// 		int	startX = 0;
// 		int endX = stepX;
// 		int x = 0;
// 		while (x < (int)row)
// 		{
// 			if (worldMap[y][x] == 0)
// 			{
// 				draw_color_stripe(startX, endX, startY, endY, colorBlack);
// 			}
// 			else if (worldMap[y][x] == 1)
// 			{
// 				draw_color_stripe(startX+1, endX-1, startY+1, endY-1, colorWhite);
// 			}
// 			startX = endX;
// 			endX += stepX;
// 			x++;
// 		}
// 		startY = endY;
// 		endY += stepY;
// 		y++;
// 	}
// 	player(param);
// }

// void	draw_floor_and_ceiling(t_cubed *cubed)
// {
// 	uint32_t colorBrown = ft_pixel(139, 69, 19, 0xFF);
// 	uint32_t colorPurple = ft_pixel(160, 32, 240, 0xFF);

// 	draw_color_stripe(0, cubed->screen_width - 1, 0, cubed->screen_height / 2 - 1, colorPurple);
// 	draw_color_stripe(0, cubed->screen_width - 1, cubed->screen_height / 2 - 1, cubed->screen_height - 1, colorBrown);
// }