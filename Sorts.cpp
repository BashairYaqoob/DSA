void shellsort(int arr[], int n){
	for(int i=n/2; i>0; i/=2){
		for(int j=i; j<n; j++){
			int temp=arr[j];
			int k;
			for(k=j; k>=i && arr[k-i]>temp; k-=i){
			arr[k]=arr[k-i];
			}
			arr[k]=temp;
		}
	}
}
__________________________________________________
void selectionsort(int arr[], int n){
	for(int i=0; i<n-1; i++){
		int min_index=i;
		for(int j=i+1; j<n;j++){
			if(arr[j]<arr[min_index])
			min_index=j;
		}
		int temp=arr[i];
		arr[i]=arr[min_index];
		arr[min_index]=temp;
	}
}___________________________________________
void insertionsort(int arr[], int n){
	for(int i=1; i<n; i++){
		int key=arr[i];
		int j=i-1;
		while(j>=0 &&arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}
____________________________
void combsort(int arr[], int n){
	float shrink=1.3;
	int gap=n;
	bool swapped =true;
	while(gap>1 || swapped){
		gap=(int)(gap/shrink);
		if(gap<1){gap=1;}
		swapped=false;
		for (int i = 0; i+gap< n; ++i)
		{
			if(arr[i]>arr[i+gap]){
				int temp=arr[i];
				arr[i]=arr[i+gap];
				arr[i+gap]=temp;
				swapped=true;
			}
		}
		
	}
}
______________________________________________________
void merge(int myarr[], int l, int m, int r){
			int j=i;
			int j=m+1;
			int k=l;
			int temp[5];
			while(i<=m && j<=r){
				if(myarr[i]<myarr[j]){
					temp[k]=myarr[i];
					i++;
					k++;
				}
				else{
					temp[k]=myarr[j];
					j++;
					k++;
				}
			}
			while(i<=m){
				temp[k]=myarr[i];
				i++;
				k++;
			}
			while(j<=r){
				temp[k]=myarr[j];
				j++;
				k++;
			}
			for(int s=l; s<=r; s++){
				myarr[s]=temp[s];
			}
		}
		void mergesort(int arr[], int l, int r){
			if(l<r){
				int mid=l+r/2;
				mergesort(arr,l,mid);
				mergesort(arr,mid+1,r);
				merge(arr,l,mid,r);
			}
		}
