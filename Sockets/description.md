# Sockets  

1. Create socket  
__```int socket(int domain, int type, int protocol)```__
<pre>
<b>@param domain</b> - protocol family. <b>AF_INET</b> or <b>AF_INET6</b>.
<b>@param type</b> - Protocol type. <b>SOCK_STREAM</b> (for TCP), <b>SOCK_DGRAM</b> (for UDP).
<b>@param protocol</b> - usually set to 0 to indicate that default port should be used.
<b>@return</b> - file descriptor for socket or -1 for error.
</pre>

2. Bind to an address  
__```int bind(int fd, struct sockaddr *local_addr, socklen_t addr_len)```__
<pre>
<b>@param fd</b> - file descriptor.
<b>@param local_addr</b> - pointer to structure containing details of address to bind to. <b>INADDR_ANY</b> (usually used)
<b>@param addr_len</b> - length of address structure.
<b>@return</b> - 0 on success and -1 on error.
</pre>

3. Listen on the address  
__```int listen(int fd, int backlog_queue_log)```__
<pre>
<b>@param fd</b> - file descriptor.
<b>@param backlog_queue_log</b> - maximum number of queued connection requests upto <b>backlog_queue_log</b>.
<b>@return</b> - 0 for success and -1 for error.
</pre>

4. Accept connection to bound address  
__```int accept(int fd, struct sockaddr *remote_host, socklen_t addr_length)```__
<pre>
<b>@param fd</b> - orginal file descriptor.
<b>@param remote_host</b> - write client address details into remote_host structure.
<b>@param addr_len</b> - write actual size of address structure into <b>addr_len</b>.
<b>@return</b> - return new file descriptor for added connection.
</pre>

5. Connect a socket to a remote host  
__```int connect(int fd, struct sockaddr *remote_host, socklen_t addr_length)```__
<pre>
<b>@param fd</b> - file descriptor.
<b>@param remote_host</b> - pointer to structure containing details of remote host.
<b>@param addr_len</b> - size of address of remote host structure.
<b>@return</b> - 0 on success, -1 otherwise.
</pre>

6. Send <i>n</i> bytes from <b>*buffer</b> to <b>socket fd</b>  
__```int send(int fd, void *buffer, size_t n, int flags)```__
<pre>
<b>@param fd</b> - file descriptor.
<b>@param buffer</b> - buffer or data to send.
<b>@param n</b> - number of bytes.
<b>@param flags</b> - flags if any.
<b>@return</b> - return number of bytes sent or -1 for error.
</pre>

7. Receive </i>n</i> bytes from <b>socket fd</b> into <b>*buffer</b>  
__```int receive(int fd, void *buffer, size_t n, int flags)```__
<pre>
<b>@param fd</b> - file descriptor.
<b>@param buffer</b> - buffer or data to receive in.
<b>@param n</b> - number of bytes.
<b>@param flags</b> - flags if any.
<b>@return</b> - return number of bytes received or -1 for error.
</pre>
