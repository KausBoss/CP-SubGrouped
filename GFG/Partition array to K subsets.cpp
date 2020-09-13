bool issearch(int A[],int index,int target,int K,int partition[]){
	if(index<0){
		return true;
	}

	int v=A[index--];


	for(int i=0;i<K;i++){
		if(partition[i]+v<=target){
			partition[i]+=v;
			if (issearch(A,index,target,K,partition)){
				return true;
			}

			partition[i]=partition[i]-v; 
		}
		if (partition[i] == 0){
			break;
		} 
	}
	return false;
}

bool isKPartitionPossible(int A[], int N, int K){
	int index,target;
	int sum=0;
	for(int i=0;i<N;i++){
   		sum=sum + A[i];
	}
	if(sum%K>0)
	return false;

	target=sum/K;
	sort(A,A+N);
	int partition[K];
	for(int i=0;i<K;i++){
    	partition[i]=0;
	}
	index=N-1;

	return issearch(A,index,target,K,partition);
}
