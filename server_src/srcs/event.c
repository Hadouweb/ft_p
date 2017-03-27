#include "server.h"

void	add_client(pid_t pid, t_server *server, int socket, struct sockaddr_in config)
{
	t_client	*client;

	printf("Add_client\n");
	client = (t_client*)malloc(sizeof(t_client));
	if (client == NULL)
		print_error_exit("malloc", __FILE__, __LINE__);
	client->pid = pid;
	client->socket = socket;
	client->config = config;
	client->link.next = NULL;
	client->link.prev = NULL;
	ft_list_push_back(&server->client_list, &client->link);
}

void	event_connection(t_server *server)
{
	pid_t 				pid;
	socklen_t			sock_len;
	struct sockaddr_in	client_config;
	int 				socket_client;

	sock_len = sizeof(struct sockaddr_in);
	server->pid_event = fork();
	printf("FORK EVENT CONNECTION\n");
	if (server->pid_event == 0)
	{
		printf("FORK EVENT CONNECTION CHILD\n");
		while (42)
		{
			socket_client = accept(server->socket,
			(struct sockaddr *) &client_config, &sock_len);
			if (socket_client < 0)
				print_error_exit("accept", __FILE__, __LINE__);
			printf("ACCEPT CONNECTION\n");
			pid = fork();
			if (pid == 0)
			{
				add_client(pid, server, socket_client, client_config);
				break ;
			}
		}
	} else
		wait(NULL);
}

void	handle_client(t_server *server, void (*f)(t_server *, t_client *))
{
	t_link		*client_link;
	t_client	*client;

	client_link = server->client_list.head;
	while (client_link)
	{
		client = PTR_NODE(client_link, t_client, link);
		f(server, client);
		client_link = client_link->next;
	}
}

void 	event_message(t_server *server, t_client *client)
{
	ssize_t 	ret_recv;
	char 		buf[1024];

	(void)server;
	if (client->pid == 0)
	{
		printf("Client: %d\n", client->socket);
		while ((ret_recv = recv(client->socket, buf, sizeof(buf), 0)) > 0)
		{
			buf[ret_recv] = '\0';
			printf("%s\n", buf);
		}
		if (ret_recv == -1)
			print_error_exit("recv", __FILE__, __LINE__);
	}
}
