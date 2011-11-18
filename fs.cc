#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include "fs_client.h"
#include "fs_server.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>


using namespace std;

int main(int argc, char *argv[])
{
    int server_port;
    FILE *stdin;
    string usernames[10];
    string passwords[10];
    string curr_word="";
    int index = 0;
    int UorP = 0;
    struct sockaddr_in addr;
    int sock;

    //get the server port from command line
    server_port = atoi(argv[1]);

 /*   while (fread(&curr_word, 1, , stdin) != 0) { // Read the data from input
      // Do something with data stored in buffer
    	if(UorP == 0){
    		usernames[index] = curr_word;
    		UorP = 1;
			curr_word = "";
    	}
    	else{
    		passwords[index] = curr_word;
    		UorP = 0;
    		index++;
    	}
    }*/

    printf("the server port is: %d\n",server_port);

    //create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1)
    {
        printf("error opening socket");
        return -1;
    }

    //configure socket
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, NULL, sizeof(int));

    //bind socket
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(server_port);
    bind(sock, (struct sockaddr*) &addr, sizeof(addr));


    //wait for requests
    listen(sock, 10);



	return 0;
}
