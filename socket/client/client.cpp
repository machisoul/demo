// client.cpp
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[1024] = {0};

    // 创建Socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        std::cerr << "Error creating socket" << std::endl;
        return -1;
    }

    // 设置Server端的地址和端口
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);

    // 将IP地址从字符串转换为网络地址
    if (inet_pton(AF_INET, "192.168.12.47", &server_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address" << std::endl;
        return -1;
    }

    // 连接到Server端
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Connection failed" << std::endl;
        return -1;
    }

    // 发送和接收消息
    while (true) {
        std::string message;
        std::cout << "Enter message: ";
        std::getline(std::cin, message);

        send(client_socket, message.c_str(), message.length(), 0);

        memset(buffer, 0, sizeof(buffer));
        int valread = read(client_socket, buffer, sizeof(buffer));
        if (valread <= 0) {
            std::cerr << "Server disconnected" << std::endl;
            break;
        }
        std::cout << "Server response: " << buffer << std::endl;
    }

    // 关闭Socket
    close(client_socket);
    return 0;
}
