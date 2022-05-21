#include "mocha.h"

Mocha::Mocha()
    : side_items {}
{
    ingredients.push_back(new Espresso(2));
    ingredients.push_back(new Milk(2));
    ingredients.push_back(new MilkFoam(1));
    ingredients.push_back(new Chocolate(1));
    name = "Mocha";
}

std::string Mocha::get_name()
{
    return this->name;
}

double Mocha::price()
{
    double price {};
    for (const auto& i : side_items)
        price += i->price();
    for (const auto& i : ingredients)
        price += i->price();
    return price;
}

Mocha::~Mocha()
{
    for (const auto& i : side_items)
        delete i;
    side_items.clear();
}

void Mocha::add_side_item(Ingredient* side)
{
    side_items.push_back(side);
}

std::vector<Ingredient*>& Mocha::get_side_items()
{
    return side_items;
}
Mocha::Mocha(const Mocha& cap)
    : EspressoBased { cap }
{
    for (const auto& i : cap.side_items) {
        if (i->get_name() == "Cinnamon")
            side_items.push_back(new Cinnamon { i->get_units() });

        if (i->get_name() == "Chocolate")
            side_items.push_back(new Chocolate { i->get_units() });

        if (i->get_name() == "Sugar")
            side_items.push_back(new Sugar { i->get_units() });

        if (i->get_name() == "Cookie")
            side_items.push_back(new Cookie { i->get_units() });

        if (i->get_name() == "Espresso")
            side_items.push_back(new Espresso { i->get_units() });

        if (i->get_name() == "Milk")
            side_items.push_back(new Milk { i->get_units() });

        if (i->get_name() == "MilkFoam")
            side_items.push_back(new MilkFoam { i->get_units() });

        if (i->get_name() == "Water")
            side_items.push_back(new Water { i->get_units() });
    }
}

void Mocha::operator=(const Mocha& Moc)
{
    if (this == &Moc)
        return;

    for (const auto& i : side_items)
        delete i;
    side_items.clear();
    auto side_list { const_cast<Mocha&>(Moc).get_side_items() };
    for (auto& i : side_list) {
        if (i->get_name() == "Cinnamon")
            this->add_side_item(new Cinnamon(i->get_units()));
        else if (i->get_name() == "Chocolate")
            this->add_side_item(new Chocolate(i->get_units()));
        else if (i->get_name() == "Sugar")
            this->add_side_item(new Sugar(i->get_units()));
        else if (i->get_name() == "Cookie")
            this->add_side_item(new Cookie(i->get_units()));
        else if (i->get_name() == "Espresso")
            this->add_side_item(new Espresso(i->get_units()));
        else if (i->get_name() == "Milk")
            this->add_side_item(new Milk(i->get_units()));
        else if (i->get_name() == "MilkFoam")
            this->add_side_item(new MilkFoam(i->get_units()));
        else if (i->get_name() == "Water")
            this->add_side_item(new Water(i->get_units()));
    }
}