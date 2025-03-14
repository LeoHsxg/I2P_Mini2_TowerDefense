#include <allegro5/base.h>
#include <random>
#include <string>
#include <utility>

#include "DirtyEffect.hpp"
#include "GameEngine.hpp"
#include "Enemy.hpp"
#include "RotateBullet.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Bullet.hpp"
#include "Collider.hpp"
#include "Turret.hpp"

class Turret;

RotateBullet::RotateBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, int id, Turret* parent) :
    Bullet("play/bullet-6.png", 300, 1.5, position, forwardDirection, rotation - ALLEGRO_PI / 2, parent) {
    // TODO 3 (2/5): You can imitate the 2 files: 'WoodBullet.hpp', 'WoodBullet.cpp' to create a new bullet.
	bulletID = id;
}
void RotateBullet::OnExplode(Enemy* enemy) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(2, 5);
    enemy->Slow(0.5, 0.8);
    getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-1.png", dist(rng), enemy->Position.x, enemy->Position.y));
}
void RotateBullet::Update(float deltaTime) {
	timer += deltaTime;
	if (timer >= period) {
		timer -= period;
	}
	// Sprite::Update only provides linear movement	
	Engine::Point diff = Engine::Point(cos(timer/period * 2 * ALLEGRO_PI + bulletID * ALLEGRO_PI / 2),
		sin(timer / period * 2 * ALLEGRO_PI + bulletID * ALLEGRO_PI / 2));
	float rotation = atan2(diff.y, diff.x) /*- ALLEGRO_PI / 2*/;
	Engine::Point normalized = diff.Normalize();
	Position = parent->Position + normalized * parent->CollisionRadius;
	Rotation = rotation;

	PlayScene* scene = getPlayScene();
	// Can be improved by Spatial Hash, Quad Tree, ...
	// However simply loop through all enemies is enough for this program.
	for (auto& it : scene->EnemyGroup->GetObjects()) {
		Enemy* enemy = dynamic_cast<Enemy*>(it);
		if (!enemy->Visible)
			continue;
		if (Engine::Collider::IsCircleOverlap(Position, CollisionRadius, enemy->Position, enemy->CollisionRadius)) {
			parent->bullet -= 1;
			OnExplode(enemy);
			enemy->Hit(damage);
			getPlayScene()->BulletGroup->RemoveObject(objectIterator);
			return;
		}
	}
	// Check if out of boundary.
	/*if (!Engine::Collider::IsRectOverlap(Position - Size / 2, Position + Size / 2,
			Engine::Point(0, 0), PlayScene::GetClientSize()))
		if (!dynamic_cast<RotateBullet*>(this)) {
			getPlayScene()->BulletGroup->RemoveObject(objectIterator);
		}*/
}
