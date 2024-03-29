/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:59:31 by emartin-          #+#    #+#             */
/*   Updated: 2020/12/08 18:01:44 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef	struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef	struct		s_ints
{
	int				i;
	int				counter;
	int				j;
}					t_ints;

typedef struct		s_nodes
{
	char			*element;
	struct s_nodes	*next;
}					t_node;

typedef struct		s_lista
{
	t_node			*first;
	int				size;
}					t_lista;

typedef struct		s_tab
{
	char			*line;
	char			**tokens;
	char			**orders;
	char			**path;
	char			**args;
	char			**command;
	char			*index;
	char			**env;
	int				status;
	int				fd1[2];
	int				fd2;
	int				save[2];
	int				i;
	int				z;
	t_node			*iterator;
}					t_tab;

char				*ft_strcpy(char *dest, char *src);
char				*ft_strncat(char *dest, char *src, unsigned int nb);
char				*ft_strcat(char *dest, char *src);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_strlen2(const char *s);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
int					ft_atoi(const char *str);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int ds);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char *s1, char *set);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				**ft_split(char const *s, char c);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(void const *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstadd_back(t_list **alst, t_list *new);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
int					ft_count_lines(char *str);
size_t				ft_line_len(const char *s);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
int					ft_strcmp(const char *s1, const char *s2);
char				**ft_split_list(char const *s, char c, t_tab *t);
void				ft_strpncpy(char *dest, char *str, int len);

t_lista				*new_list(void);
t_node				*new_node(char *s);
void				destructor_node(t_node *noode);
void				destructor_list(t_lista *lst);
void				pop_front(t_lista *lst);
void				pop_back(t_lista *lst);
void				push_front(t_lista *lst, char *s);
void				push_back(t_lista *lst, char *s);
void				push_after_n(t_lista *lst, char *s, int n);
t_lista				*copy_list(t_lista *lst);
int					size_list(t_lista *lst);
void				ft_free_lists(t_lista *lst);

void				ft_skip_all(t_ints *a, char const *s, char c);
void				ft_skipsimples(t_ints *a, char const *s, char c);
void				ft_skipdoubles(t_ints *a, char const *s, char c);
int					ft_cpyword(char const *s, t_tab *t, int j, char *str);
void				ft_dollar_cpy(t_ints *a, t_tab *t, char *str,
									char const *s);
void				ft_quotations_cpy(t_ints *a, t_tab *t, char *str,
									char const *s);
void				ft_simpquotations_cpy(t_ints *a, char *str, char const *s);
int					ft_dollar_count(char const *s, char **env);
void				ft_dollar_found(t_ints *a, char **env, char const *s);
int					ft_check_dollar(char const *s, char **env);
void				ft_quotations_found(t_ints *a, char **env, char const *s);
void				ft_simpquotations_found(t_ints *a, char const *s);
void				ft_not_zero(t_ints *a);
int					skip_env(char const *s);

#endif
