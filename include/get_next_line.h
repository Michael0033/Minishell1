/*
** get_next_line.h for get_next_line.h in /home/besnai_m/rendu/CPE_2014_get_next_line
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Sun Nov 23 16:13:18 2014 michael besnainou
** Last update Sun Jan 18 22:27:23 2015 michael besnainou
*/

#ifndef		GET_NEXT_LINE_H_
# define	GET_NEXT_LINE_H_
#  define	BUFFER_SIZE 1

typedef struct	s_struct
{
  char		*line;
  int		n;
  int		m;
}	       	t_struct;

char		*get_next_line(const int fd);

#endif		/* !GET_NEXT_LINE_H */
