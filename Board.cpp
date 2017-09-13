#include "Board.h"

Board::Board() : m_nBoardWidth(245), m_nBoardHeight(145), background(NULL), firstDraw(false), playBoard(tilesCount)
{
	boardPos.x = (DrawMgr::getMgr()->getScreenWidth() - m_nBoardWidth ) / 2;
	boardPos.y = (DrawMgr::getMgr()->getScreenHeight() - m_nBoardHeight) / 2;

	for( std::vector<Tile*>::iterator it = playBoard.begin(); it != playBoard.end() - 1; it++ )
	{
		(*it) = new Tile();
	}

	// for( int i = 0; i < bRows; i++)
	// {
	// 	for( int j = 0; j < bCols; j++)
	// 	{
	// 		if( i == bRows - 1 && j == bCols - 1)
	// 		{
	// 			continue;
	// 		}
	// 		playBoard[i][j] = new Tile();
	// 	}
	// }
}

Board::~Board()
{
	delete Board::board;
	Board::board = NULL;

	SDL_FreeSurface(background);

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
	// if(!firstDraw)
	// {
	// 	return this->background;
	// }
	// else
	// {
	// 	return this->moddedBackground;
	// }
}

void Board::fillBoard()
{
	int x = 0;
	int y = 0;
	int i = 0;

	if(firstDraw)
	{
		SDL_FillRect(background, NULL, SDL_MapRGB(background->format, 216, 120, 41));
	}

	for( std::vector<Tile*>::iterator it = playBoard.begin(); it != playBoard.end(); it++)
	{
		if(!firstDraw && (*it) != NULL)
		{
			(*it)->setInitalPos(i);
			(*it)->setPos(x,y);
			(*it)->setMousePos((*it)->getPos().x + boardPos.x , (*it)->getPos().y + boardPos.y);
			SDL_BlitSurface((*it)->getSurface(), NULL, background , &((*it)->getPos()) );
			x += (*it)->getHeight() + 5;

			switch(i)
			{
			case 4:
				x = 0;
				y += (*it)->getHeight() + 5;
				break;
			case 9:
				x = 0;
				y += (*it)->getHeight() + 5;
				break;
			default:break;

			}

			i++;
		}
		else
		{
			if( (*it) != NULL)
			{
				(*it)->setMousePos( (*it)->getPos().x + boardPos.x , (*it)->getPos().y + boardPos.y);
				SDL_BlitSurface((*it)->getSurface(), NULL, background, &((*it)->getPos()) );
			}
		}
	}

	// for( int i = 0; i < bRows; i++)
	// {
	// 	for( int j = 0; j < bCols; j++)
	// 	{
	// 		if ( i == bRows - 1 && j == bCols - 1)
	// 		{
	// 			continue;
	// 		}
	// 		if(!firstDraw)
	// 		{
	// 			playBoard[i][j]->setPos(x,y);
	// 			playBoard[i][j]->setMousePos( playBoard[i][j]->getPos().x + boardPos.x, playBoard[i][j]->getPos().y + boardPos.y);
	// 			SDL_BlitSurface( playBoard[i][j]->getSurface(), NULL, background, &( playBoard[i][j]->getPos()) );
	// 			x += playBoard[i][j]->getHeight() + 5;
	// 		}
	// 		else
	// 		{
	// 			playBoard[i][j]->setMousePos( playBoard[i][j]->getPos().x + boardPos.x, playBoard[i][j]->getPos().y + boardPos.y);
	// 			SDL_BlitSurface( playBoard[i][j]->getSurface(), NULL, background, &( playBoard[i][j]->getPos()) );
	// 		}
	// 	}
	// 	x = 0;
	// 	y += playBoard[0][0]->getHeight() + 5;
	// }

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
		if( (*it) != NULL)
		{
			(*it)->handleEvent(e, playBoard);
		}
	}

	// for( int i = 0; i < bRows; i++)
	// {
	// 	for( int j = 0; j < bCols; j++)
	// 	{
	// 		// if( i == bRows - 1 && j == bCols - 1)
	// 		// {
	// 		// 	continue;
	// 		// }
	// 		playBoard[i][j]->handleEvent(e);
	// 	}
	// }

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
