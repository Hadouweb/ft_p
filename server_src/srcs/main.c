#include "server.h"

void	close_socket(t_server *server)
{

	close(server->socket);
}

int		main(int ac, char **av)
{
	t_server	server;

	if (ac != 2)
		print_usage(av[0]);
	ft_bzero(&server, sizeof(t_server));
	set_server_config(&server, (uint16_t)ft_atoi(av[1]));
	event_connection(&server);
	handle_client(&server, event_message);
	close_socket(&server);
	return (0);
}