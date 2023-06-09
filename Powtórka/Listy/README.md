##### Reprezentacja wskaźnikowa i tablicowa listy - porównanie

Implementacja tablicowa wymaga podania w momencie implementacji maksymalnego rozmiaru tablicy, stąd często "marnotrawienie pamięci"

Lista wskaźnikowa potrzebuje więcej pamięci do przechowywania tej samej liczby danych

Pewne operacje zajmują więcej czasu w jednej implementacji niż w drugiej:
- np. INSERT i DELETE zajmują stały czas w reprezentacji wskaźnikowej ale ich czas rośnie wraz z rozmiarem listy w reprezentacji tablicowej
- np. PREVIOUS i END zajmują stały czas w reprezentacji tablicowej, ale ich czas rośnie wraz z rozmiarem listy w reprezentacji wskaźnikowej