
#define once
class ListException
{
    std::string error;
    public:
        std::string what()
        {
            return error;
        }

    ListException(std::string error): error(error) {}
};

template < class T>
    class List
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

        Node<T> *head;
        int size;
        public:
            class Iterator;
        Iterator begin()
        {
            return Iterator(head);
        }

        Iterator end()
        {
            return Iterator(nullptr);
        }

        class Iterator
        {
            public:
                Iterator()
                {
                    current_node = head;
                }

            Iterator(const Node<T> *pNode)
            {
                current_node = pNode;
            }

            Iterator &operator=(const Node<T> *pNode)
            {
                this->current_node = pNode;
                return * this;
            }

            // Prefix ++ overload
            Iterator &operator++()
            {
                if (current_node)
                {
                    current_node = current_node->next_ptr;
                }

                return * this;
            }

            // Postfix ++ overload
            Iterator &operator++(int)
            {
                Iterator iterator = *this;
                ++ *this;
                return iterator;
            }

            bool operator!=(const Iterator &iterator)
            {
                return current_node != iterator.current_node;
            }

            int operator*()
            {
                return current_node->data;
            }

            private:
                const Node<T> *current_node;
        };

        List();
        ~List();
        void push_back(T data);
        void push_front(T data);
        void insert(T data, int index);
        void remove(int index);
        T get_element(int index);
        T pop_front();
        T pop_back();
        void clear();
        bool empty();
        int get_size()
        {
            return size;
        }

        private:
            Node<T> *get_pointer(int index)
            {
                if (index >= 0 && index < size)
                {
                    Node<T> *current = head;
                    // go to the position in the List
                    for (int i = 0; i < index; i++)
                    {
                        current = current->next_ptr;
                    }

                    return current;
                }
                else
                {
                    throw ListException("\nerror: index is wrong\n");
                }
            }
    };

template < class T>
    List<T>::List()
    {
        head = nullptr;
        size = 0;
    }

template < class T>
    List<T>::~List()
    {
        while (head != nullptr)
        {
            pop_front();
        }
    }

// check List emptiness (List has size, but why not)
template < class T>
    bool List<T>::empty()
    {
        return head == nullptr;
    }

template < class T>
    void List<T>::push_front(T data)
    {
        // set new head
        // old head is sent as a parameter
        head = new Node<T> (data, head);
        size++;
    }

template < class T>
    void List<T>::push_back(T data)
    {
        // if stack is not init
        if (head == nullptr)
        {
            push_front(data);
        }
        else
        {
            Node<T> *current = head;
            // go to the last element
            while (current->next_ptr != nullptr)
            {
                current = current->next_ptr;
            }

            // set the new last element
            current->next_ptr = new Node<T> (data);
            size++;
        }
    }

template < class T>
    void List<T>::insert(T data, int index)
    {
        // if insert as the first element
        if (index == 0)
        {
            push_front(data);
        }
        else if (index >= 0 && index <= size)
        {
            Node<T> *previous = head;
            // go to the position in the List
            for (int i = 0; i < index - 1; i++)
            {
                previous = previous->next_ptr;
            }

            // paste element and old next_ptr send as a parameter
            previous->next_ptr = new Node<T> (data, previous->next_ptr);
            size++;
        }
        else
        {
            throw ListException("\nerror: index is wrong\n");
        }
    }

template < class T>
    T List<T>::pop_front()
    {
        if (size > 0)
        {
            // get data from first element
            T data = head->data;
            // save adress first element
            Node<T> *tmp = head;
            // redefine first element
            head = head->next_ptr;
            // clear old first element
            delete tmp;
            size--;
            return data;
        }
        else
        {
            throw ListException("\nerror: List is empty\n");
        }
    }

template < class T>
    T List<T>::pop_back()
    {
        // if List consists of one element
        if (size == 1)
        {
            return pop_front();
        }
        else if (size > 1)
        {
            Node<T> *current = head;
            // go to the second last element
            for (int i = 0; i < size - 2; i++)
            {
                current = current->next_ptr;
            }

            // get address the last element
            Node<T> *tmp = current->next_ptr;
            // get the data of the last element
            T data = tmp->data;
            // remove the last element from the List
            current->next_ptr = nullptr;
            // clean adress
            delete tmp;
            size--;
            return data;
        }
        else
        {
            throw ListException("\nerror: List is empty\n");
        }
    }

template < class T>
    void List<T>::clear()
    {
        this->~List();
    }

template < class T>
    void List<T>::remove(int index)
    {
        // if remove the first element
        if (index == 0)
        {
            pop_front();
        }
        else if (index > 0 && index < size)
        {
            Node<T> *previous = head;
            // go to the "preposition" in the List
            for (int i = 0; i < index - 1; i++)
            {
                previous = previous->next_ptr;
            }

            // element which need to delete
            Node<T> *temp = previous->next_ptr;
            // redefine next_ptr element in the "preposition"
            previous->next_ptr = temp->next_ptr;
            // free up memory
            delete temp;
            size--;
        }
        else
        {
            throw ListException("\nerror: index is wrong\n");
        }
    }

template < class T>
    T List<T>::get_element(int index)
    {
        return get_pointer(index)->data;
    }