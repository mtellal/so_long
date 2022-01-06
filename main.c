#include "so_long.h"

#include <X11/keysym.h>

int	main(int argc, char **argv)
{
	t_data data;

	errno = 0;
	
	if (argc == 2)
	{
		map_all(argv[1], &data);
		data.move = 0;
		data.sc = 70;
		data.w = ft_strlen(data.tab[0]);
		data.h = tab_len(data.tab);
		game(&data);
	}
	else
	{
		print_err("invalid args", 0);
	}
}
