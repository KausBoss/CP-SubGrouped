void merger(int *a, int arr[], int k, int lim){
	int *temp[10000];
	int i=0, j=0, k=0;
	while(i<lim && j<k){
		if(a[i] < arr[j]){
			temp[k++] = a[i++];
		}
		else{
			temp[k++] = arr[j++];	
		}
	}
	while(j<k){temp[k++] = arr[j++];}
	while(a[i] < arr[j]){temp[k++] = a[i++];}
	for(int i=0; i<lim+k; i++){
		a[i] = temp[i];
	}
}

int *mergeKArrays(int arr[][N], int k){
	int *a = new int[k*k];
	for(int i=0; i<k; i++){
		a[i] = arr[0][i];
	}
	for(int i=1; i<k; i++){
		merger(a, arr[i], k, i*k);
	}
	return a;
}