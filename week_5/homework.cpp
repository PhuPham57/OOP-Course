#include <iostream>
#include <string>

using namespace std;

#define MAX 20

struct FLOWER
{
    string name;
    double price;
    int quantity;
    string type;
};

//Bai 1

void inputArray(FLOWER List[], int &n)
{
    do {
        cout << "How many flowers? ";
        cin >> n;
    } while (n <= 0 || n > MAX);

    for (int i = 0; i < n; i++)
    {
        cout << "\nFlower " << i + 1 << ":\n";
        cout << "  Name: ";
        cin >> List[i].name;

        // Validation: price > 0
        do {
            cout << "  Price: ";
            cin >> List[i].price;
        } while (List[i].price <= 0);

        // Validation: quantity >= 0
        do {
            cout << "  Quantity: ";
            cin >> List[i].quantity;
        } while (List[i].quantity < 0);

        cout << "  Type: ";
        cin >> List[i].type;
    }
}

int main()
{
    FLOWER List[MAX];
    int n;
}