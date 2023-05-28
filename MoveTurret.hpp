#ifndef MOVETURRET_HPP
#define MOVETURRET_HPP
#include "Turret.hpp"

class MoveTurret : public Turret {
public:
    static const int Price;
    MoveTurret(float x, float y);
    void CreateBullet() override;
};
#endif // PLUGGUNTURRET_HPP
