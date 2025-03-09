#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define HEIGHT 70
#define WIDTH 70

int main(int argc, char *argv[])
{
	(void)argc;
	int xshift = 0, yshift = 0;
	int h = HEIGHT;
	int w = WIDTH;

	if (*argv && *++argv) h = atoi(*argv);
	if (*argv && *++argv) w = atoi(*argv);
	if (*argv && *++argv) xshift = atoi(*argv);
	if (*argv && *++argv) yshift = atoi(*argv);

	for (int i=0; i<yshift; ++i) printf("\n");
	for (float x=0; x<h; ++x) {
		for (float y=0; y<w; ++y) {
		        float adj = (2*x - w) / h;
		        float opp = (2*y - h) / h;
		        float hyp = sqrtf(adj*adj + opp*opp);

			float o = hyp;
			o -= 0.5;
			o += (0.01*h) / (2*(x - y) + h - w);
			o = o > 0 ? o : -o;
		        o = 0.1 / o;

			char c = "X.,=O%&@"[(int)(floorf(o/(o+1)*8))];
			printf("%c%c", c, c);
		}
		printf("\n");
		for (int i=0; i<xshift; ++i) printf("\t");
	}
	return 0;
}
