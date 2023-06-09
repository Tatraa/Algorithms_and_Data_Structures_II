/* Stos (LIFO)
// Stos jest to lista, w której wstawianie oraz usuwanie elementów odbywa się tylko na jednym końcu zwanym
// wierzchołkiem stosu (TOP). Z reguły identyfikujemy wierzchołek z pierwszym elementem listy.
// Operacje na liście"
// MAKENULL(S) - uczyń stos pustym
// TOP(S) - zwróć element znajdujący się na wierzchołku stosu
// POP(S) - usuń element znajdujący się na wierzchołku stosu
// PUSH(x,S) - umieść element x na wierzchołku stosu S. Element, który znajdował się poprzednio na wierzchołku
// stosu staje się wtedy następnym po x
// EMPTY(S) - zwraca true, jeśli S jest stosem pustym, w przeciwnym razie false
*/

const maxlenght=20;
typedef int elementtype;
typedef int positionl

class Stos{
protected:
    int S[maxlenght];
    position Top;
public:
    Stos();
    void Push(elementtype x);
    void Pop();
    bool Empty();
    elementtype TopElem();
    void Makenul();
};

Stos::Stos(void)
{
    Top=-1;
}

void Stos::Makenull()
{
    Top=-1;
}

void Stos::Push(elementtype x)
{
    if (Top <maxlegth-1)
    {
        Top++;
        S[Top]= x;
    }
}// PUSH

void Stos::Pop()
{
    if (Top >= 0) Top--;
}//POP

bool Stos::Empty()
{
    return (Top==-1);
}//Empty

elementtype Stos::TopElem()
{
    if (Top>=0) return S[Top];
}