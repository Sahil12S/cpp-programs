# Sockets  

1. Create socket  
```
int socket(int domain, int type, int protocol)
@param domain - protocol family. AF_INET or AF_INET6.
@param type - Protocol type. SOCK_STREAM (for TCP), SOCK_DGRAM (for UDP).
@param protocol - usually set to 0 to indicate that default port should be used.
@return - file descriptor for socket or -1 for error.
```

2. Bind to an address
```
int bind(int fd, struct sockaddr *local_addr, socklen_t addr_len)
@param fd - file descriptor.
@param local_addr - pointer to structure containing details of address to bind to. INADDR_ANY (usually used)
@param addr_len - length of address structure.
@return - 0 on success and -1 on error.
```

3. Listen on the address
```
int listen(int fd, int backlog_queue_log)
@param fd - file descriptor.
@param backlog_queue_log - maximum number of queued connection requests upto backlog_queue_log.
@return - 0 for success and -1 for error.
```

4. Accept connection to bound address
```
int accept(int fd, struct sockaddr *remote_host, socklen_t addr_length)
@param fd - orginal file descriptor.
@param remote_host - write client address details into remote_host structure.
@param addr_len - write actual size of address structure into addr_len.
@return - return new file descriptor for added connection.
```

5. Connect a socket to a remote host
```
int connect(int fd, struct sockaddr *remote_host, socklen_t addr_length)
@param
@param
@param
@return
```



@param
@param
@param
@return
