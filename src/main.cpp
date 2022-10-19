#include "CLAID.hpp"

int main()
{
    CLAID_RUNTIME->loadFromXML("TutorialConfig.xml");
    CLAID_RUNTIME->start();
}