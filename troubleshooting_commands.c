#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("=== Network Troubleshooting Commands (Linux/unbuntu) ===\n\n");

    printf("1. IP Configuration:\n");
    system("ip a"); // Shows IP addresses
    printf("\n");

    printf("2. Ping google.com:\n");
    system("ping -c 4 google.com"); // Checks connectivity
    printf("\n");

    printf("3. Traceroute to google.com:\n");
    system("traceroute google.com"); // Shows route to server
    printf("\n");

    printf("4. Netstat (active connections):\n");
    system("netstat -a"); // Lists network connections
    printf("\n");

    printf("5. ARP -a (IP-to-MAC mapping):\n");
    system("arp -a"); // Shows ARP table
    printf("\n");

    printf("6. NSLookup www.google.com:\n");
    system("nslookup www.google.com"); // DNS lookup
    printf("\n");

    return 0;
}
