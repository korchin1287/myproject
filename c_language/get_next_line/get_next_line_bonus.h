#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 32

typedef struct		s_list
{
	char			*content;
	struct s_list	*next;
	int				fd;
}					t_list;

int					get_next_line(int fd, char **line);
size_t				ft_strlen(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s);

#endif
