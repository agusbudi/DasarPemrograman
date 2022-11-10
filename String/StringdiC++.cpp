#include<cstdio>
#include<string>
using namespace std;

int main(){
	string s ="The title refers to the story's main antagonist, the Dark Lord Sauron, who, in an earlier age, created the One Ring to rule the other Rings of Power given to Men, Dwarves, and Elves, in his campaign to conquer all of Middle-earth. From homely beginnings in the Shire, a hobbit land reminiscent of the English countryside, the story ranges across Middle-earth, following the quest to destroy the One Ring mainly through the eyes of the hobbits Frodo, Sam, Merry and Pippin.";

	printf("panjang: %d\n", s.length());
	
	printf("posisi indeks ke %d\n", s.find("hobbit"));
	printf("mengambil substring: %s\n", s.substr(10, 6).c_str());
}
