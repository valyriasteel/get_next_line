#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	free(s1);
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}

int	ft_strchr(char *save, char c)
{
	int	i;

	if (!save)
		return (-1);
	i = -1;
	while (save[++i])
		if (save[i] == c)
			return (i);
	return (-1);
}

char	*ft_substr(char *save, int start, int len)
{
	char	*str;
	int		i;

	if (!save)
		return (NULL);
	if (start >= ft_strlen(save))
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len)
		str[i] = save[start + i];
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(char *save)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (ft_strlen(save) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (save[++i])
		str[i] = save[i];
	str[i] = '\0';
	return (str);
}

int	ft_strlen(char *save)
{
	int	i;

	i = 0;
	while (save[i])
		i++;
	return (i);
}