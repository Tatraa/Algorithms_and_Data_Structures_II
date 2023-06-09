# ONP - Odwrotna notacja polska

System notacji beznawiasowej umożliwiający zapis wyrażeń arytmetycznych w ten sposób, że najpierw występują operandy (argumenty) a następnie operator (działanie)

Np. </br>
__2 3 +__ odpowiada wyrażeniu __2 + 3__ </br>
__x sin__ odpowiada wyrażeniu __sinx__ </br>
__x y + sin__ odpowiada wyrażeniu __sin(x+y)__ </br>
__a-b+c/de-*__ odpowiada wyrażeniu __(-a+b)/c*(d-e)__


### Pseudokod algorytmu

Funkcja infix_do_onp(wyrazenie_infix):
    inicjalizuj pusty stos
    inicjalizuj pusty napis wyjsciowy

    Dla kazdego znaku w wyrazenie_infix:
        Jeśli znak jest operandem:
            Dodaj go do napisu wyjsciowego
        W przeciwnym razie, jeśli znak jest operatorem:
            Dopóki stos nie jest pusty i operator na szczycie stosu ma wyższy lub równy priorytet niż bieżący operator:
                Usuń operator ze stosu i dodaj go do napisu wyjsciowego
            Dodaj bieżący operator na stos
        W przeciwnym razie, jeśli znak jest lewym nawiasem '(':
            Dodaj go na stos
        W przeciwnym razie, jeśli znak jest prawym nawiasem ')':
            Dopóki operator na szczycie stosu nie jest lewym nawiasem '(':
                Usuń operator ze stosu i dodaj go do napisu wyjsciowego
            Usuń lewy nawias '(' ze stosu
    Dopóki stos nie jest pusty:
        Usuń operator ze stosu i dodaj go do napisu wyjsciowego

    Zwróć napis wyjsciowy


Funkcja onp_do_infix(wyrazenie_onp):
    inicjalizuj pusty stos

    Dla kazdego znaku w wyrazenie_onp:
        Jeśli znak jest operandem:
            Dodaj go na stos
        W przeciwnym razie, jeśli znak jest operatorem:
            Zdejmij dwa operandy ze stosu
            Utwórz napis infix, łącząc operator, drugi operand i pierwszy operand w odpowiedniej kolejności
            Dodaj utworzony napis infix na stos
    Zwróć wyrażenie infix będące jedynym elementem stosu


#### Przykładowe użycie:
wyrazenie = "2 + 3 * 4"
wyrazenie_onp = infix_do_onp(wyrazenie)
print(wyrazenie_onp)  # Wyświetli "2 3 4 * +"

wyrazenie_infix = onp_do_infix(wyrazenie_onp)
print(wyrazenie_infix)  # Wyświetli "2 + 3 * 4"
