#include "espresso_based.h"

std::vector<Ingredient*>& EspressoBased::get_ingredients()
{
    return ingredients;
}

EspressoBased::EspressoBased()
    : ingredients {}
    , name {}
{
}

EspressoBased::~EspressoBased()
{
    for (const auto& i : ingredients)
        delete i;
    ingredients.clear();
}

EspressoBased::EspressoBased(const EspressoBased& esp)
{
    ingredients = esp.ingredients;
    name = esp.name;
}

void EspressoBased::operator=(const EspressoBased& esp)
{
    // I have problem with operator=
    for (auto& i : ingredients)
        delete i;
    ingredients = esp.ingredients;
    name = esp.name;
}