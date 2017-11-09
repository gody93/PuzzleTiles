#include "Board.h"

Board::Board() : success(false)
			   , m_nBoardWidth(320)
			   , m_nBoardHeight(190)
			   , m_nOffset(5)
			   , tilesCount(15)
			   , firstDraw(false)
			   , hasTileBeenMoved(false)
			   , background(NULL)
			   , r(0)
			   , g(0)
			   , b(0)
			   , playBoard(tilesCount)
{
	boardPos.x = (DrawMgr::getMgr()->getScreenWidth() - m_nBoardWidth ) / 2;
	boardPos.y = (DrawMgr::getMgr()->getScreenHeight() - m_nBoardHeight) / 2;

	int i = 0;
	for( std::vector<Tile*>::iterator it = playBoard.begin(); it != playBoard.end() - 1; it++)
	{
		(*it) = new Tile();
		(*it)->setSurface(DrawMgr::getMgr()->GetTileResource(i));
		i++;
	}

	playBoardToModify = playBoard;
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

	for( std::vector<Tile*>::iterator it = playBoardToModify.begin(); it != playBoardToModify.end(); it++)
	{
		if(!firstDraw && (*it) != NULL)
		{
			(*it)->setInitalPos(i);
			(*it)->setPos(i);
			(*it)->setMousePos((*it)->getPos().x + boardPos.x , (*it)->getPos().y + boardPos.y);
			DrawMgr::getMgr()->DrawTile(*it, background);
			i++;
		}
		else
		{
			if( (*it) != NULL)
			{
				(*it)->setMousePos( (*it)->getPos().x + boardPos.x , (*it)->getPos().y + boardPos.y);
				DrawMgr::getMgr()->DrawTile(*it, background);
			}
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

void Board::handleEvent(SDL_Event e)
{
	if( e.type == SDL_MOUSEBUTTONUP )
	{
		for( std::vector<Tile*>::iterator it = playBoardToModify.begin(); it != playBoardToModify.end(); it++)
		{
			if( (*it) != NULL )
			{
				int x,y;
				SDL_GetMouseState(&x, &y);
				//Mouse is right of the button
				if( (*it)->isInsideTile(x,y) )
				{
					if( ( (*it)->getCurrPos() + m_nOffset < playBoardToModify.size() ) && ( playBoardToModify.at((*it)->getCurrPos() + m_nOffset) == NULL ) )
					{
						(*it)->moveDown();
						std::iter_swap(playBoardToModify.begin() + (*it)->getCurrPos(), playBoardToModify.begin() + (*it)->getCurrPos() + m_nOffset);
						hasTileBeenMoved = true;
						std::cout << "MoveDown \n\n";
						break;
					}
					else if( ( (*it)->getCurrPos() - m_nOffset >= 0 ) && ( playBoardToModify.at( (*it)->getCurrPos() - m_nOffset) == NULL) )
					{
						(*it)->moveUp();
						std::iter_swap(playBoardToModify.begin() + (*it)->getCurrPos(), playBoardToModify.begin() + (*it)->getCurrPos() - m_nOffset);
						hasTileBeenMoved = true;
						std::cout << "MoveUp \n\n";
						break;
					}
					else if( ( (*it)->getPos().x + (*it)->getWidth() < m_nBoardWidth ) && ( playBoardToModify.at( (*it)->getCurrPos() + 1) == NULL ) ) // Compare it to the board width
					{																																   // because its a vector and not a 2 array
						(*it)->moveRight();
						std::iter_swap(playBoardToModify.begin() + (*it)->getCurrPos(), playBoardToModify.begin() + (*it)->getCurrPos() + 1);
						hasTileBeenMoved = true;
						std::cout << "MoveRight \n\n";
						break;
					}
					else if ( ( (*it)->getPos().x > 0 ) && ( playBoardToModify.at( (*it)->getCurrPos() - 1) == NULL ) )
					{
						(*it)->moveLeft();
						std::iter_swap(playBoardToModify.begin() + (*it)->getCurrPos(), playBoardToModify.begin() + (*it)->getCurrPos() - 1);
						hasTileBeenMoved = true;
						std::cout << "MoveLeft \n\n";
						break;
					}
				}
			}
		}
	}
	updatePositions();
	fillBoard();
}
void Board::freeTiles()
{
	for( std::vector<Tile*>::iterator it = playBoardToModify.begin(); it != playBoardToModify.end(); it++)
	{
		delete (*it);
		*it = NULL;
	}

	for( std::vector<Tile*>::iterator it = playBoard.begin(); it != playBoard.end(); it++)
	{
		delete (*it);
		*it = NULL;
	}

}

void Board::printPositions()
{
	for( std::vector<Tile*>::iterator it = playBoardToModify.begin(); it != playBoardToModify.end(); it++)
	{
		if( (*it) != NULL)
		{
			std::cout << "Initial Pos: " << (*it)->getInitialPos() << " - " << (*it)->getCurrPos() << " Current Pos " << std::endl;
		}
		else
		{
			std::cout << "This pos is empty\n";
		}
	}
}

bool Board::isItSolved()
{
	success = false;
	if( playBoardToModify == playBoard )
	{
		for( std::vector<Tile*>::iterator it = playBoardToModify.begin(); it != playBoardToModify.end(); it++)
		{
			if( (*it) != NULL)
			{
				if(  (*it)->isInCorrectPlace() )
				{
					success = true;
				}
			}
		}
	}
	return success;
}

void Board::updatePositions()
{
	if( hasTileBeenMoved )
	{
		int i = 0;
		for( std::vector<Tile*>::iterator it = playBoardToModify.begin(); it != playBoardToModify.end(); it++)
		{
			if( (*it) != NULL)
			{
				(*it)->setCurrPos(i);
			}
			i++;
		}
		isItSolved();
	}

	hasTileBeenMoved = false;
}

bool Board::getSuccess()
{
	return success;
}

void Board::randomize()
{
	// std::iter_swap(playBoardToModify.begin() + 8, playBoardToModify.begin() + 9);
	// std::iter_swap(playBoardToModify.begin() + 12, playBoardToModify.begin() + 13);

	// SDL_Rect tempPos = playBoardToModify.at(8)->getPos();
	// playBoardToModify.at(8)->setPos( playBoardToModify.at(9)->getPos().x, playBoardToModify.at(9)->getPos().y);
	// playBoardToModify.at(9)->setPos( tempPos.x, tempPos.y );

	// SDL_Rect tempPos1 = playBoardToModify.at(12)->getPos();
	// playBoardToModify.at(12)->setPos( playBoardToModify.at(13)->getPos().x, playBoardToModify.at(13)->getPos().y);
	// playBoardToModify.at(13)->setPos( tempPos1.x, tempPos1.y );

	std::random_device rd;
    std::mt19937 g(rd());

	std::shuffle( playBoardToModify.begin(),playBoardToModify.end(), g );


	hasTileBeenMoved = true;
	updatePositions();
	fillBoard();
}

Board* Board::board = NULL;
