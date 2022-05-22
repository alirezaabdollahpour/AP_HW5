#include "cappuccino.h"

double Cappuccino::price()
{
    double price {};
    for (const auto& i : side_items) {
        std::cout << i->get_name() << " ," << std::endl;
        price += i->price();
    }

    for (const auto& iterator : ingredients) {
        std::cout << iterator->get_name() << " ," << std::endl;
        price += iterator->price();
    }
    return price;
}
std::string Cappuccino::get_name()
{
    return this->name;
}

Cappuccino::~Cappuccino()
{
    for (const auto& iterator : side_items)
        delete iterator;
    side_items.clear();
}

void Cappuccino::add_side_item(Ingredient* side)
{
    side_items.push_back(side);
}

std::vector<Ingredient*>& Cappuccino::get_side_items()
{
    return side_items;
}

Cappuccino::Cappuccino(const Cappuccino& cap)
    : EspressoBased { cap }
{
    for (Ingredient* component : cap.side_items) {
        if (component->get_name() == "Cinnamon") {
            side_items.push_back(new Cinnamon { component->get_units() });
        } else if (component->get_name() == "Chocolate") {
            side_items.push_back(new Chocolate { component->get_units() });
        } else if (component->get_name() == "Sugar") {
            side_items.push_back(new Sugar { component->get_units() });
        } else if (component->get_name() == "Cookie") {
            side_items.push_back(new Cookie { component->get_units() });
        } else if (component->get_name() == "Espresso") {
            side_items.push_back(new Espresso { component->get_units() });
        } else if (component->get_name() == "Milk") {
            side_items.push_back(new Milk { component->get_units() });
        } else if (component->get_name() == "MilkFoam") {
            side_items.push_back(new MilkFoam { component->get_units() });
        }
    }
};

void Cappuccino::operator=(const Cappuccino& cap)
{
    if (this == &cap)
        return;
    else
        side_items.clear();
    for (const auto& i : cap.side_items) {
        if (i->get_name() == "Milk")
            side_items.push_back(new Milk { i->get_units() });

        if (i->get_name() == "Chocolate")
            side_items.push_back(new Chocolate { i->get_units() });

        if (i->get_name() == "Sugar")
            side_items.push_back(new Sugar { i->get_units() });

        if (i->get_name() == "Cookie")
            side_items.push_back(new Cookie { i->get_units() });

        if (i->get_name() == "Cinnamon")
            side_items.push_back(new Cinnamon { i->get_units() });

        if (i->get_name() == "Sugar")
            side_items.push_back(new Sugar { i->get_units() });

        if (i->get_name() == "Espresso")
            side_items.push_back(new Espresso { i->get_units() });

        if (i->get_name() == "MilkFoam")
            side_items.push_back(new MilkFoam { i->get_units() });

        if (i->get_name() == "Water")
            side_items.push_back(new Water { i->get_units() });
    }
}

Cappuccino::Cappuccino()
    : side_items {}
{
    ingredients.push_back(new MilkFoam(1));
    ingredients.push_back(new Espresso(2));
    ingredients.push_back(new Milk(2));
    name = "Cappuccino";
}