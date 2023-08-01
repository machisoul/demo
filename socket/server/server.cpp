/*
 * server.cpp
 * 
 */

#include <iostream>
#include <sys/socket.h>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

int main(){
	int server_socket, new_socket;
	struct sockaddr_in server_addr, client_addr;
	socklen_t client_addr_size = sizeof(client_addr);
	char buffer[1024] = {0};

	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socket == -1){
		cout << "Error creating socket" << endl;
		return -1;
	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(8080);
	// server_addr.sin_addr.s_addr = 192.168.12.47;
	inet_pton(AF_INET, "192.168.12.47", &server_addr.sin_addr);
	

	if(bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
		cout << "Binding failed!" << endl;
		return -1;
	}

	cout << "Will listen ..." << endl;
	if(listen(server_socket, 3) < 0){
		cout << "Listenning Failed!" << endl;
		return -1;
	}

	new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size);
	if(new_socket < 0){
		cout << "Acceptence Failed!" << endl;
		return -1;
	}

	cout << "server_socket is " << server_socket << ", and new_socket is " << new_socket << endl;

	while(1) {
		memset(buffer, 0, sizeof(buffer));
		string response = "Message received!";
		send(new_socket, response.c_str(), response.length(), 0);
		int valread = read(new_socket, buffer, sizeof(buffer));
		if (valread <= 0) {
			break;
		}
		cout << "Received: " << buffer << endl;
	}

	close(new_socket);
	close(server_socket);
	return 0;
}
