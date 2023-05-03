#include "MainMenu.hpp"

MainMenu::MainMenu(sf::RenderWindow& Window) :
	Frame(exchangeIF<unsigned int> ( { sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height }), {0,0}),
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
    exit.setScale(globalskale * 0.3 );

    back.load("image\\menu.png");
    back.setScale(vec2f(globalskale, globalskale));
}

void MainMenu::work() {
    draw(); 
    isStartPressed = start.isPressed();
    isMultiplayerPressed = multiplayer.isPressed();
    isSettingsPressed = settings.isPressed();
    isStatisticsPressed = statistics.isPressed();
    isAchivmentsPressed = achivments.isPressed();
    isShopPressed = shop.isPressed();
    if(exit.isPressed()) Window.close();
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

const bool& MainMenu::startPressed() const {
    return isStartPressed;
}

const bool& MainMenu::multiplayerPressed() const {
    return isMultiplayerPressed;
}

const bool& MainMenu::settingsPressed() const {
    return isSettingsPressed;
}

const bool& MainMenu::statisticsPressed() const {
    return isStatisticsPressed;
}

const bool& MainMenu::achivmentsPressed() const {
    return isAchivmentsPressed;
}

const bool& MainMenu::shopPressed() const {
    return isShopPressed;
}
