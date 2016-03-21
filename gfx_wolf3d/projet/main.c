/*
** main.c for main in /home/menett_a/Modules/infographie/colle_fin_module/gfx_colle_fantasy1
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Mon Dec 21 14:12:21 2015 Nicolas Menettrier
** Last update Wed Jan  6 14:38:19 2016 Nicolas Menettrier
*/

#include <lapin.h>
#include <math.h>
#include "include/struct.h"
#include "include/proto.h"

void	init_character(t_data *world)
{

  world->player.posx = world->map.start[0];
  world->player.posy = world->map.start[1];
  world->player.angle = world->map.start[2];
  world->color.argb[0] = 238;
  world->color.argb[1] = 16;
  world->color.argb[2] = 16;
}

t_bunny_response	key_rsp(t_bunny_event_state event,
				t_bunny_keysym key,
				void *data)
{
  t_data		*world;
  float			x;
  float			y;

  world = data;
  if (event == GO_DOWN && key == BKS_Q)
    world->player.angle = world->player.angle - 2;
  if (event == GO_DOWN && key == BKS_D)
    world->player.angle = world->player.angle + 2;
  if (event == GO_DOWN && key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  if (event == GO_DOWN && key == BKS_E)
    erase_wall(world, world->player.angle);
  move(event, key, world);
  if (world->player.angle < 0)
    world->player.angle = world->player.angle + 360;
  if (world->player.angle > 360)
    world->player.angle = 0;
  return (GO_ON);
}

t_bunny_response	main_loop(t_data *pic)
{
  bunny_set_key_response(key_rsp);
  noise_color_full(pic->pix, BLACK);
  raycasting(pic);
  put_cursor(pic);
  bunny_blit(&pic->win->buffer, &pic->pix->clipable, NULL);
  bunny_display(pic->win);
  return (GO_ON);
}

int		main(int argc, char **argv)
{
  t_data	data;
  char		*error;

  data.win = bunny_start(1200, 1000, false, "WOLF");
  data.pix = bunny_new_pixelarray(1200, 1000);
  error = NULL;
  if (argc < 2)
    return (1);
  if ((error = get_wolf(&data, argv[1])) != NULL)
    {
      my_putstr(error);
      return (1);
    }
  init_character(&data);
  bunny_set_loop_main_function((t_bunny_loop)main_loop);
  bunny_loop(data.win, 30, &data);
  bunny_delete_clipable(&data.pix->clipable);
  bunny_stop(data.win);
  return (0);
}
