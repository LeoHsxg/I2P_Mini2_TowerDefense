#include <allegro5/color.h>

#include "GameEngine.hpp"
#include "IScene.hpp"
#include "PlayScene.hpp"
#include "ToolButton.hpp"

PlayScene* ToolButton::getPlayScene() {
	return dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetActiveScene());
}
ToolButton::ToolButton(std::string img, std::string imgIn, Engine::Sprite Base, Engine::Sprite Turret, 
	float x, float y, int money) :
	ImageButton(img, imgIn, x, y), money(money), Base(Base), Turret(Turret) {
}
void ToolButton::Update(float deltaTime) {
	ImageButton::Update(deltaTime);
	if (getPlayScene()->GetMoney() >= money) {
		Enabled = true;
		Base.Tint = Turret.Tint = al_map_rgba(255, 255, 255, 255);
	} else {
		Enabled = false;
		Base.Tint = Turret.Tint = al_map_rgba(0, 0, 0, 160);
	}
}
void ToolButton::Draw() const {
	ImageButton::Draw();
	Base.Draw();
	Turret.Draw();
}