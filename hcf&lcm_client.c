#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int findHCF(int a, int b) {
if (b == 0) {
return a;
}
return findHCF(b, a % b);
}


int findLCM(int a, int b) {
int gcd = findHCF(a, b);
return (a * b) / gcd;
}


int main() {
int sockid;
int commid;
int num1, num2, hcf,lcm;
struct sockaddr_in servaddr, cliaddr;

// sockid = socket(AF_INET, SOCK_DGRAM, 0);
sockid = socket(AF_INET, SOCK_STREAM, 0);

servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
servaddr.sin_port = htons(2206);

bind(sockid, (struct sockaddr*)&servaddr, sizeof(servaddr));
listen(sockid, 10);
printf("Server waiting for numbers...\n");

int len = sizeof(cliaddr);

while (1) {
// Receive two numbers from the client
// recvfrom(sockid, &num1, sizeof(num1), 0, (struct sockaddr*)&cliaddr, &len);
//recvfrom(sockid, &num2, sizeof(num2), 0, (struct sockaddr*)&cliaddr, &len);

// Calculate the HCF
commid = accept(sockid, (struct sockaddr*)NULL, NULL);

// Receive two numbers from the client
recv(commid, &num1, sizeof(num1), 0);
recv(commid, &num2, sizeof(num2), 0);

// Calculate the sum
hcf = findHCF(num1, num2);
lcm=findLCM(num1,num2);

// Send the result back to the client
send(commid, &hcf, sizeof(hcf), 0);
send(commid, &lcm, sizeof(lcm), 0);
// sendto(sockid, &hcf, sizeof(hcf), 0, (struct sockaddr*)&cliaddr, len);
}

close(sockid); // Close the server socket
return 0;
}
