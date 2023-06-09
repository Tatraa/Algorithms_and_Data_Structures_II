/* Implementacja wskaźnikowa listy
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
}

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
{//tworzy głowę
    l=new celltype;
    l->next=NULL;
}

void Lista::Insert(elementtype x,position p)
{
    position tmp;
    tmp=p->next;
    p->next=new celltype;
    p->next->element=x;
    p->next->next=tmp;
}// INSERT

void Lista::Delete(position p)
{
    position tmp;
    tmp=p->next;
    p->next=p->next->next;
    delete tmp;
}//delete

position Lista::Locate(elementtype x)
{
position tmp;
tmp=l;
while (tmp->next!=NULL) //dopóki tmp nie wskazuje na ostatni rekord listy}
    {
    if (tmp->next->element==x) return tmp;
    
    tmp=tmp->next;
    }
return tmp; //zwraca ENDL, jeśli wcześniej nie został znaleziony rekord z elementem x
}//locate 

elementtype Lista::Retrieve(position p)
{ 
    if (p->next!=NULL)
         return p->next->element;
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
    position tmp;
    tmp=l;
    while (tmp->next!=p) tmp=tmp->next;
    return tmp;
}

position Lista::END()
{
    position tmp;
    tmp=l;
    while (tmp->next!=NULL) tmp=tmp->next;
    return tmp;
}

Lista::~Lista();
{
    while (l->next!=NULL){ temp=l->next;
        l->next=temp->next;
        delete tmp;
    }
    delete l;
}