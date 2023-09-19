#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
int sockid;
char input[100], output[100];
struct sockaddr_in servaddr;

sockid = socket(AF_INET, SOCK_DGRAM, 0);

servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = inet_addr("127.0.0.3");
servaddr.sin_port = htons(2206);

printf("Enter a string: ");
fgets(input, sizeof(input), stdin);
input[strcspn(input, "\n")] = '\0'; // Remove the newline character

// Send the string to the server
sendto(sockid, input, strlen(input), 0, (struct sockaddr*)&servaddr, sizeof(servaddr));

int len = sizeof(servaddr);

// Receive the reversed string from the server
recvfrom(sockid, output, sizeof(output), 0, (struct sockaddr*)&servaddr, &len);

printf("Reversed string: %s\n", output);

close(sockid);

return 0;
}
