#include <iostream>
#include <new>
#include <cstddef>
#include <exception>
#include <cassert>

template <typename T, size_t N>
class UncopyableCircularQue
{
    struct node_t
    {
        T data;
        node_t *next;
        node_t(const T &_data, node_t *_next) : data{_data}, next{_next} {}
    };

    node_t *head{nullptr};
    node_t *tail{nullptr};
    size_t count{0};
    T Size = N;

public:
    UncopyableCircularQue() = default;
    UncopyableCircularQue(const UncopyableCircularQue &) = delete;            // Uncopyable
    UncopyableCircularQue &operator=(const UncopyableCircularQue &) = delete; // Unassignable
   
    
    UncopyableCircularQue(UncopyableCircularQue &&queue) noexcept: head{queue.head}, tail{queue.tail}, count{queue.count}
    {
        // queue shall not own the resource
        queue.head = nullptr;
        queue.tail = nullptr;
        queue.count = 0;
    }

    UncopyableCircularQue &operator=(UncopyableCircularQue &&queue) noexcept
    {
        if (this != &queue)
        {
            clear(); // Release resources held by this instance

            // Move ownership of queue to this instance
            head = queue.head;
            tail = queue.tail;
            count = queue.count;

            // queue shall not own the resource
            queue.head = nullptr;
            queue.tail = nullptr;
            queue.count = 0;
        }

        return *this;
    }
        bool isFull(void)
        {
            bool status = false;
            if(count%Size == 0)
            {
                status = true;
            }
            return status;
        }
    bool enqueue(const T &item) noexcept
    {
        bool status{true};

        try
        {
            node_t *node = new node_t{item, nullptr};
            if (isFull())
            {
                tail=nullptr;
            }

            if (tail == nullptr)
            {
                head = node;
                tail = head;
            }
            else
            {
                tail->next = node;
                tail = node;
            }

            count++;
        }
        catch (const std::bad_alloc &)
        {
            status = false;
        }

        return status;
    }

    bool dequeue(T &item) noexcept
    {
        bool status{false};

        if (head != nullptr)
        {
            status = true;
            item = head->data;

            node_t *temp{head};
            head = head->next;
            delete temp;
            count--;

            if (head == nullptr)
            {
                tail = nullptr;
            }
        }

        return status;
    }

    size_t available(void) noexcept
    {
        return count;
    }

    void clear(void) noexcept
    {
        while (head != nullptr)
        {
            node_t *temp{head};
            head = head->next;
            delete temp;
        }

        tail = head;
        count = 0;
    }

    ~UncopyableCircularQue() { clear(); }
};

int main(void)
{
    UncopyableCircularQue<int, 10> q1;
    
    assert(0 == q1.available());
    q1.isFull();

    assert(q1.enqueue(10));
    assert(q1.enqueue(20));
    assert(q1.enqueue(30));
    assert(3 == q1.available());

    int value;
    assert(q1.dequeue(value));
    assert(value == 10);
    assert(2 == q1.available());

    UncopyableCircularQue<int,10> q2{std::move(q1)};
    assert(0 == q1.available());
    assert(2 == q2.available());

    q1 = std::move(q2);
    assert(2 == q1.available());
    assert(0 == q2.available());

    q1 = std::move(q1);
    assert(2 == q1.available());

    q1.clear();
    assert(0 == q1.available());

    std::cout << "All tests passed!" << std::endl;
    return 0;
}