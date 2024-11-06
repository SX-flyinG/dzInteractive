//Додати функціонал включити\виключити ліхтарі
//Якщо ліхтарі включені - витрата палива при поїздках збільшується на 10 %

#include <iostream>
#include <ctime>

using namespace std;

class Auto {
    string brand;
    double percentageOfFuel;
    bool lights;
public:
    Auto() { // Конструктор за замовчуванням
        brand = "Renault";
        percentageOfFuel = 100;
        lights = false;
    }
    Auto(string a, double b , bool c) { // Конструктор
        brand = a; // з параметрами
        percentageOfFuel = b;
        lights = c;
    }

    void SetBrand(string a) {
        brand = a;
    }

    void SetPercentageOfFuel(double b) {
        percentageOfFuel = b;
    }

    void SetLights(bool c) {
        lights = c;
    }

    string GetBrand() {
        return brand;
    }

    double GetPercentageOfFuel() {
        return percentageOfFuel;
    }

    bool GetLights() {
        return lights;
    }

    void FillAuto(double a) {
        if ((percentageOfFuel + a) < 100) {
            percentageOfFuel += a;
            cout << "Current percentage of fuel: " << percentageOfFuel << endl;
        }
        else {
            cout << "Percentage of fuel can not be over than 100\nTry next time" << endl;
        }
    }

    void Drive() {
        int fuelToFire = rand() % 25 + 1;
        if (lights == false) {
            percentageOfFuel -= fuelToFire;
        }
        else {
            fuelToFire += 10;
            percentageOfFuel -= fuelToFire;
        }
    }

    void SwitchLights() {
        if (lights == false) {
            cout << "U switch lights on (u fire a fuel up to 10%) ;" << endl;
            lights = true;
        }
        else {
            cout << "U swiched lights off ;" << endl;
            lights = false;
        }
    }
};

void main() {
    srand(time(NULL));
    Auto obj;
    Auto obj2;

    while (true)
    {
        cout << "1 -> Fill\n2 -> Drive\n3 - Switch Lights On/Off : ";
        int result;
        cin >> result;
        if (result == 1) {
            obj.FillAuto(15);
        }
        else if (result == 2) {
            obj.Drive();
        }

        else if (result == 3) {
            obj.SwitchLights();
        }

        cout << "Current percentage of fuel: " << obj.GetPercentageOfFuel() << endl;

        if (obj.GetPercentageOfFuel() <= 0) {
            cout << "Our auto is empty" << endl;
            break;
        }
    }
}