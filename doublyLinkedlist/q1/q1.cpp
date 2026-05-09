#include "Watchlist.h"
int main()
{
    Watchlist list;

    list.addMovieAtEnd(101, "Inception", 8.8);
    list.addMovieAtEnd(102, "Interstellar", 8.7);
    list.addMovieAtEnd(103, "The Dark Knight", 9.0);
    list.addMovieAtEnd(104, "Tenet", 7.3);

    list.displayWatchlist();

    list.playNext();
    list.playNext();
    list.playPrevious();

    list.findHighestRatedMovie();

    list.removeMovieByName("Interstellar");

    list.displayWatchlist();

    list.reverseWatchlist();

    list.displayWatchlist();

    return 0;
}