#pragma once

#include "Frame.hpp"
#include "Sprite.hpp"
#include "Button/Button.hpp"
#include "BackSprite.hpp"
#include <functional>

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

    virtual bool startPressed() const;
    virtual bool multiplayerPressed() const;
    virtual bool& settingsPressed();
    virtual bool statisticsPressed() const;
    virtual bool achivmentsPressed() const;
    virtual bool shopPressed() const;
    
};

