# Sockets  

1. Create socket  
```
__int socket(int domain, int type, int protocol)__
@param domain - protocol family. AF_INET or AF_INET6.
@param type - Protocol type. SOCK_STREAM (for TCP), SOCK_DGRAM (for UDP).
@param protocol - usually set to 0 to indicate that default port should be used.
@return - file descriptor for socket or -1 for error.
```

2. Bind to an address
```
__int bind(int fd, struct sockaddr *local_addr, socklen_t addr_len)__
@param fd - file descriptor.
@param local_addr - pointer to structure containing details of address to bind to. INADDR_ANY (usually used)
@param addr_len - length of address structure.
@return - 0 on success and -1 on error.
```

3. Listen on the address
```
__int listen(int fd, int backlog_queue_log)__
@param fd - file descriptor.
@param backlog_queue_log - maximum number of queued connection requests upto backlog_queue_log.
@return - 0 for success and -1 for error.
```

4. Accept connection to bound address
```
__int accept(int fd, struct sockaddr *remote_host, socklen_t addr_length)__
@param fd - orginal file descriptor.
@param remote_host - write client address details into remote_host structure.
@param addr_len - write actual size of address structure into addr_len.
@return - return new file descriptor for added connection.
```

5. Connect a socket to a remote host
```
__int connect(int fd, struct sockaddr *remote_host, socklen_t addr_length)__
@param fd -
@param remote_host -
@param addr_len -
@return -
```

6. Send _n_ bytes from __*buffer__ to __socket fd__.
```
__int send(int fd, void *buffer, size_t n, int flags)__
@param fd -
@param buffer -
@param n -
@param flags -
@return -
```

7. Receives _n_ bytes from __socket fd__ to __*buffer__.
```
__int receive(int fd, void *buffer, size_t n, int flags)__
@param fd -
@param buffer -
@param n -
@param flags -
@return -
```
