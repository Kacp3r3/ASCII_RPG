#ifndef TILE_H
#define TILE_H
class Tile
{
public:
	enum Content
	{
		NOTHING = 0,
		WALL = 1,
	};
public:
	Tile();
	Tile(Content c, bool solid);
	~Tile();

	//Gettery
	bool isSolid() const;
	Content GetContent()const;
	//Settery
	void makeSolid(bool x);
	void setContent(Content x);
private:
	bool bSolid;
	Content eContent;
};

#endif
