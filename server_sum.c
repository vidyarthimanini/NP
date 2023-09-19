#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
int sockid;
int num1, num2, sum;
struct sockaddr_in servaddr;

sockid = socket(AF_INET, SOCK_STREAM, 0);

servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = inet_addr("127.0.0.6");
servaddr.sin_port = htons(2200);

connect(sockid, (struct sockaddr*)&servaddr, sizeof(servaddr));

printf("Enter the first number: ");
scanf("%d", &num1);

printf("Enter the second number: ");
scanf("%d", &num2);

// Send the numbers to the server
send(sockid, &num1, sizeof(num1), 0);
send(sockid, &num2, sizeof(num2), 0);

// Receive the result from the server
recv(sockid, &sum, sizeof(sum), 0);

printf("Sum of the numbers: %d\n", sum);

close(sockid);

return 0;
}
