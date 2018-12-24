//
// Created by Amr Hendy on 12/5/2018.
//

#include "Receiver.h"

//see this for examples https://linux.die.net/man/3/getaddrinfo

// fill the socket address with the sender address
Packet Receiver::receive_packet(int socket_fd, struct sockaddr_in socket_address) {
    Packet packet;
    socklen_t addrlen = sizeof(socket_address);
    //make it a blocking for some time only.
    int bytes = recvfrom(socket_fd, &packet, sizeof(packet),
                         MSG_WAITALL, (struct sockaddr *) &socket_address, &addrlen);
    if(bytes != sizeof(Packet) || bytes <= 0) {
        perror("Not received all the packet data");
        return Packet();
    }
    printf("packet %d received.\n", packet.seqno);
    cout << "packet size is " << packet.len << endl;
    return packet;
}

// fill the socket address with the sender address
Ack_Packet Receiver::receive_ack_packet(int socket_fd, struct sockaddr_in socket_address, int& status, int TIMEOUT) {

    clock_t begin = clock();
    int flags = fcntl(socket_fd, F_GETFL);
    fcntl(socket_fd, F_SETFL, flags | O_NONBLOCK);
    while((clock() - begin)/ CLOCKS_PER_SEC < TIMEOUT){
        Ack_Packet ack_packet;
        socklen_t addrlen = sizeof(socket_address);
        int bytes = recvfrom(socket_fd, &ack_packet, sizeof(ack_packet),
                             0, (struct sockaddr*)&socket_address, &addrlen);
        if(bytes > 0){
            status = 1;
            return ack_packet;
        }
    }
    status = 0;
    return Ack_Packet();
}

// fill the socket address with the sender address
Ack_Server_Packet Receiver::receive_ack_server_packet(int socket_fd, struct sockaddr_in socket_address) {
    Ack_Server_Packet ack_server_packet;
    socklen_t addrlen = sizeof(socket_address);
    int bytes = recvfrom(socket_fd, &ack_server_packet, sizeof(ack_server_packet),
                         MSG_WAITALL, (struct sockaddr*)&socket_address, &addrlen);
    if(bytes != sizeof(Ack_Server_Packet)){
        std::perror("Not received all the packet data");
    }
    printf("Acknowledge received.\n");
    return ack_server_packet;
}
