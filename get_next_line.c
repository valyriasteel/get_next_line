#include "get_next_line.h"

char	*ft_read(int fd, char *save)
{
	char	*buff;
	int		len;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	len = read(fd, buff, BUFFER_SIZE);
	if (len < 0)
	{
		free(buff);
		return (NULL);
	}
	buff[len] = '\0';
	save = ft_strjoin(save, buff);
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	int			len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read(fd, save);
	if (!save)
		return (NULL);
	len = ft_strchr(save, '\n');
	line = ft_substr(save, 0, len);
	save = ft_substr(save, len + 1, ft_strlen(save) - len);
	if (!line || !save)
		return (NULL);
	free(save);
	return (line);
}

int main(void)
{
	int fd;
	char *line;

	fd = open("deneme.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
}