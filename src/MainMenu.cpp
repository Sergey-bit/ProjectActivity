#include "MainMenu.hpp"

MainMenu::MainMenu(sf::RenderWindow& Window) :
	Frame({ 1600, 900 }, { 0,0 }) ,
    start( Window , vec2i(250 * globalskale, 100 * globalskale)),
    multiplayer(Window, vec2i(250 * globalskale, 226 * globalskale)),
    settings(Window, vec2i(250 * globalskale, 350 * globalskale)),
    statistics(Window, vec2i(250 * globalskale, 474 * globalskale)),
    achivments(Window, vec2i(250 * globalskale, 598 * globalskale)),
    shop(Window, vec2i(250 * globalskale, 722 * globalskale)),
    exit(Window, vec2i(965 * globalskale, 683 * globalskale)),
    Window(Window),
    back(Window)

{
    start.setCalmTexture("image\\startgame.png"); 
    start.setHoverTexture("image\\startgame_hovered.png");
    start.setPressedTexture("image\\startgame_pressed.png");
    start.setScale(globalskale * skalebutton);

    multiplayer.setCalmTexture("image\\multiplayer.png");
    multiplayer.setHoverTexture("image\\multiplayer_hovered.png");
    multiplayer.setPressedTexture("image\\multiplayer_pressed.png");
    multiplayer.setScale(globalskale * skalebutton);

    settings.setCalmTexture("image\\settings.png");
    settings.setHoverTexture("image\\settings_hovered.png");
    settings.setPressedTexture("image\\settings_pressed.png");
    settings.setScale(globalskale * skalebutton);

    statistics.setCalmTexture("image\\statistics.png");
    statistics.setHoverTexture("image\\statistics_hovered.png");
    statistics.setPressedTexture("image\\statistics_pressed.png");
    statistics.setScale(globalskale * skalebutton);

    achivments.setCalmTexture("image\\achivments.png");
    achivments.setHoverTexture("image\\achivments_hovered.png");
    achivments.setPressedTexture("image\\achivments_pressed.png");
    achivments.setScale(globalskale * skalebutton);

    shop.setCalmTexture("image\\shop.png");
    shop.setHoverTexture("image\\shop_hovered.png");
    shop.setPressedTexture("image\\shop_pressed.png");
    shop.setScale(globalskale * skalebutton);

    exit.setCalmTexture("image\\exit.png");
    exit.setHoverTexture("image\\exit.png");
    exit.setPressedTexture("image\\exit.png");
    exit.setScale(globalskale * skalebutton * 0.175);

    back.load("image\\menu.png");
    back.setScale(vec2f(globalskale, globalskale));
}

void MainMenu::work() {
    draw();

    if (start.isPressed()) {
        isStartPressed = true;
    }
    if (multiplayer.isPressed()) {
        isMultiplayerPressed = true;
    }
    if (settings.isPressed()) {
        isSettingsPressed = true;
    }
    if (statistics.isPressed()) {
        isStatisticsPressed = true;
    }
    if (achivments.isPressed()) {
        isAchivmentsPressed = true;
    }
    if (shop.isPressed()) {
        isShopPressed = true;
    }
    if (exit.isPressed()) {
       Window.close();
    }

}

void MainMenu::draw() {
    back.draw();
    start.draw();
    multiplayer.draw();
    settings.draw();
    statistics.draw();
    achivments.draw();
    shop.draw();
    exit.draw();
}

bool MainMenu::startPressed() const {
    return isStartPressed;
}

bool MainMenu::multiplayerPressed() const {
    return isMultiplayerPressed;
}

bool MainMenu::settingsPressed() const {
    return isSettingsPressed;
}

bool MainMenu::statisticsPressed() const {
    return isStatisticsPressed;
}

bool MainMenu::achivmentsPressed() const {
    return isAchivmentsPressed;
}

bool MainMenu::shopPressed() const {
    return isShopPressed;
}
