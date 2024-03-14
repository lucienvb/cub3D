#include "../../include/cubed.h"

static t_hit    is_hit_validate(t_cubed *c, double x,
    bool x_ray_is_shortest)
{
    if (x_ray_is_shortest)
    {
        if (c->map[c->mapY][c->mapX + (int)c->dirX] == '1')
        {
            c->percentage_wall_width = fmod(x, 40) / 40;
            c->side = true;
            return (x_ray_hit);
        }
    }
    else
    {
        if (c->map[c->mapY + (int)c->dirY][c->mapX] == '1')
        {
            c->percentage_wall_width = fmod(x, 40) / 40;
            c->side = false;
            return (y_ray_hit);
        }
    }
    return (no_hit);
}
t_hit   is_hit(t_cubed *c, double player_to_grid_x,
    double player_to_grid_y, bool x_ray_is_shortest)
{
    double  pa;
    double  x;
    double  y;

    pa = c->pa + c->fov;
    x = 0;
    y = 0;
    if (x_ray_is_shortest)
    {
        x = ((c->posX + player_to_grid_x) * c->grid_width);
		y = ((c->posY + player_to_grid_x * sin(pa) / cos(pa)) * c->grid_height);
        return (is_hit_validate(c, y, x_ray_is_shortest));
    }
    else
    {
        x = ((c->posX + player_to_grid_y * cos(pa) / sin(pa)) * c->grid_width);
		y = ((c->posY + player_to_grid_y) * c->grid_height);
        return (is_hit_validate(c, x, x_ray_is_shortest));
    }
}