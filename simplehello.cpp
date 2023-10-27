1. Simple Hello
Client.c
#include &lt;stdio.h&gt;
#include &lt;sys/socket.h&gt;
#include &lt;netinet/in.h&gt;
#include &lt;string.h&gt;

int main()
{
int clientSocket;
char buffer[1024];
struct sockaddr_in serverAddr;
socklen_t addr_size;

/*—- Create the socket. The three arguments are: —-*/
/* 1) Internet domain 2) Stream socket 3) Default protocol (TCP in this case) */
clientSocket = socket(PF_INET, SOCK_STREAM, 0);

/*—- Configure settings of the server address struct —-*/
/* Address family = Internet */
serverAddr.sin_family = AF_INET;
/* Set port number, using htons function to use proper byte order */
serverAddr.sin_port = htons(7891);
/* Set IP address to localhost */
serverAddr.sin_addr.s_addr = inet_addr(&quot;127.0.0.1&quot;);
/* Set all bits of the padding field to 0 */
memset(serverAddr.sin_zero, &#39;\0&#39;, sizeof serverAddr.sin_zero);

/*—- Connect the socket to the server using the address struct —-*/
addr_size = sizeof serverAddr;
connect(clientSocket, (struct sockaddr *) &amp;serverAddr, addr_size);

/*—- Read the message from the server into the buffer —-*/
recv(clientSocket, buffer, 1024, 0);

/*—- Print the received message —-*/
printf(&quot;Data received: %s&quot;,buffer);

return 0;
}

Server.c
#include &lt;stdio.h&gt;
#include &lt;sys/socket.h&gt;
#include &lt;netinet/in.h&gt;
#include &lt;string.h&gt;

int main()
{
int welcomeSocket, newSocket;
char buffer[1024];
struct sockaddr_in serverAddr;
struct sockaddr_storage serverStorage;
socklen_t addr_size;

/*—- Create the socket. The three arguments are: —-*/
/* 1) Internet domain 2) Stream socket 3) Default protocol (TCP in this case) */
welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);

/*—- Configure settings of the server address struct —-*/
/* Address family = Internet */
serverAddr.sin_family = AF_INET;
/* Set port number, using htons function to use proper byte order */
serverAddr.sin_port = htons(7891);
/* Set IP address to localhost */
serverAddr.sin_addr.s_addr = inet_addr(&quot;127.0.0.1&quot;);
/* Set all bits of the padding field to 0 */
memset(serverAddr.sin_zero, &#39;\0&#39;, sizeof serverAddr.sin_zero);

/*—- Bind the address struct to the socket —-*/
bind(welcomeSocket, (struct sockaddr *) &amp;serverAddr, sizeof(serverAddr));

/*—- Listen on the socket, with 5 max connection requests queued —-*/
if(listen(welcomeSocket,5)==0)
printf(&quot;Listening\n&quot;);
else
printf(&quot;Error\n&quot;);

/*—- Accept call creates a new socket for the incoming connection —-*/
addr_size = sizeof serverStorage;
newSocket = accept(welcomeSocket, (struct sockaddr *) &amp;serverStorage, &amp;addr_size);

/*—- Send message to the socket of the incoming connection —-*/
strcpy(buffer,&quot;Hello World\n&quot;);
send(newSocket,buffer,13,0);

return 0;
}
