#include <iostream>
#include <string>

using namespace std;

#define MAX 20

struct Flower {
    string name;
    double price;
    int quantity;
    string type;
};

// Hàm hỗ trợ nhập và kiểm tra dữ liệu đầu vào
void inputFlowers(Flower flowers[], int &n) {
    do {
        cout << "Enter number of flowers (1 <= N <= 20): ";
        cin >> n;
    } while (n < 1 || n > MAX);

    for (int i = 0; i < n; i++) {
        cout << "\nFlower " << i + 1 << ":\n";
        cout << "  Name: ";
        cin >> flowers[i].name;

        do {
            cout << "  Price (> 0): ";
            cin >> flowers[i].price;
        } while (flowers[i].price <= 0);

        do {
            cout << "  Quantity (>= 0): ";
            cin >> flowers[i].quantity;
        } while (flowers[i].quantity < 0);

        cout << "  Type: ";
        cin >> flowers[i].type;
    }
}

//Bai 1
void displayAllFlowers(const Flower flowers[], int n) {
    cout << "\n--- Display all flowers ---\n";
    cout << "No  Name        Price     Qty   Type\n";
    cout << "-------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "   " << flowers[i].name << "\t\t" 
             << flowers[i].price << "\t  " << flowers[i].quantity 
             << "    " << flowers[i].type << "\n";
    }
}

//Bai 2
void findMostExpensiveFlower(const Flower flowers[], int n) {
    cout << "\n--- Most expensive flower ---\n";
    int maxIdx = 0;
    for (int i = 1; i < n; i++) {
        if (flowers[i].price > flowers[maxIdx].price) maxIdx = i;
    }
    cout << "Most expensive: " << flowers[maxIdx].name << " (" << flowers[maxIdx].price << ")\n";
}

//Bai 3
void findCheapestFlower(const Flower flowers[], int n) {
    cout << "\n--- Cheapest flower ---\n";
    int minIdx = 0;
    for (int i = 1; i < n; i++) {
        if (flowers[i].price < flowers[minIdx].price) minIdx = i;
    }
    cout << "Cheapest: " << flowers[minIdx].name << " (" << flowers[minIdx].price << ")\n";
}

//Bai 4
void findFlowerWithLargestQuantity(const Flower flowers[], int n) {
    cout << "\n--- Flower with largest quantity ---\n";
    int maxIdx = 0;
    for (int i = 1; i < n; i++) {
        if (flowers[i].quantity > flowers[maxIdx].quantity) maxIdx = i;
    }
    cout << "Largest quantity: " << flowers[maxIdx].name << " (" << flowers[maxIdx].quantity << ")\n";
}

//Bai 5
void calculateTotalQuantity(const Flower flowers[], int n) {
    cout << "\n--- Total quantity ---\n";
    int total = 0;
    for (int i = 0; i < n; i++) total += flowers[i].quantity;
    cout << "Total quantity of all flowers: " << total << "\n";
}

//Bai 6
void calculateAveragePrice(const Flower flowers[], int n) {
    cout << "\n--- Average price ---\n";
    double sum = 0;
    for (int i = 0; i < n; i++) sum += flowers[i].price;
    cout << "Average price: " << sum / n << "\n";
}

//Bai 7
void countFlowersByType(const Flower flowers[], int n) {
    cout << "\n--- Count flowers by type ---\n";
    for (int i = 0; i < n; i++) {
        bool counted = false;
        for (int j = 0; j < i; j++) {
            if (flowers[i].type == flowers[j].type) {
                counted = true;
                break;
            }
        }
        if (!counted) {
            int count = 0;
            for (int k = 0; k < n; k++) {
                if (flowers[k].type == flowers[i].type) count++;
            }
            cout << flowers[i].type << ": " << count << "\n";
        }
    }
}

//Bai 8
void findFlowersByGivenType(const Flower flowers[], int n) {
    cout << "\n--- Find all flowers of a given type ---\n";
    string targetType;
    cout << "Enter type to search: ";
    cin >> targetType;
    
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (flowers[i].type == targetType) {
            cout << "- " << flowers[i].name << " (Price: " << flowers[i].price << ", Qty: " << flowers[i].quantity << ")\n";
            found = true;
        }
    }
    if (!found) cout << "No flowers found for type: " << targetType << "\n";
}

//Bai 9
void searchFlowerByName(const Flower flowers[], int n) {
    cout << "\n--- Search by name ---\n";
    string targetName;
    cout << "Enter flower name: ";
    cin >> targetName;

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (flowers[i].name == targetName) {
            cout << "Found! Price: " << flowers[i].price << ", Quantity: " << flowers[i].quantity << ", Type: " << flowers[i].type << "\n";
            found = true;
            break;
        }
    }
    if (!found) cout << "Flower not found!\n";
}

//Bai 10
void checkIfFlowerExists(const Flower flowers[], int n) {
    cout << "\n--- Check if flower exists ---\n";
    string targetName;
    cout << "Enter flower name to check: ";
    cin >> targetName;

    bool exists = false;
    for (int i = 0; i < n; i++) {
        if (flowers[i].name == targetName) {
            exists = true;
            break;
        }
    }
    cout << "Exists: " << (exists ? "Yes" : "No") << "\n";
}


//Bai 11
void countFlowersWithLowQuantity(const Flower flowers[], int n)
{
    cout << "\n--- Count flowers with low quantity (< 5) ---\n";
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (flowers[i].quantity < 5) count++;
    }
    cout << "Number of flowers with quantity < 5: " << count << "\n";
}

int main() {
    Flower flowers[MAX];
    int n = 0;

    inputFlowers(flowers, n);

    //1
    displayAllFlowers(flowers, n);

    //2
    findMostExpensiveFlower(flowers, n);

    //3
    findCheapestFlower(flowers, n);

    //4
    findFlowerWithLargestQuantity(flowers, n);

    //5
    calculateTotalQuantity(flowers, n);

    //6
    calculateAveragePrice(flowers, n);

    //7
    countFlowersByType(flowers, n);

    //8
    findFlowersByGivenType(flowers, n);

    //9
    searchFlowerByName(flowers, n);

    //10
    checkIfFlowerExists(flowers, n);

    //11
    countFlowersWithLowQuantity(flowers, n);

    return 0;
}