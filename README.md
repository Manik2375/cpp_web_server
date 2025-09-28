# cpp-web-server

**NOTE: Currently I plan to add more features to this server. It currently lack proper file handling and much more**

A simple C++ web server implementation for educational purposes. This project demonstrates basic socket programming, HTTP request handling, and file serving using C++ and POSIX APIs.

## Features
- Handles HTTP requests (GET)
- Serves static HTML and CSS files from the `assets/` directory
- Modular socket classes for easy extension
- Simple logging and connection management

## Project Structure
- `hoothoot.cpp`, `hoothoot.hpp`: Main place to use the Webserver class
- `Networking/Servers/`: Server classes (e.g., `WebServer`, `SimpleServer`)
- `Networking/Sockets/`: Socket abstraction classes
- `assets/`: Static HTML and CSS files to be served
- `CMakeLists.txt`: Build configuration

## Building

- Make sure Cmake and C++ compiler is installed (I recommend using gcc with C++20)
- `<sys/socket.h>` only works on **Linux** (and maybe MacOS, not 100% sure). Please run the project in **Linux**

Then run:

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

## Running
After building, run the server binary (e.g., `cpp_web_server`).

```bash
cd ../
./build/cpp_web_server
```

## Sending Requests
You can use `curl` to send requests from the terminal:

```bash
curl http://127.0.0.1:4000/
```
Replace `PORT` with the port your server is listening on. (By default it's 4000)

Or just open it in a web browser.


## How project works

We have 2 directories inside `Networking`, one is `Socket` for cpp sockets and other one is `Servers` for your servers. The project aim to provide a library like ability to create servers, not only for web but for your needs

### `Sockets` folder
- `SimpleSocket` - Provides basic socket features, to create `socket()`
- `BindingSocket` - Allows you to `bind()` to the network
- `ListeningSocket` - Allows you to `listen()` to the socket. 
- `ConnectingSocket` - [NOT RECOMMENDED TO USE] Purpose is to `connect()` to socket, but currently not well maintained file

### `Servers` folder
- `SimpleServer` - This is what will mainly deal with the sockets in `Sockets` folder
- `WebServer` - Our webserver, which defines how to handle http request and stuff

## Troubleshooting
- If you cannot reuse a port after restarting, ensure the socket option `SO_REUSEADDR` is set before binding. Or maybe try changing the port in `hoothoot.cpp`
- If requests appear empty, check your socket read logic and buffer handling.
- For file serving issues, verify file paths and permissions.

## References
Please check these resources:
- https://beej.us/guide/bgnet/ - Great guide recommended to read first
- https://www.youtube.com/watch?v=YwHErWJIh6Y 
  - Great tutorial but uses a bit old C++ version (like C-style casting and other stuff). This project gains the foundation from this video, but I've changed many things from project. Like:
  - Using modern type casting
  - Understanding the HTML and CSS request path, to give appropriate files
  - Giving 404 error
  - etc... (I plan to add more ^-^)

## License
This project is for educational use.

