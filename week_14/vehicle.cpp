#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ================= VEHICLE =================
class Vehicle {
private:
    string id;
    string brand;
    double pricePerDay;

public:
    Vehicle() : id(""), brand(""), pricePerDay(0) {}
    Vehicle(string i, string b, double p) : id(i), brand(b), pricePerDay(p) {}
    virtual ~Vehicle() {}

    string getId() const { return id; }
    string getBrand() const { return brand; }
    double getPricePerDay() const { return pricePerDay; }

    void setId(string i) { id = i; }
    void setBrand(string b) { brand = b; }
    void setPricePerDay(double p) { pricePerDay = p; }

    virtual void displayInfo() const {
        cout << "ID: " << id << endl;
        cout << "Brand: " << brand << endl;
        cout << "Price per day: " << pricePerDay << endl;
    }

    virtual double calculateRentalFee(int days) const {
        return days * pricePerDay;
    }
};

// ================= CAR =================
class Car : public Vehicle {
private:
    int seats;

public:
    Car() : Vehicle(), seats(0) {}
    Car(string i, string b, double p, int s) : Vehicle(i, b, p), seats(s) {}

    int getSeats() const { return seats; }
    void setSeats(int s) { seats = s; }

    void displayInfo() const override {
        cout << "Type: Car" << endl;
        Vehicle::displayInfo();
        cout << "Seats: " << seats << endl;
    }

    // Giảm 10% nếu thuê từ 7 ngày
    double calculateRentalFee(int days) const override {
        double fee = days * getPricePerDay();
        if (days >= 7) fee = fee * 0.9;
        return fee;
    }
};

// ================= MOTORBIKE =================
class Motorbike : public Vehicle {
private:
    int engineCC;

public:
    Motorbike() : Vehicle(), engineCC(0) {}
    Motorbike(string i, string b, double p, int cc) : Vehicle(i, b, p), engineCC(cc) {}

    int getEngineCC() const { return engineCC; }
    void setEngineCC(int cc) { engineCC = cc; }

    void displayInfo() const override {
        cout << "Type: Motorbike" << endl;
        Vehicle::displayInfo();
        cout << "Engine: " << engineCC << " cc" << endl;
    }

    // Giảm 5% nếu thuê từ 5 ngày
    double calculateRentalFee(int days) const override {
        double fee = days * getPricePerDay();
        if (days >= 5) fee = fee * 0.95;
        return fee;
    }
};

// ================= TRUCK =================
class Truck : public Vehicle {
private:
    double loadCapacity;   // tải trọng (tấn)
    double shippingFee;    // phí vận chuyển cố định

public:
    Truck() : Vehicle(), loadCapacity(0), shippingFee(0) {}
    Truck(string i, string b, double p, double load, double ship)
        : Vehicle(i, b, p), loadCapacity(load), shippingFee(ship) {}

    double getLoadCapacity() const { return loadCapacity; }
    double getShippingFee() const { return shippingFee; }
    void setLoadCapacity(double load) { loadCapacity = load; }
    void setShippingFee(double ship) { shippingFee = ship; }

    void displayInfo() const override {
        cout << "Type: Truck" << endl;
        Vehicle::displayInfo();
        cout << "Load capacity: " << loadCapacity << " tons" << endl;
        cout << "Shipping fee: " << shippingFee << endl;
    }

    // Số ngày * đơn giá + phí vận chuyển cố định
    double calculateRentalFee(int days) const override {
        return days * getPricePerDay() + shippingFee;
    }
};

// ================= MAIN =================
int main() {
    cout.setf(ios::fixed);
    cout.precision(0);

    vector<Vehicle*> vehicles;
    vector<int> rentalDays;   // số ngày thuê của từng phương tiện

    vehicles.push_back(new Car("C01", "Toyota Vios", 800000, 5));
    rentalDays.push_back(7);
    vehicles.push_back(new Car("C02", "Honda City", 900000, 5));
    rentalDays.push_back(3);
    vehicles.push_back(new Motorbike("M01", "Honda Wave", 150000, 110));
    rentalDays.push_back(5);
    vehicles.push_back(new Motorbike("M02", "Yamaha Exciter", 200000, 150));
    rentalDays.push_back(2);
    vehicles.push_back(new Truck("T01", "Hyundai Porter", 1200000, 2.5, 500000));
    rentalDays.push_back(4);

    cout << "===== VEHICLE LIST =====" << endl;
    for (int i = 0; i < vehicles.size(); i++) {
        vehicles[i]->displayInfo();
        cout << "Rental days: " << rentalDays[i] << endl;
        cout << "Rental fee: " << vehicles[i]->calculateRentalFee(rentalDays[i]) << endl;
        cout << endl;
    }

    // Tổng doanh thu thuê xe
    double total = 0;
    for (int i = 0; i < vehicles.size(); i++)
        total += vehicles[i]->calculateRentalFee(rentalDays[i]);
    cout << "Total rental revenue: " << total << endl;

    // Phương tiện có phí thuê cao nhất
    int maxIndex = 0;
    for (int i = 1; i < vehicles.size(); i++)
        if (vehicles[i]->calculateRentalFee(rentalDays[i]) >
            vehicles[maxIndex]->calculateRentalFee(rentalDays[maxIndex]))
            maxIndex = i;
    cout << "\n===== HIGHEST RENTAL FEE =====" << endl;
    vehicles[maxIndex]->displayInfo();
    cout << "Rental fee: " << vehicles[maxIndex]->calculateRentalFee(rentalDays[maxIndex]) << endl;

    // Giải phóng bộ nhớ
    for (int i = 0; i < vehicles.size(); i++)
        delete vehicles[i];

    return 0;
}