#include <iostream>
#include <stdlib.h>
#include "fungsi.h"

using namespace std;

class Kapal{
    public:   
        double health;
        double damage;
        int max_range;
        int *position = (int*)calloc(2, sizeof(int));
        
        Kapal(double inputHealth, double inputDamage, int inputMaxRange, int *inputPosition){
            Kapal::health = inputHealth;
            Kapal::damage = inputDamage;
            Kapal::max_range = inputMaxRange;
            Kapal::position[0] = *(inputPosition);
            Kapal::position[1] = *(inputPosition+1);
        }

        void move(int *x, int *y){
            Kapal::position[0] += *x;
            Kapal::position[1] += *y;
        }

        double distance_to_target(Kapal inputTarget){
            return (kuadrat((double)(Kapal::position[0] - inputTarget.position[0])) + kuadrat((double)(Kapal::position[1] - inputTarget.position[1])));
        }

        void attack(Kapal inputEnemy){
            double distance = Kapal::distance_to_target(inputEnemy);
            if(distance <= Kapal::max_range){
                inputEnemy.health -= Kapal::damage;
                cout << "Damage given: " << Kapal::damage << endl;
                cout << "Enemy health: " << inputEnemy.health << endl;
            }else{
                cout << "ERROR!!!" << endl;
                cout << "Target berada di luar jangkauan" << endl;
            }
        }
};

double kuadrat(double angka){
    return angka * angka;
}