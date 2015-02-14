/*
** mysh.c for mysh in 
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Wed Jan 21 11:52:59 2015 michael besnainou
** Last update Sun Feb  1 23:21:48 2015 michael besnainou
*/

#include <stdlib.h>
#include <signal.h>
#include "include/my.h"

void		cmp_login(char **env, t_con *con)
{
  con->verif.u = 0;
  con->verif.un = 0;
  con->verif.ln = 0;
  if (my_strncmp(con->string.str, env[con->stru.i], 5) == 0)
    {
      con->stru.a = con->stru.a + 1;
      con->verif.u = con->verif.u + 1;
    }
  else if (my_strncmp(con->string.str2, env[con->stru.i], 9) == 0)
    {
      con->stru.a = con->stru.a + 1;
      con->verif.un = con->verif.un + 1;
    }
  else if (my_strncmp(con->string.str3, env[con->stru.i], 8) == 0)
    {
      con->stru.a = con->stru.a + 1;
      con->verif.ln = con->verif.ln + 1;
    }
}

void		check_user(char **env, t_con *con)
{
  if (con->verif.u == 1)
    my_putstr(&env[con->stru.i - 1][5]);
  else if (con->verif.un == 1)
    my_putstr(&env[con->stru.i - 1][9]);
  else if (con->verif.ln == 1)
    my_putstr(&env[con->stru.i - 1][8]);
}

int		prompt(char **env, t_con *con)
{
  con->stru.a = 0;
  con->stru.i = 0;
  con->string.str = "USER=";
  con->string.str2 = "USERNAME=";
  con->string.str3 = "LOGNAME=";
  while (env[con->stru.i] != NULL && con->stru.a == 0)
    {
      cmp_login(env, con);
      con->stru.i = con->stru.i + 1;
    }
  my_putstr(TEXT_COLOR_BLUE);
  check_user(env, con);
  my_putstr(TEXT_COLOR_WHITE);
  my_putstr(" - ");
  my_putstr(TEXT_COLOR_RED);
  my_putstr("$> ");
  my_putstr(TEXT_COLOR_WHITE);
  return (0);
}

int		init(char **env, t_con *con)
{
  char		*s;

  prompt(env, con);
  while ((s = get_next_line(0)))
    {
      con->stru.argv_tab = my_str_to_wordtab(s);
      get_path(env, con);
      prompt(env, con);
    }
  return (0);
}

int		main(int argc, char **argv, char **env)
{
  t_con		*con;

  (void)argc;
  (void)argv;
  gere_empty_env(env);
  con = malloc(sizeof(t_con));
  con->stru.path = malloc(sizeof(*con->stru.path)* 1000);
  if (con == NULL || con->stru.path == NULL)
    return (2);
  signal(SIGINT, gere_ctrl_c);
  con->stru.j = 0;
  init(env, con);
  free(con);
  free(con->stru.path);
  return (0);
}
