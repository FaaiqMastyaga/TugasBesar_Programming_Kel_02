#include <iostream>
#include "fungsi.cpp"

using namespace std;

int main(){
    srand(time(NULL));
    int coordinate[2] = {0,0};
    int enemy_destroyed = 0;
    char perintah;

    Kapal* cakru = new Kapal("cakru", 200, 40, 5, coordinate);

    while(cakru->getHealth() > 0){
        do{
            set_coordinate(coordinate);
        }while((coordinate[0] == cakru->getPosition()[0]) && (coordinate[1] == cakru->getPosition()[1]));
        
        Kapal* enemy = new Kapal("enemy", random(MIN_HEALTH, MAX_HEALTH), random(MIN_DAMAGE, MAX_DAMAGE), random(MIN_RANGE, MAX_RANGE), coordinate);

        while(enemy->getHealth() > 0 && cakru->getHealth() > 0){
            show_info(cakru, enemy);
            command_info();
            cin >> perintah;
            command(perintah, cakru, enemy);
        }
        if(cakru->getHealth() > 0){
            cout << "\nKapal musuh telah dihancurkan, Kapten!" << endl;
            enemy_destroyed += 1;
            delete(enemy);
        }
    }
    cout << "\nKita telah kalah, Kapten. Kapal kita telah dihancurkan" << endl;
    cout << "Kapal musuh yang berhasil dihancurkan: " << enemy_destroyed << endl;
    delete(cakru);
    return 0;
}