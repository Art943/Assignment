#ifndef CBUFFER_H
#define CBUFFER_H
#include <iostream>
#include<algorithm>

template<typename T, size_t N>

class CircularBuffer 
{
private:
    T buffer[N];
    size_t head;
    size_t tail;
    size_t count;

public:
    // Constructor
    CircularBuffer() : head(0), tail(0), count(0) 
    {
        static_assert(N >= 4, "Buffer size must be at least 4");
    }

    // Delete copy constructor and copy assignment operator
    CircularBuffer(const CircularBuffer&) = delete;
    CircularBuffer& operator=(const CircularBuffer&) = delete;

    // Function to clear the buffer
    void clear(void) 
    {
        head = tail = count = 0;
    }

    // Function to read data from buffer
    T read(void) 
    {
        T data = buffer[head];
        head = (head + 1) % N;
        if(count!=N)
        {
            count--;
        }
        return data;
    }

    // Function to write data to buffer
    void write(const T& data) 
    {
        buffer[tail] = data;
        tail = (tail + 1) % N;
        
        if (count == N) 
        { 
            head = (head + 1) % N;
        }
        if(count!=N)
        {
            count++;
        }
    }

    // Function to return the number of data elements stored in the buffer
    size_t size(void) const 
    {
        return count;
    }

    // Function to check if buffer is full
    bool full(void) const 
    {
        return count == N;
    }
    template<typename U = T>
    typename std::enable_if<std::is_same<U, int>::value || std::is_same<U, float>::value || std::is_same<U, double>::value, double>::type
    average(void)
    {
        double sum = 0.0;
        if (count == 0) 
        {
        return 0.0; // Return 0 if buffer is empty
        }
        
        for (size_t i = 0; i != count; i++)
        {
            sum += buffer[i];
        }
        return sum/count;
    }
};

#endif