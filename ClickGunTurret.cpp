#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "Enemy.hpp"
#include "Turret.hpp"
#include "AudioHelper.hpp"
#include "WoodBullet.hpp"
#include "Group.hpp"
#include "ClickGunTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "ShootEffect.hpp"

const int ClickGunTurret::Price = 30;
ClickGunTurret::ClickGunTurret(float x, float y) :
    Turret(TURRET_PLUG, "play/tower-base.png", "play/turret-7.png", x, y, 175, Price, 4) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}
void ClickGunTurret::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    // Change bullet position to the front of the gun barrel.
    getPlayScene()->BulletGroup->AddNewObject(new WoodBullet(Position + normalized * 36, diff, rotation, this));
    // TODO 4 (2/2): Add a ShootEffect here. Remember you need to include the class.
    getPlayScene()->EffectGroup->AddNewObject(new ShootEffect(Position.x + diff.x * 20, Position.y + diff.y * 20));
    AudioHelper::PlayAudio("gun.wav");
}