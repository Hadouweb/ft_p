#ifndef SERVER_H
# define SERVER_H

# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <netdb.h>
# include <stdio.h>
# include "libft.h"

typedef struct 				s_client
{
	t_link					link;
	pid_t 					pid;
	int 					socket;
	struct sockaddr_in		config;
}							t_client;

typedef struct 				s_server
{
	int 					socket;
	struct sockaddr_in		config;
	t_list					client_list;
	pid_t 					pid_event;
}							t_server;


/*
** ********************************* config.c *********************************
*/
void						set_server_config(t_server *server, uint16_t port);

/*
** ********************************* event.c **********************************
*/
void						event_connection(t_server *server);
void 						event_message(t_server *server, t_client *client);

void	handle_client(t_server *server, void(*f)(t_server *, t_client *));

/*
** ********************************* util.c ***********************************
*/
void						add_client(pid_t pid, t_server *server, int socket,
								struct sockaddr_in config);

/*
** ********************************* error.c **********************************
*/
void						print_usage(char *prog_name);
void						print_error_exit(char *str, char *file, int line);

#endif