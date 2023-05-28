#include <string>
#include <utility>
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IObject.hpp"
#include "IScene.hpp"
#include "PlayScene.hpp"

#include "DiceNormalEnemy.hpp"
#include "DiceEliteEnemy.hpp"

DiceEliteEnemy::DiceEliteEnemy(int x, int y)
	: Enemy("play/dice-2.png", x, y, 25, 70, 7, 15) {
}

void DiceEliteEnemy::OnExplode() {
	PlayScene* scene = getPlayScene();
	Enemy* enemy;
	scene->EnemyGroup->AddNewObject(enemy = new DiceNormalEnemy(Position.x, Position.y));
	enemy->UpdatePath(scene->mapDistance);
	// Compensate the time lost.
	enemy->Update(0);
	Enemy::OnExplode();
}