#include "../header/sorter.hpp"
#include "../header/sort_name.hpp"
#include <vector>

void Sort_Name::sort(Collection* gallery) {
   for (int i = 0; i < gallery->getCollectionSize(); i++) {
	for (int j = i + 1; j < gallery->getCollectionSize(); j++) {
	   if (gallery->getVideoGame(i)->getName() > gallery->getVideoGame(j)->getName()) {
		gallery->swapGames(i, j);
	   }
	}
   }
}
