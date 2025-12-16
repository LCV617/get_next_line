#include "get_next_line.h"



#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);

static void	read_all(const char *path)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return ;
	}
	i = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("--%s", line);
		free(line);
		i++;
	}
	close(fd);
}

static void	interleave_two(const char *p1, const char *p2)
{
	int		fd1, fd2;
	char	*line;

	fd1 = open(p1, O_RDONLY);
	fd2 = open(p2, O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
	{
		perror("open");
		if (fd1 >= 0) close(fd1);
		if (fd2 >= 0) close(fd2);
		return ;
	}

	while (1)
	{
		line = get_next_line(fd1);
		if (line)
		{
			printf("--[fd1] %s", line);
			free(line);
		}
		line = get_next_line(fd2);
		if (line)
		{
			printf("--[fd2] %s", line);
			free(line);
		}
		if (!line && !get_next_line(fd1))
			break;
	}
	close(fd1);
	close(fd2);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		read_all(av[1]);
		return (0);
	}
	if (ac == 3)
	{
		interleave_two(av[1], av[2]); /* utile pour le bonus */
		return (0);
	}
	write(2, "Usage:\n  ./a.out file\n  ./a.out file1 file2\n", 46);
	return (1);
}
