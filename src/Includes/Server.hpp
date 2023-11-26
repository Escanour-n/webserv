#ifndef SERVER_HPP
#define SERVER_HPP
#include<sstream>
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <netdb.h>
#include<vector>
#include<map>
#include <sys/poll.h>
#include <sys/select.h>
#include "Parser.hpp"
#include"Cgi.hpp"
#include "ParssingRequist.hpp"

struct _Data { 
	std::string	file; 
	std::string	respond;
};
class	ServerRun
{
	public :
		ServerRun(ServerData);
		~ServerRun();

		int		Newsocket();
		bool	bindConection(int	Port, int	sreverfd);
		void	HandelRequist(struct pollfd	*struct_fds ,size_t	i,std::vector<struct pollfd>&, std::vector<int>);
		String	ParssingRecuistContent( String );
		void	acceptRquist( std::vector<int>	servers );
		void	listenSocket(int	serverfd);
		void	RunAllServers();
		void cgi(std::vector<String>);
		String getRespond(const ServerModel & server, const String &path);
		String getRespondLocation(const Location & _location, const std::string & path, const ServerModel & server);

	private :
		std::vector<String> query;
        std::map<String, String> cgiscipts;
		ServerData servers;

};

void	acceptRquist( std::vector<int>	servers );
#endif
