#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

int main()
{
	int sockfd,newsfd;
	char rdbuf[128];
	struct sockaddr_in srv,cln;

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
	srv.sin_addr.s_addr  = inet_addr("0.0.0.0");

	if(bind(sockfd,(struct sockaddr*)&srv,sizeof(srv))==0)
	puts("binding address success....");
	else
	{
		perror("bind");
		return 0;
	}

	if(listen(sockfd,1)==0)
		puts("server listening <<<<..");
	else
	{
		perror("listen");
		return 0;
	}
	puts("New client connection accept..");

	int len=sizeof(cln);
	newsfd=accept(sockfd,(struct sockaddr *)&cln,&len);
	if(newsfd<0)
	{
		perror("accpect");
		return 0;
	}


	bzero(rdbuf,128);
	read(newsfd,rdbuf,128);
	printf("Received string :%s\n",rdbuf);


}
