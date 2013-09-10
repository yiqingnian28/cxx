#include <osipparser2/osip_uri.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv){
	
	osip_uri_t *uri;
	char buffer[] = "sip:j.doe@big.com;maddr=239.255.255.1;ttl=15";
	int i;

	i=osip_uri_init(&uri);
	if (i!=0) { 
		printf("cannot allocate\n"); 
		return -1; 
	}
	
	
	
	i=osip_uri_parse(uri, buffer);
	if (i!=0) { 
		printf("cannot parse uri\n"); 
	}
	
	char *result = (char*)malloc(sizeof(char) * 100);
	osip_uri_to_str(uri, &result);
	
	printf("uri:%s\n",result);
	printf("hostname:%s\n",osip_uri_get_host(uri));
	
	osip_uri_free(uri);

	return 0;
}