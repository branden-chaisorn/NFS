
#include <iostream>

#include <cstdlib>

#include "fs_client.h"

#include "fs_crypt.h"

#include "fs_param.h"

#include "fs_server.h"

using namespace std;






void main(int argc, char *argv[])
{

  char *server;
  int server_port;
  int session, seq=0;
  char buf[10];
  FILE *stdin;
  string usernames[];
  string passwords[];
  string first_usrn="";
  string first_pwrd="";

  int index = 0;


  if (argc != 3)
    {
      cout << "error: usage: " << argv[0] << "\n"; exit(1);
    }


  server = argv[1];
  server_port = atoi(argv[2]); //returns the integer version

  //open the password file
  UANDP = fopen(argv[3], "r");

  //do a reading of the usernames and passwords
  while(!feof(stdin)){
   scanf(%s, );
   scanf(%s, );

   index++;
  }

  //close the file
  fclose(stdin);

  // fs_session("user1", "password1", server, server_port, &session);

  //fs_create("user1", "password1", session, seq++, "tmp");

  //fs_append("user1", "password1", session, seq++, "tmp", "abc", 3);

  //fs_read("user1", "password1", session, seq++, "tmp", 1, buf, 2);

  //fs_delete("user1", "password1", session, seq++, "tmp");

}
