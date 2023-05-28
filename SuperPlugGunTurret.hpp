#ifndef SUPPERPLUGGUNTURRET_HPP
#define SUPPERPLUGGUNTURRET_HPP
#include "Turret.hpp"

class SuperPlugGunTurret : public Turret {
public:
    static const int Price;
    SuperPlugGunTurret(float x, float y);
    void CreateBullet() override;
};
#endif // PLUGGUNTURRET_HPP
