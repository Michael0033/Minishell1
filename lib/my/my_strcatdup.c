/*
** my_strcatdup.c for my_strcatcdup.c in 
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Tue Jan 27 14:58:36 2015 michael besnainou
** Last update Sun Feb  1 18:28:16 2015 michael besnainou
*/

#include <stdlib.h>
#include "../../include/my.h"

char		*my_strcatdup(char *src, char *dst)
{
  char		*str;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if ((str = malloc(sizeof(char) * (my_strlen(src) + my_strlen(dst) + 2)))
      == NULL)
    exit(1);
  while (src[i] != '\0')
    {
      str[j] = src[i];
      i = i + 1;
      j = j + 1;
    }
  str[j++] = '/';
  i = 0;
  while (dst[i] != '\0')
    {
      str[j] = dst[i];
      i = i + 1;
      j = j + 1;
    }
  str[j] = '\0';
  return (str);
}

