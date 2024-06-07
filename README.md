# C++ Server

A basic Web Server written from scratch in C++.
* The server currently only supports GET requests. I will be working on adding other functionalities soon.
* [Click here to see a live demo](https://cpp-server.fly.dev)

# The functionality of this server depends on the [POCO Library](https://pocoproject.org).
To install POCO:
```shell
    curl https://pocoproject.org/releases/poco-1.13.3/poco-1.13.3.zip -o poco.zip
    unzip poco.zip
    cd poco-1.13.3
    mkdir cmake-build
    cd cmake-build
    cmake .. 
    cmake --build . --target install
```

# To run the server locally:
```shell
    git clone https://github.com/aakar-mutha/cpp-server.git
    cd cpp-server
    mkdir build
    cmake ..
    make
    ./serve

```

Lastly, thank you for coming here. Please let me know how I can improve it. The website that you see here is an old version I had made to learn HTML. CSS and JS. 

[![Linkedin](https://i.sstatic.net/gVE0j.png) LinkedIn](https://www.linkedin.com/in/aakar-mutha)
&nbsp;
[![GitHub](https://i.sstatic.net/tskMh.png) GitHub](https://github.com/aakar-mutha)