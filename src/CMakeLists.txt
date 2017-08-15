SET(EntitySources
    Entity/Entity.hpp
    Entity/Entity.cpp Entity/Player/Player.cpp Entity/Player/Player.hpp)

SET(BoardSources
    Board/Game.cpp
    Board/Game.hpp)

SET(SourceFiles
    DungeonCrawl_main.cpp
    ${BoardSources}
    ${EntitySources}
    )

ADD_EXECUTABLE(
        DungeonCrawlGame
        ${SourceFiles}
)

INCLUDE_DIRECTORIES(Board)
INCLUDE_DIRECTORIES(Entity)
INCLUDE_DIRECTORIES(Entity/Player)