/*
** my.h for my_h in /home/besnai_m/rendu/C-Prog ELEM/CPE_2014_bsq/include
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Mon Jan 12 13:50:46 2015 michael besnainou
** Last update Sun Feb  1 23:34:41 2015 michael besnainou
*/
#ifndef			MY_H_
# define		MY_H_
# define		TEXT_COLOR_BLUE		"\033[34m"
# define		TEXT_COLOR_WHITE	"\033[00m"
# define		TEXT_COLOR_RED		"\033[31m"

typedef struct		s_struct
{
  char			**path_tab;
  char			**argv_tab;
  char			*path;
  int			i;
  int			j;
  int			a;
  int			z;
}			t_struct;

typedef struct		s_string
{
  char			*str;
  char			*str2;
  char			*str3;
  char			*str4;
  char			*str5;
}			t_string;

typedef struct		s_verif
{
  int			u;
  int			un;
  int			ln;
}			t_verif;

typedef struct		s_con
{
  t_struct		stru;
  t_verif		verif;
  t_string		string;
}			t_con;

void			my_putchar(char c);
void			my_putstr(char *str);
void			my_putstr_error(char *str);
int			my_strlen(char *str);
int			my_put_nbr(int nb);
int			my_strncmp(char *s1, char *s2, int n);
char			*my_strcatdup(char *src, char *dst);
char			*my_strcat(char *dest, char *src);
char			*get_next_line(const int fd);
char			**my_str_to_wordtab(char *str);
void			check_wordtab(char *tab, int max, char *str, int min);
int			prompt(char **env, t_con *con);
int			init(char **env, t_con *con);
void			check_user(char **env, t_con *con);
void			cmp_login(char **env, t_con *con);
void			get_path(char **env, t_con *con);
void			gere_path_functions(char **env, t_con *con);
void			gere_exit(t_con *con);
void			gere_cd(t_con *con);
void			gere_ctrl_c();
void			gere_empty_env(char **env);

#endif			/* !MY_H_ */
