class Lock {
		static int n;
		volatile int level[]; // level[i] for thread i
		volatile int victimn[]; // victim[L] for level L

public:
//Construtor:
	Lock(int n) {
		for (int i = 1; i < n; i++) {
			level[i] = 0;
		}
	}
	 
	void lock( int id){
		int i = id;
		for (int L = 1; L < n; L++) {
			level[i] = L;
			victimn[L] = i;
			
			// spin while conflicts exist
		    bool conflicts_exist = true;
			while (conflicts_exist) {
			   conflicts_exist = false;
			   for (int k = 1; k < n; k++) {
			      if (k != i && level[k] >= L && victimn[L] == i) {
			         conflicts_exist = true;
			         break;
			      }
			   }
			};
			
			i ++;
		}
	}


	void unlock(int id) {
		level[id] = 0;
	}
	 
}
