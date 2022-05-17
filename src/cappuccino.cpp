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

// double Cappuccino::price()
// {

// }