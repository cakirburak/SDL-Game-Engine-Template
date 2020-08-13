const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

Game* game = nullptr;

int main(void){

    SDL_Window* window = SDL_CreateWindow(
            "Temp",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN);
    if(window)
    {
        printf("Window Initialized!\n");
    }else{ return 0; }

    SDL_Renderer* renderer = SDL_CreateRenderer(
            window, -1,
            SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    if(renderer)
    {
        printf("Renderer Initialized!\n");
    }else{ return 0; }

    game = new Game();

    while(game->running())
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            game->handleEvents(&event);
        }

        game->update();
        game->render(renderer);
    }

    game->clean(window, renderer);

    return 0;
}
