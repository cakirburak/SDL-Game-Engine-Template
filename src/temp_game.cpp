#include "temp_game.hpp"

Game::Game()
{}

Game::~Game()
{}

void Game::update()
{}

void Game::render(SDL_Renderer* renderer)
{
    // RENDER BEGIN //
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );

    // RENDER END //
    SDL_RenderPresent(renderer);
}

void Game::handleEvents(SDL_Event* event)
{
    switch (event->type){
        case SDL_QUIT:
            isRunning = false;
            break;

        default:
            break;

    }
}

void Game::clean(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    window = NULL;
    renderer = NULL;

    SDL_Quit();

    printf("Game has Cleaned!\n");
}

