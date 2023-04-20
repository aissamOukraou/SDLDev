#ifndef _GAME_OBJECT_
#define _GAME_OBJECT_

class GameObject
{
public:
    GameObject();
    ~GameObject();
    void draw();
    void update();
    void clean();
protected:
    int _xpos;
    int _ypos;


};








#endif