#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// ===== Lớp cha: Room =====
class Room {
protected:
    string name;          // tên loại phòng
    int maxAdults;        // số người lớn tối đa
    int maxChildren;      // số trẻ em tối đa
    double pricePerNight; // giá một đêm
public:
    // Constructor
    Room(string name = "", int maxAdults = 2, int maxChildren = 1, double price = 0) {
        this->name = name;
        this->maxAdults = maxAdults;
        this->maxChildren = maxChildren;
        this->pricePerNight = price;
    }
    virtual ~Room() {}

    // Getter
    string getName() const { return name; }
    int getMaxAdults() const { return maxAdults; }
    int getMaxChildren() const { return maxChildren; }
    double getPrice() const { return pricePerNight; }

    // Setter
    void setName(string n) { name = n; }
    void setMaxAdults(int a) { maxAdults = a; }
    void setMaxChildren(int c) { maxChildren = c; }
    void setPrice(double p) { pricePerNight = p; }

    // Chi phí cho nhiều phòng, nhiều đêm (lớp con có thể viết lại)
    virtual double calculateCost(int rooms, int nights) {
        return rooms * nights * pricePerNight;
    }
};

// ===== Lớp con: StandardRoom =====
class StandardRoom : public Room {
public:
    StandardRoom(double price = 500000) : Room("Standard Room", 2, 1, price) {}
};

// ===== Lớp con: DeluxRoom =====
// 1 trẻ em ngủ giường đơn lớn, 2 giường đôi
class DeluxRoom : public Room {
public:
    DeluxRoom(double price = 800000) : Room("Delux Room", 2, 1, price) {}
};

// ===== Lớp con: LuxuryRoom =====
// có phòng tắm riêng
class LuxuryRoom : public Room {
public:
    LuxuryRoom(double price = 1200000) : Room("Luxury Room", 2, 1, price) {}
};

// ===== main =====
int main() {
    const int TYPES = 3;
    Room* rooms[TYPES];                  // mảng các loại phòng
    rooms[0] = new StandardRoom();
    rooms[1] = new DeluxRoom();
    rooms[2] = new LuxuryRoom();

    int available[TYPES] = {10, 10, 10}; // mỗi loại có 10 phòng

    int adults = 30, children = 20;      // đoàn 50 khách
    int nights = 1;

    // Số phòng cần: đủ chỗ cho người lớn (2/phòng) và trẻ em (1/phòng)
    int roomsForAdults = (adults + 1) / 2;
    int roomsNeeded = roomsForAdults > children ? roomsForAdults : children;
    cout << "Rooms needed: " << roomsNeeded << "\n\n";

    // 3 options: mỗi option ghép 2 loại phòng
    int options[3][2] = { {0, 1}, {0, 2}, {1, 2} };

    for (int i = 0; i < 3; i++) {
        int first = options[i][0], second = options[i][1];

        // Lấp đầy loại đầu trước, phần còn lại dùng loại thứ hai
        int fromFirst = roomsNeeded < available[first] ? roomsNeeded : available[first];
        int fromSecond = roomsNeeded - fromFirst;

        cout << "Option " << i + 1 << ": ";
        if (fromSecond > available[second]) {
            cout << "not enough rooms\n";
            continue;
        }

        double total = rooms[first]->calculateCost(fromFirst, nights)
                     + rooms[second]->calculateCost(fromSecond, nights);

        cout << fromFirst << " x " << rooms[first]->getName() << " + "
             << fromSecond << " x " << rooms[second]->getName() << "\n";
        cout << "Total cost: " << fixed << setprecision(0) << total << " VND\n\n";
    }

    for (int i = 0; i < TYPES; i++) delete rooms[i];
    return 0;
}