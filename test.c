// #include "get_next_line.h"
#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int	fd1;
	int	fd2;
	int	fd3;
	char	*text;
	fd1 = open("text1.txt", O_RDONLY);
	fd2 = open("text2.txt", O_RDONLY);
	fd3 = open("text3.txt", O_RDONLY);
	while (1)
	{
		text = get_next_line(fd1);
		if (!text)
			break;
		// printf("::%ld::\n", ft_strlen(text));
		printf("%s", text);
		text = free_char(text);
		text = NULL;
	}
	while (1)
	{
		text = get_next_line(fd2);
		if (!text)
			break;
		// printf("::%ld::\n", ft_strlen(text));
		printf("%s", text);
		text = free_char(text);
		text = NULL;
	}
	while (1)
	{
		text = get_next_line(fd3);
		if (!text)
			break;
		// printf("::%ld::\n", ft_strlen(text));
		printf("%s", text);
		text = free_char(text);
		text = NULL;
	}
	return (0);
}