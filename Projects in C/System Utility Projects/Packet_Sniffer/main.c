#include <stdio.h>
#include <pcap.h>

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_if_t *alldevs, *d;

    if (pcap_findalldevs(&alldevs, errbuf) == -1)
    {
        printf("Error finding devices: %s\n", errbuf);
        return 1;
    }

    printf("Available Network Devices:\n");
    int i = 1;
    for (d = alldevs; d; d = d->next)
    {
        printf("%d. %s - %s\n", i++, d->name, d->description ? d->description : "No description");
    }

    pcap_freealldevs(alldevs);
    return 0;
}
