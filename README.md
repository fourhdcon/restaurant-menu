# Restaurant menu

App that could be used for setup web in city displaying restaurants' menu. It's based on MIT license so please don't use it commercially.

## HTML
- index.html

Structure of website
## CSS
- style.css

Stylesheet of website
## PHP
- index.php

Only used for display website on Heroku.
## CPP
- main.cpp

Api used for giving response to the client request.

### Compiling
**To compile it you need to have libcgicc and libmysql!**

You have to know where you have libcgicc.a file:
```bash
whereis libcgicc.a
```
In response you could get:  
```bash
libcgicc: /usr/lib/x86_64-linux-gnu/libcgicc.a /usr/lib/x86_64-linux-gnu/libcgicc.so
```
We wanted the first one: `/usr/lib/x86_64-linux-gnu/libcgicc.a`

Now, the example compilation command looks like:  
```bash
g++ main.cpp /usr/lib/x86_64-linux-gnu/libcgicc.a -lmysqlclient -O3 -o restaurant_menu.cgi
```

**Note! Until you create a mysqlConnectionPass.txt file that has the right values to connect to the database, restaurant_menu.cgi will throw mysql_connection_error.**
mysqlConnectionPass.txt should looks like:
{ip of your database - host}
{user}
{password}
{database name}
{port}
