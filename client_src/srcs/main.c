#include "client.h"

void	print_usage(char *prog_name)
{
	ft_putstr_fd("Usage: ", 2);
	ft_putstr_fd(prog_name, 2);
	ft_putstr_fd(" port\n", 2);
	exit(1);
}

void	print_error_exit(char *str, char *file, int line)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(" in file: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(" line: ", 2);
	ft_putnbr_fd(line, 2);
	ft_putchar('\n');
	exit(1);
}

int 	get_socket(void)
{
	int 				s;
	struct protoent		*protocol;

	protocol = getprotobyname("tcp");
	if (protocol == NULL)
		print_error_exit("getprotobyname", __FILE__, __LINE__);
	s = socket(AF_INET, SOCK_STREAM, protocol->p_proto);
	if (s < 0)
		print_error_exit("socket", __FILE__, __LINE__);
	return (s);
}

void	set_server_config(t_server *server, uint16_t port)
{
	int 	ret_bind;
	int 	ret_listen;

	server->config.sin_family = AF_INET;
	server->config.sin_port = port;
	server->config.sin_addr.s_addr = INADDR_ANY;
	ret_bind = bind(server->socket, (struct sockaddr*)&server->config,
					sizeof(server->config));
	if (ret_bind < 0)
		print_error_exit("bind", __FILE__, __LINE__);
	ret_listen = listen(server->socket, 42);
	if (ret_listen != 0)
		print_error_exit("listen", __FILE__, __LINE__);
}

void	try_connection(t_server *server)
{
	int 				ret_accept;
	socklen_t			sock_len;

	sock_len = sizeof(struct sockaddr_in);
	ret_accept = accept(server->socket,
						(struct sockaddr*)&server->client.config, &sock_len);
	printf("ok\n");
	if (ret_accept == -1)
		print_error_exit("accept", __FILE__, __LINE__);
}

void 	receive_message(t_server *server)
{
	int 	ret_recv;
	int 	ret_send;
	char 	buf[12];

	ret_recv = recv(server->client.socket, buf, sizeof(buf), 0);
	if (ret_recv == -1)
		print_error_exit("recv", __FILE__, __LINE__);
	ret_send = send(server->client.socket, buf, sizeof(buf), 0);
	if (ret_send < 0)
		print_error_exit("send", __FILE__, __LINE__);
}

void	close_socket(t_server *server)
{
	close(server->client.socket);
	close(server->socket);
}

int		main(int ac, char **av)
{
	t_server	server;

	if (ac != 2)
		print_usage(av[0]);
	ft_bzero(&server, sizeof(t_server));
	server.socket = get_socket();
	set_server_config(&server, (uint16_t)ft_atoi(av[1]));
	try_connection(&server);
	receive_message(&server);
	return (0);
}