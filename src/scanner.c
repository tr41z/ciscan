#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "include/scanner.h"

void scan_ports(const char *hostname, int portD, int portU) {
    for (int i = portD; i <= portU; i++) {
        establish_handshake(hostname, i);
    }
    printf("Scanning ports for %s... in range %i - %i\n", hostname, portD, portU);
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
        printf("Failed to connect to server on port: %i\n", port);
        return 1;
    } else {
        printf("Connection successful on port: %i\n", port);
    }

    close(sockfd);
    return 0;
}