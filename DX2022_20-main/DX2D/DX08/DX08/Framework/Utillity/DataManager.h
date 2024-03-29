#pragma once
class DataManager
{
private:
	DataManager();
	~DataManager();

public:

	static void Create()
	{
		if (_instance == nullptr)
		{
			_instance = new DataManager();
		}
	}
	
	static void Delete()
	{
		if (_instance != nullptr)
		{
			delete _instance;
		}
	}
	
	static DataManager* GetInstance()
	{
		if (_instance != nullptr)
			return _instance;

		return nullptr;
	}

	void LoadItemInfo();

	const ItemInfo& GetItemByName(string name);

	const unordered_map<string, ItemInfo>& GetItemTable() { return _itemTable; }

private:
	static DataManager* _instance;

	unordered_map<string, ItemInfo> _itemTable;
	shared_ptr<tinyxml2::XMLDocument> _document;
};