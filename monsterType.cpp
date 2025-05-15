#include <iostream>

namespace Monster
{

    enum MonsterType
    {
        orc,
        goblin,
        troll,
        ogre,
        skeleton
    };
}

int main()
{

    using enum Monster::MonsterType;
    [[maybe_unused]] Monster::MonsterType someMonster{troll};

    std::cout << someMonster << '\n';

    return 0;
}