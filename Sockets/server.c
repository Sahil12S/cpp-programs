#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void error(const char *msg);

void dostuff (int sock);

int main(int argc, char const *argv[]) {
    int sockfd, newsockfd, portno, pid;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;

    if (argc < 2) {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }

    // Create a socket.
    // int socket(int domain, int type, int protocol)
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    } else {
        printf("Socket created.\n");
    }

    // Clear address structure
    /**
     * Places n 0-value bytes in area pointed by address.
     * @param serv_addr - address where 0 bytes are to be placed.
     * @param n - number of bytes to placed
     */
    bzero((char *) &serv_addr, sizeof(serv_addr));

    portno = atoi(argv[1]);

    /* setup host_addr structure for use in bind call */
    // server byte order
    serv_addr.sin_family = AF_INET;

    // automatically be filled with current host's IP address
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // convert short integer value for port must be converted into network byte order
    serv_addr.sin_port = htons(portno);

    // bind(int fd, struct sockaddr *local_addr, socklen_t addr_length)
    // bind() passes file descriptor, the address structure,
    // and the length of the address structure
    // This bind() call will bind  the socket to the current IP address on port, portno
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR on binding");
    } else {
        printf("Bind complete.\n");
    }

    // This listen() call tells the socket to listen to the incoming connections.
    // The listen() function places all incoming connection into a backlog queue
    // until accept() call accepts the connection.
    // Here, we set the maximum size for the backlog queue to 5.
    listen(sockfd,5);

    // The accept() call actually accepts an incoming connection
     clilen = sizeof(cli_addr);

     while (1) {

         // This accept() function will write the connecting client's address info
         // into the the address structure and the size of that structure is clilen.
         // The accept() returns a new socket file descriptor for the accepted connection.
         // So, the original socket file descriptor can continue to be used
         // for accepting new connections while the new socker file descriptor is used for
         // communicating with the connected client.
         newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
         if(newsockfd < 0)
            error("ERROR on accept");

        // inet_ntoa - convert IPv4 address from network byte order to string.
        // ntohs - convert unsigned short integer from netwrok byte order to host byte order.
        printf("server: go connection from %s port %d\n",
        inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        pid = fork();
        if (pid < 0) {
            error("ERROR on fork");
        }
        if (pid == 0) {
            close(sockfd);
            dostuff(newsockfd);
            exit(0);
        }
        else close(newsockfd);

    } /* end of while */

    return 0;
}


void error(const char *msg) {
    perror(msg);
    exit(1);
}


/******** DOSTUFF() *********************
 There is a separate instance of this function
 for each connection.  It handles all communication
 once a connnection has been established.
 *****************************************/

void dostuff (int sock) {
    int n;
    char buffer[256];

    // Intializes buffer
    bzero(buffer, 256);

    n = read(sock, buffer, 255);
    if(n < 0)
        error("ERROR reading from socket");
    printf("Here is the message: %s\n", buffer);

    n = write(sock, "I got your message", 18);
    if (n < 0) {
        error("ERROR writing to socket");
    }
}
