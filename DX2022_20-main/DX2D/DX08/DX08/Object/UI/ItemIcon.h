#pragma once
class ItemIconButton
{
public:
	ItemIconButton();
	~ItemIconButton();

	void Update();
	void Render();
	
	void SetPosition(Vector2 pos) { _sprite->GetTransform()->SetPosition(pos); }
	void SetScale(Vector2 scale) { _sprite->GetTransform()->SetScale(scale); }
	void SetItem(Vector2 curFrame) { _sprite->SetCurFrame(curFrame); }
	void SetItem(const ItemInfo& info) { _sprite->SetCurFrame(Vector2(info.frameX, info.frameY)); }
	shared_ptr<Button> GetButton() { return _button; }


private:
	// 스프라이트
	// Button
	shared_ptr<Sprite> _sprite;
	shared_ptr<Button> _button;
};