#include <stdio.h>

int main()
{
    int s, r, n, storage = 0;

    printf("Enter bucket size: ");
    scanf("%d", &s);

    printf("Enter output rate per time unit: ");
    scanf("%d", &r);

    printf("Enter number of incoming packets: ");
    scanf("%d", &n);

    int p[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter size of packet %d: ", i + 1);
        scanf("%d", &p[i]);
        printf("\nProcessing packet[%d] of size %d\n", i + 1, p[i]);

        if (p[i] + storage > s)
        {
            printf("Packet dropped. Bucket full.\n");
        }
        else
        {
            storage += p[i];
            printf("Packet accepted. Bucket status: %d/%d\n", storage, s);

            if (storage >= r)
                storage -= r;
            else
                storage = 0;

            printf("After output, bucket status: %d/%d\n", storage, s);
        }
    }

    return 0;
}
