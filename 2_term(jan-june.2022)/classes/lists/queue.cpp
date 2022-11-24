
#define once
class QueueException
{
    std::string error;
    public:
        std::string what()
        {
            return error;
        }

    class QueueException(std::string error): error(error) {}
};

template < class T>
    class Queue
    {
        template < class T>
            class Node
            {
                public:
                    Node * next_ptr;
                T data;
                // T() - clear trash in data
                // next_ptr - point to next element
                Node(T data = T(), Node *next_ptr = nullptr)
                {
                    this->data = data;
                    this->next_ptr = next_ptr;
                }
            };

        Node<T> *head, *tail;
        public:
            Queue();
        ~Queue();
        void push(T data);
        T pop();
        bool empty();
        T top();
    };

template < class T>
    Queue<T>::Queue()
    {
        // init Queue
        head = nullptr;
        tail = nullptr;
    }

template < class T>
    Queue<T>::~Queue()
    {
        while (head != nullptr)
        {
            pop();
        }
    }

template < class T>
    void Queue<T>::push(T data)
    {
        // FIFO
        // temp equals last element
        Node<T> *temp = tail;
        // create new element in the end
        tail = new Node<T> (data);
        // for first element
        if (!head)
        {
            head = tail;
        }

        // second last element is linking with
        // the new last element
        else
        {
            temp->next_ptr = tail;
        }
    }

// check Queue emptiness
template < class T>
    bool Queue<T>::empty()
    {
        return head == nullptr;
    }

template < class T>
    T Queue<T>::pop()
    {
        // if Queue isn't empty
        if (!empty())
        {
            // save ptr for further cleaning
            Node<T> *temp = head;
            // save data, bec-se head will be changed
            int data = head->data;
            // change head to previous element
            head = head->next_ptr;
            if (head == nullptr)
            {
                tail = nullptr;
            }

            // clear data
            delete temp;
            return data;
        }
        else
        {
            throw QueueException("\nerror: Queue is empty\n");
        }
    }

template < class T>
    T Queue<T>::top()
    {
        if (!empty())
        {
            return head->data;
        }
        else
        {
            throw QueueException("\nerror: Queue is empty\n");
        }
    }