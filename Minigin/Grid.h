#pragma once
#include "Tile.h"

class Grid : public GameObject
{
public:
	explicit Grid(const std::string& levelName,const std::shared_ptr<GameObject> player,int width);
	virtual ~Grid();
	void Init()override;
	std::vector<std::shared_ptr<Tile>> GetTiles() const { return mTiles; }
	int GetTileIdx()const;
	int GetTileLeftIdx()const;
	int GetTileRightIdx()const;
	int GetTileUpIdx()const;
	int GetTileDownIdx()const;

private:
	void Parse(const std::string& line);
	int GetRow() const;
	int GetColumn() const;
	int mGridWidth;
	int mAmtOfRows = mGridWidth / 32;
	int mCurrentLineHeight = 0;
	int mCurrentXPos = 0;
	std::vector<std::shared_ptr<Tile>> mTiles;
	std::string mLevelName;
	std::string mLevelPath = "../Levels/";
	std::shared_ptr<GameObject> mPlayer;
};

