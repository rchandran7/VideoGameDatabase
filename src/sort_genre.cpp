#include "../header/sorter.hpp"
#include "../header/sort_genre.hpp"
#include <vector>

void Sort_Genre::sort(Collection* gallery) {
   for (int i = 0; i < gallery->getCollectionSize(); i++) {
        for (int j = i + 1; j < gallery->getCollectionSize(); j++) {
           if (gallery->getVideoGame(i)->getGenre() > gallery->getVideoGame(j)->getGenre()) {
                gallery->swapGames(i, j);
           }
        }
   }
}
