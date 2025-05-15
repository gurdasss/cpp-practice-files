#include <iostream>
#include <string>
#include <string_view>

enum class MonsterType
{
    ogre,
    dragon,
    orc,
    giantSpider,
    slime,
};

struct Monster
{
    std::string monsterName{};
    MonsterType monsterType{};
    int health{};
};

constexpr std::string_view getMonsterType(const MonsterType &monster)
{
    using enum MonsterType;

    switch (monster)
    {
    case ogre:
        return "Ogre";
    case dragon:
        return "Dragon";
    case orc:
        return "Orc";
    case giantSpider:
        return "Giant Spider";
    case slime:
        return "Slime";

    default:
        return "???";
    }
}

std::ostream &operator<<(std::ostream &out, const Monster &monster)
{
    out << "This " << getMonsterType(monster.monsterType);
    out << " is named " << monster.monsterName;
    out << " and has " << monster.health << " health.";

    return out;
}

int main()
{
    using enum MonsterType;

    Monster torg{"Torg", ogre, 145};

    std::cout << torg << '\n';

    Monster blurp{"Blurp", slime, 23};

    std::cout << blurp << '\n';

    return 0;
}