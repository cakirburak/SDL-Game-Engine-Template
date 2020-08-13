#ifndef TEMP_GAME_HPP
#define TEMP_GAME_HPP

class Game {

public:
    Game();
    ~Game();

    void handleEvents(SDL_Event* event);
    void update();
    void render(SDL_Renderer* renderer);
    void clean(SDL_Window* window, SDL_Renderer* renderer);
    bool running(){ return isRunning; }


private:
    bool isRunning;

};

#endif
