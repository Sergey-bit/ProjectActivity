#pragma once
#include <Frame.hpp>
#include <Sprite.hpp>
#include <Button\Button.hpp>
#include <BackSprite.hpp>

class MainMenu: public Frame {
private:
    float globalskale = sf::VideoMode::getDesktopMode().width / 1920.0;
    float skalebutton = 0.75;

    sf::RenderWindow& Window;

    Button start;
    Button multiplayer;
    Button settings;
    Button statistics;
    Button achivments;
    Button shop;
    Button exit;
    BackSprite back;

    bool isStartPressed = false;
    bool isMultiplayerPressed = false;
    bool isSettingsPressed = false;
    bool isStatisticsPressed = false;
    bool isAchivmentsPressed = false;
    bool isShopPressed = false;

public:
    MainMenu(sf::RenderWindow& Window);
    virtual void work();
    virtual void draw();

    virtual const bool& startPressed() const;
    virtual const bool& multiplayerPressed() const;
    virtual const bool& settingsPressed() const;
    virtual const bool& statisticsPressed() const;
    virtual const bool& achivmentsPressed() const;
    virtual const bool& shopPressed() const;
    
};

