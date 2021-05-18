#include "../../incs/libft.h"

int		have_return(char *save)
{
	int i;

	i = 0;
	if (!save)
		return (0);
	while (save[i])
	{
		if (save[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_new_line(char **save, int fd)
{
	int		i;
	char	*temp;

	if (!save)
		return (0);
	i = 0;
	while (save[fd][i] && save[fd][i] != '\n')
		i++;
	temp = ft_calloc(sizeof(char), (i + 1));
	if (!temp)
		return (0);
	i = 0;
	while (save[fd][i] && save[fd][i] != '\n')
	{
		temp[i] = save[fd][i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*get_new_save(char **save, int fd)
{
	char	*temp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!save[fd])
		return (0);
	while (save[fd][i] && save[fd][i] != '\n')
		i++;
	if (!save[fd][i])
	{
		free(save[fd]);
		return (0);
	}
	i++;
	temp = ft_calloc(sizeof(char), (ft_strlen(save[fd]) - i + 1));
	if (!temp)
		return (0);
	while (save[fd][i])
		temp[j++] = save[fd][i++];
	temp[j] = '\0';
	free(save[fd]);
	return (temp);
}

int		get_next_line(int fd, char **line)
{
	static char		*save[4096];
	char			buff[1 + 1];
	int				reader;

	if (fd < 0)
		return (-1);
	if (!save[fd])
		save[fd] = ft_calloc(1, 1);
	if (!save[fd])
		return (-1);
	reader = 1;
	while (reader != 0 && !(have_return(save[fd])))
	{
		reader = read(fd, buff, 1);
		if (reader == -1)
			return (-1);
		buff[reader] = '\0';
		save[fd] = ft_strjoin(save[fd], buff);
	}
	*line = get_new_line(save, fd);
	save[fd] = get_new_save(save, fd);
	return (reader);
}