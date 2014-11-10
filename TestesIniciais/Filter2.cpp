class Filter {
 int[] level;
 int[] victim;
 
	 public Filter(int n) {
	     level = new int[n];
	     victim = new int[n]; // use 1..n-1
	     for (int i = 0; i < n; i++) {
	         level[i] = 0;
	     }
	 }
 
	 public void lock() {
	     int me = ThreadID.get();
	     for (int i = 1; i < n; i++) { //attempt level 1
		     level[me] = i;
		     victim[i] = me;
		     // spin while conflicts exist
		     boolean conflicts_exist = true;
		     while (conflicts_exist) {
			   conflicts_exist = false;
			   for (int k = 1; k < n; k++) {
			      if (k != me && level[k] >= i && victim[i] == me) {
			         conflicts_exist = true;
			         break;
			      }
			   }
			};
	     }
	 }
 
	 public void unlock() {
	     int me = ThreadID.get();
	    level[me] = 0;
	}
}
