/*
** my_strlen.c for my_strlen.c in /home/besnai_m/rendu/C-Prog ELEM/CPE_2014_bsq/lib/my
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Mon Jan 12 13:55:25 2015 michael besnainou
** Last update Mon Jan 12 13:56:26 2015 michael besnainou
*/

#include "../../include/my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}
