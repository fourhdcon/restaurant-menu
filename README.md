# Restaurant menu

## CPP
main.cpp is for api that is being used to giving response to the client req

### To compile it you need to have libcgicc and libmysql
You have to know where you have libcgicc.a file:
```bash
whereis libcgicc.a
```  
In response you can get:
```bash
libcgicc: /usr/lib/x86_64-linux-gnu/libcgicc.a /usr/lib/x86_64-linux-gnu/libcgicc.so
```  
We wanted the first one: /usr/lib/x86_64-linux-gnu/libcgicc.a  
Now, the example compilation command looks like:
```bash
g++ main.cpp /usr/lib/x86_64-linux-gnu/libcgicc.a -lmysqlclient -o api.cgi
```
