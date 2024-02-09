#include "checker.h"

int	print_err(char *text, int ret)
{
	ft_printf("%s", text);
	return (ret);
}

int	main()
{
	char	**lines;
	char	*line;
	int	i;

	i = 0;
	ft_printf("Enter lines separated by newline (Ctrl+D to finish):\n");
	lines = malloc(sizeof(char *));
	if (!lines)
		return (print_err("Malloc error\n", 1));
	while ((line = get_next_line(STDIN_FILENO)))
		lines[i++] = ft_strdup(line);
	while (i >= 0)
		free(lines[i--]);
	free(lines);
	return (0);
}
