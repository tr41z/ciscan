#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "include/scanner.h"
#include "include/utils.h"

void scan_ports(const char *hostname, int portL, int portU) {
    int open_ports = 0;
    
    for (int i = portL; i <= portU; i++) {
        if (establish_handshake(hostname, i) == 0) { open_ports++; }
    }
}

int establish_handshake(const char *hostname, int port) {
    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket!");
        return 1;
    }

    // Setup server address
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0) { 
        return 1; 
        } else { printf("%i\n", port); }

    close(sockfd);
    return 0;
}