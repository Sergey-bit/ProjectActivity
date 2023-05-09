#include <MainMenu.hpp>

inline void loadButton(Button& button, const std::string& calmPath,
    const std::string& hoverPath, const std::string& pressedPath)
{
    button.setCalmTexture(calmPath);
    button.setHoverTexture(hoverPath);
    button.setPressedTexture(pressedPath);
}

MainMenu::MainMenu(sf::RenderWindow& Window) :
	Frame(exchangeIF<unsigned int>( { sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height }), {0,0}),
    start( Window , 250 * globalskale, 100 * globalskale),
    multiplayer(Window, 250 * globalskale, 226 * globalskale),
    settings(Window, 250 * globalskale, 350 * globalskale),
    statistics(Window, 250 * globalskale, 474 * globalskale),
    achivments(Window, 250 * globalskale, 598 * globalskale),
    exit(Window, 965 * globalskale, 683 * globalskale),
    shop(Window),
    Window(Window),
    back(Window)
{
    back.load(TEX_PATH "MainMenu\\Background\\MainMenuBackground.png");
    back.setScale(globalskale);

    loadButton(start,
        TEX_PATH "MainMenu\\Buttons\\StartGameButton\\Calm.png",
        TEX_PATH "MainMenu\\Buttons\\StartGameButton\\Hover.png",
        TEX_PATH "MainMenu\\Buttons\\StartGameButton\\Pressed.png");

    loadButton(multiplayer,
        TEX_PATH "MainMenu\\Buttons\\PlayingWithFriendsButton\\Calm.png",
        TEX_PATH "MainMenu\\Buttons\\PlayingWithFriendsButton\\Hover.png",
        TEX_PATH "MainMenu\\Buttons\\PlayingWithFriendsButton\\Pressed.png");

    loadButton(settings,
        TEX_PATH "MainMenu\\Buttons\\SettingsButton\\Calm.png",
        TEX_PATH "MainMenu\\Buttons\\SettingsButton\\Hover.png",
        TEX_PATH "MainMenu\\Buttons\\SettingsButton\\Pressed.png");

    loadButton(statistics,
        TEX_PATH "MainMenu\\Buttons\\StaticsticsButton\\Calm.png",
        TEX_PATH "MainMenu\\Buttons\\StaticsticsButton\\Hover.png",
        TEX_PATH "MainMenu\\Buttons\\StaticsticsButton\\Pressed.png");

    loadButton(achivments,
        TEX_PATH "MainMenu\\Buttons\\AchievementButton\\Calm.png",
        TEX_PATH "MainMenu\\Buttons\\AchievementButton\\Hover.png",
        TEX_PATH "MainMenu\\Buttons\\AchievementButton\\Pressed.png");

    loadButton(exit,
        TEX_PATH "MainMenu\\Buttons\\ExitButton\\Calm.png",
        TEX_PATH "MainMenu\\Buttons\\ExitButton\\Calm.png",
        TEX_PATH "MainMenu\\Buttons\\ExitButton\\Calm.png");

    shop.load(TEX_PATH "MainMenu\\Buttons\\ShopButton\\Calm.png");
    shop.setPosition({ (int)(250 * globalskale), (int)(722 * globalskale) });
    exit.setScale(globalskale * 0.3);
    shop.setScale(globalskale * skalebutton);
    settings.setScale(globalskale * skalebutton);
    statistics.setScale(globalskale * skalebutton);
    achivments.setScale(globalskale * skalebutton);
    multiplayer.setScale(globalskale * skalebutton);
    start.setScale(globalskale * skalebutton);
}

void MainMenu::work() {
    draw(); 
    isStartPressed = start.isPressed();
    isMultiplayerPressed = multiplayer.isPressed();
    isSettingsPressed = settings.isPressed();
    isStatisticsPressed = statistics.isPressed();
    isAchivmentsPressed = achivments.isPressed();
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
