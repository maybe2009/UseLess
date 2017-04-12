#include "IO.hpp"

#include <unistd.h>
#include <iostream>

using namespace std;

class UnixFileIO : 
    public Reader<ssize_t, int, void*, size_t>,
    public Writer<ssize_t, int, const void*, size_t> 
{
public:
    virtual ssize_t read(int fd, void* buf, size_t n) override;
    virtual ssize_t write(int fd, const void* buf, size_t n) override;
};

ssize_t UnixFileIO::read(int fd, void* buf, size_t n) 
{
    return ::read(fd, buf, n);
}

ssize_t UnixFileIO::write(int fd, const void* buf, size_t n)
{
    return ::write(fd, buf, n);
}

int main() {
    UnixFileIO io;
    char buffer[6];
    io.write(1, "hello", 6);
    io.read(0, buffer, 6);
    buffer[6] = 0;
    
    cout << "Hello say " << buffer << endl;    
}