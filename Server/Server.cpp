//
// Created by Amr Hendy on 11/28/2018.
//

#include "Server.h"

Server::Server(string server_conf_file_dir) {
    freopen(server_conf_file_dir.c_str(), "r", stdin);
    cin >> server_port_number >> maximum_window_size >> random_seed >> packet_loss_prob;
    active_clients = 0;
}

void Server::init_server() {
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    // Creating socket file descriptor for the server
    if ((server_socket_fd = socket(address.sin_family, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    int opt = 1;
    // Check if it is used and forcefully attaching socket to our desired address and port
    if (setsockopt(server_socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt Error");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(server_port_number);
    int ret = bind(server_socket_fd, (struct sockaddr *)&address, sizeof(address));
    if (ret < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
}

void Server::start_server() {
    init_server();
    /* start listening on this port */
    int status = listen(server_socket_fd, SERVER_CONNECTION_QUEUE_SIZE);
    /* if error happened print it*/
    if(status){
        perror("error in listening");
        exit(EXIT_FAILURE);
    }
    printf("Server is waiting for connections\n");

    struct sockaddr_storage client_addr;    /* client address info */
    while(1) {
        /* server main loop */
        socklen_t sock_size = sizeof(client_addr);
        int client_socket_fd;                          /* client socket descriptor */
        client_socket_fd = accept(server_socket_fd, (struct sockaddr *)&client_addr, &sock_size); /* accept connection */
        if(client_socket_fd == -1){
            perror("accept error");
            continue;
        }
        if(active_clients == MAX_ALLOWED_CONNECTIONS){
            printf("Reached the max limit number of connections, So server can't handle that client connection\n")
            continue;
        }
        printf("Successfully Established Connection with a Client has fd = %d \n",client_socket_fd);
        /*
         *    handle the connection, by forking a new process.
         */
        int pid;
        // failure with fork so ignore that connection
        if ((pid = fork()) == -1) {
            close(client_socket_fd);
            continue;
        }
        // this is the parent process, and the pid represent the child process id
        else if(pid > 0) {
            // close the socket in the parent process as it is already copied in the child process
            close(client_socket_fd);
            active_clients++;
            continue;
        }
        // this is the new created child process and the process id = getpid()
        else if(pid == 0) {
            handle_client(client_socket_fd);
            close(client_socket_fd);
            active_clients--;
            printf("Finished Client with fd = %d \n",client_socket_fd);
            // to prevent the child of creating new processes
            exit(0);
            // or use kill(getpid(), SIGKILL);
        }
    }
}

// That thread will serve the single client
void Server::handle_client(int client_socket_fd) {

}