class MyLinkedList
{
private:
    struct Node
    {
        int val;
        Node *next;
        Node() : val(0), next(nullptr) {}
        Node(int x) : val(x), next(nullptr) {}
        Node(int x, Node *next) : val(x), next(next) {}
    };
    Node *head;
    Node *tail;
    int count;

public:
    /** Initialize your data structure here. */
    MyLinkedList()
    {
        head = tail = nullptr;
        count = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if (!head || !tail)
            return -1;
        if (index == 0)
            return head->val;
        if (index == count - 1)
            return tail->val;
        int i = 0;
        for (Node *c = head; c != nullptr; c = c->next, ++i)
            if (i == index)
                return c->val;
        return -1;
    }

    /** Add a node of value val before the first element of the linked list. 
     * After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        head = new Node(val, head);
        if (!tail)
            tail = head;
        ++count;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        if (!head)
        {
            addAtHead(val);
            tail = head;
        }
        else
        {
            tail->next = new Node(val, nullptr);
            tail = tail->next;
        }
        ++count;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index > count)
            return;
        if (index == count)
            addAtTail(val);
        else if (index == 0)
            addAtHead(val);
        else
        {
            Node *c = head;
            int i = 0;
            while (i++ < index - 1)
                c = c->next;
            c->next = new Node(val, c->next);
            ++count;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (!head || !tail || index < 0 || index > count)
            return;
        if (index == 0)
        {
            Node *td = head;
            head = head->next;
            --count;
            delete td;
            return;
        }
        int i = 0;
        bool deleted = false;
        for (Node *c = head; !deleted && c->next != nullptr; c = c->next, ++i)
            if (i == index - 1)
            {
                Node *td = c->next;
                c->next = td->next;
                if (index == count - 1)
                    tail = c;
                --count;
                delete td;
                deleted = true;
            }
    }
};