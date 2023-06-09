/* Drzewo - zbiór elementów zwanych wierzchołkami, spośród których jeden wyróżniony nazywany jest korzeniem.
// W zbiorze wierzchołków określona jest relacja bycia rodzicem, która nakłada hierarchiczną strukturę na ten zbiór
// Najwyżej jest korzeń, ostatnie dzieci są nazywane liśćmi 
// Podstawowe operacje:
// Parent(n) - zwraca rodzica węzła n w drzewie T. Jeśli n to korzeń to zwraca węzeł pusty
// LeftMostChild(n) - zwraca pierwsze z lewej dziecko węzła n, lub węzeł pusty jeśli jest liściem
// RightSibling(n) - zwraca pierwszego na prawo sąsiada węzła n w T. Musi on mieć tego samego rodzica
// co węzeł n. Jeśli nie ma takiego węzła to zwraca węzeł pusty
// Label(n) - zwraca etykietę węzła n w T.
// Create(v, T1, T2, T3...) - tworzy nowy węzeł o etykiecie v i daje mi "i" dzieci, które są korzeniami drzew T1, T2, ...
// Root(T) - zwraca węzeł który jest korzeniem T lub węzeł pusty jeśli T jest drzewem pustym
// Makenull(T) - czyni T drzewem pustym
*/

struct Node
{ Telement info;
 Node * left;
 Node * right;};
typedef Node *PNode;
class BinaryTree
{
protected:
    PNode T;
public:
    BinaryTree();
    PNode PARENT(PNode n,PNode T);
    PNode LEFT_MOST_CHILD(PNode n);
    PNode RIGHT_SIBLING(PNode n);
    Telement GetLabel(PNode n);
    PNode BuildTree1(int n)
    void BuildTree(int n);
    PNode ROOT();
    void MAKENULL(PNode p);
};

BinaryTree::BinaryTree()
{T=NULL;}

BinaryTree::~BinaryTree()
{MAKENULL(T);}

void BinaryTree::MAKENULL(PNode p)
{
    if (p!=NULL)
    {
        if (p->left!=NULL) MAKENULL(p->left);
        if (p->right!=NULL) MAKENULL(p->right);
        delete p;
        p=NULL;
    }
}

PNode BinaryTree::ROOT()
{
    return T;
}

PNode BinaryTree::PARENT(PNode n ,PNode T)
{
    if (n==T) return NULL
        return PARENT1(n,T);
}

PNode BinaryTree::PARENT1(PNode n ,PNode T)
{
    if ((T->left==n) || (T->right==n)) 
        return T;
    Pnode tmp1=NULL;
    Pnode tmp2=NULL;
    if (T->left!=NULL)
        tmp1=PARENT1(n,T->left);
    if (T->right!=NULL)
        tmp2=PARENT1(n,T->right)
    return (tmp1!=NULL)?tmp1 :tmp2;
}

PNode BinaryTree::LEFT_MOST_CHILD(PNode n)
{
    return n->left;
}

PNode BinaryTree::RIGHT_SIBLING(PNode n)
{
    PNode tmp=PARENT(n,T);
    if ((tmp->left)==n) return tmp->right;
    else return NULL;
}

PNode BinaryTree::BuildTree1(int n)
{
    if (n==0) return;
    int nl, np;
    Telement x;
    PNode tmp;
    nl=n/ 2;
    np= n-nl-1;
    cout <<"Podaj wartość do wstawienia:";
    cin >>x;
    tmp=new Node;
    tmp->info=x;
    tmp->left=BuildTree1(nl);
    tmp->right=BuildTree1(np);
    return tmp;
}

void BinaryTree::BuildTree(int n)
{
    T=BuildTree1(n);
}

// Istnieje wiele zadań, które wykonuje się na drzewach - najczęściej należy wykonać jakąś operację na każdym węźle drzewa
// W jakiej kolejności odwiedzać węzły drzewa aby wykonać żądaną operacje?

// preorder (porządek wzdłużny) - odwiedzany korzeń przed poddrzewami
// inorder (porządek poprzeczny) - odwiedzamy lewe poddrzewo, korzeń, prawe poddrzewo
// postorder (porządek wsteczny) - odwiedzamy korzeńpo poddrzewach

void PreOrder(PNode t)
{
    if (t!= NULL) 
    {
        cout << t->info;
        PreOrder(t->left);
        PreOrder(t->right);
    }
}

void InOrder(PNode t)
{
    if (t!= NULL) 
    {
        InOrder(t->left);
        cout << t->info;
        InOrder(t->right);
    }
}

void PostOrder(PNode t)
{
    if (t!= NULL) 
    {
        PostOrder(t->left);
        PostOrder(t->right);
        cout << t->info;
    }
}
