#include "Cube.h"

class Button : public Cube
{
public:
    Button();
    ~Button();
    virtual SDL_Surface* getSurface() = 0;
	virtual SDL_Rect& getPos() = 0;
	virtual void setPos(int = 0, int = 0) = 0;
	virtual int getWidth() const = 0;
	virtual int getHeight() const = 0;

private:

    SDL_Surface* background;

    int m_nButtonWidth, m_nButtonHeight;

};
