#include<stdio.h>
#include<string.h>
#define STRSIZ 10

//Naming Convention for Types: suffix_t
typedef struct {
	char name[STRSIZ];
	double diameter; /* equatorial diameter in km */
	int moons; /* number of moons */
	double orbit_time, /* years to orbit sun once */
	rotation_time; /* hours to complete one revolution on axis */
} planet_t;

typedef struct {
	double diameter;
	planet_t planets[9];
	char galaxy[STRSIZ];
} solar_sys_t;

//Displays with labels all components of a planet_t structure
void print_planet(planet_t pl) { /* input - one planet structure */
	printf("%s\n", pl.name);
	printf(" Equatorial diameter: %.0f km\n", pl.diameter);
	printf(" Number of moons: %d\n", pl.moons);
	printf(" Time to complete one orbit of the sun: %.2f years\n", pl.orbit_time);
	printf(" Time to complete one rotation on axis: %.4f hours\n", pl.rotation_time);
}

//Determines whether or not the components of planet_1 and planet_2 match
int planet_equal(planet_t planet_1, planet_t planet_2){
	return (strcmp(planet_1.name, planet_2.name) == 0 && planet_1.diameter == planet_2.diameter &&
		planet_1.moons == planet_2.moons && planet_1.orbit_time == planet_2.orbit_time &&
		planet_1.rotation_time == planet_2.rotation_time);
}



/*
 * Fills a type planet_t structure with input data. Integer returned as
 * function result is success/failure/EOF indicator.
 * 1 => successful input of one planet
 * 0 => error encountered
 * EOF => insufficient data before end of file
 * In case of error or EOF, value of type planet_t output argument is
 * undefined.
*/
	
int scan_planet(planet_t *plnp) { /* output - address of planet_t structure to fill */
	int result;
	
//	result = scanf("%s%lf%d%lf%lf", (*plnp).name, 
//									&(*plnp).diameter,
//									&(*plnp).moons,
//									&(*plnp).orbit_time,
//									&(*plnp).rotation_time);

	//rewrite previous scanf with indirect component selection operator "->"
	result = scanf("%s%lf%d%lf%lf", plnp->name,
									&plnp->diameter,
									&plnp->moons,
									&plnp->orbit_time,
									&plnp->rotation_time);									
	if (result == 5)
		result = 1;
	else if (result != EOF)
		result = 0;
	return (result);
}

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
	
	int status = scan_planet(&current_planet);
	print_planet(current_planet);
}
