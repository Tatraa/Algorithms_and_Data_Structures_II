/* Sortowanie przez zamianę
// Dane:    int a[n]
// Wyjście: tablica posortowania niemalejąco
// Sposób postępowania:
// Algorytm opiera się na zasadzie porównywania i zamiany par sąsiadujących ze sobą obiektów (przeglądając od prawej do lewej)
// W ten sposób po pierwszym kroku algorytmu w lewym końcu tablicy będzie najmniejszy element, po drugim kroku pierwsze dwa itd
*/

bubblesort()
int x;
{
    for(int i=1; i<n; i++){
        for(int j = n-1; j>=i; j--){
            if(a[j-1] > a[j]){
                swap(a[j-1], a[j]);
            }
        }
    }
}