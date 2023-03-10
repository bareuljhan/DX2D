#include "framework.h"
#include "Inventory.h"

Inventory::Inventory()
{
	_pannel = make_shared<Quad>(L"Resource/Texture/UI/InventoryPanel.png");

	_slotOffset = Vector2(100, 100);

	for (int y = 1; y >= -1; y--)
	{
		for (int x = -1; x < 2; x++)
		{
			shared_ptr<Slot> slot = make_shared<Slot>();
			slot->SetPosition(Vector2(_slotOffset.x * x, _slotOffset.y * y));
			slot->SetParent(_pannel->GetTransform());
			_slots.push_back(slot);
		}
	}

	_icon = make_shared<ItemIcon>();
	
	_itemDates.resize(9);

	_itemDates[0] = (DATA_M->GetItemByName("Sword"));
	_itemDates[1] = (DATA_M->GetItemByName("Shoes"));
}

Inventory::~Inventory()
{
}

void Inventory::Update()
{
	_icon->SetPosition(_slots[0]->GetTransform()->GetWorldPos());
	_pannel->Update();
	_icon->Update();

	for(auto slot : _slots)
		slot->Update();
}

void Inventory::Render()
{
	_pannel->Render();

	for (auto slot : _slots)
		slot->Render();

	_icon->Render();
}

void Inventory::PostRender()
{
	RECT rect;
	// 750 170 ... 가로세로 200, 30
	rect.left = 650;
	rect.right = 850;
	rect.bottom = WIN_HEIGHT - 185;
	rect.top = WIN_HEIGHT - 155;

	wstring money = to_wstring(_money);
	DirectWrite::GetInstance()->RenderText(L"Money : " + money, rect, 25.0f, L"Ownglyph 2022 UWY Yoon Yeong");
}
