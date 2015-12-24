#include "guest.h"

guest::guest()
{
    qDebug() << "Guest hand: ";
    info->Hand.PrintCards();
}

guest::~guest()
{

}

