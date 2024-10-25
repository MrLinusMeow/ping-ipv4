#include <fcntl.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(){
	int fd = open("ipv4-list.hex", O_CREAT|O_RDWR|O_APPEND, S_IRUSR|S_IWUSR);
	char buf[9] = {'0','0','0','0','0','0','0','0','\n'};
	union ipv4 { uint64_t n; uint8_t b[4]; };
	union ipv4 ip;
	for(ip.n = 1; ip.n < 4294967296; ++ip.n){
		write(fd, buf, 9);
		
		buf[0] = ((ip.b[3] / 16) > 9) ? (ip.b[3] / 16) + 0x57 : (ip.b[3] / 16) + 0x30;
		buf[1] = ((ip.b[3] % 16) > 9) ? (ip.b[3] % 16) + 0x57 : (ip.b[3] % 16) + 0x30;
		buf[2] = ((ip.b[2] / 16) > 9) ? (ip.b[2] / 16) + 0x57 : (ip.b[2] / 16) + 0x30;
		buf[3] = ((ip.b[2] % 16) > 9) ? (ip.b[2] % 16) + 0x57 : (ip.b[2] % 16) + 0x30;
		buf[4] = ((ip.b[1] / 16) > 9) ? (ip.b[1] / 16) + 0x57 : (ip.b[1] / 16) + 0x30;
		buf[5] = ((ip.b[1] % 16) > 9) ? (ip.b[1] % 16) + 0x57 : (ip.b[1] % 16) + 0x30;
		buf[6] = ((ip.b[0] / 16) > 9) ? (ip.b[0] / 16) + 0x57 : (ip.b[0] / 16) + 0x30;
		buf[7] = ((ip.b[0] % 16) > 9) ? (ip.b[0] % 16) + 0x57 : (ip.b[0] % 16) + 0x30;
	}
	close(fd);
	return 0;
}
