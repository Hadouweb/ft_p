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
	int 					socket;
	struct sockaddr_in		config;
}							t_client;

typedef struct 				s_server
{
	int 					socket;
	struct sockaddr_in		config;
	t_client				client;
}							t_server;

#endif