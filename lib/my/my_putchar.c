/*
** my_putchar.c for my_putchar.c in /home/besnai_m/rendu/C-Prog ELEM/CPE_2014_bsq/lib/my
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Mon Jan 12 13:54:13 2015 michael besnainou
** Last update Mon Jan 12 13:54:33 2015 michael besnainou
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
