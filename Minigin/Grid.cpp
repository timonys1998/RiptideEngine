#include "MiniginPCH.h"
#include "Grid.h"
#include "fstream"
#include "Pill.h"


Grid::Grid(const std::string& levelName, const std::shared_ptr<GameObject> player,int width)
	:mLevelName(levelName)
	,mPlayer(player)
	,mGridWidth(width)
{
	Init();
	
}


Grid::~Grid()
{
}

void Grid::Init()
{
	std::ifstream inputStream{ mLevelPath + mLevelName };
	std::string tileType;
	if(inputStream.good())
	{
		while (std::getline(inputStream, tileType))
		{
			Parse(tileType);
		}
	}

	for (auto t : mTiles)
	{
		t->Init();
		AddChild(t);
		if(t->GetType() == Tile::SmallPill)
		{
			auto pill = std::make_shared<Pill>(t->GetComponent<Transform>()->GetPosition(), false);
			pill->Init();
			AddChild(pill);
		}
		else if(t->GetType() == Tile::BigPill)
		{
			auto pill = std::make_shared<Pill>(t->GetComponent<Transform>()->GetPosition(), true);
			pill->Init();
			AddChild(pill);
		}
	}

	
	mPlayer->Init();
	AddChild(mPlayer);

}

int Grid::GetRow() const
{
	return int(mPlayer->GetComponent<Transform>()->GetPosition().y) / TILESIZE;
}

int Grid::GetColumn() const
{
	return int(mPlayer->GetComponent<Transform>()->GetPosition().x) / TILESIZE;
}

int Grid::GetTileIdx() const
{
	return GetRow() * mAmtOfRows + GetColumn();
}

int Grid::GetTileLeftIdx() const
{
	return GetRow() * mAmtOfRows + (GetColumn() - 1);
}

int Grid::GetTileRightIdx() const
{
	return GetRow() * mAmtOfRows + (GetColumn() + 1);
}

int Grid::GetTileUpIdx() const
{
	return (GetRow() - 1) * mAmtOfRows + GetColumn();
}

int Grid::GetTileDownIdx() const
{
	return (GetRow() + 1) * mAmtOfRows + GetColumn();
}

void Grid::Parse(const std::string& line)
{
	
	for (auto it = line.begin(); it < line.end(); ++it)
	{
		auto type = (*it);
		if(type == '0')
		{
			mTiles.push_back(std::make_shared<Tile>(mCurrentXPos, mCurrentLineHeight,Tile::Type(0) ));
		}
		else if (type == '1')
		{
			mTiles.push_back(std::make_shared<Tile>(mCurrentXPos, mCurrentLineHeight, Tile::Type(1)));
		}
		else if (type == '2')
		{
			mTiles.push_back(std::make_shared<Tile>(mCurrentXPos, mCurrentLineHeight, Tile::Type(2)));
		}
		else if (type == '3')
		{
			mTiles.push_back(std::make_shared<Tile>(mCurrentXPos, mCurrentLineHeight, Tile::Type(3)));
		}
		mCurrentXPos += TILESIZE;
		
	}
	mCurrentLineHeight += TILESIZE;
	mCurrentXPos = 0;
}

