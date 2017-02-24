
#include <stdio.h>
#include <stdlib.h>

#define PINGGATE "pingsOutputs/pingGate.txt"
#define PINGNEIGHBOUR "pingsOutputs/pingNeighbour.txt"
#define PINGGOOGLE "pingsOutputs/pingGoogle.txt"

typedef struct PingEntry{
	int hour;
	int minute;
	int second;
	int numPacket;
	float replyTime;	
}PingEntry;

PingEntry onePing;
int i, j, k;

int countPings(FILE *pingsFile);
int getLastPing(FILE *pingsFile);
void showUnsucessfullPings(FILE *pingsFile, int lastPingNumber, int numberOfPings);
void showFirstAndLastPingsTimes(FILE *pingsFile, int gamb);
void doAnalysis(FILE *pingsFile, int pingTotal);
int checkPingHour(PingEntry ping);
int checkPingMinute(PingEntry ping);
void createPingArray(FILE *pingsFile, int pingTotal, PingEntry *pingArray);
void showPingArray(PingEntry *pingArray, int pingTotal);

int main(){
	
	//open the files containing already treated pings results
	FILE *ptPingGate, *ptPingNeighbour, *ptPingGoogle;
	ptPingGate = fopen(PINGGATE, "rt");
	ptPingNeighbour = fopen(PINGNEIGHBOUR, "rt");
	ptPingGoogle = fopen(PINGGOOGLE, "rt");
	
	//show number of pings for each host
	int pingsNumberGate, pingsNumberNeighbour, pingsNumberGoogle;
	pingsNumberGate = countPings(ptPingGate);
	pingsNumberNeighbour = countPings(ptPingNeighbour);
	pingsNumberGoogle = countPings(ptPingGoogle);	
	printf("number of sucessfull pings to the local gateway: %i\n", pingsNumberGate);
	printf("number of sucessfull pings to the neighbour gateway: %i\n", pingsNumberNeighbour);
	printf("number of sucessfull pings to Google's DNS server: %i\n", pingsNumberGoogle);
	printf("\n");
	
	//show last sucessfull ping for each host
	int lastGatePing, lastNeighbourPing, lastGooglePing;
	lastGatePing = getLastPing(ptPingGate);
	lastNeighbourPing = getLastPing(ptPingNeighbour);
	lastGooglePing = getLastPing(ptPingGoogle);
	printf("last sucessfull ping to local gateway: %i\n", lastGatePing);
	printf("last sucessfull ping to neighbour gateway: %i\n", lastNeighbourPing);
	printf("last sucessfull ping to Google's DNS server: %i\n", lastGooglePing);
	printf("\n");
	
	//show last and first pings to each host
	printf("pings to local gateway: \n");
	showFirstAndLastPingsTimes(ptPingGate, 0);
	printf("\n");
	printf("pings to neighbour gateway: \n");
	showFirstAndLastPingsTimes(ptPingNeighbour, -1);
	printf("\n");
	printf("pings to Goggle's DNS server: \n");
	showFirstAndLastPingsTimes(ptPingGoogle, -1);
	printf("\n");
	getchar();
	
	//show analysis
	printf("detailed analysis of pings to the local gateway: \n");
	doAnalysis(ptPingGate, pingsNumberGate);
	printf("\n");
	getchar();
	printf("detailed analysis of pings to the neighbour gateway: \n");
	doAnalysis(ptPingNeighbour, pingsNumberNeighbour);
	printf("\n");
	getchar();
	printf("detailed analysis of pings to Google's DNS server: \n");
	doAnalysis(ptPingGoogle, pingsNumberGoogle);
	printf("\n");
	getchar();
	
	//closes the files
	fclose(ptPingGate);
	fclose(ptPingNeighbour);
	fclose(ptPingGoogle);
	
	return 0;
}

void doAnalysis(FILE *pingsFile, int pingTotal){
	
	//creation of the ping array
	PingEntry pingArray[pingTotal];
	createPingArray(pingsFile, pingTotal, pingArray);
		
	//values being atributed to the hourMinuteArray, first with 0 values, them real values	
	int totalHours;
	totalHours = pingArray[pingTotal-1].hour - pingArray[0].hour + 1;
	int hourMinuteArray[totalHours][60]; //ta forçando 5 horas precisa mudar
	for(i=0;i<totalHours;i++){
		for(j=0;j<60;j++){
			hourMinuteArray[i][j]=0;
		}
	}	
	int tmpHour=0, tmpMinute=0;
	for(i=0;i<pingTotal;i++){
		tmpHour = pingArray[i].hour;
		tmpMinute = pingArray[i].minute;
		hourMinuteArray[tmpHour-pingArray[0].hour][tmpMinute]++;
	}
	
	//show results
	for(i=0;i<totalHours;i++){
		for(j=0;j<60;j++){
			printf("%i:%i -> ", i+10, j);
			for(k=0;k<hourMinuteArray[i][j];k++){
				printf("X");
			}
			printf("\n");
		}
		getchar();
	}	
	
}


void showPingArray(PingEntry *pingArray, int pingTotal){
	for(i=0;i<pingTotal;i++){
		printf("%i %i %i %i %.3f\n", pingArray[i].hour, pingArray[i].minute,
	    pingArray[i].second, pingArray[i].numPacket,
	    pingArray[i].replyTime);
	}	
}

void createPingArray(FILE *pingsFile, int pingTotal, PingEntry *pingArray){
	fseek(pingsFile, 0, SEEK_SET);
	for(i=0;i<pingTotal;i++){
		fscanf(pingsFile, "%i", &pingArray[i].hour);
		fscanf(pingsFile, "%i", &pingArray[i].minute);
		fscanf(pingsFile, "%i", &pingArray[i].second);
		fscanf(pingsFile, "%i", &pingArray[i].numPacket);
		fscanf(pingsFile, "%f", &pingArray[i].replyTime);
	}
}


int checkPingHour(PingEntry ping){
	return ping.hour;
}

int checkPingMinute(PingEntry ping){
	return ping.minute;
}

void showFirstAndLastPingsTimes(FILE *pingsFile, int gamb){
	int hour, minute, second;
	fseek(pingsFile, 0, SEEK_SET);
	fscanf(pingsFile, "%i", &onePing.hour);
	fscanf(pingsFile, "%i", &onePing.minute);
	fscanf(pingsFile, "%i", &onePing.second);
	fscanf(pingsFile, "%i", &onePing.numPacket);
	fscanf(pingsFile, "%f", &onePing.replyTime);
	hour = onePing.hour;
	minute = onePing.minute;
	second = onePing.second;
	printf("1st sucessfull ping at: %i:%i:%i\n", hour, minute, second);
	fseek(pingsFile, 1, SEEK_END);
	fseek(pingsFile, -sizeof(onePing)+gamb, SEEK_CUR); 
	fscanf(pingsFile, "%i", &onePing.hour);
	fscanf(pingsFile, "%i", &onePing.minute);
	fscanf(pingsFile, "%i", &onePing.second);
	fscanf(pingsFile, "%i", &onePing.numPacket);
	fscanf(pingsFile, "%f", &onePing.replyTime);
	hour = onePing.hour;
	minute = onePing.minute;
	second = onePing.second;
	printf("Last sucessfull ping at: %i:%i:%i\n", hour, minute, second);
}

void showUnsucessfullPings(FILE *pingsFile, int lastPingNumber, int numberOfPings){
	fseek(pingsFile, 0, SEEK_SET);
	int pingsArray[lastPingNumber+1];
	for(i=0;i<numberOfPings;i++){
		fscanf(pingsFile, "%i", &onePing.hour);
		fscanf(pingsFile, "%i", &onePing.minute);
		fscanf(pingsFile, "%i", &onePing.second);
		fscanf(pingsFile, "%i", &onePing.numPacket);
		fscanf(pingsFile, "%f", &onePing.replyTime);
		pingsArray[onePing.numPacket] = 1;
	}
	for(i=0;i<lastPingNumber+1;i++){
		if(pingsArray[i]!=1){
			printf("ping %i falhou\n", i);
		}
	}	
}

int getLastPing(FILE *pingsFile){
	fseek(pingsFile, 0, SEEK_END);
	fseek(pingsFile, -sizeof(onePing)+1, SEEK_CUR);
	fscanf(pingsFile, "%i", &onePing.hour);
	fscanf(pingsFile, "%i", &onePing.minute);
	fscanf(pingsFile, "%i", &onePing.second);
	fscanf(pingsFile, "%i", &onePing.numPacket);
	fscanf(pingsFile, "%f", &onePing.replyTime);
	return onePing.numPacket;
}

int countPings(FILE *pingsFile){	
	char checkChar; 
	int pingsNumber=0; 
	while((checkChar=fgetc(pingsFile)) != EOF){
		if(checkChar=='\n'){
			pingsNumber++;
		}
	}	
	return pingsNumber;
}

//show unsucessfull pings numbers
//showUnsucessfullPings(ptPingGate, lastGatePing, pingsNumberGate);
//showUnsucessfullPings(ptPingNeighbour, lastNeighbourPing, pingsNumberNeighbour);
//showUnsucessfullPings(ptPingGoogle, lastGooglePing, pingsNumberGoogle);
	


/*


 
*/