#ifndef __LOG4CPP_IO__
#define __LOG4CPP_IO__

template <typename T, typename... Args>
class Reader 
{
public:
    virtual T read(Args... args) = 0;
};

template <typename T, typename... Args>
class Writer 
{
public:
    virtual T write(Args... args) = 0;
};


#endif