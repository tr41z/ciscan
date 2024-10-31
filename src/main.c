#include <stdio.h>
#include "include/scanner.h"
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Wrong flag format: ... <hostname> <port down> <port upper>\n");
        return 1;
    }

    const char *hostname = argv[1];
    const char *portD = argv[2];
    const char *portU = argv[3];

    int portDown = atoi(portD);
    int portUpper = atoi(portU);    

    scan_ports(hostname, portDown, portUpper);

    return 0;
}