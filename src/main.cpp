#include <iostream>
#include "fungsi.cpp"
#include <bits/stdc++.h>

using namespace std;

int main(){
    srand(time(NULL));
    int coordinate[2] = {0,0};
    int enemy_destroyed = 0;
    char perintah;

    Kapal* cakru = new Kapal("cakru", 200, 40, 5, coordinate);

    while(cakru->health > 0){
        do{
            set_coordinate(coordinate);
        }while((cakru->position[0] == coordinate[0]) && (cakru->position[1] == coordinate[1]));
        
        Kapal* enemy = new Kapal("enemy", random(MIN_HEALTH, MAX_HEALTH), random(MIN_DAMAGE, MAX_DAMAGE), random(MIN_RANGE, MAX_RANGE), coordinate);

        while(enemy->health > 0 && cakru->health > 0){
            show_info(cakru, enemy);
            command_info();
            cin >> perintah;
            system("cls");
            command(perintah, cakru, enemy);
        }
        if(cakru->health > 0){
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