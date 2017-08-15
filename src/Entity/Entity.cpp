//
// Created by djcupo on 8/14/17.
//

#include "Entity.hpp"

std::ostream &operator<<(std::ostream &os, const Entity &entity) {
    os << entity.icon;
    return os;
}

void Entity::setIcon(char icon) {
    Entity::icon = icon;
}

void Entity::setLocation(int x, int y) {
    Entity::x = x;
    Entity::y = y;
}

int Entity::getX() const {
    return x;
}

int Entity::getY() const {
    return y;
}

void Entity::setIdentifiers(std::string name, char icon) {
    Entity::name = name;
    Entity::icon = icon;
}

const std::string &Entity::getName() const {
    return name;
}

char Entity::getIcon() const {
    return icon;
}
