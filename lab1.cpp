#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct market
{
    string name;
    string description;
    double price;
    int count;
    string unit;
    long long int id;
};
int main()
{
    setlocale(LC_ALL, "Rus");
    market m[50];
    ifstream fin("market.txt");
    int i = 0;
    if (fin)
    {

        while (fin >> m[i].name >> m[i].description >> m[i].price >> m[i].count >> m[i].unit >> m[i].id)
            /*cout << m[i].name << " " << m[i].description << " " << m[i].price << " " << m[i].count << " " << m[i].unit << " " << m[i].id << endl;*/
            i++;
        fin.close();
    }
    else
        cout << "Error!" << endl;

    cout << "Линейный поиск:" << endl;
    for (i = 0; i < 50; i++) {
        if (m[i].name == "tea") {
            cout << m[i].name << " " << m[i].description << " " << m[i].price << " " << m[i].count << " " << m[i].unit << " " << m[i].id << endl;
        }
    }

    cout << endl << "Бинарный поиск:" << endl;
    cout << "Введите название продукта: ";
    char name[21];
    cin >> name;
    int first = 0;
    int last = 49;
    int mid;
    bool found = false;
    while (first <= last) {
        mid = (first + last) / 2;

        if (name > m[mid].name) {
            first = mid + 1;
        }
        else if (name < m[mid].name) {
            last = mid - 1;
        }
        else {
            first = last + 1;
            found = true;
            break;
        }
    }
    cout << m[mid].name << " " << m[mid].description << " " << m[mid].price << " " << m[mid].count << " " << m[mid].unit << " " << m[mid].id << endl;
    system("pause");
    return -1;
}
