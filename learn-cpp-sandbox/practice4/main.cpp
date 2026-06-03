#include "lesson_13.h"
#include <iostream>


int main()
{
    // Fraction f { 3, 4 };
    // aliasPrac();
    // enumPrac1();

    // SortOrder order{numerical};
    // sortData(order);

    // bitFlagPrac();

    // Color point {color_blue};
    // Feeling feeling {feeling_blue};

    // Color::Color point {Color::blue};
    // Feeling::Feeling feeling {Feeling::blue};

    // MonsterType::MonsterType monster{MonsterType::ogre};
    // std::cout << monster << std::endl;

    // Animal animal{giraffe};
    // std::cout << animal << std::endl;

    // castingEnums();

    // constexpr ColorSwitch::Color colorRed {ColorSwitch::Color::red};
    // std::cout << "Your shirt is " << ColorSwitch::getColorName(colorRed) << std::endl;

    // constexpr PetSwitches::Pet piglet { PetSwitches::Pet::pig};
    // std::cout << "Your pet's name is " << PetSwitches::getPetName(piglet) << std::endl;

    // std::cout << "Enter one of your pets' names:\n";
    // std::string s{};
    // std::cin >> s;
    // std::optional<PetSwitches::Pet> petName { PetSwitches::getPetFromString(s) };   // result needs to be dereferenced before using elsewhere
    // if (!petName)
    //     std::cout << "There is no pet by that name.\n";
    // else
    // {
    //     std::string_view dereffedName { getPetName(*petName) };
    //     std::cout << "Oh yeah, " << dereffedName << " is here\n";
    // }

    // ScopedEnum::Color color { ScopedEnum::Color::red };
    // ScopedEnum::Fruit fruit { ScopedEnum::Fruit::apple };
    // ScopedEnum::enumFunc(color, fruit);

    // enum Color
    // {
    //     red,
    //     black,
    // };
    // enum Fruit
    // {
    //     apple,
    //     banana,
    // };
    // Color color { red };
    // Fruit fruit { apple };
    // if (fruit == color)
    //     std::cout << "The fruit and color are the same\n";
    // else
    //     std::cout << "The fruit and the color are diff\n";


    // Color color { Color::black };
    // int colorEnum = static_cast<int>(color);
    // std::cout << colorEnum << "\n";

    // WoojSwitch::Pet zekiel { WoojSwitch::zeke };
    // WoojSwitch::Pet chloe { WoojSwitch::chlo };
    // const std::string_view chloeStr { WoojSwitch::getPetFromEnum(WoojSwitch::rodent) };
    // std::cout << "Chloe's name is " << chloeStr << '\n';
    // std::cout << "Rodent is numbered " << *(WoojSwitch::getEnumFromString(chloeStr)) + 1 << "\n";

    // BasicStruct::doRandomBs();
    // InitializerList::printWage();
    RepeatStructInitialize::printInitialized();

    return 0;
}