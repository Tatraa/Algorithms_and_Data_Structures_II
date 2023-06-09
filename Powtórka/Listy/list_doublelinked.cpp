/* Implementacjadwukierunkowej listy
// Często potrzebne jest przechodzenie po liście w obu kierunkach oraz dostęp do elementów bezpośrednio poprzedzającego
// oraz bezpośrednio następującego po danym
// W takich sytuacjach wyposażamy każdą komórkę listy we wskaźniki: do elementu poprzedzającego i 
// następującego po nim
// ciąg zmiennych dynamicznych powiązanych wiązaniami. Jedna zmienna wskazuje na drugą dzięki polu
// typu wskaźnikowego, który jest jej składnikiem
// Operacje na liście:
// INSERT(x,p,L) – wstaw x na pozycję p na liście L
// Jeśli p jest pozycją END(L), to lista a_1,...,a_n staje się listą a_1,..,a_n,x
// LOCATE(x,L) zwraca pozycję pierwszego wystąpienia elementu x w liście L. Jeśli x nie 
// występuje w liście to zwraca END(L)
// Retrievie(p,L) - zwraca element występujący w L na pozycju p
// DELETE(p,L) - usuwa element na pozycji p z listy. Gdy w L nie ma pozycji p lub p=END(L) to wynik jest nieokreślony
// NEXT(p,L) - zwraca pozycje następną w stosunku do p w L. jeśli p jest pozycją ostatniego elementu w liście L to next(p,L)=END(L)
// PRevious(p,L) - zwraca pozycję poprzednią w stosunku do p w L. Gdy p=FIRST(L) to previous jest nieokreślone
// MAKENULL(L) - czyni liste pustą i zwraca pozycję END(L)
// FIRST(L) - zwraca pozycję pierwszego elementu w L. Jeśli L jest pusta zwraca END(L)
*/

typedef int elementtype;
typedef struct celltype {
    elementtype element;
    celltype * next;
    celltype * prev;
}
typedef celltype * position;

class Lista
{
protected : 
position l; // wskaźnik do głowy listy
public:
    Lista(); //konstruktor
    ~Lista(); //destruktor
    void Insert(elementtype x, position p);
    void Delete(position p);
    elementtype Retrieve(position p);
    position Locate(elementtype x);
    position First();
    position Next(position p);
    position Previous(position p);
    position END();
};

Lista::Lista()
{//mamy listę bez głowy, więc konstruktor ustawia l na NULL
    l=NULL;
}

void Lista::Insert(elementtype x,position p){
    position tmp;
    if (p==l) //chcemy wstawić na początek listy
    { 
        l=new celltype;
        l->element=x;
        l->next=p;
        l->prev=NULL;
        if (l->next!=NULL) l->next->prev=l;
    }
    else
    { 
        if (p==NULL)//chcemy wstawić na koniec listy-za ostatnim elementem
    {
        tmp=l; while (tmp->next!=NULL) tmp=tmp->next;}
    else tmp=p->prev;
    tmp->next=new celltype;
    tmp->next->element=x;
    tmp->next->next=p;
    tmp->next->prev=tmp;
    if (tmp->next->next!=NULL) tmp->next->next->prev=tmp->next;
    }
}// INSERT

void Lista::Delete(position p)
{
    if (l!=NULL) 
    {
        if (p->prev!=NULL) p->prev->next=p->next;
        if (p->next!=NULL) p->next->prev=p->prev;
        if (p==l) l=p->next;
        delete p;
    }
}//delete

position Lista::Locate(elementtype x)
{
    position tmp=l;
    while (tmp!=NULL) 
    {
        if (tmp->element==x) return tmp;
        tmp=tmp->next;
    }
    return tmp; //zwraca ENDL, jeśli wcześniej nie został
                // znaleziony rekord z elementem x}
}//locate

elementtype Lista::Retrieve(position p)
{
    return p->element;
}//retrieve

position Lista::First()
{
    return l;
}

position Lista::Next(position p)
{
    return p->next;
}

position Lista::Previous(position p)
{
    if (p==NULL) //chcemy zwrócić wskaźnik do ostatniej komórki
    {
        position tmp=l;
        while (tmp->next!=NULL) tmp=tmp->next;
        return tmp;
    }
    else
        return p->prev; 
}

Lista::~Lista()
{
    //mamy listę bez głowy, więc destruktor usuwa wszystkie elementy oprócz głowy
    position tmp;
    while (l!=NULL)
    {
        tmp=l;
        l=l->next;
        delete tmp;
    }
}
