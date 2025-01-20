#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////
//
// Code of Singly Linear
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template <class T>
class SinglyLL
{
    private:
        struct nodeSL<T> * First;
        int iCount;

    public:
        SinglyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    cout<<"Inside Constructor\n";
    First = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::Display()
{
    struct nodeSL<T> * temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<"|-> ";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct nodeSL<T> * newn = NULL;

    newn = new nodeSL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct nodeSL<T> * newn = NULL;
    struct nodeSL<T> * temp = First;

    newn = new nodeSL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeSL<T> * newn = NULL;
    int i = 0;
    struct nodeSL<T> * temp;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else 
    {
        temp = First;
        
        newn = new nodeSL<T>;
        newn->data = No;
        newn->next = NULL;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp -> next = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First -> next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp ->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeSL<T> * temp1;
    struct nodeSL<T> * temp2;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else 
    {
        temp1 = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }    
}

/////////////////////////////////////////////////////////////
//
// Code of Doubly Circular
//
/////////////////////////////////////////////////////////////
template <class T>
struct nodeDC
{
    T data;
    struct nodeDC *next;
    struct nodeDC *prev;
};

template <class T>
class DoublyCL
{
    private:
        struct nodeDC<T> * First;
        struct nodeDC<T> * Last;
        int iCount;

    public:
        DoublyCL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
DoublyCL<T>:: DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
    if(First == NULL && Last == NULL)
    {
        cout<<"Linked List is emprty\n";
        return;
    }

    cout<<"<=> ";
    do
    {
        cout<<"| "<<First->data <<"| <=> ";
        First = First -> next;
    }while(Last -> next != First);

    cout<<"\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last ->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;    
}

template <class T>
void DoublyCL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDC<T> * temp = NULL;
    struct nodeDC<T> * newn = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeDC<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one node
    {
        First = First -> next;
        delete Last->next;
        First -> prev = Last;
        Last -> next = First;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one node
    {
        Last = Last -> prev;
        delete First -> prev;

        Last -> next = First;
        First -> prev = Last;
    }
    iCount--;    
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    struct nodeDC<T> * temp = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }    
}

/////////////////////////////////////////////////////////////
//
// Code of Doubly Liear
//
/////////////////////////////////////////////////////////////
template<class T>
struct nodeDL
{
    T data;
    struct nodeDL *next;
    struct nodeDL *prev;
};

template<class T>
class DoublyLL
{
    private:
        struct nodeDL<T>* First;
        int iCount;

    public:
        DoublyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);        
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template<class T>
DoublyLL<T>::DoublyLL()
{
    First=NULL;
    iCount=0;
}

template<class T>
void DoublyLL<T>::Display()
{ struct nodeDL<T> *temp = First;
    cout<<"\nNULL <=>";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<"|<=> ";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

template<class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template<class T>
void DoublyLL<T>::InsertFirst(T No)
{
    struct nodeDL<T> *newn = NULL;

    newn = new nodeDL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;
    newn->prev=NULL;

    
    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First=newn;

    }
    iCount++;
}

template<class T>
void DoublyLL<T>::InsertLast(T No)
{
     struct nodeDL<T>* newn = NULL;
    struct nodeDL<T>* temp = First;

    newn = new nodeDL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
        newn->prev=temp;
    }
    iCount++;
}

template<class T>
void DoublyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDL<T>* newn = NULL;
    int i = 0;
    struct nodeDL<T>* temp=NULL;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else 
    {
        temp = First;
        
        newn = new nodeDL<T>;
        newn->data = No;
        newn->next = NULL;
        newn->prev=NULL;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp -> next->prev = newn;
        temp->next=newn;
        newn->prev=temp;
        iCount++;
    }
}

template<class T>
void DoublyLL<T>::DeleteFirst()
{
    struct nodeDL<T>* temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
        
    }
    else
    {
        First = First -> next;
        First->prev=NULL;
        delete temp;
        
    }
    iCount--;
}

template<class T>
void DoublyLL<T>::DeleteLast()
{
    
    struct nodeDL<T>* temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp ->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template<class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{ int i = 0;
    struct nodeDL<T>* temp1;
    struct nodeDL<T>* temp2;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else 
    {
        temp1 = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;
        if (temp2->next != NULL)
        {
            temp2->next->prev = temp1;
        }
        delete temp2;
      iCount--;
    }    

}

/////////////////////////////////////////////////////////////
//
// Code of Singly Circular
//
/////////////////////////////////////////////////////////////
template<class T>
struct nodeSC
{
    T data;
    struct nodeSC *next;
};
template<class T>
class SinglyCL
{
    private:
        struct nodeSC<T>* First;
        struct nodeSC<T>* Last;
        int iCount;

    public:
        SinglyCL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template<class T>
SinglyCL<T>::SinglyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template<class T>
void SinglyCL<T>::Display()
{    struct nodeSC<T>* temp = First; 
    if ((First == NULL) && (Last==NULL))
        {
            cout << "Linked list is empty\n";
            return;
        }
        
       
        do
        {
            cout <<"|"<<temp->data<<"|->";
            temp = temp->next;
        } while (temp != First);
        cout <<"\n";
}

template<class T>
int SinglyCL<T>::Count()
{
    return iCount;
}

template<class T>
void SinglyCL<T>::InsertFirst(T No)
{      struct nodeSC<T>* newn = NULL;
        newn=new nodeSC<T>;

        newn->data = No;
        newn->next = NULL;

        if ((First == NULL)&& (Last==NULL))
        {
            First = newn;
            Last = newn;
            newn->next = First;
        }
        else
        {
            newn->next = First;
            First = newn;
            Last->next = First;
        }
        iCount++;
}

template<class T>
void SinglyCL<T>::InsertLast(T No)
{
    struct nodeSC<T>* newn = new nodeSC<T>;
        newn->data = No;
        newn->next = NULL;

        if ((First == NULL) && (Last==NULL))
        {
            First = newn;
            Last = newn;
            newn->next = First;
        }
        else
        {
            Last->next = newn;
             Last = newn;
            Last->next = First;
        }
        iCount++;
}

template<class T>
void SinglyCL<T>::InsertAtPos(T No, int iPos)
{   struct nodeSC<T>* temp = NULL;
    struct nodeSC<T>* newn = NULL;
    int i = 0;
    if (iPos < 1 || iPos > iCount + 1)
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos==1)
    { 
        InsertFirst(No);
    }
    else if (iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        newn=new nodeSC<T>;
        newn->data=No;
        newn->next=NULL;
        temp = First;
        for (int i = 1; i < iPos - 1; ++i)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }

    iCount++;
}

template<class T>
void SinglyCL<T>::DeleteFirst()
{
    if (First == NULL)
    {
        cout << "Linked list is empty.\n";
        return;
    }

    if (First == Last)
    {
        // Only one node in the list
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        struct nodeSC<T>* temp = First;
        First = First->next;
        Last->next = First; // Update circular link
        delete temp;
    }

    iCount--;
}

    

template<class T>
void SinglyCL<T>::DeleteLast()
{   if (First == NULL)
    {
        cout << "Linked list is empty\n";
    }
    else if (First == Last)
    {
        // Only one node in the list
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        struct nodeSC<T>* temp = First;
        while (temp->next != Last)
        {
            temp = temp->next;
        }

        delete Last;
        Last = temp;
        Last->next = First; // Update circular link
    }

    iCount--;
}


template<class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{    struct nodeSC<T>* temp1=NULL;
     int i=0;
    if (iPos < 1 || iPos > iCount)
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
         temp1 = First;
        for (int i = 1; i < iPos - 1; ++i)
        {
            temp1 = temp1->next;
        }
        
        struct nodeSC<T>* target = temp1->next;
        temp1->next = target->next;
        delete target;
        iCount--;
    }
   
}


/////////////////////////////////////////////////////////////
//
// Code of Stack
//
/////////////////////////////////////////////////////////////
template<class T>
struct nodeS
{
    T data;
    struct nodeS *next;
};

template<class T>
class Stack
{
    private:
        struct nodeS<T>* First;
        int iCount;

    public:
        Stack();
        void Display();
        int Count();
        void Push(T No);  // InsertFirst()
        int Pop();   // DeleteFirst()
};

template<class T>
Stack <T>:: Stack()
{
    First = NULL;
    iCount = 0;
}

template<class T>
void Stack<T> ::Display()
{
    cout<<"Elements of stack are : \n";
    struct nodeS<T>* temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"\n";
        temp = temp -> next;
    }
    cout<<"\n";
}

template<class T>
int Stack<T> ::Count()
{
    return iCount;
}

template<class T>
void Stack<T> ::Push(T No)
{
    struct nodeS<T>* newn = NULL;

    newn = new nodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template<class T>
int Stack<T> ::Pop()
{
    int iValue = 0;
    struct nodeS<T>* temp = NULL;

    if(First == NULL)
    {
        cout<<"Unable to pop the element as stack is empty\n";
        return -1;
    }
    else
    {
        temp = First;

        iValue = First -> data;
        First = First -> next;
        delete temp;
        
        iCount--;
    }

    return iValue;
}


/////////////////////////////////////////////////////////////
//
// Code of Queue
//
/////////////////////////////////////////////////////////////
template<class T>
struct nodeQ
{
    T data;
    struct nodeQ *next;
};

template<class T>
class Queue
{
    private:
        struct nodeQ<T>* First;
        int iCount;

    public:
        Queue();
        void Display();
        int Count();
        void EnQueue(T No);  // InsertLast()
        T DeQueue();   // DeleteFirst()
};

template<class T>
Queue<T> :: Queue()
{
    First = NULL;
    iCount = 0;
}

template<class T>
void Queue<T> ::Display()
{
    cout<<"Elements of Queue are : \n";
    struct nodeQ<T>* temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp -> next;
    }
    cout<<"\n";
}

template<class T>
int Queue <T>::Count()
{
    return iCount;
}

template<class T>
void Queue<T> ::EnQueue(T No)
{
    struct nodeQ<T>* newn = NULL;
    struct nodeQ<T>* temp = NULL;

    newn = new nodeQ<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while(temp ->next != NULL)
        {
            temp = temp -> next;
        }

        temp->next = newn;
    }
    iCount++;
}

template<class T>
T Queue<T> ::DeQueue()
{
    int iValue = 0;
    struct nodeQ<T>* temp = NULL;

    if(First == NULL)
    {
        cout<<"Unable to remove the element as queue is empty\n";
        return -1;
    }
    else
    {
        temp = First;

        iValue = First -> data;
        First = First -> next;
        delete temp;
        
        iCount--;
    }

    return iValue;
}

int main()
{
    // LL of integer
    cout<<"-------------- Singly LL of Integers --------------\n";

    SinglyLL<int> *iobj = new SinglyLL<int>();
    int iRet = 0;

    iobj->InsertFirst(51);
    iobj->InsertFirst(21);
    iobj->InsertFirst(11);

    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    iobj->InsertLast(101);
    iobj->InsertLast(111);
    iobj->InsertLast(121);
    
    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    iobj->InsertAtPos(105,5);

    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    iobj->DeleteAtPos(5);
    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    // DC of float
     cout<<"-------------- DoublyCircular LL of Float --------------\n";
     
     DoublyCL<float> *fobj = new DoublyCL<float>();
    int fRet = 0;

    fobj->InsertFirst(51.2f);
    fobj->InsertFirst(21.2f);
    fobj->InsertFirst(11.2f);

    fobj->Display();
    fRet = fobj->Count();
    cout<<"Number of elemensts are : "<<fRet<<endl;

    fobj->InsertLast(101.2f);
    fobj->InsertLast(111.2f);
    fobj->InsertLast(121.2f);
    
    fobj->Display();
    fRet = fobj->Count();
    cout<<"Number of elemensts are : "<<fRet<<endl;

    fobj->InsertAtPos(105.2f,5);

    fobj->Display();
    fRet = fobj->Count();
    cout<<"Number of elemensts are : "<<fRet<<endl;

    fobj->DeleteAtPos(5);
    fobj->Display();
    fRet = fobj->Count();
    cout<<"Number of elemensts are : "<<fRet<<endl;
    
    // DL of character
     cout<<"-------------- DoublyLinear LL of Char --------------\n";

     DoublyLL<char> *cobj = new DoublyLL<char>();
    int cRet = 0;

    cobj->InsertFirst('A');
    cobj->InsertFirst('B');
    cobj->InsertFirst('C');

    cobj->Display();
    cRet = cobj->Count();
    cout<<"Number of elemensts are : "<<cRet<<endl;

    cobj->InsertLast('D');
    cobj->InsertLast('E');
    cobj->InsertLast('F');
    
    cobj->Display();
    cRet = cobj->Count();
    cout<<"Number of elemensts are : "<<cRet<<endl;

    cobj->InsertAtPos('G',5);

    cobj->Display();
    cRet = cobj->Count();
    cout<<"Number of elemensts are : "<<cRet<<endl;

    cobj->DeleteAtPos(5);
    cobj->Display();
    cRet = cobj->Count();
    cout<<"Number of elemensts are : "<<cRet<<endl;

    // SC of double
     cout<<"-------------- SinglyCircular LL of Double --------------\n";

     SinglyCL<double>*dobj = new SinglyCL<double>();
    int dRet = 0;

    dobj->InsertFirst(51.111);
    dobj->InsertFirst(21.111);
    dobj->InsertFirst(11.111);

    dobj->Display();
    dRet = dobj->Count();
    cout<<"Number of elemensts are : "<<dRet<<endl;

    dobj->InsertLast(101.111);
    dobj->InsertLast(111.111);
    dobj->InsertLast(121.111);
    
    dobj->Display();
    dRet = dobj->Count();
    cout<<"Number of elemensts are : "<<dRet<<endl;

    dobj->InsertAtPos(105.555,5);

    dobj->Display();
    dRet = dobj->Count();
    cout<<"Number of elemensts are : "<<dRet<<endl;

    dobj->DeleteAtPos(5);
    dobj->Display();
    dRet = dobj->Count();
    cout<<"Number of elemensts are : "<<dRet<<endl;

     // Stack
     cout<<"--------------  Stack of int --------------\n";
    Stack<int>*siobj = new Stack<int>();
    int siRet = 0;

    siobj->Push(10);
    siobj->Push(20);
    siobj->Push(30);
    siobj->Push(40);

    siobj->Display();

    siRet = siobj->Count();

    cout<<"Number of elements in the stack are : "<<siRet<<"\n";
    
    siRet = siobj->Pop();

    cout<<"Poped element is : "<<siRet<<"\n";

    siRet = siobj->Pop();

    cout<<"Poped element is : "<<siRet<<"\n";
    
    siobj->Display();

    siRet = siobj->Count();

    cout<<"Number of elements in the stack are : "<<siRet<<"\n";

    siobj->Push(50);

    siobj->Display();

    siRet = siobj->Count();

    cout<<"Number of elements in the stack are : "<<siRet<<"\n";
    

     // Queue
     cout<<"--------------  Queue of float --------------\n";
    Queue<float>*qfobj = new Queue<float>();
    int qfRet = 0;
    
    
    qfobj->EnQueue(10);
    qfobj->EnQueue(20);
    qfobj->EnQueue(30);
    qfobj->EnQueue(40);

    qfobj->Display();

    qfRet = qfobj->Count();

    cout<<"Number of elements in the Queue are : "<<qfRet<<"\n";
    
    qfRet = qfobj->DeQueue();

    cout<<"Removed element is : "<<qfRet<<"\n";

    qfRet = qfobj->DeQueue();

    cout<<"Removed element is : "<<qfRet<<"\n";
    
    qfobj->Display();

    qfRet = qfobj->Count();

    cout<<"Number of elements in the Queue are : "<<qfRet<<"\n";

    qfobj->EnQueue(50);

    qfobj->Display();

    qfRet = qfobj->Count();

    cout<<"Number of elements in the Queue are : "<<qfRet<<"\n";
    
    return 0;

    

    
}
