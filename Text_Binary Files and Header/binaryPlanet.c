#include<stdio.h>
#include<string.h>
#include "planet.h"

int main(){
	planet_t current_planet,
	previous_planet,
	blank_planet = {"", 0, 0, 0, 0};
	
	strcpy(current_planet.name, "Jupiter");
	current_planet.diameter = 142800;
	current_planet.moons = 16;
	current_planet.orbit_time = 11.9;
	current_planet.rotation_time = 9.925;
	
	printf("%s's equatorial diameter is %.1f km.\n", current_planet.name, current_planet.diameter);
	
	//A new copy of a structure’s value
	previous_planet = current_planet;
	
	print_planet(previous_planet);
	//previous_planet.diameter = 10;
	printf("%d\n", planet_equal(previous_planet, current_planet));
	saveText(current_planet);
	saveBin(current_planet);


//	int status = scan_planet(&current_planet);
//	print_planet(current_planet);	
	
//	readText(&current_planet);	
	readBin(&current_planet);
	print_planet(current_planet);
}
