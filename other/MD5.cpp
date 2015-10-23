/* Implemented according to RFC1321
 * https://www.ietf.org/rfc/rfc1321.txt
 * Only applies to Little endian machine
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int main() {
    // http://www.cplusplus.com/reference/cstdio/fread/?kw=fread
    FILE *fp;
    long fSize;

    fp = fopen("input.txt", "rb");
    if ( fp == NULL ) {
        printf("Error! Cannot open the file!\n");
    }

    fseek(fp, 0, SEEK_END);
    fSize = ftell(fp);
    rewind(fp);

    unsigned char* buffer = (unsigned char*) malloc(sizeof(unsigned char) * fSize);
    if ( buffer == NULL ) {
        printf("Error!\n");
    }

    fread(buffer, 1, fSize, fp);

    long size = fSize;
    // append "1" bit to message: padding 1000 0000, which equals 128
    buffer[size++] = 128;

    // append "0" bit until message length in bits ≡ 448 (mod 512)
    while ( size % 64 != 56 ) {
        buffer[size++] = 0;
    }

    // append original length in bits mod to message
    memcpy(buffer + size, (int*) &fSize, sizeof(int));
    size += 4;
    memcpy(buffer + size, (int*) &fSize + 1, sizeof(int));
    size += 4;

    // Test
    printf("%ld\n", size);
    for ( int i = 0; i < size; ++i ) {
        printf("%u ", buffer[i]); 
    }

    // Init MD Buffer
    
    fclose(fp);
    free(buffer);
}
