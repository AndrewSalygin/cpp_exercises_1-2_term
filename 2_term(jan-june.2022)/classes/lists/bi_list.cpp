
#define once
class BiListException
{
    std::string error;
    public:
        std::string what()
        {
            return error;
        }

    BiListException(std::string error): error(error) {}
};

template < class T>
    class BiList
    {
        template < class T>
            class Node
            {
                public:
                    Node * next_ptr;
                Node * previous_ptr;
                T data;
                // T() - clear trash in data
                // next_ptr - point to next element
                Node(T data = T(), Node *next_ptr = nullptr, Node *previous_ptr = nullptr)
                {
                    this->data = data;
                    this->next_ptr = next_ptr;
                    this->previous_ptr = previous_ptr;
                }
            };

        Node<T> *head, *tail;
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

        BiList();
        ~BiList();
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
                    if (abs(index) <= abs(size - 1 - index))
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
                        Node<T> *current = tail;
                        // go to the position in the List
                        for (int i = size - 1; i > index; i--)
                        {
                            current = current->previous_ptr;
                        }

                        return current;
                    }
                }
                else
                {
                    throw BiListException("\nerror: index is wrong\n");
                }
            }
    };

template < class T>
    BiList<T>::BiList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

template < class T>
    BiList<T>::~BiList()
    {
        while (head != nullptr)
        {
            pop_front();
        }

        tail = nullptr;
    }

// check List emptiness (List has size, but why not)
template < class T>
    bool BiList<T>::empty()
    {
        return head == nullptr;
    }

template < class T>
    void BiList<T>::push_front(T data)
    {
        // set new head
        // old head is sent as a parameter
        if (head)
        {
            Node<T> *temp = head;
            head = new Node<T> (data, head);
            // connect old element with new left element
            temp->previous_ptr = head;
        }
        else
        {
            head = new Node<T> (data);
            tail = head;
        }

        size++;
    }

template < class T>
    void BiList<T>::push_back(T data)
    {
        // if stack is not init
        if (head == nullptr)
        {
            push_front(data);
        }
        else
        {
            // set new tail
            // old tail is sent as a parameter
            Node<T> *temp = tail;
            tail = new Node<T> (data, nullptr, tail);
            // connect old element with new right element
            temp->next_ptr = tail;
            size++;
        }
    }

template < class T>
    void BiList<T>::insert(T data, int index)
    {
        // if insert as the first element
        if (index == 0)
        {
            push_front(data);
        }
        else if (index == size)
        {
            push_back(data);
        }
        else if (index > 0 && index < size)
        {
            if (abs(index) <= abs(size - 1 - index))
            {
                Node<T> *previous = head;
                // go to the position in the List
                for (int i = 0; i < index - 1; i++)
                {
                    previous = previous->next_ptr;
                }

                // paste element and current next_ptr send as a parameter
                // current element as a previous parametr for pasting element
                previous->next_ptr = new Node<T> (data, previous->next_ptr, previous);
                // go to new element
                previous = previous->next_ptr;
                // go to old next_ptr and define for it - new previous_ptr (pasting element)
                previous->next_ptr->previous_ptr = previous;
            }
            else
            {
                Node<T> *next = tail;
                // go to the position in the List
                for (int i = size - 1; i > index; i--)
                {
                    next = next->previous_ptr;
                }

                // paste element and current previous_ptr send as a parameter
                // current element as a next parametr for pasting element
                next->previous_ptr = new Node<T> (data, next, next->previous_ptr);
                // go to new element
                next = next->previous_ptr;
                // go to old previous_ptr and define for it - new next_ptr (pasting element)
                next->previous_ptr->next_ptr = next;
            }

            size++;
        }
        else
        {
            throw BiListException("\nerror: index is wrong\n");
        }
    }

template < class T>
    T BiList<T>::pop_front()
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
            throw BiListException("\nerror: List is empty\n");
        }
    }

template < class T>
    T BiList<T>::pop_back()
    {
        // if List consists of one element
        if (size == 1)
        {
            return pop_front();
        }
        else if (size > 1)
        {
            // get address the second last element
            Node<T> *tmp = tail->previous_ptr;
            // get the data of the last element
            T data = tail->data;
            // remove the last element from the List
            tmp->next_ptr = nullptr;
            // clean data
            delete tail;
            // redefine adress
            tail = tmp;
            size--;
            return data;
        }
        else
        {
            throw BiListException("\nerror: List is empty\n");
        }
    }

template < class T>
    void BiList<T>::clear()
    {
        this->~BiList();
    }

template < class T>
    void BiList<T>::remove(int index)
    {
        // if insert as the first element
        if (index == 0)
        {
            pop_front();
        }
        else if (index == size - 1)
        {
            pop_back();
        }
        else if (index > 0 && index < size - 1)
        {
            if (abs(index) <= abs(size - 1 - index))
            {
                Node<T> *previous = head;
                // go to the position in the List
                for (int i = 0; i < index - 1; i++)
                {
                    previous = previous->next_ptr;
                }

                // element which need to delete
                Node<T> *temp = previous->next_ptr;
                // redefine next_ptr and previous_ptr
                // in the "preposition"
                previous->next_ptr = temp->next_ptr;
                temp->next_ptr->previous_ptr = previous;
                // free up memory
                delete temp;
            }
            else
            {
                Node<T> *next = tail;
                // go to the position in the List
                for (int i = size - 1; i > index + 1; i--)
                {
                    next = next->previous_ptr;
                }

                // element which need to delete
                Node<T> *temp = next->previous_ptr;
                // redefine next_ptr and previous_ptr
                // in the "preposition"
                next->previous_ptr = temp->previous_ptr;
                temp->previous_ptr->next_ptr = next;
                // free up memory
                delete temp;
            }

            size--;
        }
        else
        {
            throw BiListException("\nerror: index is wrong\n");
        }
    }

template < class T>
    T BiList<T>::get_element(int index)
    {
        return get_pointer->data;
    }