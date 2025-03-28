#ifndef TURRET_HPP
#define TURRET_HPP
#include <allegro5/base.h>
#include <list>
#include <string>

#include "Sprite.hpp"

class Enemy;
class PlayScene;

class Turret: public Engine::Sprite {
protected:
    enum TurretType {
        TURRET_PLUG,
        TURRET_MACHINE,
        TOOL_SHOVEL,
        TOOL_SHIFTER,
    };
    int price;
    float coolDown;
    float reload;
    float rotateRadian = 2 * ALLEGRO_PI;
    Sprite imgBase;
    std::list<Turret*>::iterator lockedTurretIterator;
    PlayScene* getPlayScene();
    // Reference: Design Patterns - Factory Method.
    virtual void CreateBullet() = 0;

public:
    int bullet;
    bool Enabled = true;
    bool Preview = false;
    bool rotInit = false;
    TurretType turretType;
    Enemy* Target = nullptr;
    Turret(TurretType turretType,std::string imgBase, std::string imgTurret, float x, float y, float radius, int price, float coolDown);
    void Update(float deltaTime) override;
    void Draw() const override;
	int GetPrice() const;
};
#endif // TURRET_HPP
