#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int	fd;
	char	*text;
	fd = open("text1.txt", O_RDONLY);
	while (1)
	{
		text = get_next_line(fd);
		if (!text)
			break;
		// printf("::%ld::\n", ft_strlen(text));
		printf("%s", text);
		text = free_char(text);
		text = NULL;
	}
	return (0);
}