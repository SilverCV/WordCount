#include "WordCount.h"
int main(int argc,char* argv[]) {
    clock_t start = clock();
    WordCount(argc,argv);
	clock_t end = clock();
	printf("%d\n",(end-start));
    return 0;
}
