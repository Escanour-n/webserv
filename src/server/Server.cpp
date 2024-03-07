#include"Server.hpp"

void	Server::bindSocket(int fd, const String &ip, int port)
{
	S_address socket_info;
	socket_info.sin_family = PF_INET;
	socket_info.sin_port = htons((short)port);
	socket_info.sin_addr.s_addr = convertStringToBinary(ip);
	cout << "IP : " << ip << " PORT : " << port << " URL ==> http://" << ip << ":" << port << endl;
	if(bind(fd, (const sockaddr*)&socket_info, sizeof(socket_info)) == -1)
	{
		close(fd);
		exit(1);
		// throw runtime_error("bind : can't Bind this Port");
	}
}

void	Server::listenPort(int Socketfd)
{
	/**
	 * @attention check BACKLOG fhmha
	*/
	if(listen(Socketfd, SOMAXCONN)  == -1)
	{
		close(Socketfd);
		throw runtime_error("listen : can't listen");
	}
}
int		Server::setSocket()
{
	int fdSocket = socket(PF_INET, SOCK_STREAM, 0);
	if(fdSocket < -1)
		throw runtime_error("socket : can't open the file conection");
	int option = 1;

	/**
	 * @attention check setsockopt fhmha chno katakhd
	*/
	setsockopt(fdSocket, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(int));
	return fdSocket;
}
