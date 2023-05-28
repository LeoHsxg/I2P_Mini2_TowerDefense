#ifndef TOOLBUTTON_HPP
#define TOOLBUTTON_HPP
#include <string>

#include "ImageButton.hpp"
#include "Sprite.hpp"

class PlayScene;

class ToolButton : public Engine::ImageButton {
protected:
    PlayScene* getPlayScene();
public:
	int money;
	Engine::Sprite Base;
	Engine::Sprite Turret;
	ToolButton(std::string img, std::string imgIn, Engine::Sprite Base, Engine::Sprite Turret, float x, float y, int money);
	void Update(float deltaTime) override;
	void Draw() const override;
};
#endif // TURRETBUTTON_HPP
