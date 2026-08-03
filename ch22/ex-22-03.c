// Find the error in the following program fragment and show how to fix it.
// FILE *fp;
//
// if (fp = fopen(filename, "r")) {
//    read characters until end-of-file
// }
// fclose(fp);
//
// My answer:
//
// FILE *fp;
//
// fp = fopen(filename, "r");
// if (fp == NULL) {
//    printf("can't open %s\n", filename");
//    exit(EXITFAILURE);
// } else {
//    read characters until end-of-file
//    fclose(fp);
// }
