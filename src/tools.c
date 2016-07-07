/*
** tools.c for  in /home/soussa_y/rendu/CPE_2015_BSQ
**
** Made by yoram soussan
** Login   <soussa_y@epitech.net>
**
** Started on  Sun Dec 20 23:10:22 2015 yoram soussan
** Last update Sun Dec 20 23:10:24 2015 yoram soussan
*/

#include <unistd.h>
#include "../include/my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	s;

  s = 0;
  while (str[s] != '\0')
    {
      my_putchar(str[s]);
      s++;
    }
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}

int	is_neg(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while ((str[i] > '9' || str[i] < '0') && str[i] != '\n' && str[i] != '\0')
    {
      if (str[i] == '-')
	j = j + 1;
      i = i + 1;
    }
  if (j % 2 == 0)
    return (1);
  else
    return (-1);
}

int	my_getnbr(char *str)
{
  int	i;
  int	n;

  n = 0;
  i = 0;
  while ((str[i] < '0' || str[i] > '9')
	 && str[i] != '\n' && str[i] != '\0' && str[i])
    i = i + 1;
  while (str[i] >= '0' && str[i] <= '9'
	 && str[i] != '\n' && str[i] != '\0' && str[i])
    {
      n = n * 10 + str[i] - 48;
      i = i + 1;
    }
  return (n * is_neg(str));
}
