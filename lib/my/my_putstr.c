/*
** my_putstr.c for my_putstr.c in /home/besnai_m/rendu/C-Prog ELEM/CPE_2014_bsq/lib/my
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Mon Jan 12 13:54:42 2015 michael besnainou
** Last update Sun Jan 18 22:19:33 2015 michael besnainou
*/

#include <unistd.h>

void	my_putstr(char *str)
{
  while (*str)
    write(1, str++, 1);
}
