#ifndef ROTATETURRET_HPP
#define ROTATETURRET_HPP
#include "Turret.hpp"

class RotateTurret : public Turret {
public:
    static const int Price;
    RotateTurret(float x, float y);
    void CreateBullet() override;
    void Update(float deltaTime);
};
#endif // PLUGGUNTURRET_HPP
