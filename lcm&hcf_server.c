#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
int sockid;
int num1, num2, hcf,lcm;
struct sockaddr_in servaddr;

// sockid = socket(AF_INET, SOCK_DGRAM, 0);
sockid = socket(AF_INET, SOCK_STREAM, 0);


servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = inet_addr("127.0.0.3");
servaddr.sin_port = htons(2206);

connect(sockid, (struct sockaddr*)&servaddr, sizeof(servaddr));
printf("Enter the first number: ");
scanf("%d", &num1);

printf("Enter the second number: ");
scanf("%d", &num2);

// Send the numbers to the server
// sendto(sockid, &num1, sizeof(num1), 0, (struct sockaddr*)&servaddr, sizeof(servaddr));
// sendto(sockid, &num2, sizeof(num2), 0, (struct sockaddr*)&servaddr, sizeof(servaddr));

send(sockid, &num1, sizeof(num1), 0);
send(sockid, &num2, sizeof(num2), 0);

// Receive the result from the server
recv(sockid, &hcf, sizeof(hcf), 0);
recv(sockid, &lcm, sizeof(lcm), 0);
int len = sizeof(servaddr);

// Receive the result from the server
// recvfrom(sockid, &hcf, sizeof(hcf), 0, (struct sockaddr*)&servaddr, &len);

printf("HCF of the numbers: %d\n", hcf);
printf("LCM of the numbers: %d\n", lcm);

close(sockid);

return 0;
}
