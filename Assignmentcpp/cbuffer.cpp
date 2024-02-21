#include "cbuffer.h"
#include <cassert>
/*    Use a type (T) and a non-type(N) template parameters.
    Make the class as an uncopyable class by deleting
        The default copy constructor and the default copy assignment operator
    A buffer is an array of type T whose length is N
        Ensure that N is at least 4
    The class shall have a function to clear a buffer
    The class shall have a function to read data from a buffer
    The class shall have a function to write data to a buffer
        If the buffer is full then the oldest data shall be overwritten
    The class shall have a function to return the number of data elements stored in a buffer
    The class shall have a function to check if a buffer is full or not
    If the template type(T) is int, float or double then the class shall have a function to return average of the data elements stored in a circular buffer.
        The function shall not remove data elements stored in the buffer.
        The return type of the function shall be double.
    Don’t use assertion in the class. But to test the class, use assertion.*/

int main (void)
{
    CircularBuffer<int, 5> buffer;
    assert(buffer.size() == 0);
    assert(!buffer.full());
    buffer.write(1);
    buffer.write(2);
    buffer.write(3);
    assert(buffer.size() == 3);
    assert(!buffer.full());
    assert(buffer.average() == 2);
    buffer.write(4);
    buffer.write(5);
    assert(buffer.size() == 5);
    assert(buffer.full());
    buffer.write('h'); // Should overwrite oldest data
    assert(buffer.read() == 2);
    assert(buffer.average() == 0);
    assert(buffer.read()==3);
    std::cout<<"All Tests Passed!"<<std::endl;
    return 0;
}