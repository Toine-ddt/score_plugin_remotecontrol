#!/bin/sh

g++ http_server_sync.cpp -lpthread -lstdc++fs
echo compiled
echo go http://127.0.0.1:8080/remote.html
./a.out 127.0.0.1 8080 .

