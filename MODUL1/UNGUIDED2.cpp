/* fungsi dari class. 
Class berfungsi untuk mengelompokkan data dan variabel yang berhubungan menjadi satu kesatuan

fungsi dari struct.
Struck berfungsi untuk mengelompokkan beberapa data yang berbeda tipe menjadi satu unit
*/

#include <iostream>
using namespace std;
// Struct Person yang berisi data nama string dan umur int
struct Person {
    string Name;
    int Year;
};
// Class Vehicle yang berisi data brand string, model string, dan tahun rilis int dalam akses public
class Vehicle {
  public:
    string Brand;   
    string Model;
    int YearReleased;
};
int main() {
    // Deklarasi Struct Person
    Person person{" Shozo Kawasaki", 1878};
    cout << "\n- Biography - " << endl;
    cout << "Name: " << person.Name << endl;
    cout << "Year: " << person.Year << endl;
    // Deklarasi Class Vehicle
    Vehicle vehicle;
    vehicle.Brand = "Kawasaki";
    vehicle.Model = "H2R";
    vehicle.YearReleased = 2015;
    cout << "Vehicle brand: " << vehicle.Brand << endl;
    cout << "Vehicle model: " << vehicle.Model << endl;
    cout << "Vehicle year released: " << vehicle.YearReleased << endl;
    return 0;
}