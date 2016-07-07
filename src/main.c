/*
** main.c for  in /home/soussa_y/rendu/CPE_2015_BSQ
**
** Made by yoram soussan
** Login   <soussa_y@epitech.net>
**
** Started on  Sun Dec 20 23:08:51 2015 yoram soussan
** Last update Wed Jan 13 19:47:37 2016 yoram soussan
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include "../include/bsq.h"
#include "../include/my.h"

void    print_my_map_i(char **map, int *i, int x, int y)
{
  while (*i < x)
    {
      write(1, map[(*i)++], y);
      my_putchar('\n');
    }
}

void    print_my_map(char **map, t_pt2 *coin, t_pt2 *dim)
{
  int   i;
  int   j;

  i = 0;
  if (coin->x == 0 && coin->y == 0 && coin->val == 0)
    print_my_map_i(map, &i, dim->x, dim->y);
  print_my_map_i(map, &i, coin->x, dim->y);
  while (i >= coin->x && i <= coin->x + coin->val - 1)
    {
      j= -1;
      while (++j < dim->y)
	if ((j <= coin->y + coin->val - 1) && (j >= coin->y))
	  my_putchar('x');
	else
	  my_putchar(map[i][j]);
      my_putchar('\n');
      i++;
    }
  print_my_map_i(map, &i, dim->x, dim->y);
}

int	print_map_vide(char **map, int index, int count)
{
  int	save;
  int	i;
  int	j;

  save = (index < count ? index : count);
  i = 0;
  while (map[i])
    {
      j = 0;
      while (map[i][j])
	{
	  if (i < save && j < save)
	    my_putchar('x');
	  else
	    my_putchar('.');
	  j++;
	}
      my_putchar('\n');
      i++;
    }
  return (0);
}

int	verif_map(char **map, int index, int nb, int count)
{
  while (map[index])
    {
      count = 0;
      while (map[index][count])
	{
	  if (map[index][count] == 'o')
	    nb = nb + 1;
	  if (map[index][count] != '.' && map[index][count] != 'o')
	    return (my_map_error());
	  count = count + 1;
	}
      index = index + 1;
    }
  if (index == 0 && count == 0)
    return (my_map_error());
  if (nb == 0)
    return (print_map_vide(map, index, count));
  return (analyse_map(map, index, count));
}

int	main(int argc, char **argv)
{
  int	index;
  int	nb_line;
  int	fd;
  char	**map;
  char	*line;

  if ((my_error(argc)) == -1)
    return (-1);
  index = 0;
  if ((fd = open(argv[1], O_RDONLY)) == -1)
    return (my_error2("Error : failed to open map\n"));
  if ((line = recup_ligne(fd)) == NULL)
    return (my_map_error());
  if ((nb_line = my_getnbr(line)) <= 0)
    return (my_map_error());
  if ((map = malloc(sizeof(char *) * (nb_line + 1))) == NULL)
    return (my_malloc_error());
  while (index != nb_line)
    if ((map[index++] = recup_ligne(fd)) == NULL)
      return (my_map_error());
  if (recup_ligne(fd) != NULL)
    return (my_map_error());
  if (close(fd) == -1)
    return (my_error2("Error : failed to close map\n"));
  return (verif_map(map, 0, 0, 0));
}
