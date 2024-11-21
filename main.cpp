#include "ContBancar.h"
#include "ContBancarPremium.h"

int main() {
    try {
        // Test pentru clasa de baza ContBancar
        std::cout << "Test pentru clasa de baza ContBancar:\n";
        ContBancar cont1(2);
        cont1.setNumeTitular(0, "Ion Tiriac");
        cont1.setNumeTitular(1, "Donald Trump");
        cont1.adaugaSuma(0, 100.50);
        cont1.adaugaSuma(1, 200.75);
        cont1.afiseazaConturi();

        // Test move constructor pentru ContBancar
        std::cout << "\nTest move constructor pentru ContBancar:\n";
        ContBancar contMoved(std::move(cont1)); // Mutam cont1 in contMoved
        contMoved.afiseazaConturi();
        // cont1 nu mai poate fi folosit intr-un mod sigur

        // Test pentru clasa derivata ContBancarPremium
        std::cout << "\nTest pentru clasa derivata ContBancarPremium:\n";
        ContBancarPremium contPremium(2, 5.0); // 2 conturi, dobanda 5%
        contPremium.setNumeTitular(0, "Elon Musk");
        contPremium.setNumeTitular(1, "Jeff Bezos");
        contPremium.adaugaSuma(0, 1000);
        contPremium.adaugaSuma(1, 2000);

        std::cout << "\nInainte de aplicarea dobanzii:\n";
        contPremium.afiseazaConturiPremium();

        // Aplica dobanda
        contPremium.aplicaDobanda();

        std::cout << "\nDupa aplicarea dobanzii:\n";
        contPremium.afiseazaConturiPremium();

        // Test move constructor pentru ContBancarPremium
        std::cout << "\nTest move constructor pentru ContBancarPremium:\n";
        ContBancarPremium contPremiumMoved(std::move(contPremium)); // Mutam contPremium in contPremiumMoved
        contPremiumMoved.afiseazaConturiPremium();
        // contPremium nu mai poate fi folosit intr-un mod sigur

    } catch (const std::exception& e) {
        std::cerr << "Eroare: " << e.what() << "\n";
    }

    return 0;
}
