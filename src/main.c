#include <stdio.h>
#include <stdlib.h>
#include "include/scanner.h"
#include "include/utils.h"

int main(int argc, char **argv) {
    display_menu();
    
    if (argc < 4) {
        printf("Wrong flag format: ... <hostname> <port down> <port upper>\n");
        return 1;
    }


    const char *hostname = argv[1];
    const char *portL = argv[2];
    const char *portU = argv[3];

    int portLower = atoi(portL);
    int portUpper = atoi(portU);    
    
    printf("TARGET IP: %s\n", hostname);
    printf("PORT RANGE: %i-%i\n\n", portLower, portUpper);
    
    printf("PORT       STATUS       SERVICE\n");
    printf("-------------------------------\n");

    scan_ports(hostname, portLower, portUpper);

    return 0;
}