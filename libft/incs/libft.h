/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodauga <leodauga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:28:25 by ldauga            #+#    #+#             */
/*   Updated: 2021/05/17 14:08:40 by leodauga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <time.h>
# include <math.h>

typedef struct s_list
{
	int 			content;
	int				rank;
	struct s_list	*next;
}				t_list;

int				ft_atoi(char *str);
char			*ft_itoa(int n);
int				ft_atoi_base(char *str, char *base);
char			*ft_convert_base(char *nbr, char *base_from, char *base_to);
int				ft_len(int nbr, char *base);
void			ft_putnbr_base(int nbr, char *base, char *retour, int i);
char			*retour(int nbr, char *base_to);

int				ft_open_files(char *str);
int				ft_close_files(int fd);

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_ischar(char *str, int c);

void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, void *src, size_t n);
void			*ft_memccpy(void *dst, void *src, int c, size_t n);
void			*ft_memmove(void *dst, void *src, size_t len);
void			*ft_memchr(void *s, int c, size_t n);
int				ft_memcmp(void *s1, void *s2, size_t n);

char			*ft_strchr(char *s, int c);
size_t			ft_strlcat(char *dst, char *src, size_t dstsize);
size_t			ft_strlcpy(char *dest, char *src, size_t dstsize);
size_t			ft_strlen(char *s);
int				ft_strncmp(char *s1, char *s2, size_t n);
char			*ft_strrchr(char *str, int c);
char			*ft_strdup(char *s1);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strtrim(char *s1, char *set);
char			**ft_split(char *str, char charset);
char			*ft_strmapi(char *s, char (*f)(unsigned int, char));
char			*ft_strnstr(char *str, char *to_find, size_t len);
int				ft_strnchr(char *str, int c, size_t n);
char			*ft_strcat(char *s1, char *s2);
char			*ft_strcatchar(char *s1, int c);

int				ft_tolower(int c);
int				ft_toupper(int c);

void			ft_dellst_back(t_list **list);
void			ft_dellst_front(t_list **list);
void			ft_dellst_one(t_list **list, int i);
void			ft_lstadd_back(t_list **list, int valeur);
void			ft_lstadd_front(t_list **list, int valeur);
void			ft_lstaff(t_list *list);
void			ft_lstaff_color(t_list *list, char *color);
void			ft_lstclear(t_list **lst);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstn(t_list *lst, int n);
int				ft_lstsize(t_list *lst);

int				get_next_line(int fd, char **line);
void			gnl_ft_strcpy(char *line, char *buffer, int len, int save);
int				gnl_ft_strlen(char *buffer, int save);
char			*gnl_ft_strjoin(char *line, char *buffer, int len, int save);

void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			*ft_realloc(char *src, int size);

int				ft_rand_in_range(int lower, int upper);
int				ft_rand_percent(int nb1, int percent_nb1, int nb2);
void			ft_swap(int *a, int *b);

void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putstr_color(char *str, char *color);
void			ft_putchar_color(int c, char *color);

#endif
