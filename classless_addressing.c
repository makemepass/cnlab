#include <stdio.h>
#include <math.h>

int main() {
    unsigned int a, b, c, d, prefix;
    unsigned int ip, mask, network, broadcast;
    unsigned int num_hosts;

    printf("Enter IP address with prefix: ");
    scanf("%u.%u.%u.%u/%u", &a, &b, &c, &d, &prefix);

    ip = (a << 24) | (b << 16) | (c << 8) | d;
    mask = (prefix == 0) ? 0 : (0xFFFFFFFF << (32 - prefix));
    network = ip & mask;
    broadcast = network | ~mask;

    if (prefix == 31)
        num_hosts = 0;
    else if (prefix == 32)
        num_hosts = 1;
    else
        num_hosts = pow(2, (32 - prefix)) - 2;

    printf("\n--- CIDR Calculation ---\n");
    printf("CIDR Notation       : %u.%u.%u.%u/%u\n", a, b, c, d, prefix);
    printf("Subnet Mask         : %u.%u.%u.%u\n",
           (mask >> 24) & 255, (mask >> 16) & 255,
           (mask >> 8) & 255, mask & 255);
    printf("Network Address     : %u.%u.%u.%u\n",
           (network >> 24) & 255, (network >> 16) & 255,
           (network >> 8) & 255, network & 255);
    printf("Broadcast Address   : %u.%u.%u.%u\n",
           (broadcast >> 24) & 255, (broadcast >> 16) & 255,
           (broadcast >> 8) & 255, broadcast & 255);

    if (prefix <= 30) {
        printf("First Host          : %u.%u.%u.%u\n",
               ((network + 1) >> 24) & 255, ((network + 1) >> 16) & 255,
               ((network + 1) >> 8) & 255, (network + 1) & 255);
        printf("Last Host           : %u.%u.%u.%u\n",
               ((broadcast - 1) >> 24) & 255, ((broadcast - 1) >> 16) & 255,
               ((broadcast - 1) >> 8) & 255, (broadcast - 1) & 255);
    } else {
        printf("First Host          : N/A\n");
        printf("Last Host           : N/A\n");
    }

    printf("Number of Hosts     : %u\n", num_hosts);
    return 0;
}
