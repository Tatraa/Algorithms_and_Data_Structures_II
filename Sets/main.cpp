#include <iostream>
#include <algorithm>
#include "set.cpp"

int main() {
    Set<int> s;

    std::cout << "\n 1 == True \n 0 == False \n" << std::endl;

    s.insert(4);
    s.insert(2);
    s.insert(6);
    s.insert(7);

    std::cout << "Zbior s: ";
    s.display();

    std::cout << "Czy '2' zawiera sie w tym zbiorze?: " << s.isMember(2) << std::endl;
    std::cout << "Czy '5' zawiera sie w tym zbiorze?: " << s.isMember(5) << std::endl;

    std::cout << "Usuwam element '2' ze zbioru..." <<  std::endl;
    s.remove(2);

    //s.display();

    std::cout << "Jaki element wyskoczy ze zbioru po uzyciu pop()?: ";
    std::cout << s.pop() << std::endl;

    //s.display();
    Set<int> s2;
    s2.insert(3);
    s2.insert(4);
    s2.insert(5);
    s2.insert(7);

    std::cout << "Aktualny zbior s: ";
    s.display();

    std::cout << "Aktualny zbior s2: ";
    s2.display();

    Set<int> s3 = s.intersection(s2);
    std::cout << "Intersection:" << std::endl;
    std::cout << "Czy '3' jest elementem wspolnym zbiorow s i s2?: " << s3.isMember(3) << std::endl;
    std::cout << "Czy '7' jest elementem wspolnym zbiorow s i s2?: "<< s3.isMember(7) << std::endl;

    //s3.display();

    Set<int> s4 = s.difference(s2);
    std::cout << "Difference:" << std::endl;
    std::cout << "Czy '6' jest elementem roznicy zbiorow s i s2?: " << s4.isMember(6) << std::endl;
    std::cout << "Czy '3' jest elementem roznicy zbiorow s i s2?: " << s4.isMember(3) << std::endl;

    //s4.display();

    Set<int> s5 = s._union(s2);
    std::cout << "Union:" << std::endl;
    std::cout << "Czy '1' jest elementem sumy zbiorow s i s2?: " << s5.isMember(1) << std::endl;
    std::cout << "Czy '3' jest elementem sumy zbiorow s i s2?: " << s5.isMember(3) << std::endl;
    std::cout << "Czy '4' jest elementem sumy zbiorow s i s2?: " << s5.isMember(4) << std::endl;

    //s5.display();

    std::cout << "Jaki element wyskoczy z sumy zbiorow po uzyciu pop()?: ";
    std::cout << s5.pop() << std::endl;

    std::cout << "Wielkosc obiektu sumy zbiorow s i s2 po uzyciu `s5.pop()`: ";
    std::cout << s5.size() << std::endl;
    s5.display();
}