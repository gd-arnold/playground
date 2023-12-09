#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <openssl/ssl.h>
#include <string.h>

int
main(int argc, char* argv[])
{
    int client_fd = socket(AF_INET, SOCK_STREAM, 0); 

    struct sockaddr_in server_address = {
        AF_INET,
        htons(443),
        htonl(0x08080808) // 8.8.8.8 (google's ip)
    };

    connect(client_fd, (struct sockaddr*) &server_address, sizeof(server_address));

    SSL_CTX* ctx = SSL_CTX_new(TLS_method());
    SSL* ssl = SSL_new(ctx);
    SSL_set_fd(ssl, client_fd);
    SSL_connect(ssl);

    char* request = "GET /\r\n\r\n";
    SSL_write(ssl, request, strlen(request));

    char buffer[1024] = {0};
    SSL_read(ssl, buffer, 1023);

    printf("%s", buffer);

    close(client_fd);
    return 0;
}
