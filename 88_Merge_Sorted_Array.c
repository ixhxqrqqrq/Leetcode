void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i = 0,j=0,k=0;
    int* res= (int*) calloc( nums1Size,sizeof(int) );
    if ( res==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }

    for ( i=0,j=0; i<m && j<n; k++) {
        if(nums1[i]>nums2[j]){
            res[k] = nums2[j];
            j++;
        }
        else {
            res[k] = nums1[i];
            i++;
        }
    }
    while(i<m){
        res[k] = nums1[i];
        i++;
        k++;
    }
    while (j<n) {
        res[k] = nums2[j];
        j++;
        k++;
    }

    for ( i=0; i<nums1Size; i++ ) {
        nums1[i] = res[i];
    }


    res	= NULL;
    free ( res );




}
