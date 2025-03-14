#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "RotateBullet.hpp"
#include "Group.hpp"
#include "RotateTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "ShootEffect.hpp"

const int RotateTurret::Price = 60;
RotateTurret::RotateTurret(float x, float y) :
    Turret(TURRET_PLUG, "play/tower-base.png", "play/planet.png", x, y, 200, Price, 6) {
    reload = 0;
}
void RotateTurret::CreateBullet() {
    bullet += 4;
    Engine::Point diff, normalized, bulPosition;
    for (int i = 0; i < 4; i++) {
        diff = Engine::Point(cos(i * ALLEGRO_PI / 2), sin(i * ALLEGRO_PI / 2));
        normalized = diff.Normalize();
        float rotation = atan2(diff.y, diff.x);
        bulPosition = Position + normalized * CollisionRadius;
        getPlayScene()->BulletGroup->AddNewObject(new RotateBullet(bulPosition, 
            Engine::Point(0, 0), rotation, i, this));
    }
    AudioHelper::PlayAudio("gun.wav");
}

void RotateTurret::Update(float deltaTime) {
    imgBase.Position = Position;
    imgBase.Tint = Tint;
    if (!Enabled)
        return;
	Sprite::Update(deltaTime);
	// Shoot reload.
	reload -= deltaTime;
    if (reload <= 0 && bullet == 0) {
        // shoot.
        reload = coolDown;
        CreateBullet();
    }
}