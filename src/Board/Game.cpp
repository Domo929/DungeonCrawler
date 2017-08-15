//
// Created by djcupo on 8/14/17.
//

#include <iostream>
#include <sstream>
#include "Game.hpp"

#define EMPTYICON '.'
#define EXITICON '@'
#define PLAYERICON '#'


Game::Game(int X, int Y) : xSize(X), ySize(Y) {

    emptyEntity.setIdentifiers("Empty", EMPTYICON);
    exitEntity.setIdentifiers("Exit", EXITICON);
    player.setIdentifiers("Player", PLAYERICON);

    gameBoard.resize((unsigned long) ySize);

    for (auto &line : gameBoard) {
        line.resize((unsigned long) xSize, emptyEntity);
    }

    try {
        placeEntity(player, 0, 0);
        placeEntity(exitEntity, xSize - 1, ySize - 1);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl << std::endl << std::endl << ".....dumbass" << std::endl;
    }
}

void Game::play() {

    while (true) {
        clearScreen();
        printBoard();
        char keyPress;
        while ((keyPress = input()) == ' ');

        if(keyPress == 'q') break;

        try {
            movePlayer(keyPress);
        } catch (std::exception &e) {
            placeEntity(player, player.getX(), player.getY());
        }

        if (sameLocation(player, exitEntity)) {
            clearScreen();
            printBoard();
            std::cout << std::endl << "Congratulations! You made it to the end!" << std::endl;
            break;
        }
    }


}


//HELPERS//
void Game::printBoard() {
    for (auto row : gameBoard) {
        for (const auto &spot: row) {
            std::cout << spot << ' ';
        }
        std::cout << std::endl;
    }

}

void Game::placeEntity(Entity &entity, int x, int y) {
    if (!validLocation(x, y)) {
        std::ostringstream msg;
        msg << "X or Y is out of range for Entity: " << entity.getName() << std::endl;
        throw std::invalid_argument(msg.str());
    } else {
        entity.setLocation(x, y);
        gameBoard[entity.getY()][entity.getX()] = entity;
    }

}

bool Game::validLocation(int X, int Y) {
    return (X >= 0 && X < xSize && Y >= 0 && Y < ySize);
}

void Game::clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

char Game::input() {
    int firstChar = getchar();
    switch (firstChar) {
        case '\033':
            getchar(); // skip the [
            switch (getchar()) { // the real value
                case 'A': //Up
                    return 'A';
                case 'B': //Down
                    return 'B';
                case 'C': //Right
                    return 'C';
                case 'D': //Left
                    return 'D';
                default:
                    break;
            }
            break;
        case 'q':
            return 'q';
    }


    return ' ';

}

void Game::movePlayer(char dir) {
    switch (dir) {
        case 'A': //Up
            placeEntity(emptyEntity, player.getX(), player.getY());
            placeEntity(player, player.getX(), player.getY() - 1);
            return;
        case 'B': //Down
            placeEntity(emptyEntity, player.getX(), player.getY());
            placeEntity(player, player.getX(), player.getY() + 1);
            return;
        case 'C': //Right
            placeEntity(emptyEntity, player.getX(), player.getY());
            placeEntity(player, player.getX() + 1, player.getY());
            return;
        case 'D': //Left
            placeEntity(emptyEntity, player.getX(), player.getY());
            placeEntity(player, player.getX() - 1, player.getY());

            return;
        default:
            break;
    }
}

bool Game::sameLocation(const Entity &player, const Entity &check) {
    return (player.getX() == check.getX() && player.getY() == check.getY());
}
