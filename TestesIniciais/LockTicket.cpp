#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <iostream>

using namespace std;

class LockTicket {
	
	public: volatile bool wantCS[2] = {false, false};
 	public: volatile int turn = 1;
 	
	 
	//public: vector<bool> wantCS = {false, false}; 
	
	LockTicket(){
		
	}
	
	void requestCS(int id) {
	  int otherId = 1 - id;
	  wantCS[id] = true;
	  turn = otherId;
	  while (wantCS[otherId] && turn == otherId);
	}
	
	void releaseCS(int id) {
	  wantCS[id] = false;
	}
   	
};
   
