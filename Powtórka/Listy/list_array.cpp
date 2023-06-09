/* Implementacja tablicowa listy
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

const int maxlenght = 10;
struct list{
    elementtype elements[maxlength];
    int last;
} 
int position;

Position END(list l){
    return l.last + 1;
}

Position FIRST(List l){
    return 0;
}

Position Nextt(position p, list l){
    if ((p>l.last) || (p<0)) return -1;
    return p+1;
}

Position Previous(position p, list l){
    if ((p>l.last + 1) || (p<0)) return -1;
    return p-1;
}

Position Locate(elementtype x, list l){
    int i=0;
    while((i<=l.last) && (l.elements[i] != x)) i++;
    return i;
}

Position Retrieve(position p, list l){
    if ((p>l.last) || (p<0)) return min
    return l.elements[p];
}

bool instert(int x, position p, list l){
    if (l.last>=maxlength) return false //brak miejsca w tablicy
    else if ((p>l.last+1) || (p<0)) return false //pozycja nie istnieje
    else{
        for (int i=l.last; i>=p;i- -) //przesuń elementy z pozycji p, p+1,… w dół tablicy
            l.elements[i+1]=l.elements[i]
        l.elements[p]=x;
        l.last=l.last+1;
        return true;
    }
}

bool delete(position p, list l){
    if ((p>l.last) || (p<0)) return false;//'pozycja nie istnieje'
    else {
        for (int i=p;i< l.last;i++)
            l.elements[i]=l.elements[i+1];
        l.last--;
        return true;
    }
}