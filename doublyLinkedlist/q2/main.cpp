#include <iostream>
#include "PlaylistDLL.h"
using namespace std;

int main()
{
    PlaylistDLL playlist;

    playlist.addSongAtEnd(1, "Shape of You", 3.5);
    playlist.addSongAtEnd(2, "Believer", 3.2);
    playlist.addSongAtEnd(3, "Perfect", 4.1);
    playlist.addSongAtEnd(4, "Faded", 3.4);

    playlist.displayPlaylist();

    playlist.playNext();
    playlist.playNext();
    playlist.playPrevious();

    playlist.deleteSongByName("Believer");

    playlist.displayPlaylist();

    playlist.reversePlaylist();

    playlist.displayPlaylist();

    return 0;
}