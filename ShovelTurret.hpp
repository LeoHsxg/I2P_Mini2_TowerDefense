#ifndef SHOVELTURRET_HPP
#define SHOVELTURRET_HPP
#include "Turret.hpp"

class ShovelTurret : public Turret {
public:
    static const int Price;
    ShovelTurret(float x, float y);
    void CreateBullet() override;
};
#endif // PLUGGUNTURRET_HPP
