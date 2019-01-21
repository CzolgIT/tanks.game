#include "Main.h"

MainMenu::MainMenu() : _Menu(4)
{
    if (Game::netManager != nullptr)
        Game::netManager->disconnectPlayer();

    if (!isNicknameSet()) {

        SDL_Event e;
        bool quit = false;
        SDL_StartTextInput();
        elements.push_back( new TextStatic( "Enter your nickname" , 32 , 2.3 , 6 , 0.2 ) );
        std::string inputText = "A";

        TextStatic *txt = new TextStatic(inputText, 32 , 8.3 , 6 , 0.2);
        elements.push_back(txt);
        while (!quit) {

            //Handle events on queue
            while (SDL_PollEvent(&e) != 0) {
                //User requests quit
                if (e.type == SDL_QUIT) {
                    quit = true;
                }
                    //Special key input
                else if (e.type == SDL_KEYDOWN) {
                    //Handle backspace
                    if (e.key.keysym.sym == SDLK_BACKSPACE && inputText.length() > 0) {
                        //lop off character
                        inputText.pop_back();
                    }
                    if (e.key.keysym.sym == SDLK_RETURN || e.key.keysym.sym == SDLK_ESCAPE) {
                        quit = true;
                    }
                }
                    //Special text input event
                else if (e.type == SDL_TEXTINPUT) {
                    //Not copy or pasting
                    if (!((e.text.text[0] == 'c' || e.text.text[0] == 'C') &&
                          (e.text.text[0] == 'v' || e.text.text[0] == 'V') && SDL_GetModState() & KMOD_CTRL)) {
                        //Append character
                        inputText += e.text.text;

                    }
                }

            }
            if (inputText != "")
            txt->setNewName(inputText);
            else txt->setNewName(" ");
            draw();

        }

        std::cout << inputText << std::endl;
        SDL_StopTextInput();
        elements.clear();
        setNickname(inputText);

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

bool MainMenu::isNicknameSet() {

    std::ifstream infile("config.txt");
    std::string name ("NAME");

    std::string line;
    while (std::getline(infile, line))
    {
        if( name.compare(line.substr(0,4)) == 0)
        {
            if (line.length() <=5)
                return false;
        }
    }

    return true;
}

void MainMenu::setNickname(std::string name) {

    std::fstream config("config.txt", std::fstream::app);
    config << " "<< name;
}
