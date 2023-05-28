## Notes on Beej's Guide to Network Programming

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

### Chapter 3
---

Network routing systems:
- IPv4 (4 bytes, 2^32 possible addresses (not enough), e.g 192.0.2.111)
- IPv6 (16 bytes, 2^128 possible addresses (a shit ton), e.g 2001:0db8:c9d2:aee5:73e3:934a:a5ae:9551)

Loopback addresses:
- 127.0.0.1 (IPv4)
- 0000:0000:0000:0000:0000:0000:0000:0001 (IPv6)

An IP address consists of two parts:
- Network address (a unique number assigned to a network)
- Host address (assigned to a host within the network)

A subnet mask is used to reveal the two portions of an IP address (e.g. 255.255.255.0 & 192.0.2.12
means that the first 3 bytes represent the network address and the last one is the host address)

A subnet mask can also be represented with a slash notation.
(e.g. 255.255.255.0 & 192.0.2.12 is equivalent to 192.0.2.12/24
The number after the slash represents the bits occuped by the network address.)

A two-byte hex number (e.g. b34f) can be stored in two ways depending on the
underlying architecture:
- Big Endian: b3 4f (also called Network Byte Order)
- Little Endian: 4f b3

The order in which it's stored is called Host Byte Order.

The data always needs to be in Network Byte Order when transmitted over the network,
so a conversion from and to the Host Byte Order is required every time it's send and received.
