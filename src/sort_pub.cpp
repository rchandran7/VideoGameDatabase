#include "../header/sorter.hpp"
#include "../header/sort_pub.hpp"
#include <vector>

void Sort_Pub::sort(Collection* gallery) {
   for (int i = 0; i < gallery->getCollectionSize(); i++) {
        for (int j = i + 1; j < gallery->getCollectionSize(); j++) {
           if (gallery->getVideoGame(i)->getPub() > gallery->getVideoGame(j)->getPub()) {
                gallery->swapGames(i, j);
           }
        }
   }
}
