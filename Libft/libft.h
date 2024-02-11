/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 04:31:53 by asuc              #+#    #+#             */
/*   Updated: 2023/08/12 04:31:53 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

long	ft_atoi(const char *str);
char	**ft_split(const char *str, char charset);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_putnbr_fd(long n, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *str, int fd);
char	*ft_itoa(int n);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	ft_putendl_fd(char *s, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	*ft_memcpy(void *destination, const void *source, size_t size);
int		ft_memcmp(const void *pointer1, const void *pointer2, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strtrim(char const *str, char const *set);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
char	*get_next_line(int fd);
int		ft_printf(const char *format, ...);
char	*ft_itoa_base(unsigned long n, int base);
int		ft_num_len_base(unsigned long n, int base);
int		print_hex(unsigned long nb);
int		print_hex_other(unsigned int nb, int mode);
int		print_format(const char *format, int index, va_list arg);
char	*ft_itoa_base_hex(unsigned int n, int base, int mode);
int		is_format(char c);
int		process_format(const char *format, va_list arg);
int		handle_percent(const char *format, int *index, va_list arg, int *err);
int		handle_character(const char *format, int *index, va_list arg, int *err);
char	*ft_realloc(char *str, int size);

#endif
