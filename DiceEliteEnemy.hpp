#ifndef DICEELITEENEMY_HPP
#define DICEELITEENEMY_HPP
#include "Enemy.hpp"

class DiceEliteEnemy : public Enemy {
public:
    DiceEliteEnemy(int x, int y);
    void OnExplode();
};
#endif // REDNORMALENEMY_HPP
