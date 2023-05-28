## Notes to Beej's Guid to Network Programming

### Chapter 2
---

Sockets are a way to speak to a file using standard Unix file descriptors.
A file descriptor is an integer associated with an open file.
The file can be a network connection, a FIFO, a pipe, a terminal, a real on-disk
file...

So communication with another program over the Internet is done through a file
descriptor.

Two types of sockets:
- Stream sockets (reliable two-way connected communication systems, use TCP)
- Datagram sockets (unreliable and connectionless but transimt data faster, use UDP)

