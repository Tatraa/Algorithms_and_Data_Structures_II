/* Sortowanie przez wstawianie
// Dane:    int a[n]
// Wyjście: tablica posortowana niemalejąco
// Sposób postępowania:
// Dla każdego i = 2,3,..,n należy powtarzać wstawianie a[i] w już uporządkowaną część listy a[1]<=...<=a[i-1]
// Przykład: 5 3 8 6 1 9
             3 5 8 6 1 9
             3 5 8 6 1 9
             3 5 6 8 1 9
             1 3 5 6 8 9
*/
void prostewstawianie()

int j,x; 
{
    for (int i=2;i<=n;i++){ x=a[i]; a[0]=x; 
        j=i-1;
        while (x<a[j]){ 
            a[j+1]=a[j];
            j=j-1; //przesuwamy w prawo, robimy miejsce na nasz element
        } 
        a[j+1]=x;
    }
}
