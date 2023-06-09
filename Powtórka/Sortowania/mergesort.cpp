/* Sortowanie przez scalanie
// Dane:    int a[n]
// Wyjście: tablica posortowania niemalejąco
// Spsób postępowania:
// Podziel ciąg a[0],..,a[n-1], na dwa podciągi, a[0],..,a[m] oraz a[m+1],..,a[n-1]
// Posortuj rekurencyjnie każdy z podciągów
// Scal oba podciągi w jeden
*/

void mergesort(int l, int r){
    int m;
    if(l<r){
        m = (l+r) / 2;
        mergesort(l, m); // dzielenie
        mergesort(m+1, r);
        bitmerge(l, m, r) // scalanie
    }
}

// Scalanie:
// Zastosujemy łatwiejszą w zaprogramowaniu wersje scalania: SCALANIE CIĄGU BITONICZNEGO
// Tablica aux[0..n-1] - globalna tablica robocza
// Będziemy kopiować z tablicy a do aux oba sąsiednie ciągi, w prawym odwracając kolejność
// W ten sposób powstanie ciąg bitoniczny: do połowy rosnący, do połowy malejący

bitmerge (int l, int m,int r){
    for (int i=0; i<=m; i++) aux[i] = a[i] ;
    for (int j=m+1; j<=r;j++) aux[r+m+1-j] = a[j] ;
    // teraz scalaj ciąg bitoniczny w aux, przepisując go na stare
    // miejsce w tablicy a; w tym celu przeglądaj ciąg bitoniczny 
    // od lewej i od prawej 
    i=l ; j=r ;
    for (int k=l;k<=r;k++) {
    //wystarcza zliczanie przepisanych elementów;
    //nie trzeba sprawdzać wyjścia i, j poza tablicę *)

    if aux[j] < aux[i] 
        { a[k] = aux[j] ; j = j-1 } 
    else
        {a[k] = aux[i] ; i = i+1 }
    }
}