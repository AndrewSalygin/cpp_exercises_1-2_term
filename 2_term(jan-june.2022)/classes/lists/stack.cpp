
#define once
class StackException
{
    std::string error;
    public:
        std::string what()
        {
            return error;
        }

    StackException(std::string error): error(error) {}
};

template < class T>
    class Stack
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

        // last element (top of the Stack)
        Node<T> *head;
        public:
            Stack();
        ~Stack();
        void push(T data);
        T pop();
        bool empty();
        T top();
    };

template < class T>
    Stack<T>::Stack()
    {
        // init Stack
        head = nullptr;
    }

template < class T>
    Stack<T>::~Stack()
    {
        while (head != nullptr)
        {
            pop();
        }
    }

template < class T>
    void Stack<T>::push(T data)
    {
        // LIFO
        head = new Node<T> (data, head);
    }

// check Stack emptiness
template < class T>
    bool Stack<T>::empty()
    {
        return head == nullptr;
    }

template < class T>
    T Stack<T>::pop()
    {
        // if Stack isn't empty
        if (!empty())
        {
            // save ptr for further cleaning
            Node<T> *temp = head;
            // save data, bec-se head will be changed
            int data = head->data;
            // change head to previous element
            head = head->next_ptr;
            // clear data
            delete temp;
            return data;
        }
        else
        {
            throw StackException("\nerror: Stack is empty\n");
        }
    }

template < class T>
    T Stack<T>::top()
    {
        if (!empty())
        {
            return head->data;
        }
        else
        {
            throw StackException("\nerror: Stack is empty\n");
        }
    }