#ifndef ROTATEBULLET_HPP
#define ROTATEBULLET_HPP
#include "Bullet.hpp"

class Enemy;
class Turret;
namespace Engine {
    struct Point;
}  // namespace Engine

class RotateBullet : public Bullet {
public:
    int bulletID;
    float period = 4.5;
    explicit RotateBullet(Engine::Point position, Engine::Point forwardDirection,
        float rotation, int id, Turret* parent);
    void OnExplode(Enemy* enemy) override;
    void Update(float deltaTime);
};
#endif // WOODBULLET_HPP
