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

	for (int i = 0; i < 9; i++)
	{
		shared_ptr<ItemIconButton> icon = make_shared<ItemIconButton>();
		icon->GetButton()->SetIntEvent(std::bind(&Inventory::SetCurIndex, this, i));
		_icons.push_back(icon);
	}
	
	_itemDates.resize(9);

	Set();
}

Inventory::~Inventory()
{
}

void Inventory::Update()
{
	_pannel->Update();
	for (auto icon : _icons)
		icon->Update();

	for(auto slot : _slots)
		slot->Update();
}

void Inventory::Render()
{
	_pannel->Render();

	for (auto slot : _slots)
		slot->Render();

	for (auto icon : _icons)
		icon->Render();
}

void Inventory::PostRender()
{
	Vector2 tempPos = _pannel->GetTransform()->GetWorldPos();

	RECT rect;
	// 750 170 ... 가로세로 200, 30
	rect.left = tempPos.x - 100;
	rect.right = tempPos.x + 100;

	rect.bottom = tempPos.y + 185;
	rect.top = tempPos.y + 155;

	wstring money = to_wstring(_money);
	DirectWrite::GetInstance()->RenderText(L"Money : " + money, rect, 25.0f, L"Ownglyph 2022 UWY Yoon Yeong");

	if (_curIndex >= 0 && _curIndex < 9)
	{
		ItemInfo temp = _itemDates[_curIndex];
		ImGui::Text(temp.name.c_str());
		ImGui::SliderInt("index", &_curIndex, 0, 8);
	}
}

void Inventory::SetCurIndex(int value)
{
	if (value < 0 || value > 9)
	{
		_curIndex = -1;
		return;
	}
	if(_curIndex != -1)
		_slots[_curIndex]->SetRelease();
	_curIndex = value;
	_slots[_curIndex]->SetChoice();
}

void Inventory::Set()
{
	Inventory::Update();

	for (int i = 0; i < _icons.size(); i++)
	{
		_icons[i]->SetPosition(_slots[i]->GetTransform()->GetWorldPos());
		_icons[i]->SetItem(_itemDates[i]);
	}
}

bool Inventory::AddItem(string name)
{
	ItemInfo info = DATA_M->GetItemByName(name);
	
	if (info.name == ""|| _money - info.price < 0)
		return false;

	auto iter = std::find_if(_itemDates.begin(), _itemDates.end(), [](const ItemInfo& info)-> bool
	{
		if (info.name == "")
			return true;
		return false;
	});

	if (iter == _itemDates.end())
		return false;
	
	*iter = info;
	Set();

	return true;
}

void Inventory::SellItem(string name)
{
	auto iter = std::find_if(_itemDates.begin(), _itemDates.end(), [name](const ItemInfo& info)->bool
	{
		if (info.name == name)
			return true;
		return false;
	});

	if (iter == _itemDates.end())
		return;

	AddMoney(iter->price);
	iter->SetEmpty();

	Set();
}

void Inventory::SellItem()
{
	if (_curIndex < 0 || _curIndex > 8) return;

	ItemInfo& info = _itemDates[_curIndex];

	if (info.name == "") return;

	AddMoney(info.price);
	info.SetEmpty();

	_curIndex = -1;

	Set();
}

bool Inventory::AddMoney(UINT amount)
{
	_money += amount;
	return true;
}

bool Inventory::SubMoney(UINT amount)
{
	if (_money - amount < 0) return false;
	_money -= amount;

	return true;
}
