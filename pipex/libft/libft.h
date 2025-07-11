/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:03:40 by seungule          #+#    #+#             */
/*   Updated: 2023/06/21 18:01:06 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

void		ft_bzero(void *s, size_t n);
int			ft_isalnum(int num);
int			ft_isalpha(int num);
int			ft_isascii(int num);
int			ft_isdigit(int num);
int			ft_isprint(int num);
void		*ft_memcpy(void *dest, const void *source, size_t num);
void		*ft_memset(void *dest, int num, size_t count);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
size_t		ft_strlcpy(char *dest, const char *src,	size_t size);
size_t		ft_strlen(const char *str);
int			ft_strncmp(char *s1, char *s2, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t num);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *string, int c);
char		*ft_strrchr(const char *string, int c);
void		*ft_memchr(const void *buf, int c, size_t count);
int			ft_memcmp(const void *buf1, const void *buf2, size_t count);
char		*ft_strnstr(const char *dest, const char *src, size_t len);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t num, size_t size);
char		*ft_strdup(const char *src);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
