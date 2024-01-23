#include "../../include/cubed.h"

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

// void draw_color_stripe(int32_t startX, int32_t endX, int32_t startY, int32_t endY, uint32_t color)
// {
// 	int32_t	y;
// 	int32_t	x;

// 	y = startY;
// 	while (y < endY)
//     {
// 		x = startX;
//        while(x < endX)
//         {
//             mlx_put_pixel(image, x, y, color);
// 			x++;
//         }
// 		y++;
// 	}
// }