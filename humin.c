#include <stdio.h>
#include <stdlib.h>
#include <string.h>	// needed for strcmp()-ing the '-h' argument

#define SECONDS_DAY 86400
#define SECONDS_HR  3600
#define SECONDS_MIN 60

// print help
void usage(void)
{
	printf("converts seconds to human readable format\n");
	printf("usage: %s <seconds>\n", "humin");
}

int main(int argc, char **argv)
{
	int input;
	int days = 0, hours = 0, minutes = 0, seconds = 0;

	// print usage if a single argument isn't given,
	// or if the first argument is '-h'
	if (argc != 2 || strcmp(argv[1], "-h") == 0) {
		usage();
		exit(1);
	}

	// convert input to int
	input = atoi(argv[1]);

	// seconds conversion
	days = input / SECONDS_DAY;
	hours = (input % SECONDS_DAY) / SECONDS_HR;
	minutes = (input % SECONDS_HR) / SECONDS_MIN;
	seconds = input % SECONDS_DAY % SECONDS_HR % SECONDS_MIN;

	// if days aren't needed, print in hh:mm:ss format
	if (days == 0) {
		printf("%02d:%02d:%02d\n",
			hours, minutes, seconds);
	}
	else {
		printf("%02d days %02d:%02d:%02d\n",
			days, hours, minutes, seconds);
	}
}
