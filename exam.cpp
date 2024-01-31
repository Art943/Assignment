#include <iostream>
#include <cstddef>
#include <cassert>

template <typename T, size_t N>
class CBuffer
{
    T data[N]{};
    int tail{0};
    int head{0};
    size_t counter{0};

public:
    bool write(int value)
    {
        bool status{false};
        if (tail == (N - 1))
        {
            tail = 0;
        }
        else if (counter == 0)
        {
            data[tail] = value;
            counter++;
            tail++;
            status = true;
        }
        else
        {
            data[tail] = value;
            tail++;
            status = true;
        }
        return status;
    }
    bool read(int elem)
    {

        bool status{false};
        if (counter == (N - 1))
        {
            head = 0;
        }
        if (counter == 0)
        {
            head++;
            std::cout << "Empty" << std::endl;
            status = true;
        }
        else
        {
            data[head];
            status = true;
            head++;
        }

        return status;
    }
    void clear(void)
    {
        data[head] = 0;
    }
};
int main(void)
{
    CBuffer<int, 10> cir;
    assert(cir.write(10));
    assert(cir.read(0));
    cir.clear();
    std::cout << "All systems pass!" << std::endl;
    return 0;
}