#include<iostream>
#include<string>

using namespace std;

class MusicPlayer{
	private:
		string playlist[100];
		int totalSongs = 0;
		string currentlyPlayingSong;
		
	public:
		void addSong(string song){
			if (totalSongs<100){
				playlist[totalSongs]=song;
				totalSongs++;
				cout << " Song added: " << song << endl;
			}else{
				cout << "Playlist is full. No more songs can be added."<<endl;
			}
		}
		void removeSong(string song){
			bool found = false;
			for (int i = 0; i<totalSongs;i++){
				if (playlist[i] == song){
					for (int j=i; j <totalSongs - 1; j++){
						playlist[j] = playlist[j+1];
					}
					totalSongs--;
					found = true;
					cout<< "Song removed:"<< song <<endl;
					break;
				}
			}
			if(!found){
				cout<< "Song not found in the playlist!"<<endl;
			}
		}
		
		void playSong (string song){
			bool found = false;
			for (int i=0; i<totalSongs; i++){
				if (playlist[i]==song){
					currentlyPlayingSong = song;
					found = true;
					cout<< "Now Playing :"<< song <<endl;
					break;
				}
			}
			if(!found){
				cout<< "Song not found in the playlist."<<endl;
			}
		}
		
		void displayPlaylist(){
			if(totalSongs ==0){
				cout<< "Playlist is empty."<< endl;
			}else{
				cout<<"Playlist:"<<endl;
				for (int i=0; i<totalSongs;i++){
					cout << i+1<<"."<<playlist[i]<<endl;
				}
			}
		}
};

int main(){
	MusicPlayer player;
	
	player.addSong("Song 1");
	
	player.addSong("Song 2");
	
	player.addSong("Song 3");
	
	player.displayPlaylist();
	
	player.playSong("Song 3");
	
	player.removeSong("Song 2");
	
	player.displayPlaylist();
	
	return 0;
	
	
}
