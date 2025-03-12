# WinDLLServer

WinDLLServer is a project that demonstrates the integration of Windows DLLs, a simple web server, and memory mapping functionalities using C and the Windows API. This project serves as a learning tool for understanding how to build and manage DLLs, create a basic web server, and work with memory-mapped files in a Windows environment.

## Project Structure

- **driverdllc**
  - `driverDLL.dll`: The dynamic link library (DLL) for driver-related functionalities.
  - `runner.c`: The main runner program that interacts with the DLL.
  - `runner.exe`: The compiled executable for the runner program.
  - `memoryma...`: Memory mapping related files.


- **WebServer**
  - `index.html`: A simple HTML file served by the web server.
  - `server.c`: The source code for the simple web server.
  - `server.exe`: The compiled executable for the web server.

## Features

- **Dynamic Link Library (DLL)**: Demonstrates how to create and use a DLL in a Windows environment.
- **Web Server**: A basic web server that serves an HTML file and handles HTTP GET requests.
- **Memory Mapping**: Example of using memory-mapped files for inter-process communication or data sharing.

## Getting Started

### Prerequisites

- Windows operating system.
- MinGW or another C compiler that supports Windows API.
- Basic understanding of C programming and Windows API.

### Installation

1. Clone the repository:
   ```sh
   git clone https://github.com/MistaaOlivaaa/WinCNetDLL
   cd WinDLLServer
   code .
   



