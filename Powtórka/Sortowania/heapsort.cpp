/* Sortowanie stogowe
// Drzewo jest zbiorem elementów zwanych wierzchołkami, spośród których jeden wyróżniony nazywamy korzeniem
// W zbiorze wierzchołków określona jest relacja bycia rodzicem, która nakłada hierarchiczną strukturę na ten zbiór
// Drzewo binarne to drzewo, które albo jest drzewem pustym, albo drzewem w którym każdy węzeł posiada co najwyżej
// dwoje dzieci (prawe i lewe)
//
// Wartości w węzłach - dzieciach są mniejsze od wartości w węźle rodzicielskim
// Stóg:        9
//             / \
//            8   7
//           / \ / \
//          6  3 5  2
//         /
//        4
// Reprezentacja tablicowa: 9 8 7 6 3 5 2 4
*/


// Tworzenie kopca
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Budowanie kopca (Heap)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Wydobywanie elementów z kopca
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}