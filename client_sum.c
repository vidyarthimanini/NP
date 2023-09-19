#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
int sockid, commid;
int num1, num2, sum;
struct sockaddr_in servaddr;

sockid = socket(AF_INET, SOCK_STREAM, 0);

servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
servaddr.sin_port = htons(2200);

bind(sockid, (struct sockaddr*)&servaddr, sizeof(servaddr));
listen(sockid, 10);

while (1) {
commid = accept(sockid, (struct sockaddr*)NULL, NULL);

// Receive two numbers from the client
recv(commid, &num1, sizeof(num1), 0);
recv(commid, &num2, sizeof(num2), 0);

// Calculate the sum
sum = num1 + num2;

// Send the result back to the client
send(commid, &sum, sizeof(sum), 0);
close(commid);
}

close(sockid); // Close the server socket
return 0;
}
