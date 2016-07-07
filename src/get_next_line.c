/*
** get_next_line.c for  in /home/soussa_y/rendu/CPE_2015_BSQ
**
** Made by yoram soussan
** Login   <soussa_y@epitech.net>
**
** Started on  Sun Dec 20 23:09:37 2015 yoram soussan
** Last update Sun Dec 20 23:24:38 2015 yoram soussan
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/bsq.h"

char		*alldone(char *line, int len)
{
  static int	laps;

  if (len == 0)
    return (NULL);
  if (laps == 0)
    {
      laps = 1;
      return (line);
    }
  else
    return (NULL);
}

char		*my_realloc(char *line, int len)
{
  int		i;
  char		*bigger_line;

  i = 0;
  if (len == 0 && ((line = malloc(BUFFSIZE + 1)) == NULL))
    return (NULL);
  if (len == 0)
    return (line);
  if ((bigger_line = malloc(len + BUFFSIZE + 1)) == NULL)
    return (NULL);
  while (i <= len)
    {
      bigger_line[i] = line[i];
      i = i + 1;
    }
  bigger_line[i] = '\0';
  free(line);
  return (bigger_line);
}

char		*recup_ligne(const int fd)
{
  static int	i;
  static char	buffer[BUFFSIZE];
  static int	j;
  static int	red;
  static char	*line;

  if (i == 0 && (red = read(fd, buffer, BUFFSIZE)) == 0)
    return (alldone(line, j));
  if ((line = my_realloc(line, j)) == NULL)
    return (NULL);
  while (i < red)
    {
      if (buffer[i] == '\n')
	{
	  i = i + 1;
	  line[j] = '\0';
	  j = 0;
	  return (line);
	}
      line[j] = buffer[i];
      i = i + 1;
      j = j + 1;
    }
  i = 0;
  return (recup_ligne(fd));
}
