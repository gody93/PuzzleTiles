#include "Board.h"

Board::Board() : m_nBoardWidth(245), m_nBoardHeight(245), background(NULL)
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
	this->background = SDL_CreateRGBSurface(0, m_nBoardHeight, m_nBoardWidth, 32, 0, 0, 0, 0);

	SDL_FillRect(background , NULL, SDL_MapRGB(background->format, 216, 120, 41));

	fillBoard();

	return this->background;
}

void Board::fillBoard()
{
	for( int i = 0; i < 15; i++)
	{
		playBoard.push_back( new Tile() );
	}
	int x = 0;
	int y = 0;
	// playBoard.at(0)->setPos();
	// //SDL_Rect blitDest = playBoard.at(0)->getPos();

	// playBoard.at(0)->setMousePos(playBoard.at(0)->getPos().x + boardPos.x , playBoard.at(0)->getPos().y + boardPos.y);
	// SDL_BlitSurface(playBoard.at(0)->getSurface(), NULL, background , &(playBoard.at(0)->getPos()) );

	// playBoard.at(1)->setPos(50);
	// playBoard.at(1)->setMousePos(playBoard.at(1)->getPos().x + boardPos.x , playBoard.at(1)->getPos().y + boardPos.y);
	// SDL_BlitSurface(playBoard.at(1)->getSurface(), NULL, background , &(playBoard.at(1)->getPos()) );

	for( int i = 0; i < 15; i++)
	{
		playBoard.at(i)->setPos(x,y);
		playBoard.at(i)->setMousePos(playBoard.at(i)->getPos().x + boardPos.x , playBoard.at(i)->getPos().y + boardPos.y);
		SDL_BlitSurface(playBoard.at(i)->getSurface(), NULL, background , &(playBoard.at(i)->getPos()) );
		x += playBoard.at(i)->getHeight() + 5;

		switch(i)
		{
		case 4:
			x = 0;
			y += playBoard.at(i)->getHeight() + 5;
			break;
		case 9:
			x = 0;
			y += playBoard.at(i)->getHeight() + 5;
			break;
		case 14:
			x = 0;
			y += playBoard.at(i)->getHeight() + 5;
			break;
		default:break;
		}
	}


	// for( int i = 0; i < bRows; i++)
	// {
	// 	playBoard.at(i)->setPos(0,y);
	// 	for( int j = 0; j < bCols; j++)
	// 	{
	// 		if( j == 0)
	// 		{
	// 			x = 0;
	// 		}
	// 		playBoard.at(j)->setPos(x);
	// 		playBoard.at(j)->setMousePos(playBoard.at(j)->getPos().x + boardPos.x , playBoard.at(j)->getPos().y + boardPos.y);
	// 		SDL_BlitSurface(playBoard.at(j)->getSurface(), NULL, background , &(playBoard.at(j)->getPos()) );
	// 		x += playBoard.at(j)->getWidth() + 5 ;
	// 	}
	// 	y += playBoard.at(i)->getHeight();
	// }
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

void Board::freeTiles()
{
	// for( int i = 0; i <= bRows; i++)
	// {
	// 	delete playBoard[i];
	// 	playBoard[i] = NULL;
	// }
}
Board* Board::board = NULL;
