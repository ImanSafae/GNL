#include "get_next_line.h"

int	main()
{
	int fd = open("gnlTester/files/41_with_nl", O_RDONLY);
	char	*tmp = get_next_line(fd);
	
	// printf("[%s]\n", tmp);
	free(tmp);
	tmp = 0;
	tmp = get_next_line(fd);
	// printf("[%s]\n", tmp);
	// free(tmp);
	// tmp = 0;
	// tmp = get_next_line(fd);
	// printf("[%s]\n", tmp);
	// tmp = 0;
	// tmp = get_next_line(fd);
	// printf("[%s]\n", tmp);
	// free(tmp);
	// tmp = 0;
	// tmp = get_next_line(fd);
	// printf("[%s]\n", tmp);
	// free(tmp);
	// tmp = 0;
	// tmp = get_next_line(fd);
	// printf("[%s]\n", tmp);
	free(tmp);
	close(fd);
}