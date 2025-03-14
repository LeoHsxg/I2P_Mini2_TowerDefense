#include <algorithm>
#include <string>

#include "Point.hpp"
#include "Slider.hpp"

#include "ImageButton.hpp"
#include "AudioHelper.hpp"
#include "GameEngine.hpp"
#include "LOG.hpp"

Slider::Slider(float x, float y, float w, float h) :
	ImageButton("stage-select/slider.png", "stage-select/slider-blue.png", x, y),
	Bar("stage-select/bar.png", x, y, w, h),
	End1("stage-select/end.png", x, y + h / 2, 0, 0, 0.5, 0.5),
	End2("stage-select/end.png", x + w, y + h / 2, 0, 0, 0.5, 0.5)
{
	Position.x += w;
	Position.y += h / 2;
	Anchor = Engine::Point(0.5, 0.5);
}
void Slider::Draw() const {
	Bar.Draw();
	End1.Draw();
	End2.Draw();
	ImageButton::Draw();
}
void Slider::SetOnValueChangedCallback(std::function<void(float value)> onValueChangedCallback) {
	OnValueChangedCallback = onValueChangedCallback;
}
void Slider::SetValue(float value) {
	// TODO 1 (4/7): Call 'OnValueChangedCallback' when value changed. Can imitate ImageButton's 'OnClickCallback'.
	// Also, move the slider along the bar, to the corresponding position.
	OnValueChangedCallback(value);
}
void Slider::OnMouseDown(int button, int mx, int my) {
	// TODO 1 (5/7): Set 'Down' to true if mouse is in the slider.
	if ((button & 1) && Bar.Position.x <= mx && mx <= Bar.Position.x + Bar.Size.x
		 && Bar.Position.y - 21 <= my && my <= Bar.Position.y + Bar.Size.y + 21) {
		Down = true;
	}
}
void Slider::OnMouseUp(int button, int mx, int my) {
	// TODO 1 (6/7): Set 'Down' to false.
	if ((button & 1) && Bar.Position.x <= mx && mx <= Bar.Position.x + Bar.Size.x
		&& Bar.Position.y - 21 <= my && my <= Bar.Position.y + Bar.Size.y + 21
		&& Down == true) {
		Slider::OnMouseMove(mx, my);
	}
	Down = false;
}
void Slider::OnMouseMove(int mx, int my) {
	// TODO 1 (7/7): Clamp the coordinates and calculate the value. Call 'SetValue' when you're done.
	float value;
	if (Down) {
		/*this->controlIterator*/
		/*mx = std::max(mx, (int)(Bar.Position.x + Bar.Size.x));
		mx = std::min(mx, (int)(Bar.Position.x));*/
		value = (float)(mx - Bar.Position.x) / (float)(Bar.Size.x);
		if (value < 0) value = 0;
		if (value > 1) value = 1;
		SetValue(value);
		Position.x = Bar.Position.x + Bar.Size.x * value;
	}
}
