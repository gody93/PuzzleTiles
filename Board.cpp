#include "Board.h"

Board::Board() : m_nBoardWidth(245), m_nBoardHeight(145), background(NULL), firstDraw(false)
{
	boardPos.x = (DrawMgr::getMgr()->getScreenWidth() - m_nBoardWidth ) / 2;
	boardPos.y = (DrawMgr::getMgr()->getScreenHeight() - m_nBoardHeight) / 2;
}

Board::~Board()
{
	delete Board::board;
	Board::board = NULL;

	freeTiles();
}

Board* Board::getBoard()
{
	if(!board)
	{
		board = new Board();
	}

	return board;
}

SDL_Rect& Board::getPos()
{
	return boardPos;
}

void Board::setPos(int x, int y)
{
	boardPos.x = x;
	boardPos.y = y;
}

SDL_Surface* Board::getSurface()
{
	this->background = SDL_CreateRGBSurface(0, m_nBoardWidth, m_nBoardHeight, 32, 0, 0, 0, 0);

	SDL_FillRect(background , NULL, SDL_MapRGB(background->format, 216, 120, 41));

	return this->background;
}

void Board::fillBoard()
{
	for( int i = 0; i < 14; i++)
	{
		playBoard.push_back( new Tile() );
	}

	int x = 0;
	int y = 0;
	int i = 0;

	for( std::vector<Tile*>::iterator it = playBoard.begin(); it != playBoard.end(); it++)
	{
		if(!firstDraw)
		{
			(*it)->setPos(x,y);
			(*it)->setMousePos((*it)->getPos().x + boardPos.x , (*it)->getPos().y + boardPos.y);
			SDL_BlitSurface((*it)->getSurface(), NULL, background , &((*it)->getPos()) );
			x += (*it)->getHeight() + 2;

			switch(i)
			{
			case 4:
				x = 0;
				y += (*it)->getHeight() + 2;
				break;
			case 9:
				x = 0;
				y += (*it)->getHeight() + 2;
				break;
			default:break;

			}

			i++;
		}
		else
		{
			SDL_BlitSurface((*it)->getSurface(), NULL, background, &( (*it)->getPos()) );
		}
	}
	firstDraw = true;
}

int Board::getWidth() const
{
	return m_nBoardWidth;
}

int Board::getHeight() const
{
	return m_nBoardHeight;
}

Tile* Board::getTile()
{
	return playBoard.at(1);
}

void Board::handleEvent(SDL_Event e)
{
	for( std::vector<Tile*>::iterator it = playBoard.begin(); it != playBoard.end(); it++)
	{
		(*it)->handleEvent(e);
	}

	fillBoard();
}
void Board::freeTiles()
{
	for( std::vector<Tile*>::iterator it = playBoard.begin(); it != playBoard.end(); it++)
	{
		delete (*it);
		*it = NULL;
	}
}
Board* Board::board = NULL;
