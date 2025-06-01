#include "Random.h"
#include <iostream>
#include <string>
#include <string_view>

class Monster
{
public:
    // unscoped enum (nested type)
    // member types are always defined at the top

    enum Type
    {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        maxMonsterTypes,
    };

    // used std::string_view so that no expensive string
    // copies will be made

    Monster(Type monsterType, std::string_view name,
            std::string_view roar, int hitPoint)
        // member initializer list (member-wise initialization)
        : m_type{monsterType},
          m_name{name},
          m_roar{roar},
          m_hitPoints{hitPoint}
    {
    }

    void print() const;

private:
    Type m_type{};
    std::string m_name{};
    std::string m_roar{};
    int m_hitPoints{};

    std::string_view getMonsterTypeAsString(Type monsterType) const;
};

// member functions defined outside the class
// definition must be set inline explicitly

inline void Monster::print() const
{
    if (m_hitPoints > 0)
    {
        std::cout << m_name << " the "
                  << getMonsterTypeAsString(m_type)
                  << " has " << m_hitPoints
                  << " hit points and says "
                  << m_roar << '\n';
    }
    else
    {
        std::cout << m_name << " the "
                  << getMonsterTypeAsString(m_type)
                  << " is dead.\n";
    }
}

std::string_view Monster::getMonsterTypeAsString(Type monsterType) const
{

    switch (monsterType)
    {
    case dragon:
        return "dragon";
    case goblin:
        return "goblin";
    case ogre:
        return "ogre";
    case orc:
        return "orc";
    case skeleton:
        return "skeleton";
    case troll:
        return "troll";
    case vampire:
        return "vampire";
    case zombie:
        return "zombie";
    default:
        return "???";
    }
}

namespace MonsterGenerator
{

    std::string_view getName(int choice)
    {
        switch (choice)
        {
        case 0:
            return "Blarg";
        case 1:
            return "Moog";
        case 2:
            return "Pksh";
        case 3:
            return "Tyrn";
        case 4:
            return "Mort";
        case 5:
            return "Hans";
        default:
            return "???";
        }
    }

    std::string_view getRoar(int choice)
    {
        switch (choice)
        {
        case 0:
            return "*ROAR*";
        case 1:
            return "*peep*";
        case 2:
            return "*squeal*";
        case 3:
            return "*whine*";
        case 4:
            return "*growl*";
        case 5:
            return "*burp*";
        default:
            return "???";
        }
    }

    Monster generate()
    {
        constexpr int minChoice{0};
        constexpr int maxChoice{5};

        constexpr int minHitPoints{0};
        constexpr int maxHitPoints{100};

        return Monster{Monster::skeleton,
                       getName(Random::get(minChoice, maxChoice)),
                       getRoar(Random::get(minChoice, maxChoice)),
                       Random::get(minHitPoints, maxHitPoints)};
    }
}

int main()
{
    Monster m{MonsterGenerator::generate()};
    m.print();

    return 0;
}