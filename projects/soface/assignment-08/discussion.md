(1) What is an IP address?
It is a unique number assigned to each divice on a network.
Why do we need IP addresses?
So that we can know what device we are trying to access, it is the only way to interface with another device.
What is the relation between TCP and IP?
IP handles addressing and routing of data packets, while TCP ensures reliable communication by managing packet delivery, ordering, and error checking.
What is a socket?
A socket is an endpoint for communication between two devices, defined by an IP address and a port number.
127.0.0.1 is localhost, it is used to test network stuff without having to use an external network

(2) What does a client-server architecture mean?
Client server architecture is where a client request a service from a server and it sends back some response.

Websites are server client architecture. ChatGPT is a good example because something like an LLM takes a lot of memory that something like your phone simply doesn't have, so the server runs it for you and send the much more compact response.

The server provides services and listens for incoming requests, while the client initiates requests to the server. By the nature of this relationship it is always obvious which is the server and which is the client. A device can act as both a client and a server depending on the context, as these roles are conceptual rather than fixed. In most larger context there is a dedicated server.

(3)
A broker is a middleman that takes requests and then sends them to server that can handle the type of requests and then it takes the response and gives to the client. So Client -> Broker -> Service for requests and Service -> Broker -> Client for responses

The big benefit is that you don't have to worry about a server crashing, as long as the broker has multiple servers it can access for any task then you gain a robustness and stability client side. Also it is easier for the client to communicate in general 

The downside is it is fundamentally slower, especially as the broker gets more advanced so if you have to make 10k calls to a server running it through a broker, will slow down response time

(4) What does Peer-to-Peer mean?
Peer-to-Peer (P2P) is a network architecture where each node can act as both a client and a server. Instead of relying on a central server, peers communicate directly with each other.

Idk if I have encountered it probably in some form I am unaware of.

A peer-to-peer network might use servers to dicover peers but each node is a both.

The benefits include no reliance on a server that might crash if one device crashes then the peer network still works.

Downside is higher complexity, also it can't do stuff where all need to communicate. So a videogame for example where there are two teams of five, there needs to be a server that decides what actually happens and sends updates to all clients.