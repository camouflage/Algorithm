/* Implemented according to RFC1321
 * https://www.ietf.org/rfc/rfc1321.txt
 * Only applies to Little endian machine
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

const unsigned int T[] = {
    0xd76aa478,  /* T1 */
    0xe8c7b756,  /* T2 */
    0x242070db,  /* T3 */
    0xc1bdceee,  /* T4 */
    0xf57c0faf,  /* T5 */
    0x4787c62a,  /* T6 */
    0xa8304613,  /* T7 */
    0xfd469501,  /* T8 */
    0x698098d8,  /* T9 */
    0x8b44f7af,  /* T10 */
    0xffff5bb1,  /* T11 */
    0x895cd7be,  /* T12 */
    0x6b901122,  /* T13 */
    0xfd987193,  /* T14 */
    0xa679438e,  /* T15 */
    0x49b40821,  /* T16 */
    0xf61e2562,  /* T17 */
    0xc040b340,  /* T18 */
    0x265e5a51,  /* T19 */
    0xe9b6c7aa,  /* T20 */
    0xd62f105d,  /* T21 */
    0x02441453,  /* T22 */
    0xd8a1e681,  /* T23 */
    0xe7d3fbc8,  /* T24 */
    0x21e1cde6,  /* T25 */
    0xc33707d6,  /* T26 */
    0xf4d50d87,  /* T27 */
    0x455a14ed,  /* T28 */
    0xa9e3e905,  /* T29 */
    0xfcefa3f8,  /* T30 */
    0x676f02d9,  /* T31 */
    0x8d2a4c8a,  /* T32 */
    0xfffa3942,  /* T33 */
    0x8771f681,  /* T34 */
    0x6d9d6122,  /* T35 */
    0xfde5380c,  /* T36 */
    0xa4beea44,  /* T37 */
    0x4bdecfa9,  /* T38 */
    0xf6bb4b60,  /* T39 */
    0xbebfbc70,  /* T40 */
    0x289b7ec6,  /* T41 */
    0xeaa127fa,  /* T42 */
    0xd4ef3085,  /* T43 */
    0x04881d05,  /* T44 */
    0xd9d4d039,  /* T45 */
    0xe6db99e5,  /* T46 */
    0x1fa27cf8,  /* T47 */
    0xc4ac5665,  /* T48 */
    0xf4292244,  /* T49 */
    0x432aff97,  /* T50 */
    0xab9423a7,  /* T51 */
    0xfc93a039,  /* T52 */
    0x655b59c3,  /* T53 */
    0x8f0ccc92,  /* T54 */
    0xffeff47d,  /* T55 */
    0x85845dd1,  /* T56 */
    0x6fa87e4f,  /* T57 */
    0xfe2ce6e0,  /* T58 */
    0xa3014314,  /* T59 */
    0x4e0811a1,  /* T60 */
    0xf7537e82,  /* T61 */
    0xbd3af235,  /* T62 */
    0x2ad7d2bb,  /* T63 */
    0xeb86d391,  /* T64 */
};

const unsigned int s[] = {
    7, 12, 17, 22,
    5, 9, 14, 20,
    4, 11, 16, 23,
    6, 10, 15, 21
};

unsigned int F(unsigned int x, unsigned int y, unsigned int z) {
    return (x & y) | (~x & z);
}

unsigned int G(unsigned int x, unsigned int y, unsigned int z) {
    return (x & z) | (y & ~z);
}

unsigned int H(unsigned int x, unsigned int y, unsigned int z) {
    return x ^ y ^ z;
}

unsigned int I(unsigned int x, unsigned int y, unsigned int z) {
    return y ^ (x | ~z);
}

unsigned int shiftLeft(unsigned int x, int n) {
    return ( (x << n) | (x >> (32 - n)) );

}

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

    
    printf("%ld\n", size);
    for ( int i = 0; i < size; ++i ) {
        printf("%u ", buffer[i]); 
    }
    

    // Init MD Buffer
    unsigned int a = 0x67452301;
    unsigned int b = 0xefcdab89;
    unsigned int c = 0x98badcfe;
    unsigned int d = 0x10325476;
    
    unsigned char x[16];
    for ( int i = 0; i < size / 64; ++i ) {
        unsigned aa = a;
        unsigned bb = b;
        unsigned cc = c;
        unsigned dd = d;

        for ( int j = 0; j < 16; ++j ) {
            x[j] = buffer[i * 16 + j];
        }

        a = b + ((a + F(b, c, d) + x)
    }
    
    fclose(fp);
    free(buffer);
}
