#pragma once
class ItemIcon
{
public:
	ItemIcon();
	~ItemIcon();

	void Update();
	void Render();
	
	void SetPosition(Vector2 pos) { _sprite->GetTransform()->SetPosition(pos); }
	void SetScale(Vector2 scale) { _sprite->GetTransform()->SetScale(scale); }
	void SetItem(Vector2 curFrame) { _sprite->SetCurFrame(curFrame); }

private:
	// 스프라이트
	// Button
	shared_ptr<Sprite> _sprite;
	shared_ptr<Button> _button;
};