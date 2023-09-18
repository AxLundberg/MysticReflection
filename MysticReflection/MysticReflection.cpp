// MysticReflection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <format>

int main()
{
    int nOpponents = 3; // standard number of opponents in EDH
    int nReflections;

    std::cout << "Enter a X value number of creatures entering the battlefield: ";
    while (!(std::cin >> nReflections) || nReflections < 0) {
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cerr << "Invalid input. Please enter a whole number." << std::endl;
    }

    std::cout << "\nMystic Reflection targetting:\n\n";

    std::cout << "--- Akoum Battlesinger ---\n";
    {
        int nSingers = nReflections + 1;
        int nTriggers = nReflections*nSingers;
        int initialPower = 1;
        int individualPower = initialPower + nTriggers;
        auto result = std::format(" Results in:\n   {} Battlesingers with {} power\n   For a total Power of {}\n",
            nSingers, individualPower, nSingers*individualPower);
        std::cout << result;
        std::cout << " Formula:\n    x^3+2x^2+2x+1 = (x+1)+x(x+1)^2 = ";
        std::cout << std::pow(nReflections, 3) + 2 * std::pow(nReflections, 2) + 2 * nReflections + 1 << "\n\n";

    }
    std::cout << "--- Halimar Excavator ---\n";
    {
        int nExcavators = nReflections + 1;
        int nTriggers = nExcavators * nReflections;
        auto result = std::format(" Results in:\n   {} Excavators triggering {} times, each trigger causing {} targeted milling\n   For a total mill of {}\n",
            nExcavators, nReflections, nExcavators, nTriggers * nExcavators);
        std::cout << result;
        std::cout << " Formula:\n    x^3+2x^2+x = x(x+1)^2 = ";
        std::cout << nReflections*std::pow(nReflections+1, 2) <<"\n\n";
    }
    std::cout << "--- Hagra Diabolist ---\n";
    {
        int nDiabolists = nReflections + 1;
        int nTriggers = nDiabolists * nReflections;
        auto result = std::format(" Results in:\n   {} Diabolists Triggering {} times, each trigger causing {} targeted life loss\n   For a total life loss of {}\n",
            nDiabolists, nReflections, nDiabolists, nTriggers * nDiabolists);
        std::cout << result;
        std::cout << " Formula:\n    x^3+2x^2+x = x(x+1)^2 = ";
        std::cout << nReflections * std::pow(nReflections + 1, 2) << "\n\n";
    }
    std::cout << "--- Devilish Valet ---\n";
    {
        int nDevils = nReflections + 1;
        auto result = std::format(" Results in:\n   Initial Valet with {} power and {} Valets with {} Power for a total Power of {}\n",
            std::pow(2, nReflections), nReflections, std::pow(2, nReflections-1), std::pow(2, nReflections)+nReflections* std::pow(2, nReflections - 1));
        std::cout << result;
        std::cout << " Formula:\n    2^x+x*2^(x-1) = ";
        std::cout << std::pow(2, nReflections) + nReflections* std::pow(2, nReflections - 1) << "\n\n";
    }
    std::cout << "--- Gary ---\n";
    {
        int devotion = 2*(nReflections + 1);
        auto result = std::format(" Results in:\n   {} devotion, {} reflected Garys etb'ing, each trigger causing {} radiated life loss and {} times the lifegain\n   For a total life loss of {} for each opponen\n",
            devotion, nReflections, devotion, nOpponents, nReflections*devotion);
        std::cout << result;
        std::cout << " Formula(per oppo):\n    x*2(x+1) = 2x^2+2x = ";
        std::cout << nReflections * devotion << "\n";
        std::cout << " Formula(total loss/gain):\n    3(2x^2+2x) = ";
        std::cout << nOpponents * nReflections * devotion << "\n\n";
    }
    std::cout << "--- 'Whenever X or another Y' ---\n";
    {
        int nTriggers = (nReflections + 1) * nReflections;
        std::cout << "  -Coercive Recruiter-\n";
        {
            auto result = std::format("     Results in:\n   {} Recruiter triggers, which can gain control of {} creatures\n",
                nTriggers, nTriggers);
            std::cout << result;
        }
        std::cout << "  -Darksteel Splicer-\n";
        {
            auto result = std::format("     Results in:\n   {} Splicer triggers, which creates {} 3/3 golems\n",
                nTriggers, nTriggers*nOpponents);
            std::cout << result;
        }
        std::cout << "  -Ganax, Astral Hunter-\n";
        {
            auto result = std::format("     Results in:\n   {} Ganax triggers, which creates {} treasures\n",
                nTriggers, nTriggers);
            std::cout << result;
        }
        std::cout << "  -Grim Guardian-\n";
        {
            auto result = std::format("     Results in:\n   {} Guardian triggers, causing {} life loss on each opponent, for a total life loss of {}\n",
                nTriggers, nTriggers, nTriggers*nOpponents);
            std::cout << result;
        }
        std::cout << "  -Omnath, Locus of Rage-\n";
        {
            auto result = std::format("     Results in:\n   {} Omnath death triggers each dealing 3 dmg to any target, causing {} total dmg\n",
                nTriggers, 3*nTriggers);
            std::cout << result;
        }
        std::cout << "  -Scourge of Valkas-\n";
        {
            auto result = std::format("     Results in:\n   {} Valkas triggers each dealing {} dmg to any target, causing {} total dmg\n",
                nTriggers, nReflections + 1, (nReflections+1) * nTriggers);
            std::cout << result;
        }
        std::cout << "  -Risen Reef-\n";
        {
            auto result = std::format("     Results in:\n   {} Reef triggers, resulting in {} Reef 'draws'\n",
                nTriggers, nTriggers);
            std::cout << result;
        }
        std::cout << "  -Thieves' Guild Enforcer-\n";
        {
            auto result = std::format("     Results in:\n   {} Enforcer triggers, Causing each Opponent to mill {} cards for a total mill of {} cards\n",
                nTriggers, nTriggers*2, nOpponents*nTriggers*2);
            std::cout << result;
        }
        std::cout << "  -Nylea's Colossus-\n";
        {
            auto result = std::format("     Results in:\n   {} Colossus triggers, which can turn a 1 p/t into {} p/t\n",
                nTriggers, std::pow(2, nTriggers));
            std::cout << result;
            std::cout << " Formula(p/t multiplier):\n    2^(x^2+x) = ";
            std::cout << std::pow(2, nTriggers) << "\n\n";
        }
    }

    // under Opponents control
    std::cout << "--- Ferocidon/Poisonbelly ---\n";
    {
        int nTriggersPerETB = nReflections;
        auto result = std::format(" Results in:\n   {} dmg/life loss triggers per creature entering under their control\n",
            nTriggersPerETB);
        std::cout << result;
    }
    
}
