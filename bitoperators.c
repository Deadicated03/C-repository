#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/stat.h>






int reverse_endian(int num);


int main(void)
{
	int num = 0xA0B0C0;

	printf("Original number: %8X (%d)\n", num, num);
	num = reverse_endian(num);
	printf("Reversed endianess number: %8X (%d)\n", num, num);
	
	return 0;
}


int reverse_endian(int num)
{
	int b1, b2, b3, b4;

	/* Isolate the 4 bytes */
	b1 = num & 0xFF;             /* = 255 = 11111111b */
	b2 = (num >> 8)  & 0xFF;     /* = 255 = 11111111b */
	b3 = (num >> 16) & 0xFF;     /* = 255 = 11111111b */
	b4 = (num >> 24) & 0xFF;     /* = 255 = 11111111b */

	/* Shift and place the 4 bytes */
	num = b1;                  /* Push b1 */
	num = (num << 8) | b2;     /* Push b2 */
	num = (num << 8) | b3;     /* Push b3 */
	num = (num << 8) | b4;     /* Push b4 */

	return (num);
}
