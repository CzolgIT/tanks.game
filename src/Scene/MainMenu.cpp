#include "Main.h"

MainMenu::MainMenu() : _Menu(4)
{
    if (Game::netManager != nullptr)
        Game::netManager->disconnectPlayer();

    if (!Game::configuration->isNicknameSet()) {

        SDL_Event e;
        bool quit = false;
        elements.push_back( new TextStatic( "Enter your nickname" , 32 , 2.3 , 3 , 0.2 ) );
        std::string inputText = "";

        TextStatic *txt = new TextStatic(inputText, 32 , 8.3 , 6 , 0.2);
        elements.push_back(txt);
        SDL_StartTextInput();
        while (!quit) {

            while (SDL_PollEvent(&e) != 0) {
                if (e.type == SDL_QUIT) {
                    quit = true;
                }
                else if (e.type == SDL_KEYDOWN) {
                    if (e.key.keysym.sym == SDLK_BACKSPACE && inputText.length() > 0) {
                        inputText.pop_back();
                    }
                    if (e.key.keysym.sym == SDLK_RETURN || e.key.keysym.sym == SDLK_ESCAPE) {
                        quit = true;
                    }
                }
                else if (e.type == SDL_TEXTINPUT) {
                    inputText += e.text.text;
                }

            }
            if (inputText != "")
                 txt->setNewName("\""+inputText+"\"");
            else txt->setNewName("\"\"");
            draw();
        }

        SDL_StopTextInput();
        if (inputText == "")
            inputText = "Player";

        elements.clear();
        Game::configuration->setNickname(inputText);

    }



    // najpierw buttony
    elements.push_back( new Button( "play on sigma" , 32 , 17.5 , 1 ) );
    elements.push_back( new Button( "play on lan" , 32 , 21.5 , 2 ) );
    elements.push_back( new Button( "settings" , 32 , 25.5 , 3 ) );
    elements.push_back( new Button( "exit" , 32 , 31 , -1 ) );
    elements.push_back( new TextStatic( "Tanks" , 32 , 2.3 , 6 , 0.2 ) );
    elements.push_back( new TextStatic( "Game" , 32 , 8.3 , 6 , 0.2 ) );

    elements[selected]->setActive(true);

    Mix_HaltMusic();
    Game::soundManager->PlayMenuMusic();


}

