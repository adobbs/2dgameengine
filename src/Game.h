#ifndef GAME_H
#define GAME_H

class Game
{
private:
    /* data */
public:
    Game(/* args */);
    ~Game();
    void Initialize();
    void Run();
    void ProcessInput();
    void Update();
    void Render();
    void Destroy();
};

#endif
