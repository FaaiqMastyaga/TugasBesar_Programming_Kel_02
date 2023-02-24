#include <iostream>
#include "fungsi.cpp"

using namespace std;

int main(){
    srand(time(NULL));
    int *coordinate;
    int enemy_destroyed = 0;
    int perintah;
    char arah;

    // Prepare array dinamis untuk koordinat
    coordinate = (int*)calloc(2, sizeof(int));
    // Membuat objek kapal cakru (player)
    Kapal* cakru = new Kapal("cakru", 200, 40, 5, coordinate);

    while(cakru->health >= 0){
        do{
            coordinate[0] = random(-MAP_SIZE, MAP_SIZE);
            coordinate[1] = random(-MAP_SIZE, MAP_SIZE);
        }while((cakru->position[0] == coordinate[0]) && (cakru->position[1] == coordinate[1]));
        
        // Membuat objek enemy
        Kapal* enemy = new Kapal("enemy", random(MIN_HEALTH, MAX_HEALTH), random(MIN_DAMAGE, MAX_DAMAGE), random(MIN_RANGE, MAX_RANGE), coordinate);

        while(enemy){
            show_info(cakru, enemy);
            command_info();
            cin >> perintah;
            switch(perintah){
                case 1:
                    cakru->attack(enemy);
                    break;
                case 2:
                    direction();
                    cout << "Ke mana kita akan bergerak, Kapten? : ";
                    cin >> arah;
                    cakru->move(arah);
                    break;
                case 3:
                    cout << "\nKapal kita berdiam di tempat sesuai arahan, Kapten." << endl;
                    break;
            }
            if((perintah < 1) || (perintah > 3)){
                cout << "\nKami tidak mengerti maksud Anda, Kapten" << endl;
            }
        }

    cin.get();
    cout << endl;
    }
    return 0;
}