//
// Created by djcupo on 8/14/17.
//

#ifndef DUNGEONCRAWL_ENTITY_HPP
#define DUNGEONCRAWL_ENTITY_HPP


#include <ostream>

class Entity {
protected:
    std::string name;
    char icon;
    int x;
    int y;


public:
    Entity() = default;

    virtual ~Entity() = default;

    friend std::ostream &operator<<(std::ostream &os, const Entity &entity);

    void setIdentifiers(std::string name, char icon);

    void setIcon(char icon);

    void setLocation(int x, int y);

    int getX() const;

    int getY() const;

    const std::string &getName() const;

    char getIcon() const;


};


#endif //DUNGEONCRAWL_ENTITY_HPP
