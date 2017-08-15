//
// Created by djcupo on 8/14/17.
//

#ifndef DUNGEONCRAWL_BOARD_HPP
#define DUNGEONCRAWL_BOARD_HPP


#include <vector>
#include "Entity.hpp"
#include "Player.hpp"

class Game {

private:

    const int xSize;
    const int ySize;

    std::vector<std::vector<Entity>> gameBoard;

    Player player;
    Entity emptyEntity;
    Entity exitEntity;


    void printBoard();

    void placeEntity(Entity &entity, int x, int y);

    bool validLocation(int X, int Y);

    void clearScreen();

    char input();

    void movePlayer(char dir);

    bool sameLocation(const Entity &player, const Entity &check);

public:

    Game(int X, int Y);

    void play();

};


#endif //DUNGEONCRAWL_BOARD_HPP
