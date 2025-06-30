#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

int main()
{
	int sockfd,newsfd;
	char wrbuf[128];
	struct sockaddr_in srv;

	puts("socket is creating.....");
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
		perror("socket");
		return 0;
	}
	puts("socket created successfully....");
	srv.sin_family       = AF_INET;
	srv.sin_port         = htons(1205);
	srv.sin_addr.s_addr  = inet_addr("127.0.0.1");

	if(connect(sockfd,(struct sockaddr*)&srv,sizeof(srv))==0)
		puts("connection established successfully <<<<..");
	else
	{
		perror("connect");
		return 0;
	}
 
	printf("Enter the string :\n");
	scanf("%s",wrbuf);
	write(sockfd,wrbuf,strlen(wrbuf)+1);

}
