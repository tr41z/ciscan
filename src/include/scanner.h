#ifndef SCANNER_H
#define SCANNER_H

void scan_ports(const char *hostname, int portU, int portD);
int establish_handshake(const char *hostname, int port);

#endif