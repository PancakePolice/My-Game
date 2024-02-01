#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Character.h"
using namespace std;

void ChooseAttack(Character& attacker, Character& defender, int choice = 0);
void ChooseDefense(Character& defender, int choice = 0);
void Duel(Character& challenger, Character& opponent);

int main() {
    Character player("Player"), enemy;
    srand(time(NULL));

    Duel(player, enemy);

    cout << "THE END." << endl;

    system("pause");

    return 0;
}

void Duel(Character& challenger, Character& opponent) {
    cout << challenger.getName() << " has challeneged " << opponent.getName() << " to a duel!" << endl;

    while (challenger.getHealth() > 0 && opponent.getHealth() > 0) {

        // Phase 1
        ChooseDefense(opponent, 4);
        ChooseAttack(challenger, opponent);

        // Check for intermittent death
        if (challenger.getHealth() <= 0 || opponent.getHealth() <= 0)
            continue;

        cout << endl;

        // Phase 2
        ChooseDefense(challenger);
        ChooseAttack(opponent, challenger, 4);

        cout << endl;
    }

    if (challenger.getHealth() <= 0)
        cout << challenger.getName();
    else
        cout << opponent.getName();
    cout << " has been slain." << endl;
}

void ChooseAttack(Character& attacker, Character& defender, int choice) {
    bool isValidOption = true;

    if (choice != 4) {
        cout << "Pick an ACTION:\n1. Attack\n2. Strike\n3. Magic" << endl;
        cin >> choice;
    }

    do {
        switch (choice) {
        case 1:
            attacker.Attack(defender);

            cout << attacker.getName() << " attacked " << defender.getName() << "." << endl;
            if (defender.getDefense() == 1)
                cout << defender.getName() << " blocked for " << attacker.getAttack() / 2 << " damage!" << endl;
            else
                cout << defender.getName() << " took " << attacker.getAttack() << " damage!" << endl;

            if (!isValidOption)
                isValidOption = true;
            break;
        case 2:
            attacker.Strike(defender);
            
            cout << attacker.getName() << " struck " << defender.getName() << "." << endl;
            if (defender.getDefense() == 2)
                cout << defender.getName() << " parried it! " << endl << attacker.getName() << " takes " << attacker.getAttack() * 2 << " damage!" << endl;
            else
                cout << defender.getName() << " took " << attacker.getAttack() * 2 << " damage!" << endl;
          

            if (!isValidOption)
                isValidOption = true;
            break;
        case 3:
            attacker.Magic(defender);

            // DEBUG READOUT
            cout << attacker.getName() << " used magic on " << defender.getName() << "." << endl;
            if (defender.getDefense() == 3)
                cout << defender.getName() << " warded it for " << attacker.getMagic() << " damage!" << endl;
            else
                cout << defender.getName() << " took " << attacker.getMagic() << " damage!" << endl;
            

            if (!isValidOption)
                isValidOption = true;
            break;
        default:
            choice = rand() % 3 + 1;
            isValidOption = false;
            break;
        }
    } while (!isValidOption);
}

void ChooseDefense(Character& defender, int choice) {
    bool isValidOption = true;

    if (choice != 4) {
        cout << "Pick an ACTION:\n1. Block\n2. Parry\n3. Ward" << endl;
        cin >> choice;
    }

    do {
        switch (choice) {
        case 1:
            defender.Block();
            if (!isValidOption)
                isValidOption = true;
            break;
        case 2:
            defender.Parry();
            if (!isValidOption)
                isValidOption = true;
            break;
        case 3:
            defender.Ward();
            if (!isValidOption)
                isValidOption = true;
            break;
        default:
            choice = rand() % 3 + 1;
            isValidOption = false;
            break;
        }
    } while (!isValidOption);
}
