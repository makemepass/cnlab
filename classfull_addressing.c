#include <stdio.h>
int main() {
    int a, b, c, d;
    printf("Enter IP address (format: a.b.c.d): ");
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);
    if ((a < 0 || a > 255) || (b < 0 || b > 255) || 
        (c < 0 || c > 255) || (d < 0 || d > 255)) {
        printf("Invalid IP address!\n");
        return 0;
    }
    printf("\nAnalyzing IP Address: %d.%d.%d.%d\n", a, b, c, d);
    printf("--------------------------------------\n");
    if (a >= 1 && a <= 126) {
        printf("Class: A\n");
        printf("Default Mask: 255.0.0.0\n");
        printf("Network ID: %d.0.0.0\n", a);
        printf("Host ID: 0.%d.%d.%d\n", b, c, d);
    }
    else if (a >= 128 && a <= 191) {
        printf("Class: B\n");
        printf("Default Mask: 255.255.0.0\n");
        printf("Network ID: %d.%d.0.0\n", a, b);
        printf("Host ID: 0.0.%d.%d\n", c, d);
    }
    else if (a >= 192 && a <= 223) {
        printf("Class: C\n");
        printf("Default Mask: 255.255.255.0\n");
        printf("Network ID: %d.%d.%d.0\n", a, b, c);
        printf("Host ID: 0.0.0.%d\n", d);
    }
    else if (a >= 224 && a <= 239) {
        printf("Class: D (Multicast)\n");
        printf("Used for Multicast Applications.\n");
    }
    else if (a >= 240 && a <= 255) {
        printf("Class: E (Experimental)\n");
        printf("Reserved for Research Purposes.\n");
    }
    else {
        printf("Invalid or Reserved IP address range (0.x.x.x or 127.x.x.x)\n");
    }
    return 0;
}
