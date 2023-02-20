#include <iostream>
#include "fungsi.cpp"

using namespace std;

int main(){
    int *coordinate;

    // Test membuat objek kapal cakru
    coordinate = (int*)calloc(2, sizeof(int));
    Kapal cakru = Kapal(10000.0, 500.0, 4, coordinate);
    free(coordinate);

    cout << "Kapal cakru" << endl;
    cout << "Health: " << cakru.health << endl;
    cout << "Damage: " << cakru.damage << endl;
    cout << "Range attack: " << cakru.max_range << endl;
    cout << "Posisi: (" << cakru.position[0] << ", " << cakru.position[1] << ")" << endl;

    // Test membuat objek kapal enemy1
    coordinate = (int*)calloc(2, sizeof(int));
    *(coordinate) = 1;
    *(coordinate+1) = 1;
    Kapal enemy1 = Kapal(7000.0, 230.0, 2, coordinate);
    free(coordinate);

    cout << "\nKapal enemy1" << endl;
    cout << "Health: " << enemy1.health << endl;
    cout << "Damage: " << enemy1.damage << endl;
    cout << "Range attack: " << enemy1.max_range << endl;
    cout << "Posisi: (" << enemy1.position[0] << ", " << enemy1.position[1] << ")" << endl;
    
    cout << "info" << endl;
    cakru.attack(enemy1);

    // Test membuat objek kapal enemy1
    coordinate = (int*)calloc(2, sizeof(int));
    *(coordinate) = 10;
    *(coordinate+1) = 10;
    Kapal enemy2 = Kapal(7000.0, 230.0, 2, coordinate);
    free(coordinate);

    cout << "\nKapal enemy2" << endl;
    cout << "Health: " << enemy2.health << endl;
    cout << "Damage: " << enemy2.damage << endl;
    cout << "Range attack: " << enemy2.max_range << endl;
    cout << "Posisi: (" << enemy2.position[0] << ", " << enemy2.position[1] << ")" << endl;
    
    cout << "info" << endl;
    cakru.attack(enemy2);
    return 0;
}