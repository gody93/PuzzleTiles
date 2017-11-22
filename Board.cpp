#include "Board.h"

Board::Board() : success(false)
			   , m_nBoardWidth(320)
			   , m_nBoardHeight(190)
			   , m_nOffset(5)
			   , tilesCount(15)
			   , hasGameEnded(false)
			   , hasTileBeenMoved(false)
			   , hasSolution(false)
			   , background(NULL)
			   , r(0)
			   , g(0)
			   , b(0)
			   , playBoard(tilesCount)
{
	boardPos.x = (DrawMgr::getMgr()->getScreenWidth() - m_nBoardWidth ) / 2;
	boardPos.y = (DrawMgr::getMgr()->getScreenHeight() - m_nBoardHeight) / 2;

	int i = 0;
	for	(std::vector<Tile*>::iterator it = playBoard.begin(); it != playBoard.end() - 1; it++)
	{
		(*it) = new Tile();
		(*it)->setSurface(DrawMgr::getMgr()->GetTileResource(i));
		(*it)->setInitialPos(i);
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
	SDL_FillRect(background, NULL, SDL_MapRGB(background->format, 216, 120, 41));

	for( auto tile: playBoardToModify )
	{
		if( tile != NULL)
		{
			tile->setMousePos(tile->getPos().x + boardPos.x , tile->getPos().y + boardPos.y);
			DrawMgr::getMgr()->DrawTile(tile, background);
		}
	}
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
		for( auto tile: playBoardToModify )
		{
			if( tile != NULL )
			{
				int x,y;
				SDL_GetMouseState(&x, &y);
				//Mouse is right of the button
				if( tile->isInsideTile(x,y) )
				{
					if( ( tile->getCurrPos() + m_nOffset < playBoardToModify.size() ) && ( playBoardToModify.at(tile->getCurrPos() + m_nOffset) == NULL ) )
					{
						tile->moveDown();
						std::iter_swap(playBoardToModify.begin() + tile->getCurrPos(), playBoardToModify.begin() + tile->getCurrPos() - m_nOffset);
						hasTileBeenMoved = true;
						std::cout << "MoveDown \n\n";
						break;
					}
					else if( ( tile->getCurrPos() - m_nOffset >= 0 ) && ( playBoardToModify.at( tile->getCurrPos() - m_nOffset) == NULL) )
					{
						tile->moveUp();
						std::iter_swap(playBoardToModify.begin() + tile->getCurrPos(), playBoardToModify.begin() + tile->getCurrPos() + m_nOffset);
						hasTileBeenMoved = true;
						std::cout << "MoveUp \n\n";
						break;
					}
					else if( ( tile->getPos().x + tile->getWidth() < m_nBoardWidth ) && ( playBoardToModify.at( tile->getCurrPos() + 1) == NULL ) ) // Compare it to the board width
					{																																// because its a vector and not a 2 array
						tile->moveRight();
						std::iter_swap(playBoardToModify.begin() + tile->getCurrPos(), playBoardToModify.begin() + tile->getCurrPos() - 1);
						hasTileBeenMoved = true;
						std::cout << "MoveRight \n\n";
						break;
					}
					else if ( ( tile->getPos().x > 0 ) && ( playBoardToModify.at( tile->getCurrPos() - 1) == NULL ) )
					{
						tile->moveLeft();
						std::iter_swap(playBoardToModify.begin() + tile->getCurrPos(), playBoardToModify.begin() + tile->getCurrPos() + 1);
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
	for( auto tile: playBoardToModify )
	{
		delete tile;
		tile = NULL;
	}

	for( auto tile: playBoard )
	{
		delete tile;
		tile = NULL;
	}

}

void Board::printPositions()
{
	for( auto tile: playBoardToModify )
	{
		if( tile != NULL)
		{
			std::cout << "Initial Pos: " << tile->getInitialPos() << " - " << tile->getCurrPos() << " Current Pos " << std::endl;
		}
		else
		{
			std::cout << "This pos is empty\n";
		}
	}
}

bool Board::isItSolved()
{
	hasGameEnded = false;
	if( playBoardToModify == playBoard )
	{
		for( auto tile: playBoardToModify )
		{
			if( tile != NULL)
			{
				if(  tile->isInCorrectPlace() )
				{
					hasGameEnded = true;
				}
			}
		}
	}
	return hasGameEnded;
}

void Board::isThereASolution()
{
	int changesMade = 0;
	hasSolution = false;
	for( auto tile: playBoardToModify )
	{
		if( tile != NULL )
		{
			changesMade += abs( tile->getInitialPos() - tile->getCurrPos() );
		}
	}

	if( changesMade % 2 == 0)
	{
		hasSolution = true;
		std::cout << "There is solution\n\n";
	}
	else
	{
		std::cout << "No solution \n\n";
	}
}

void Board::updatePositions()
{
	if( hasTileBeenMoved )
	{
		int i = 0;
		for( auto tile: playBoardToModify )
		{
			if( tile != NULL)
			{
				tile->setCurrPos(i);
			}
			i++;
		}
		isItSolved();
	}

	hasTileBeenMoved = false;
}

bool Board::getSuccess()
{
	return hasGameEnded;
}

void Board::randomize()
{
	std::random_device rd;
    std::mt19937 g(rd());

	do
	{
		std::shuffle( playBoardToModify.begin(),playBoardToModify.end(), g );
		hasTileBeenMoved = true;
		updatePositions();
		isThereASolution();
	}while( !hasSolution );
}

void Board::endGame()
{
	hasGameEnded = true;
}

Board* Board::board = NULL;
