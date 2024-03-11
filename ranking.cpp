// Zadanie: Ranking
// Autor: Matylda Dębska
// Nr indeksu: 325684

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int main() {

    // wczytanie tablicy wyników
    int n;
    cin >> n;
    vector<pair<int, int>> wyniki(n);
    for (int i = 0; i < n; i++) {
        cin >> wyniki[i].first;
        wyniki[i].second = i;
    }

    // sortowanie wyników 
    sort(wyniki.rbegin(), wyniki.rend());

    // wyznaczenie miejsc rankingu 
    vector<int> ranking(n);
    int miejsce = 1;
    int poprzedni_wynik = -1;
    
    for (int i = 0; i < n; i++) {
        if (wyniki[i].first != poprzedni_wynik) {
            miejsce = i + 1;
            poprzedni_wynik = wyniki[i].first;
        }
        ranking[wyniki[i].second] = miejsce;
    }

    // wypisanie wyników
    for (int i = 0; i < n; i++) {
        cout << ranking[i] << " ";
    }

    return 0;
}