#include <MainMenu.hpp>


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
    start.setCalmTexture(TEX_PATH "MainMenu\\Buttons\\StartGameButton\\Calm.png");
    start.setHoverTexture(TEX_PATH "MainMenu\\Buttons\\StartGameButton\\Hover.png");
    start.setPressedTexture(TEX_PATH "MainMenu\\Buttons\\StartGameButton\\Pressed.png");
    start.setScale(globalskale * skalebutton);

    multiplayer.setCalmTexture(TEX_PATH "MainMenu\\Buttons\\PlayingWithFriendsButton\\Calm.png");
    multiplayer.setHoverTexture(TEX_PATH "MainMenu\\Buttons\\PlayingWithFriendsButton\\Hover.png");
    multiplayer.setPressedTexture(TEX_PATH "MainMenu\\Buttons\\PlayingWithFriendsButton\\Pressed.png");
    multiplayer.setScale(globalskale * skalebutton);

    settings.setCalmTexture(TEX_PATH "MainMenu\\Buttons\\SettingsButton\\Calm.png");
    settings.setHoverTexture(TEX_PATH "MainMenu\\Buttons\\SettingsButton\\Hover.png");
    settings.setPressedTexture(TEX_PATH "MainMenu\\Buttons\\SettingsButton\\Pressed.png");
    settings.setScale(globalskale * skalebutton);

    statistics.setCalmTexture(TEX_PATH "MainMenu\\Buttons\\StaticsticsButton\\Calm.png");
    statistics.setHoverTexture(TEX_PATH "MainMenu\\Buttons\\StaticsticsButton\\Hover.png");
    statistics.setPressedTexture(TEX_PATH "MainMenu\\Buttons\\StaticsticsButton\\Pressed.png");
    statistics.setScale(globalskale * skalebutton);

    achivments.setCalmTexture(TEX_PATH "MainMenu\\Buttons\\AchievementButton\\Calm.png");
    achivments.setHoverTexture(TEX_PATH "MainMenu\\Buttons\\AchievementButton\\Hover.png");
    achivments.setPressedTexture(TEX_PATH "MainMenu\\Buttons\\AchievementButton\\Pressed.png");
    achivments.setScale(globalskale * skalebutton);

    shop.setCalmTexture(TEX_PATH "MainMenu\\Buttons\\ShopButton\\Calm.png");
    shop.setHoverTexture(TEX_PATH "MainMenu\\Buttons\\ShopButton\\Hover.png");
    shop.setPressedTexture(TEX_PATH "MainMenu\\Buttons\\ShopButton\\Pressed.png");
    shop.setScale(globalskale * skalebutton);

    exit.setCalmTexture(TEX_PATH "MainMenu\\Buttons\\ExitButton\\Calm.png");
    exit.setHoverTexture(TEX_PATH "MainMenu\\Buttons\\ExitButton\\Calm.png");
    exit.setPressedTexture(TEX_PATH "MainMenu\\Buttons\\ExitButton\\Calm.png");
    exit.setScale(globalskale * 0.3);

    back.load(TEX_PATH "MainMenu\\Background\\MainMenuBackground.png");
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
