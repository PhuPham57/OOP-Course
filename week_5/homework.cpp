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

//Bai 2
void displayArray(const FLOWER List[], int n)
{
    cout << "\n===== FLOWER SHOP =====\n\n";
    cout << "No  Name        Price     Qty   Type\n";
    cout << "-------------------------------------\n";

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "   " 
             << List[i].name << "\t\t" 
             << List[i].price << "\t  " 
             << List[i].quantity << "    " 
             << List[i].type << "\n";
    }
}

//Bai 3
void findMinMaxPrice(const FLOWER List[], int n)
{
    if (n == 0) return;

    int maxIdx = 0, minIdx = 0;

    for (int i = 1; i < n; i++)
    {
        if (List[i].price > List[maxIdx].price) maxIdx = i;
        if (List[i].price < List[minIdx].price) minIdx = i;
    }

    cout << "Most expensive flower : " << List[maxIdx].name << " (" << List[maxIdx].price << ")\n";
    cout << "Cheapest flower       : " << List[minIdx].name << " (" << List[minIdx].price << ")\n";
}

//Bai 4
void countByType(const FLOWER List[], int n)
{
    cout << "\n---- COUNT BY TYPE ----\n";
    for (int i = 0; i < n; i++)
    {
        bool alreadyCounted = false;
        for (int j = 0; j < i; j++)
        {
            if (List[i].type == List[j].type)
            {
                alreadyCounted = true;
                break;
            }
        }

        if (!alreadyCounted)
        {
            int count = 0;
            for (int k = 0; k < n; k++)
            {
                if (List[k].type == List[i].type)
                {
                    count++;
                }
            }
            cout << List[i].type << "\t: " << count << "\n";
        }
    }
}

int main()
{
    FLOWER List[MAX];
    int n;
}