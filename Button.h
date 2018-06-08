#include "Cube.h"

class Button : public Cube
{
public:
    Button();
    ~Button();
    virtual SDL_Surface* getSurface();
	virtual SDL_Rect& getPos();
	virtual void setPos(int = 0, int = 0);
	virtual int getWidth() const;
	virtual int getHeight() const;

private:

    SDL_Surface* background;
    SDL_Rect buttonPos;

    int m_nButtonWidth, m_nButtonHeight;

};
