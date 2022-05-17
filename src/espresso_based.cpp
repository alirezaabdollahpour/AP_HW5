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