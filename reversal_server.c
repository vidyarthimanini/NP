#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void reverseString(char *str) {
int length = strlen(str);
int i, j;
char temp;

for (i = 0, j = length - 1; i < j; i++, j--) {
temp = str[i];
str[i] = str[j];
str[j] = temp;
}
}

int main() {
int sockid;
char input[100], output[100];
struct sockaddr_in servaddr, cliaddr;

sockid = socket(AF_INET, SOCK_DGRAM, 0);

servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
servaddr.sin_port = htons(2206);

bind(sockid, (struct sockaddr*)&servaddr, sizeof(servaddr));

printf("Server waiting for a string...\n");

int len = sizeof(cliaddr);

while (1) {
// Receive a string from the client
recvfrom(sockid, input, sizeof(input), 0, (struct sockaddr*)&cliaddr, &len);

// Reverse the string
reverseString(input);

// Send the reversed string back to the client
sendto(sockid, input, strlen(input), 0, (struct sockaddr*)&cliaddr, len);
}

close(sockid); // Close the server socket
return 0;
}
