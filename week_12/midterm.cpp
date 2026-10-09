#include <iostream>
#include <string>
using namespace std;

class Fish {
private:
    int id;
    string name;
    string color;
    string characteristic;

    public:
    Fish() {
        id = 0;
        name = "";
        color = "";
        characteristic = "";
    }

    Fish(int i) {
        id = i;
        name = "";
        color = "";
        characteristic = "";
    }

    Fish(int i, string n) {
        id = i;
        name = n;
        color = "";
        characteristic = "";
    }

    Fish(int i, string n, string c) {
        id = i;
        name = n;
        color = c;
        characteristic = "";
    }

    Fish(int i, string n, string c, string ch) {
        id = i;
        name = n;
        color = c;
        characteristic = ch;
    }

};


int main() {

    return 0;
}