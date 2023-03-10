template <typename T>
Node<T>::Node(T value)
{
    data = value;
    next = prev = NULL;
}
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = tail = NULL;
    size = 0;
}
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{

    while (head)
    {
        Node<T>* move = head;
        head = head->next;
        delete move;
    }
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(istream& is)
{
    T n;
    size = 0;
    head = NULL;
    tail = NULL;
    while (is >> n)
    {
        this->insert_back(n);
    }
}

template <typename T>
void DoublyLinkedList<T>::insert_front(T value)
{
    Node<T>* temp = new Node<T>(value);

    if (head == NULL)
        head = tail = temp;
    else
    {
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
    size++;
}

template <typename T>
void DoublyLinkedList<T>::insert_back(T value)
{
    Node<T>* temp = new Node<T>(value);

    if (tail == NULL)
        head = tail = temp;
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    size++;
}

template <typename T>
T DoublyLinkedList<T>::delete_front()
{
    if (!is_empty())
    {
        Node<T>* temp = head;
        double delValue = temp->data;
        if (head == tail)
        {
            tail = NULL;
            head = NULL;
        }
        else {
            head = head->next; //setting head to NULL
            head->prev = NULL; //also set head->prev to NULL otherwise this node points to a freed memory space
        } //see how an else block is added
        delete temp;
        size--;

        return delValue;

    }
    return 0;
}

template <typename T>
T DoublyLinkedList<T>::delete_back()
{
    if (!is_empty())
    {
        Node<T>* temp = tail;
        double delValue = temp->data;
        if (head == tail)
        {
            head = NULL;
            tail = NULL;
        }
        else { //see how an else block is added
            tail = tail->prev;
            tail->next = NULL; // set tail->next to null otherwise it point to freed memory
        }
        delete temp;
        size--;
        return delValue;

    }
    return 0;
}

template <typename T>
bool DoublyLinkedList<T>::is_empty()
{
    if (size <= 0)
    {
        return true;
    }

    return false;
}

template <typename T>
void DoublyLinkedList<T>::display()
{
    Node<T>* temp = head;

    cout << "\n\nDisplay in forward order\n";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

template <typename T>
T DoublyLinkedList<T>::length()
{
    return size;
}

template <typename T>
void DoublyLinkedList<T>::search(T value)
{
    if (!is_empty())
    {
        Node<T>* temp = head;
        while (temp)
        {
            if (temp->data == value)
            {
                cout << "YES! got it." << endl;
                break;
            }
            temp = temp->next;
        }
    }
    else
    {
        cout << "List is empty" << endl;
    }
}

template <typename T>
void DoublyLinkedList<T>::duplicate_even()
{
    Node<T>* temp = head;
    Node<T>* temp2 = NULL;
    while(temp!= NULL)
    {
        int a = temp->data;
        if ( a%2 == 0)
        {
            if (temp == tail)
            {
                temp->next = new Node<T>(a);
                temp->next->prev = temp;
                temp->next->next = NULL;
                tail = temp->next;
            } else 
            {

            temp2 = temp->next;
            temp->next = new Node<T>(a);
            temp->next->prev = temp;
            temp->next->next = temp2;
            temp2->prev = temp->next;
            size++;
            }
            temp = temp->next;
        }
            temp = temp->next;
    }
}

template <typename T>
void DoublyLinkedList<T>::reverse()
{
     if(is_empty()){
    return;
    }
    Node<T>* temp1 = head;
    Node<T>* temp2;
    while (temp1 != NULL)
    {
        temp2 = temp1->next;
        temp1->next = temp1->prev;
        temp1->prev = temp2;
        temp1 = temp2;
    }
    temp2 = head;
    head = tail;
    tail = temp2;
}
template <typename T>
void DoublyLinkedList<T>::delete_not_unique()
{
    Node<T>* temp1 = head;
    // std::cout <<(head->next->data)<< "     ";
    
    Node<T>* temp2 = NULL;
    Node<T>* temp3 = NULL;
    bool check;
    while(temp1 != NULL)
    {        
        T data = temp1->data;
        temp2 = temp1->next;
        check = 0;
        while (temp2!= NULL)
       {
            if (temp2->data == temp1->data)
            {
                temp3 = temp2->next;
                if (temp3 != NULL)
                {
                    temp3->prev = temp2->prev;
                }
                else 
                {
                    tail = temp2->prev;
                }
                temp2->prev->next = temp3;
                temp2->prev = NULL;
                temp2->next = NULL;
                delete temp2;
                check = 1;
                temp2 = temp3;
            } else 
            {
                temp2 = temp2->next;
            }

       }
       if (check)
       {
            temp3 = temp1->next;
            if (temp1->prev != NULL)
            {
                temp1->prev->next = temp1->next;
            }
            else {
                head = temp3;
            }
            if (temp1->next != NULL)
            {
            temp1->next->prev = temp1->prev;

            }else 
            {
                tail = temp1->prev;
            }
            temp1->prev == NULL;
            temp1->next == NULL;
            delete temp1;
            temp1 = temp3;
        } else 
        {
            temp1 = temp1->next;
        }
    }        
       
}

