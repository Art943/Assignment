#include <iostream>
#include <cassert>

template <typename T>
class MovableQueue
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(const T &value) : data(value), next(nullptr) {}
    };

    Node *frontPtr;
    Node *rearPtr;
    size_t size;

    // Private function to release all allocated memory
    void clearQueue()
    {
        while (frontPtr != nullptr)
        {
            Node *temp = frontPtr;
            frontPtr = frontPtr->next;
            delete temp;
        }
        rearPtr = nullptr;
        size = 0;
    }

public:
    // Constructor
    MovableQueue() : frontPtr(nullptr), rearPtr(nullptr), size(0) {}

    // Destructor
    ~MovableQueue()
    {
        clearQueue();
    }

    // Move constructor
    MovableQueue(MovableQueue &&other) noexcept
        : frontPtr(other.frontPtr), rearPtr(other.rearPtr), size(other.size)
    {
        // Reset the source queue
        other.frontPtr = nullptr;
        other.rearPtr = nullptr;
        other.size = 0;
    }

    // Move assignment operator
    MovableQueue &operator=(MovableQueue &&other) noexcept
    {
        if (this != &other)
        {
            // Release current resources
            clearQueue();

            // Move resources from the source queue
            frontPtr = other.frontPtr;
            rearPtr = other.rearPtr;
            size = other.size;

            // Reset the source queue
            other.frontPtr = nullptr;
            other.rearPtr = nullptr;
            other.size = 0;
        }
        return *this;
    }

    // Function to enqueue a data element to the queue
    void enqueue(const T &value)
    {
        try
        {
            Node *newNode = new Node(value);
            if (isEmpty())
            {
                frontPtr = newNode;
                rearPtr = newNode;
            }
            else
            {
                rearPtr->next = newNode;
                rearPtr = newNode;
            }
            size++;
        }
        catch (const std::bad_alloc &e)
        {
            std::cerr << "Error: Memory allocation failed while enqueueing element." << std::endl;
            throw;
        }
    }

    // Function to dequeue a data element from the queue
    void dequeue()
    {
        if (isEmpty())
        {
            std::cerr << "Error: Cannot dequeue from an empty queue." << std::endl;
            throw std::out_of_range("Queue is empty");
        }

        Node *temp = frontPtr;
        frontPtr = frontPtr->next;
        delete temp;
        size--;

        // If the queue becomes empty, update rearPtr as well
        if (isEmpty())
        {
            rearPtr = nullptr;
        }
    }

    // Function to get the number of data elements stored in the queue
    size_t getSize() const
    {
        return size;
    }

    // Function to clear the queue
    void clear()
    {
        clearQueue();
    }

    // Function to check if the queue is empty
    bool isEmpty() const
    {
        return size == 0;
    }
};

int main()
{
    MovableQueue<int> queue;

    // Test enqueue
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    // Test getSize
    assert(queue.getSize() == 3);

    // Test dequeue
    queue.dequeue();
    assert(queue.getSize() == 2);

    // Test clear
    queue.clear();
    assert(queue.getSize() == 0);
    assert(queue.isEmpty());

    // Test move semantics
    MovableQueue<int> movedQueue = std::move(queue);
    assert(queue.isEmpty());
    assert(movedQueue.getSize() == 0);

    // Test move assignment
    MovableQueue<int> anotherQueue;
    anotherQueue = std::move(movedQueue);
    assert(movedQueue.isEmpty());
    assert(anotherQueue.getSize() == 0);

    std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}