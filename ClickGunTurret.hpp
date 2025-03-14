#ifndef CLICKGUNTURRET_HPP
#define CLICKGUNTURRET_HPP
#include "Turret.hpp"

class ClickGunTurret : public Turret {
public:
    static const int Price;
    ClickGunTurret(float x, float y);
    void CreateBullet() override;
    // void Update(float deltaTime);
};
#endif // PLUGGUNTURRET_HPP
