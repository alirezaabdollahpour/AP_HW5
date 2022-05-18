#include "cappuccino.h"

Cappuccino::Cappuccino()
    : side_items {}
{
    ingredients.push_back(new Espresso(2));
    ingredients.push_back(new Milk(2));
    ingredients.push_back(new MilkFoam(1));
    name = "Cappuccino";
}

std::string Cappuccino::get_name()
{
    return this->name;
}

double Cappuccino::price()
{
    double price {};
    for (const auto& i : side_items)
        price += i->price();
    for (const auto& i : ingredients)
        price += i->price();
    return price;
}

Cappuccino::~Cappuccino()
{
    for (const auto& i : side_items)
        delete i;
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