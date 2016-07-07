/*
** my_error.c for  in /home/soussa_y/rendu/CPE_2015_BSQ
**
** Made by yoram soussan
** Login   <soussa_y@epitech.net>
**
** Started on  Sun Dec 20 23:10:07 2015 yoram soussan
** Last update Mon Dec 21 22:27:25 2015 yoram soussan
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/bsq.h"

int     my_error(int argc)
{
  if (argc != 2)
    {
      my_puterror("Error : Please select one map\n", 31);
      return (-1);
    }
  return (0);
}

int	my_malloc_error()
{
  my_puterror("Error : malloc\n", 16);
  return (-1);
}

int	my_map_error()
{
  my_puterror("Error : invalid map\n", 22);
  return (-1);

}

int	my_error2(char *str)
{
  my_puterror(str, my_strlen(str));
  return (-1);
}

void	my_puterror(char *str, int size)
{
  (void)write(2, str, size);
  exit(EXIT_FAILURE);
}
