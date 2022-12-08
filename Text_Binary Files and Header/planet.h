/*
	planet.h
*/

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


void saveBin(planet_t a_planet){	
	FILE *plan_bin_outp;
	
	plan_bin_outp = fopen("planet_out.bin", "wb");
	fwrite(&a_planet,sizeof (planet_t),1, plan_bin_outp);	
	fclose(plan_bin_outp);
}

void saveText(planet_t a_planet){	
	FILE *plan_txt_outp;
	
	plan_txt_outp = fopen("planet_out.txt", "w");
	fprintf(plan_txt_outp,"%s %f %d %e %e",a_planet.name, a_planet.diameter,a_planet.moons,a_planet.orbit_time,a_planet.rotation_time);
	fclose(plan_txt_outp);
}

void readBin(planet_t *a_planet){
	FILE *plan_bin_inp;
	plan_bin_inp =fopen("planet_out.bin", "rb");
	fread(&a_planet,sizeof (planet_t),1, plan_bin_inp);
	fclose(plan_bin_inp);
}

void readText(planet_t *a_planet){
	FILE *plan_txt_inp;
	plan_txt_inp =fopen("planet_out.txt", "r");
	fscanf(plan_txt_inp, "%s%lf%d%lf%lf", a_planet->name, &a_planet->diameter, &a_planet->moons, &a_planet->orbit_time, &a_planet->rotation_time);
	fclose(plan_txt_inp);
}
