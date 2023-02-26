#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>
#include "fungsi.h"

#define MAP_SIZE 5
#define MIN_HEALTH 100 // minimum health kapal musuh
#define MAX_HEALTH 150 // maksimum health kapal musuh
#define MIN_DAMAGE 10 // minimum damage kapal musuh
#define MAX_DAMAGE 30 // maksimum damage kapal musuh
#define MIN_RANGE 1 // minimum range tembak kapal musuh
#define MAX_RANGE 4 // maksimum range tembak kapal musuh

using namespace std;

void delay(int a){
    int add;
    int time;

    time=a*1000000000;

    for(int i=0;i<time;i++){
        add*=i;
        add++;
        add++;
    }
}

void loading(){
    system("cls");
    cout<<endl;
    cout<<"Harap tunggu Kapten, CAKRU akan kembali membawa laporan ";
    delay(245);
    system("cls");
}

Kapal::Kapal(string inputType, double inputHealth, double inputDamage, int inputMaxRange, int* inputPosition){
    this->type = inputType;
    this->health = inputHealth;
    this->damage = inputDamage;
    this->max_range = inputMaxRange;
    this->position[0] = *(inputPosition);
    this->position[1] = *(inputPosition+1);
    max_health = this->health;

    if(this->type == "enemy"){
        cout << "\nLapor, Kapten! Kapal musuh terdeteksi" << endl;
    }
}

double Kapal::getHealth(){
    return this->health;
}

double Kapal::getMaxHealth(){
    return this->max_health;
}

double Kapal::getDamage(){
    return this->damage;
}

int Kapal::getMaxRange(){
    return this->max_range;
}

int* Kapal::getPosition(){
    return this->position;
}

int Kapal::check_position_to_map(int* cakruPosition){
    int x = (cakruPosition[0] >= -MAP_SIZE) && (cakruPosition[0] <= MAP_SIZE);
    int y = (cakruPosition[1] >= -MAP_SIZE) && (cakruPosition[1] <= MAP_SIZE);
    return x && y;
}

int Kapal::check_position_to_enemy(int* cakruPosition, int* enemyPosition){
    int x = (cakruPosition[0] == enemyPosition[0]);
    int y = (cakruPosition[1] == enemyPosition[1]);
    return !(x && y);
}

int Kapal::check_position(int* cakruPosition, int* enemyPosition){
    return check_position_to_map(cakruPosition) && check_position_to_enemy(cakruPosition, enemyPosition);
}

void Kapal::move(char arah, Kapal* &inputEnemy){
    if((arah == 'w') || (arah == 's') || (arah == 'd') || (arah == 'a')){
        loading();
        switch(arah){
            case 'w':
                this->position[1] += 1;
                if(!(this->check_position(this->position, inputEnemy->position))){
                    cout << "\nMaaf, Kapten. Kapal kita tidak bisa bergerak ke arah tersebut" << endl;
                    this->position[1] -= 1;
                }
                break;
            case 's':
                this->position[1] -= 1;
                if(!(this->check_position(this->position, inputEnemy->position))){
                    cout << "\nMaaf, Kapten. Kapal kita tidak bisa bergerak ke arah tersebut" << endl;
                    this->position[1] += 1;
                }
                break;
            case 'd':
                this->position[0] += 1;
                if(!(this->check_position(this->position, inputEnemy->position))){
                    cout << "\nMaaf, Kapten. Kapal kita tidak bisa bergerak ke arah tersebut" << endl;
                    this->position[0] -= 1;
                }
                break;
            case 'a':
                this->position[0] -= 1;
                if(!(this->check_position(this->position, inputEnemy->position))){
                    cout << "\nMaaf, Kapten. Kapal kita tidak bisa bergerak ke arah tersebut" << endl;
                    this->position[0] += 1;
                }
                break;
        }
    }else{
        cout << "\nKami tidak mengerti maksud Anda, Kapten" << endl;
        system("pause");
        system("cls");
    }
}

double Kapal::distance_to_target(Kapal* &inputTarget){
    return sqrt(pow((double)(this->position[0] - inputTarget->position[0]), 2) + pow((double)(this->position[1] - inputTarget->position[1]), 2)); 
}

void Kapal::attack(Kapal* &inputEnemy){
    double distance = this->distance_to_target(inputEnemy);
    if(this->type == "cakru"){
        if(distance <= this->max_range){
            inputEnemy->health -= this->damage;
            cout << "\nLapor, Kapten! Kita telah menyerang kapal lawan" << endl;
            cout << "Damage diberikan: " << this->damage << endl;
            if(inputEnemy->health<0){
                cout << "Enemy health: 0" << endl;
            }else{
                cout << "Enemy health: " << inputEnemy->health << endl;
            }
        }else{
            cout << "\nMaaf, Kapten. Target berada di luar jangkauan" << endl;
        }
        cout << "Press any key to continue the report . . . ";
        system("pause>0");
        system("cls");
    }else{
        if(distance <= this->max_range){
            inputEnemy->health -= this->damage;
            cout << "\nGawat, Kapten! Kapal kita telah diserang" << endl;
            cout << "Damage diterima: " << this->damage << endl;
            if(inputEnemy->health<0){
                cout << "Health kapal kita: 0" << endl;
            }else{
                cout << "Health kapal kita: " << inputEnemy->health << endl;
            }
            cout << "Press any key to continue the report . . . ";
            system("pause>0");
            system("cls");
        }
    }
}

void Kapal::health_recovery(double health_recovered){
    health_recovered *= 0.1;
    if(this->health==200){
        cout<<" Kapal kita tidak mengalami keruskan "<<endl;
    }else if ((this->health + health_recovered)>200){
        cout << " Kapal kita mengalami pemulihan health sebesar " << (200 - this->health) << endl;
        this->health  += health_recovered;
    }else{
        this->health  += health_recovered;
        cout << " Kapal kita mengalami pemulihan health sebesar " << health_recovered << endl;
    }
}

void Kapal::eval_health(){
    if(this->health > this->max_health){
        this->health = this->max_health;
    }
}

int random(int min, int max){
    return (rand()%(max-min+1) + min);
}

void set_coordinate(int* coordinate){
    coordinate[0] = random(-MAP_SIZE, MAP_SIZE);
    coordinate[1] = random(-MAP_SIZE, MAP_SIZE);
};

void command_info(){
    cout << "\nKami siap menerima perintah, Kapten" << endl;
    cout << "(1) Menembak" << endl; 
    cout << "(2) Bergerak" << endl; 
    cout << "(3) Diam di tempat" << endl;
    cout << "Perintah Anda, Kapten : ";
}

void direction(){
    cout << "\nKapal kita dapat bergerak dalam arah berikut, Kapten" << endl;
    cout << "(w) Maju" << endl;
    cout << "(s) Mundur" << endl;
    cout << "(a) Kiri" << endl;
    cout << "(d) Kanan" << endl;
}

void show_health(Kapal* &cakru, Kapal* &enemy){
    cout << "Health kapal kita: " << cakru->getHealth();
    if(cakru->getHealth() == cakru->getMaxHealth()){
        cout << " [MAX]";
    }
    cout << "\nHealth kapal musuh: " << enemy->getHealth() << endl;
}

void show_position(Kapal* &cakru, Kapal* &enemy){
    cout << "Posisi kapal kita: (" << cakru->getPosition()[0] << ", " << cakru->getPosition()[1] << ")" << endl;
    cout << "Posisi kapal musuh: (" << enemy->getPosition()[0] << ", " << enemy->getPosition()[1] << ")" << endl;
    cout << "Jarak terhadap musuh: " << cakru->distance_to_target(enemy) << endl;
}

void show_shoot_range(Kapal* &cakru, Kapal* &enemy){
    cout << "Range tembak kapal kita: " << cakru->getMaxRange() << endl;
    cout << "Range tembak kapal musuh: " << enemy->getMaxRange() << endl;
}

void show_info(Kapal* &cakru, Kapal* &enemy){
    cout << "\nLapor, Kapten!" << endl;
    show_health(cakru, enemy);
    show_position(cakru, enemy);
    show_shoot_range(cakru, enemy);
}


void command(int perintah, Kapal* cakru, Kapal* enemy){
    char arah;
    if((perintah == '1') || (perintah == '2') || (perintah == '3')){
        loading();
        switch(perintah){
            case '1':
                cakru->attack(enemy);
                if(enemy->getHealth() > 0){
                    enemy->attack(cakru);
                }
                break;
            case '2':
                show_info(cakru, enemy);
                direction();
                cout << "Ke mana kita akan bergerak, Kapten? : ";
                cin >> arah;
                cakru->move(arah, enemy);
                enemy->attack(cakru);
                break;
            case '3':
                cout << "\nKapal kita berdiam di tempat sesuai arahan, Kapten." << endl;
                cout << "Press any key to continue the report . . . ";
                system("pause>0");
                system("cls");
                enemy->attack(cakru);
                break;
        }
    }else{
        cout << "\nKami tidak mengerti maksud Anda, Kapten" << endl;
        system("pause");
        system("cls");
    }
}
