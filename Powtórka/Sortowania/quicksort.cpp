/* Sortowanie szybckie
// Jest to jeden z najczęściej używanych algorytmów sortowania
// Jest używany za najszybszy algorytm sortowania dla "losowych" danych wejściowych
// Algorytm pomocniczy:
// Wybierz losowo jakiś obiekt (u nas obiekt leżący w środku tablicy)
// Przeglądnij tablice od lewej, aż znajdziesz a[i]>=x
// Przeglądaj obiekt od prawej, aż znajdziesz a[j]<=x
// Zamień te dwa obiekty miejscami i kontynuuj proces "przeglądania i zamiany", aż nastąpi spotkanie gdzieś w środku tablicy
*/
quicksort(int l, int p){
    int i,j,x,w;
    i=l;
    j=p;
    x=a[(l+p)/2] // element środkowy
    while(i<=j){
        while(a[i]<x) i=i+1
        while(a[j]>x) j=j+1
        if(i<=j){
            w=a[i];
            a[i]=a[j];
            a[j]=w;
            i=i+1
            j=j-1;
        }
    }
    if (l<j) quicksort(l,j);
    if (i<p) quicksort(i,p);
}