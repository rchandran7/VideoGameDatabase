#include "../header/sorter.hpp"
#include "../header/sort_year.hpp"
#include <vector>

void Sort_Year::sort(Collection* gallery) {
   for (int i = 0; i < gallery->getCollectionSize(); i++) {
        for (int j = i + 1; j < gallery->getCollectionSize(); j++) {
           if (gallery->getVideoGame(i)->getYear() > gallery->getVideoGame(j)->getYear()) {
                gallery->swapGames(i, j);
           }
        }
   }
}
